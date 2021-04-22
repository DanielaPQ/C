#include <assert.h>		// assert
#include <ctype.h>		// toupper
#include <stdio.h>		// printf, scanf
#include <stdlib.h>		// rand
#include <time.h>
#include "new3.h"

#define ERROR_ALREADY_FOUNDED 1	// ERROR_MINA_ENCONTRADA-ERROR_ALREADY_FOUNDED
#define ERROR_ALREADY_OPENED 2	//ERROR_ESPACIO_YA_DESCUBIERTO-ERROR_ALREADY_OPENED
#define ERROR_NONE 3		// ERROR_NINGUNO-ERROR_NONE

//#define COLUMNS 4
//#define ROWS 4
#define UNCOVERED_SPACE '#'	//ESPACIO_SIN_DESCUBRIR-UNCOVERED_SPACE
#define COVERED_SPACE ' '	//ESPACIO_DESCUBIERTO-COVERED_SPACE
#define MINE 'X'
//#define NUMBER_MINES 10
#define DEBUG 0			// Si lo pones en 1, se van a desocultar las minas


/* Surronding mines */ 
int obteinsurrmines (int row, int column, char board[ROWS][COLUMNS]) {
  int count = 0, strow, endrow, stcolumn, endcolumn;	//conteo-count
  if (row <= 0) {
      strow = 0;		//filaInicio-strow
    } else {
      strow = row - 1;
    }
  
  if (row + 1 >= ROWS) {
      endrow = ROWS - 1;	//filaFin-endrow
    } else {
      endrow = row + 1;
    }
  
 if (column <= 0) {
      stcolumn = 0;		//columnaInicio-stcolumn
    } else {
      stcolumn = column - 1;
    }
  
 if (column + 1 >= COLUMNS) {
      endcolumn = COLUMNS - 1;	//columnaFin-endcolumn
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

/*array randrange*/
/* int* arrayrr (int maximum) {
 int i, NUMBER_MINES; 
 int vektor [NUMBER_MINES], list [maximum];
 
 for (i = 0; i < maximum; i++) {
    list[i] = i;
 }
for (i = 1; i < NUMBER_MINES; i++) {
    int j = i + rand() % (maximum - i);
    int temp = list[i];
    list[i] = list[j];
    list[j] = temp;

    vektor[i] = list[i];
  }
  return vektor ;
} */

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
void placemine (int row, int column, char board[ROWS][COLUMNS]) {				// colocarMina-placemine
  board[row][column] = MINE;
} 
 
 
/* Place mines randomly */ 
void placemrand (int NUMBER_MINES, char board[ROWS][COLUMNS]) {
  int l;
  //int NUMBER_MINES ;
  for (l = 0; l < NUMBER_MINES; l++) {
   int row  = randrange (0, ROWS - 1);	//aleatorioEnRango-randrange
   int column  = randrange (0, COLUMNS - 1);
      
 // for (l = 0; l < NUMBER_MINES; l++) {
      
      placemine (row, column, board);
   } 
 } 
 
 
/*Header Separator*/ 
void prtheadsep () {				//imprimirSeparadorEncabezado-prtheadsep
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
void rowsep () {				//imprimirSeparadorFilas-rowsep
  int m;
  for (m = 0; m <= COLUMNS; m++) {
    printf ("----");
  }
  printf ("\n");
}


/*Header*/ 
void prtheader () {				//  imprimirEncabezado-prtheader
  prtheadsep();                // imprimirSeparadorEncabezado-prtheadsep
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
char inttoc (int number) {				//enteroACaracter-inttoc
  return number + '0';
}


void prtboard(char board[ROWS][COLUMNS], int showmines) {
  prtheader();
  prtheadsep();
  char letter = 'A';
  int l;
  for (l = 0; l < ROWS; l++) {
    int m;
    // Imprimir la letra de la fila
    printf("| %c ", letter);
    letter++;
    for (m = 0; m < COLUMNS; m++) {
      // No le vamos a mostrar al usuario si hay una mina...
      char tletter = UNCOVERED_SPACE; //verdaderaLetra-tletter
      char aletter = board[l][m]; //letraActual-aletter
      if (aletter == MINE) {
        tletter = UNCOVERED_SPACE;
      } else if (aletter == COVERED_SPACE) {
        // Si ya lo abriC3, entonces mostramos las minas cercanas
        int surrmines = obteinsurrmines(l, m, board); //minasCercanas-surrmines
       // if (surrmines == 0){
      destaparCeros(l, m, board);
    //  }
        tletter = inttoc(surrmines);
        if (tletter == '0')
        {
            tletter = ' ';
        }
      }
      // Si DEBUG estC! en 1, o deberC-a mostrar las minas (porque perdiC3 o ganC3)
      // mostramos la mina original
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
int openbox (char rowletter, int column, char board[ROWS][COLUMNS]) {				//filaLetra-rowletter
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