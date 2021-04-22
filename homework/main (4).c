#include <assert.h>		// assert
#include <ctype.h>		// toupper
#include <stdio.h>		// printf, scanf
#include <stdlib.h>		// rand
#include <time.h>
#include "new3.h"

/* NO MODIFICAR */
#define ERROR_ALREADY_FOUNDED 1	// ERROR_MINA_ENCONTRADA-ERROR_ALREADY_FOUNDED
#define ERROR_ALREADY_OPENED 2	//ERROR_ESPACIO_YA_DESCUBIERTO-ERROR_ALREADY_OPENED
#define ERROR_NONE 3		// ERROR_NINGUNO-ERROR_NONE

//#define COLUMNS 4
//#define ROWS 4
#define UNCOVERED_SPACE '#'	//ESPACIO_SIN_DESCUBRIR-UNCOVERED_SPACE
#define COVERED_SPACE ' '	//ESPACIO_DESCUBIERTO-COVERED_SPACE
#define MINE 'X'
//#define NUMBER_MINES 10
#define DEBUG 0			// En 1, muestra minas
  

int main () {
  int showmines = 0;//deberiaMostrarMinas
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
  // Alimentar rand
  srand (time (NULL));
  stboard (board);		// iniciarTablero
  placemrand (NUMBER_MINES, board);		// colocarMinasAleatoriamente-placemrand
  
  
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
    int status = openbox (row, column, board);	//abrirCasilla-openbox
    if (noleft (board))	{			//noHayCasillasSinAbrir-noleft
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
