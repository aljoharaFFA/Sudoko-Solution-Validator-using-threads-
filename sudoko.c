#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#define rows 9
#define cols 9



void* checkColumn(void * args){
  printf("in");
  int i,j,w;
  int (*array)[rows][cols] = args;
  for (i = 0; i < rows; i++){
    for (j = 0; j < cols; j++){
      for (w = 0; w < cols - 1; w++) {
        printf("here");
        if ((*array)[rows][cols] == (*array)[rows][cols + 1]){
          printf("false");
          pthread_exit(NULL);
         
        }
      }
    }
  }
}






int main(){
  int sudoko[rows][cols] = {
    {9,2,7,1,5,4,3,9,6}
    ,{9,6,5,3,2,7,1,4,8}
    ,{3,4,1,6,8,9,7,5,2}
    ,{5,9,3,4,6,8,2,7,1}
    ,{4,7,2,5,1,3,6,8,9}
    ,{6,1,8,9,7,2,4,3,5}
    ,{7,8,6,2,3,5,9,1,4}
    ,{1,5,4,7,9,6,8,2,3}
    ,{2,3,9,8,4,1,5,6,7}
  };
  pthread_t thread;
  pthread_create(&thread, NULL, checkColumn, sudoko);
  pthread_join(thread, NULL);
  
}

