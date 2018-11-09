/****************************************/
/* Thien Ngo  */
/* Matrikel: 1857010 */
/* Uebungsblatt: 04, Aufgabe: 11 */
/* Datum: 09.11.2018 */
/****************************************/

/*
 * Aufgabe 12: Templates
 * a) #1 = explizit definierte Funktion, #2 = allgemines Template, #3 = Spezialfunktion
 * 1: #2
 * 2: #1, #2
 * 3: Fehler, da Datentypen jeweils verschieden
 * 4: cast nicht möglich, da double > float
 * 5: #3, #2
 * 6: #1, #2
 * 7: Fehler, aehnlich wie 3:
 * 8: Fehler, aehnlich wie 4:
 *
 * b)
 * 1. richtig
 * 2. falsch, keine Parameter uebergeben
 * 3. richtig
 * 4. richtig
 * 5. falsch, 'x' ist vom Typ char, erwartet wird int
 * 6. richtig
 */

#include <iostream>
#include <string>

using namespace std;

class Board {
public:
    Board(int mines, int dimX, int dimY);
    ~Board();
    void print();
    int getStatus();
    char getData(int x, int y);
    void transferData(int x, int y);
    void checkNeighborhood(int x, int y);
    int incMines(int x, int y, int &mineCounter);

private:
    char** play_board;
    char** data_board;
    const int dimX;
    const int dimY;
};

class Game {
public:
    Game(int mineCounter, int x, int y);
    int update(int x, int y);

private:
    Board board;
};

// initialize arrays dynamically
Board::Board(int mines, int dimX, int dimY) : dimX(dimX), dimY(dimY) {
  srand(time(NULL));
  play_board = new char* [dimX];
  data_board = new char* [dimX];

  for (int i = 0; i < dimX; ++i) {
    play_board[i] = new char[dimY];
    data_board[i] = new char[dimY];
  }

  // fill with #
  for (int y = 0; y < dimY; ++y) {
    for (int x = 0; x < dimX; ++x) {
      play_board[x][y] = '#';
    }
  }

  // randomly place mines
  for (int i = 0; i < mines; ++i) {
    int x;
    int y;

    while (true) {
      x = rand() % dimX;
      y = rand() % dimY;
      if(data_board[x][y] != 'm') {
        data_board[x][y] = 'm';
        break;
      }
    }
  }

  // calculate mineCounter for each field
  for (int y = 0; y < dimY; ++y) {
    for (int x = 0; x < dimX; ++x) {
      if (data_board[x][y] != 'm') {
        int mineCounter = 0;
        // all 8-directions
        // left, right
        incMines(x - 1, y, mineCounter);
        incMines(x + 1, y, mineCounter);
        // up, down
        incMines(x, y + 1, mineCounter);
        incMines(x, y - 1, mineCounter);
        // bottom left, bottom right
        incMines(x - 1, y - 1, mineCounter);
        incMines(x + 1, y - 1, mineCounter);
        // top left, top right
        incMines(x - 1, y + 1, mineCounter);
        incMines(x + 1, y + 1, mineCounter);
        // calculate as integers and cast result to char to store it in data_board array
        char final_count = (char) ( ( (int)'0') + mineCounter);
        data_board[x][y] = final_count;
      }
    }
  }
}

// deconstruct
Board::~Board() {
  for (int i = 0; i < dimY; ++i) {
    delete[] play_board[i];
    delete[] data_board[i];
  }
  delete[] play_board;
  delete[] data_board;
}

// increment mineCounter
int Board::incMines(int x, int y, int &mineCounter) {
  if (x >= 0 && x < dimX && y >= 0 && y < dimY) {
    if (data_board[x][y] == 'm') {
      mineCounter++;
    }
  }

  return 0;
}

void Board::print() {
  // align output and draw column numbers
  cout << endl << "    ";
  for (int i = 0; i < dimX; ++i) {
    cout << (char) (97 + i) << " ";
  }
  cout << endl;

  // horizontal line
  for (int i = 0; i < 3 + dimX*2; ++i) {
    cout << "-";
  }
  cout << endl;

  // draw board row by row
  for (int y = 0; y < dimY; ++y) {
    cout << (char) (97 + y) << " | ";
    for (int x = 0; x < dimX; ++x) {
      cout << play_board[x][y] << " ";
    }
    cout << endl;
  }

  // horizontal line
  for (int i = 0; i < 3 + dimX*2; ++i) {
    cout << "-";
  }

  // align output and draw column numbers
  cout << endl << "    ";
  for (int i = 0; i < dimX; ++i) {
    cout << (char) (97 + i) << " ";
  }
  cout << endl << endl;
}

char Board::getData(int x, int y) {
  if (x < dimX && y < dimY && x >= 0 && y >= 0) {
    return data_board[x][y];
  }

  return 'e';
}

void Board::transferData(int x, int y) {
  play_board[x][y] = data_board[x][y];
}

// if mines still undiscovered continue else return 1
int Board::getStatus() {
  for (int y = 0; y < dimY; ++y) {
    for (int x = 0; x < dimX; ++x) {
      if(play_board[x][y] == '#') {
        if(data_board[x][y] != 'm') {
          return 0;
        }
      }
    }
  }

  return 1;
}

// floodfill algorithm
void Board::checkNeighborhood(int x, int y) {
  if (x < dimX && y < dimY && x >= 0 && y >= 0) {
    if(data_board[x][y] == '0' && play_board[x][y] == '#') {
      play_board[x][y] = '0';
      // all 8-directions
      // left, right
      checkNeighborhood(x - 1, y);
      checkNeighborhood(x + 1, y);
      // up, down
      checkNeighborhood(x, y + 1);
      checkNeighborhood(x, y - 1);
      // bottom left, bottom right
      checkNeighborhood(x - 1, y - 1);
      checkNeighborhood(x + 1, y - 1);
      // top left, top right
      checkNeighborhood(x - 1, y + 1);
      checkNeighborhood(x + 1, y + 1);
    } else
      transferData(x, y);
  }
}

Game::Game(int mineCounter, int dimX, int dimY) : board(Board(mineCounter, dimX, dimY)) {
  board.print();
}

int Game::update(int x, int y) {
  // explosion
  if (board.getData(x, y) == 'm') {
    return -1;

    // continue playing else
  } else if(board.getData(x, y) == '0') {
    board.checkNeighborhood(x, y);
  } else if(board.getData(x, y) == 'e') {

  } else {
    board.transferData(x, y);
  }

  // win condition
  if(board.getStatus() == 1) {
    board.print();

    return 1;
  }

  cout << endl;
  board.print();

  return 0;
}

// enter column first, then row.
int main() {
  int dimX, dimY, x, y, status, mineCount;
  string coords;

  cout << "Dimension x(2-30): ";
  cin >> dimX;
  cout << "Dimension y(2-30): ";
  cin >> dimY;

  // ~10% mines, draw play board
  mineCount = ((dimX * dimY) / 10) + 1;
  Game game(mineCount, dimX, dimY);

  while(true) {
    cout << "Next turn: ";
    cin >> coords;

    if(coords.length() > 2) {
      cout << endl << "only 2 coordinates" << endl;
      continue;
    }
    // atoi()
    x = coords[1] - 97;
    y = coords[0] - 97;
    status = game.update(x, y);

    if(status == -1) {
      cout << endl << "B O O O M M M M M !" << endl;
      break;
    }
    if(status == 1) {
      cout << endl << "You win!" << endl;
      break;
    }
  }

  return 0;
}