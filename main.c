//Don't forget that coordinate system is (y,x) first

// User Runs Program -> run display() -> user selects program to open -> File is opened and user should be able to interact with it -> user exits file and back to step 1

#include <string.h>
#include <stdlib.h>
#include<stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
  #include <ncurses.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <dirent.h>
 //What programs do we need on startup?



 // Done for now
   //Displays all .txt files in the directory runs out startup
   void display(){
     //Setup
     char s[256];
     char* directory = getcwd(s,256);
     DIR *dir =  opendir(directory);
     struct dirent * currentFile;

     struct stat * stat_buffer;
     //Maybe causing a seg fault maybe not
      stat_buffer = malloc(sizeof(struct stat)*1);
      //This part causes segfault
      //First opens directory then loops through all the files assining values then prints out
      while((currentFile = readdir(dir)) != NULL){

      //Get file name from readdir's dirent
        stat(currentFile->d_name,stat_buffer);
        printf(" File Name: %s File Type: %d File Size: %ld \n", currentFile->d_name,currentFile->d_type,stat_buffer->st_size);

        }


 }

 //Upon typing the "" automatically saves changes made from window to file and closes the file
 void exitFile(FILE*f,int fd){
fflush(f);
endwin();
//
 fclose(f);

 display();
 //close(f);
 }



 void windowDelete(int y,int x, int numCols){
   //For deleting chars in ncurses window should move everything to the left
   for (int i = x; i < numCols - 1; ++i) {
     chtype ch = mvinch(y,i+1);
     mvaddch(y,i,ch);
     refresh();
   }
   mvaddch(y, numCols - 1, ' ');//Clears last char in the line
   move(y,x);
   refresh();
 }


//For writing deleting from files
 void fileDeleteChar(FILE*file,long currentPos){
 fseek(file,0,SEEK_END);
 long len = ftell(file);
 fseek(file,0,SEEK_SET);
 char*buffer = (char*)malloc(len+1);
 //Reads file into buffer
 fread(buffer,1,len,file);
//buffer[currentPos]=' ';

  for (long i = currentPos; i < len - 1; i++) {
        buffer[i] = buffer[i + 1];  // Shift characters one left
    }

    //Nullterminates
    buffer[len-1]='\0';

    fseek(file, 0, SEEK_SET);  // Moves the file pointer back to the beginning
    fwrite(buffer, 1, len - 1, file);  // Write the updated content -1 char b/c we deleted one
    fflush(file);
    ftruncate(fileno(file), len - 1); //Important to prevent new line from being added when deleting
  free(buffer);
 }


 //Done
 void offsetAdd(char input, FILE* file, long currentPos){
   //Gets current file length
 fseek(file,0,SEEK_END);
 long len = ftell(file);
  fseek(file,0,SEEK_SET);
//Part that reads file into a buffer +2 b/c of null terminating

  char* buffer=(char *)malloc(len +2);
  fread(buffer,1,len,file);//Reads the file into buffer
  if (currentPos >= len) {
    // If the position is at or beyond the end, just append the input (Might take place of append)
    buffer[len]=input;
    buffer[len+1]='\0';
  }
  else for (int i = len -1; i>= currentPos ;i--){
     //Should go backwards replacing current with the one before it
     buffer[i+1] = buffer[i];
   }
   buffer[currentPos] = input;
//buffer[len+1]='\0';
 fseek(file, 0, SEEK_SET);  // Goes back to the beginning of the file
 fwrite(buffer, 1, len + 1, file);  // Write the new content (with the inserted character)

 fflush(file);
 free(buffer);
 }




 //Opens a file and prints it out, will this allow it to edit?
  void opensss(int fileDescriptor, char*fileString){
    //Initial start up just prints everything
    initscr();
    keypad(stdscr,TRUE);
    clear();
    noecho();
    char * buffer;
    char * inputBuffer;

    //Buffer for printing from opened file to screen
    buffer = (char*) malloc(sizeof(char)* LINES);
    //Buffer for reading from input
    inputBuffer = (char*) malloc(sizeof(char) *LINES);
    FILE * file =  fopen(fileString, "r+");
    //Prints out the file's contents
    while (fgets(buffer, LINES, file) !=NULL) {
       printw("%s", buffer);
       refresh();
     }

  //Reading from file to buffer
//User input
   while (1) { //Allows us to move cursor (hopefully) using arrow keys
      int input;
      input = getch();
      if(input ==KEY_UP){
        move(getcury(stdscr)-1,getcurx(stdscr));
      }
      else if(input ==27){ //Exits when you hit esc
        break;
        //exitFile(file,fileDescriptor);
      }
      else if (input=='\n'){
      //  printw('\n');
      }
      else if(input ==KEY_DOWN){
        move(getcury(stdscr)+1,getcurx(stdscr));
      }
      else if(input== KEY_LEFT){
        move(getcury(stdscr),getcurx(stdscr)-1);
      }
      else if(input == KEY_RIGHT){
        move(getcury(stdscr),getcurx(stdscr)+1);
      }
      else if (input == 127 || input == KEY_BACKSPACE){
        //For buffer not window editing
      if (getcurx(stdscr)!=0){
        int tempx = getcurx(stdscr);
        int tempy = getcury(stdscr);
        mvaddch(getcury(stdscr),getcurx(stdscr)-1, ' ');
        windowDelete(getcury(stdscr),getcurx(stdscr)-1,COLS);
        move(tempy,tempx-1);
        int stringIndex = (getcury(stdscr) * COLS) + getcurx(stdscr);
        fileDeleteChar(file,stringIndex);
      }
    }
      else{
      insch(input);
      move(getcury(stdscr),getcurx(stdscr)+1);
          // Window to string index = (Row times x) + col
      int stringIndex = (getcury(stdscr) * COLS) + getcurx(stdscr);
      offsetAdd(input, file, stringIndex);
    }
         refresh();

    }
refresh();
exitFile(file,fileDescriptor);

  }


//Parses args so that you can run it line should be from stdin

void parse_args( char * line, char ** arg_ary ){
  //line should be a mutable string
  //Arg_ary is long enough to store the tokens of the provided line
  //1 space between every argument in string
  //Last thing of arg_ary has to be NULL

  // Parses the line maybe replace with \0
  int count =0;
  while(line){
  arg_ary[count]=  strsep(&line," ");
  count +=1;
}
//Sets the last argument of arg_ary to NULL
arg_ary[count+1] = NULL;
//PATH


}


int main (){
  //Will be reponsibole for printing and editing and saving to maybe?
  char * editingBuffer = (char *) malloc(sizeof(char)* 8000);
  free(editingBuffer);
  char inputBuffer[255];
  char  * argsArray[255];

while(1){
    display();
  fgets(inputBuffer,255,stdin);
  parse_args(inputBuffer,argsArray);
  argsArray[1][strcspn(argsArray[1], "\n")] = 0;

  if (strcmp("open",argsArray[0]) ==0){
    struct stat buffer;
    printf("opening or creating: %s",argsArray[1]);
   if (stat(argsArray[1], &buffer) == 0) { //If the file already exists opens it
     int fd= open(argsArray[1],O_CREAT |O_RDONLY);
     opensss(fd,argsArray[1]);
   }
   else{ //if it dne then creates a new file
     int fd = open(argsArray[1], O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR, 0644);
    opensss(fd, argsArray[1]);
   }

   }
 else if   (strcmp("remove",argsArray[0]) ==0 || strcmp("delete",argsArray[0]) ==0 || strcmp("rm",argsArray[0]) ==0){
   if (argsArray[1]) {
      pid_t pid = fork(); // Forks so it can run display
      if (pid == 0) { // Child process
        // Executes rm
      char *rm_args[] = {"rm", argsArray[1], NULL};//Null ending so exec works
      execvp("rm", rm_args);
      } else if (pid > 0) { // In the parent process
      //Wait for the child process to finish
          wait(NULL);
      // After rm completes, call display()
      display();
      } else { //Not part of the child process
              printf("Error: No filename provided for removal.\n"); //b/c this won won't work with an empty file
              display();
          }
 }
}
  else if((strcmp("cd",argsArray[0])) ==0){
    chdir(argsArray[1]);
    display();
  }
}
free(inputBuffer);
  //  opensss(,argsArray);
  }
  //


//Make size of file buffer max like 8k
