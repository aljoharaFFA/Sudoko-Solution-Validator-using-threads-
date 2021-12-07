#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

 int sudoko[9][9] = {
     {9,2,6,1,5,4,3,8,6}
    ,{8,1,4,3,2,9,1,4,9}
    ,{3,5,7,6,8,7,7,5,2}
    ,{5,9,3,4,6,8,2,7,1}
    ,{4,7,2,5,1,3,6,9,8}
    ,{6,1,8,9,7,2,4,3,5}
    ,{7,8,6,2,3,5,9,1,4}
    ,{1,5,4,7,9,6,7,2,3}
    ,{2,3,9,8,4,1,5,6,7}
  };

void *checkrows(){
int i,j;
int count;

for(int x=0;x<9;x++){
for(i=0;i<9;i++){
    count=0;
  for(j=0;j<9;j++){
if(sudoko[x][j]==sudoko[x][i])
    count++;
    if(count>=2){
    printf("the number %d is repeated in row %d\n",sudoko[x][j],x);
    pthread_exit(NULL);
 
    }}}
}
pthread_exit(NULL);

}

void *checkcols(){
int i,j;
int count;

for(int x=0;x<9;x++){
for(i=0;i<9;i++){
    count=0;
  for(j=0;j<9;j++){
if(sudoko[j][x]==sudoko[i][x])
    count++;
    if(count>=2){
    printf("the number %d is repeated in column %d\n",sudoko[j][x],x);
    pthread_exit(NULL);
    
    }}}
}
pthread_exit(NULL);

}












