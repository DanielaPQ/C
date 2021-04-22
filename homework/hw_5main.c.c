#include <assert.h>		
#include <ctype.h>		
#include <stdio.h>		
#include <stdlib.h>		
#include <time.h>
#include "hw5.h"


#define ERROR_ALREADY_FOUNDED 1	
#define ERROR_ALREADY_OPENED 2	
#define ERROR_NONE 3		

#define UNCOVERED_SPACE '#'	
#define COVERED_SPACE ' '	
#define MINE 'X'

#define DEBUG 0			
  

int main () {
  int showmines = 0;
  int NUMBER_MINES ;
  int renglon;
  int columna;
  int tipo;
  
  printf("Select: \n Easy mode(10x10) = 0 \n Hard mode(select) = 1 \n ");
  scanf("%d",&tipo);
  
  if (tipo == 1) 
  {
    printf("Enter number rows: ");
    scanf("%d", &renglon);
    printf("Enter number columns: ");
    scanf("%d", &columna); 
    ROWS = renglon;
    COLUMNS = columna;
  } 
  else {
   ROWS = 10;
  COLUMNS = 10;   
  }
  

  printf("Enter number of mines: ");
  scanf("%d", &NUMBER_MINES );
  
  char board[ROWS][COLUMNS];
  
  srand (time (NULL));
  stboard (board);		
  placemrand (NUMBER_MINES, board);		
  
  
 while (1) {
   prtboard (board, showmines);
   if (showmines) {
	 break;
	}
    int column;
    char row;
    printf ("Insert row ");
    scanf (" %c", &row);
    printf ("Insert column ");
    scanf ("%d", &column);
    int status = openbox (row, column, board);	
    if (noleft (board))	{			
	  printf ("You've Won\n");
	  showmines = 1;
	} else if (status == ERROR_ALREADY_OPENED) {
	  printf ("Already opened\n");
	} else if (status == ERROR_ALREADY_FOUNDED) {
	  printf ("You've loosed\n");
	  showmines = 1;
	}
  }
  return 0;
}

