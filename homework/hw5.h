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

  int ROWS;
  int COLUMNS;
int obteinsurrmines (int row, int column, char board[ROWS][COLUMNS]);

int randrange (int minimum, int maximum);
void stboard (char board[ROWS][COLUMNS]);

void placemine (int row, int column, char board[ROWS][COLUMNS]);

void placemrand (int NUMBER_MINES, char board[ROWS][COLUMNS]);

void prtheadsep ();
void rowsep ();
void prtheader ();
char inttoc (int number);
void prtboard(char board[ROWS][COLUMNS], int showmines);

int openbox (char rowletter, int column, char board[ROWS][COLUMNS]);

int noleft (char board[ROWS][COLUMNS]);

//int* arrayrr(int maximum);
int destaparCeros(int row, int column, char board[ROWS][COLUMNS]);