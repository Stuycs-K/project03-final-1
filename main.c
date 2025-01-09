
//Don't forget that coordinate system is (y,x) first

//Difference between move and wmove: Move only uses the default window wmove can use anything else

//https://www.youtube.com/watch?v=A5lX1h_2zy0
//mvprintw may be useful (y,x,"%d",c,) goes to a place and prints
//Maybe use conio.h to handle typing
// User Runs Program -> run display() -> user selects program to open -> File is opened and user should be able to interact with it

#include<stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <ncurses.h>
#include <sys/stat.h>
#include <dirent.h>
 //What programs do we need on startup?


//Parses args so that you can run it line should be from stdin
 void parse_args(char * line, char ** arg_ary){


 }



 //Displays all .txt files in the directory runs out startup
 void display(){
   char s[256];
 //Use while loop with readdir to display
 //Necessario para usando ncurses y otros
 initscr();
 //So you can use arrow keys and bakcpsace
 //stdscr is the default screen
 keypad(stdscr,TRUE);

 char* directory;
 directory = getcwd(s,256);


 }




//Opens a file and prints it out, will this allow it to edit?
 void open(FILE* f){
   int windowY = 0;
   int windowX = 0;

   //Buffer for printing from opened file to screen
   buffer = malloc(sizeof(char)* LINES);

   open(f);
   //What is the default size of a window?
   read(buffer,f,256);


   //ncurses LINES and COLUMNS
   printw(buffer,256);


   do{ //Allows us to move cursor (hopefully) using arrow keys
     input = getch();
     if(inputCode ==KEY_UP){
       move(-1,0);
     }
     if(inputCode ==KEY_DOWN){
       move(1,0);
     }
     if(inputCode== KEY_LEFT){
       move(0,-1);
     }
     if(inputCode == KEY_RIGHT){
       move(0-1);
     }
     else{
       print();
    }
    refresh();
   }




 }





//Appends s to the end of the file
void append(char s[256],FILE *f){


}

//Upon typing the ""
void exit(){}

//Continuosuly takes the input from stdin using fgets and runs the corresponding function
//Probably using execvp
void input(){}
