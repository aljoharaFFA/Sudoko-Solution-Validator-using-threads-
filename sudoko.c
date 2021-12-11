#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int thread_return_0or1[2] = {0};/*"each thread. The ith index in this array corresponds to the ith worker thread. If a worker sets its corresponding value to 1, it is indicating that its region of the Sudoku puzzle is valid. A value of 0 would indicate otherwise." 
REFERENCE: The Book page 199.*/ // i set the array to 2 because we created 3 threads, so only 3 threads to retun either 1 or 0

 int sudoko[9][9] = {// this is valid sudoko
   {5,3,4,6,7,8,9,1,2},
   {6,7,2,1,9,5,3,4,8},
   {1,9,8,3,4,2,5,6,7},
   {8,5,9,7,6,1,4,2,3},
   {4,2,6,8,5,3,7,9,1},
   {7,1,3,9,2,4,8,5,6},
   {9,6,1,5,3,7,2,8,4},
   {2,8,7,4,1,9,6,3,5},
   {3,4,5,2,8,6,1,7,9}
  };


void *rowthread(){
  int i,j;
  int count;

for(int x=0;x<9;x++){
  for(i=0;i<9;i++){
    count=0;
    for(j=0;j<9;j++){
      if(sudoko[x][j]==sudoko[x][i])
        count++;
      if(count>=2){
        thread_return_0or1[0] = 0;
        pthread_exit(NULL);
 
    }}}
}
  thread_return_0or1[0] = 1;
  pthread_exit(NULL);

}

void *columnthread(){
  int i,j;
  int count;
  for(int x=0;x<9;x++){
    for(i=0;i<9;i++){
      count=0;
      for(j=0;j<9;j++){
        if(sudoko[j][x]==sudoko[i][x])
          count++;
        if(count>=2){
          thread_return_0or1[1] = 0; //thread detected a duplicate entry
          pthread_exit(NULL);
    
    }}}
}
  thread_return_0or1[1] = 1;
  pthread_exit(NULL);

}

void *matrix(){
int i,j,k,l;
int count;

for(int x=0;x<9;x+=3){//rows
  for(int h=0;h<9;h+=3){
    for(k=x;k<x+3;k++){//
      for(l=h;l<h+3;l++){
     count=0;
        for(i=x;i<x+3;i++){
          for(j=h;j<h+3;j++){
            if(sudoko[k][l]==sudoko[i][j])
              count++;
            if(count>=2){
              thread_return_0or1[2] = 0;
              pthread_exit(NULL);
    
    }}}}}}
}
  thread_return_0or1[2] = 1;
  pthread_exit(NULL);

}

int main(){
pthread_t thread;
pthread_create(&thread, NULL, rowthread,NULL);
 pthread_join(thread, NULL);
 pthread_t thread1;
  pthread_create(&thread1, NULL, columnthread,NULL);
 pthread_join(thread1, NULL);
  pthread_t thread2;
  pthread_create(&thread2, NULL, matrix,NULL);
  pthread_join(thread2, NULL);
  for (int i =0; i<3; i++){
    if (thread_return_0or1[i] == 0){
      printf("invalid sudoko");
      return 0;
    } else {
      printf("valid sudoko");
      return 0;
    }
  }
}
