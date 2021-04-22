#define ERROR_ALREADY_FOUNDED 1	
#define ERROR_ALREADY_OPENED 2	
#define ERROR_NONE 3		


#define UNCOVERED_SPACE '#'	
#define COVERED_SPACE ' '	
#define MINE 'X'
#define DEBUG 0			

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

int destaparCeros(int row, int column, char board[ROWS][COLUMNS]);