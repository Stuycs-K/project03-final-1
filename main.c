
//Don't forget that coordinate system is (y,x) first

//Difference between move and wmove?

//https://www.youtube.com/watch?v=A5lX1h_2zy0
//mvprintw may be useful

#include<stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <ncurses.h>
#include <sys/stat.h>
#include <dirent.h>
 //What programs do we need on startup?


 //Displays all .txt files in the directory runs out startup
 void display(){
 //Use while loop with readdir to display
 //Necessario para usando ncurses y otros
 initscr();
 //So you can use arrow keys and bakcpsace
 //stdscr is the default screen
 keypad(stdscr,TRUE);

 char* directory;
 directory = getcwd();


 }




//On opening a file will print out
 void open(){



 }







//Appends s to the end of the file
void append(char s[256],FILE *f){


}

//Upon typing the ""
void exit(){}

//Continuosuly takes the input from stdin and runs the corresponding function
//Probably using execvp
void input(){}


//Ncurses
//Start with left to right
void movingPlaces(){}
