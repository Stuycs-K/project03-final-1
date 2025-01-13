
#include <string.h>
#include <stdlib.h>
#include<stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
  #include <ncurses.h>
#include <sys/stat.h>
#include <dirent.h>



int main(){



  initscr();
  //So you can use arrow keys and bakcpsace
  //stdscr is the default screen
  keypad(stdscr,TRUE);
//End of setup
while (1){
int s = getch();
  printw("Hellow WOrld ");
  printw(" %d ",s);
}
}
