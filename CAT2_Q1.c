/*
Name:Isaiah otieno 
Registration number:PA106/G/28801/25
Description:2D Array that allows user to store data elements 
*/


#include <stdio.h>

int main() {
int scores[2][4] = {
        {65, 92, 35, 70},
        {84, 72, 59, 67}
 };

 // Print elements using nested for loop
 for(int i = 0; i < 2; i++) {
 for(int j = 0; j < 4; j++) {
 printf("%d ", scores[i][j]);
  }
 printf("\n");  // Move to the next line after each row
  }

  return 0;
}