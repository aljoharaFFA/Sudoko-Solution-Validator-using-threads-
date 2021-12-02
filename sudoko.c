#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#define NUM_THREADS 27 
//why 27 threads? for each grid in the sudoko there will be a thread validating the validity, a thread for each row and column

// strcutures are just objects (like classes in java)
typedef struct {
  int row;
  int column;
} input;// input is the name of our 


int sudoku[9][9] = {0}; //a sudoko puzzle is 9 by 9 table. Also we are setting the 2D array to 0, so all enteries within the array is set to 0.

int main() {
  
    int i,j; //global variable, so we dont have to type int everytime we want to implenet something, so just typing i or j quick is much simpler.
  
  //here we will be taking input from the user, the syntax:
  printf("enter sodoku puzzle");// i is for row, j is for column
  for(i = 0; i < 9; i++){
    for(j = 0; j < 9; j++) {
      scanf("%d", &sudoku[i][j]);
    }
  }
  //priting sudoku
  printf("\n your soduku is");
  for(i = 0; i < 9; i++){
    for (j = 0; j< 9; j++){
      printf("%d", sudoku[i][j]);
    }
      printf("\n");
  }
  
  //------------------------------------------------------------
  
  
}
