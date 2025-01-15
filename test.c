
#include <string.h>
#include <stdlib.h>
#include<stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
  #include <ncurses.h>
#include <sys/stat.h>
#include <dirent.h>

void append(char s,char x[256]){

    int count =0;
    while(x[count] != '\0'){
    count +=1;
  }
  x[count] = s;
  x[count+1]='\0';



}


int main(){
char s[256];
printf("Successful \n");

fgets(s,256,stdin);
initscr();
printw("Good morning");
char *sd =getstr(s);
printw("%s",sd);
refresh();

}
