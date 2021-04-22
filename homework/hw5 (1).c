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


/* Surronding mines */ 
int obteinsurrmines (int row, int column, char board[ROWS][COLUMNS]) {
  int count = 0, strow, endrow, stcolumn, endcolumn;	
  if (row <= 0) {
      strow = 0;		
    } else {
      strow = row - 1;
    }
  
  if (row + 1 >= ROWS) {
      endrow = ROWS - 1;	
    } else {
      endrow = row + 1;
    }
  
 if (column <= 0) {
      stcolumn = 0;		
    } else {
      stcolumn = column - 1;
    }
  
 if (column + 1 >= COLUMNS) {
      endcolumn = COLUMNS - 1;	
    } else {
      endcolumn = column + 1;
    }
  int m;
  for (m = stcolumn; m <= endrow; m++) {
      int l;
      for (l = stcolumn; l <= endcolumn; l++) {
	    if (board[m][l] == MINE) {
	      count++;
	    }
	}
}
  
 return count;
}

int destaparCeros(int row, int column, char board[ROWS][COLUMNS]) {
  int conteo = 0, strow, endrow, stcolumn, endcolumn;
  if (row <= 0) {
    strow = 0;
  } else {
    strow = row - 1;
  }

  if (row + 1 >= ROWS) {
    endrow = ROWS - 1;
  } else {
    endrow = row + 1;
  }

  if (column <= 0) {
    stcolumn = 0;
  } else {
    stcolumn = column - 1;
  }
  if (column + 1 >= COLUMNS) {
    endcolumn = COLUMNS - 1;
  } else {
    endcolumn = column + 1;
  }
  int m;
  for (m = strow; m <= endrow; m++) {
    int l;
    for (l = strow; l <= endcolumn; l++) {
      if (obteinsurrmines(m,l, board) == 0) {
        board[m][l] = COVERED_SPACE;
     
      }
      if (board[m][l] != MINE) {
	       board[m][l] = COVERED_SPACE;
      }
    }
  }

}


/*Generate random numbers*/ 
int randrange (int minimum, int maximum) {
  return minimum + rand () / (RAND_MAX / (maximum - minimum + 1) + 1);
  
}


/* Fills with empty spaces */ 
void stboard (char board[ROWS][COLUMNS]) {
  int l;
  for (l = 0; l < ROWS; l++) {
    int m;
    for (m = 0; m < COLUMNS; m++) {
	  board[l][m] = UNCOVERED_SPACE;
	}
  }
}


/* Place mines */ 
void placemine (int row, int column, char board[ROWS][COLUMNS]) {				
  board[row][column] = MINE;
} 
 
 
/* Place mines randomly */ 
void placemrand (int NUMBER_MINES, char board[ROWS][COLUMNS]) {
  int l;
  
  for (l = 0; l < NUMBER_MINES; l++) {
   int row  = randrange (0, ROWS - 1);	
   int column  = randrange (0, COLUMNS - 1);
      
      
      placemine (row, column, board);
   } 
 } 
 
 
/*Header Separator*/ 
void prtheadsep () {				
  int m;
  for (m = 0; m <= COLUMNS; m++) {
    printf ("----");
    if (m + 2 == COLUMNS) {
	  printf ("-");
	}
  }
  printf ("\n");
}


/*Row separator*/ 
void rowsep () {				
  int m;
  for (m = 0; m <= COLUMNS; m++) {
    printf ("----");
  }
  printf ("\n");
}


/*Header*/ 
void prtheader () {				
  prtheadsep();                
  printf ("|   ");
  int l;
  for (l = 0; l < COLUMNS; l++) {
    printf ("| %d ", l + 1);
    if (l + 1 == COLUMNS) {
	  printf ("|");
	}
  }
  printf ("\n");
}				

	   
/* turn int to char. */
char inttoc (int number) {				
  return number + '0';
}


void prtboard(char board[ROWS][COLUMNS], int showmines) {
  prtheader();
  prtheadsep();
  char letter = 'A';
  int l;
  for (l = 0; l < ROWS; l++) {
    int m;
    
    printf("| %c ", letter);
    letter++;
    for (m = 0; m < COLUMNS; m++) {
      
      char tletter = UNCOVERED_SPACE; 
      char aletter = board[l][m]; 
      if (aletter == MINE) {
        tletter = UNCOVERED_SPACE;
      } else if (aletter == COVERED_SPACE) {
       
        int surrmines = obteinsurrmines(l, m, board); 
       
      destaparCeros(l, m, board);
    
        tletter = inttoc(surrmines);
        if (tletter == '0')
        {
            tletter = ' ';
        }
      }
      
      if (aletter == MINE && (DEBUG || showmines)) {
        tletter = MINE;
      }
      printf("| %c ", tletter);
      if (m + 1 == COLUMNS) {
        printf("|");
      }
    }
    printf("\n");
    rowsep();
  }
}/* 


/* Recibes row, column and board */ 
int openbox (char rowletter, int column, char board[ROWS][COLUMNS]) {				
  /* Turn to uppercase */
  rowletter = toupper (rowletter);
  /* - 1 because we use the column as an index */ 
    column--;
  /* Turn letter into index */ 
  int row = rowletter - 'A';
  assert (column < COLUMNS && column >= 0);
  assert (row < ROWS && row >= 0);
  if (board[row][column] == MINE) {
    return ERROR_ALREADY_FOUNDED;
  }
  if (board[row][column] == COVERED_SPACE) {
    return ERROR_ALREADY_OPENED;
  }
  /* If no error is founded,space discovered */ 
  board[row][column] = COVERED_SPACE;
  return ERROR_NONE;
}


/* If won */ 
int noleft (char board[ROWS][COLUMNS]) {
  int l;
  for (l = 0; l < ROWS; l++) {
    int m;
    for (m = 0; m < COLUMNS; m++) {
	  char actual = board[l][m];
	  if (actual == UNCOVERED_SPACE) {
	    return 0;
	  }
	}
  }
  return 1;
}