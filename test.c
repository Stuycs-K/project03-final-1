
#include <string.h>
#include <stdlib.h>
#include<stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
  #include <ncurses.h>
#include <sys/stat.h>
#include <dirent.h>

void offsetAdd(char input, char* buffer, int currentPos){
  int len = int(strlen(buffer));


  //use plus 2 b/c strlen doesn't count \0
    buffer[len+2] = '\0';
    for (int i = len; i>= currentPos ;i--){
      printf("%d i: %d \n" ,len-currentPos -i,i);
      printf("Current pair; One in front: %c One that replaces it: %c \n",buffer[len-currentPos) -i],buffer[len-(currentPos) -(i+1)]);
      //Should go backwards replacing current with the one before it
      buffer[i+1] = buffer[i];

    }
  buffer[currentPos] = input;
  buffer[len+1]='\0';

//  int termPos = 0;
//  int whereYouPutInput;
//  while(buffer[termPos] != '\0'){
//    termPos +=1;
//  }
//  whereYouPutInput = strlen(buffer)- termPos;
//    buffer[termPos+1] = '\0';
//  while(termPos !=0){
//    buffer[termPos-1] = buffer[termPos];
//  }

//  buffer[whereYouPutInput ] = input;


}




int main(){

char s[256] = "BeforeAfter";
printf("%s \n",s);
offsetAdd('x',s,3);
printf("%s \n",s);
//  initscr();
  //So you can use arrow keys and bakcpsace
  //stdscr is the default screen
//  keypad(stdscr,TRUE);
//End of setup
//while (1){
//int s = getch();
  //printw("Hellow WOrld ");
  //printw(" %d ",s);
//}
}
