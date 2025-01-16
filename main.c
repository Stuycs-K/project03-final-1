
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


  //Displays all .txt files in the directory runs out startup
  void display(){
    //Setup
    char s[256];
    char* directory = getcwd(s,256);
    DIR *dir =  opendir(directory);
    struct dirent * currentFile;

    struct stat * stat_buffer;
     stat_buffer = malloc(sizeof(struct stat)*1);
     //This part causes segfault
     //First opens directory then loops through all the files assining values then prints out
     while((currentFile = readdir(dir)) != NULL){
     //  printf("0");
       currentFile = readdir(dir);
     //Get file name from readdir's dirent
       stat(currentFile->d_name,stat_buffer);
       printf("xartgas");
       printf("File Name: %s File Type: %d File Size: %ld \n", currentFile->d_name,currentFile->d_type,stat_buffer->st_size);

       }




printf("Testing1");
  //Use while loop with readdir to display and for ncurses
  initscr();
  //So you can use arrow keys and bakcpsace
  //stdscr is the default screen
  keypad(stdscr,TRUE);
//End of setup



}

int main (){
  //Will be reponsibole for printing and editing and saving to maybe?
  char * editingBuffer = (char *) malloc(sizeof(char)* 8000);
  char *inputBuffer;
//  char  * argsArray[255];
//  fgets(inputBuffer,255,stdin);
  printf("x");
//  parse_args(inputBuffer,argsArray);
  display();
//  if (argsArray[0] == "open"){
  //  printf("successful");
//  }



}

//Make size of file buffer max like 8k


//Opens a file and prints it out, will this allow it to edit?
 void opensss(char* f, char*fileString){
   //Initial start up just prints everything
   int windowY = 0;
   int windowX = 0;
   char * buffer;
   char * inputBuffer;
   //Buffer for printing from opened file to screen
   buffer = (char*) malloc(sizeof(char)* LINES);
   //Buffer for reading from input
   inputBuffer = (char*) malloc(sizeof(char) *LINES);

 fopen(f, "w+");

  while (buffer != "\0"){


  }


  while (1) { //Allows us to move cursor (hopefully) using arrow keys
     char input;
     input = getch();
     if(input ==KEY_UP){
       move(-1,0);
     }
     if(input ==KEY_DOWN){
       move(1,0);
     }
     if(input== KEY_LEFT){
       move(0,-1);
     }
     if(input == KEY_RIGHT){
       move(0,-1);
     }
     else{
       char s[1];
       s[0]=input;
       printw("%s",s);
// put that function here
       //Should write in the file using buffer

  }
    refresh();
   }




 }



//Done
void offsetAdd(char input, char* buffer, int currentPos){
int len = strlen(buffer);

  buffer[len+2] = '\0';
  for (int i = len; i>= currentPos ;i--){
    printf("%d i: %d \n" ,len-currentPos -i,i);
    printf("Current pair; One in front: %c One that replaces it: %c \n",buffer[(len-currentPos) -i],buffer[len-(currentPos) -(i+1)]);
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

//Upon typing the "" automatically saves changes made from window to file and closes the file
void exitFile(char*f){




endwin();


//close(f);
}

// takes the input from stdin using fgets and runs the corresponding function
//Probably using execvp
void inputFile(){

  while(1){

  }




}
