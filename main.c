
//Don't forget that coordinate system is (y,x) first

//Difference between move and wmove: Move only uses the default window wmove can use anything else

//https://www.youtube.com/watch?v=A5lX1h_2zy0
//mvprintw may be useful (y,x,"%d",c,) goes to a place and prints
// User Runs Program -> run display() -> user selects program to open -> File is opened and user should be able to interact with it -> user exits file and back to step 1
//Total list of buffers needed: Buffer for printing from file to window, from input to file,


#include <string.h>
#include <stdlib.h>
#include<stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
  #include <ncurses.h>
#include <sys/stat.h>
#include <dirent.h>
 //What programs do we need on startup?


void windowDelete(int x,int y, int numCols){
  //For deleting chars in ncurses window should move everything to the left
    for (int i = x; i < numCols - 1; ++i) {
      chtype ch = mvinch(y,i+1);
      mvaddch(y,i,ch);
      refresh();
  }
move(y,x);
refresh();
}


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
endwin();
fflush(f);
 fclose(f);

 display();
 //close(f);
 }




 //Done
 void offsetAdd(char input, char* buffer, int currentPos){
 int len = strlen(buffer);

   buffer[len+2] = '\0';
   for (int i = len; i>= currentPos ;i--){
     //Should go backwards replacing current with the one before it
     buffer[i+1] = buffer[i];

   }
 buffer[currentPos] = input;
 buffer[len+1]='\0';

 }




 //Appends s to the end of the file NOT TO THE WINDOW
 //Need to change end
 //Done
 void append(char s,char x[256]){
   int count =0;
   while(x[count] != '\0'){
     count +=1;
   }
   x[count] = s;
   x[count+1]='\0';
 }



 //Opens a file and prints it out, will this allow it to edit?
  void opensss(int fileDescriptor, char*fileString){
    //Initial start up just prints everything
    initscr();
    keypad(stdscr,TRUE);
    int windowY = 0;
    int windowX = 0;
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
    //    break;
        exitFile(file,fileDescriptor);
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
      mvaddch(getcury(stdscr),getcurx(stdscr), ' ');
      windowDelete(getcury(stdscr),getcurx(stdscr),LINES);

      }
      else{
        int currentPos = getcury(stdscr) * getcurx(stdscr);  // Get the current cursor position
        offsetAdd((char)input, buffer, currentPos);  // Modify the buffer
        fseek(file, 0, SEEK_SET);  // Go to the start of the file
        fputs(buffer, file);  // Write the modified content to the file
   }

    }
refresh();

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


  //  opensss(,argsArray);
  }
  //



}

//Make size of file buffer max like 8k
