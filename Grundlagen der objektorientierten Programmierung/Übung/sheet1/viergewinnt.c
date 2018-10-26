/****************************************/
/* Thien Ngo  */
/* Matrikel: 1857010 */
/* Uebungsblatt: 01, Aufgabe: 2 */
/* Datum: 23.10.2018 */
/* Status: lauffaehig */
/****************************************/

#include <stdio.h>
#include <stdlib.h>

void printLine(int col);
void printGame(char** game, int row, int col);
int check(char** game, int row, int col, int r, int c);

int main()
{
  // Dimension des Spielfeldes
  int row = 6; // using int type seems to be more appropriate rather than double since printGame takes integers
  int col = 7;
  int r, c;
  char** game; // Spielfeld

  int player = 0; // welcher Spieler am Zug ist
  char symbols[] = {'X', 'O'}; // initialize characters with single quotes ' '
  int status = 0; // 0=Spiel laeuft, 1=Spieler hat gewonnen, 2=Feld voll

  int count = 0; // zaehlt alle Eintraege
  int colCount[col]; // zaehlt Eintraege in jeder Spalte
  for(c = 0; c < col; ++c) {
    colCount[c] = 0;
  }

  // Spielfeld anlegen und Startbelegung setzen
  game = (char**) calloc(row, sizeof(char*));
  for(r = 0; r < row; ++r) {
    game[r] = (char *) calloc(col, sizeof(char));
  }
  for(r = 0; r < row; ++r) {
    for (c = 0; c < col; ++c) {
      game[r][c] = ' '; // single quotes again since r,c are integers and game[][] is 2-dimensional array of characters
    }
  }
  // Spielzug-Schleife
  do {
    int selectionOK = 0;
    printGame(game, row, col);
    printf("Spieler %c ist an der Reihe.\n", symbols[player]);

    // Spaltenauswahl-Schleife
    do {
      printf("Naechster Zug in Spalte: ");
      scanf("%d", &c);
      --c; // Indizes 0,...,col-1
      if(colCount[c] < row) {
        r = row - 1 - colCount[c]; // naechstes freies Feld in Spalte c
        game[r][c] = symbols[player];
        ++count;
        ++colCount[c];
        selectionOK = 1;
      }
      else {
        printf("Spalte bereits voll!\n");
      }
    } while(!selectionOK); // do while !selectionOK

    status = check(game, row, col, r, c); // pruefe Gewinn
    if(!status) {// if !status
      status = count >= row * col ? 2 : status; // pruefe, of Feld voll
    }
    if(status == 1) {
      printf("\nSpieler %c hat gewonnen!", symbols[player]);
      printGame(game, row, col);
    }
    else if(status == 2) {
      printf("\nSpiel endet unentschieden!");
      printGame(game, row, col);
    }

    player = (player + 1) % 2; // round brackets so result can only 0 or 1 which corresponds to X and O
  } while(status == 0); // while game is running, status == 0

  // Speicher freigeben
  for(r = 0; r < row; ++r) {
    free(game[r]);
  }
  free(game);

  return 0;
}

// Druckt waagerechte Trennlinie in Spielfeld
// col: Breite des Spielfeldes
void printLine(int col) {
	int c;
	for(c = 0; c < col*2+1; ++c) { // *2 to reach end of playing field
		printf("-");
	}
	printf("\n");
}

// Druckt das Spielfeld mit der aktuellen Belegung
// row, col: Dimension des Spielfeldes
void printGame(char** game, int row, int col)
{
	int r, c;
	printf("\nSpielstand:\n");
	printLine(col); // col rather than row

	for(r = 0; r < row; ++r) {
		printf("|");
		for(c = 0; c < col; ++c) {
      printf("%c|", game[r][c]); // rows then colums. this was causing the initial segmentation fault
    }
		printf("\n");
		printLine(col);
	}
	for(c = 0; c < col; ++c)
		printf(" %d", c+1); // Spaltennummern
	printf("\n\n");
}

// Prueft, ob der letzte Zug ein Gewinnzug war (return 1)
// row, col: Dimension des Spielfeldes
// r, c: Koordinaten des letzten Zuges
int check(char** game, int row, int col, int r, int c)
{
	// Pruefe Waagerechte
	int count = 1;
	int step = 1;
	// Gehe solange nach links wie das Symbol gleich bleibt und zaehle die Schritte
	while(c-step >= 0 && game[r][c-step] == game[r][c]) { // logical operator AND + logical comparison ==
		++count;
		++step;
	}
	step = 1;
	// dasselbe nach rechts
	while(c+step < col && game[r][c+step] == game[r][c]) { // logical operator AND + logical comparison ==
		++count;
		++step;
	}
	if(count == 4) // player wins if he has 4 hits in a straight line, logical comparison == is more appropriate
		return 1;

	// Pruefe Senkrechte
	count = 1;
	step = 1;
	// oberhalb
	while(r-step >= 0 && game[r-step][c] == game[r][c]) { // logical operator AND + logical comparison ==
		++count;
		++step;
	}
	step = 1;
	// unterhalb
	while(r+step < row && game[r+step][c] == game[r][c]) { // logical operator AND + logical comparison ==
		++count;
		++step;
	}
	if(count == 4) // player wins if he has 4 hits in a straight line, logical comparison == is more appropriate
		return 1;

	// Pruefe Diagonale "/"
	count = 1;
	step = 1;
	// rechts oberhalb
	while(c+step < col && r-step >= 0 && game[r-step][c+step] == game[r][c]) { // logical operator AND + logical comparison ==
		++count;
		++step;
	}
	step = 1;
	// links unterhalb
	while(c-step >= 0 && r+step < row && game[r+step][c-step] == game[r][c]) { // logical operator AND + logical comparison ==
		++count;
		++step;
	}
	if(count == 4) // player wins if he has 4 hits in a straight line, logical comparison == is more appropriate
		return 1;

	// Pruefe Diagonale "\"
	count = 1;
	step = 1;
	// links oberhalb
	while(r-step >= 0 && c-step >= 0 && game[r-step][c-step] == game[r][c]) { // logical operator AND + logical comparison ==
		++count;
		++step;
	}
	step = 1;
	// rechts unterhalb
	while(r+step < row && c+step < col && game[r+step][c+step] == game[r][c]) { // logical operator AND + logical comparison ==
		++count;
		++step;
	}

	if(count == 4) // player wins if he has 4 hits in a straight line, logical comparison == is more appropriate
    return 1;

	return 0; // kein Gewinnzug
}


