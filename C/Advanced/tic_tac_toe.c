#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UNFINISHED ""
#define TIE "Tie!\n"
#define P1WINS "Player O wins!\n"
#define P2WINS "Player X wins!\n"

void turn() {
  // wait for request from player
  // receive request from player
  // update board
  // display new board
}

char *check_board(char *board) {
  return UNFINISHED;
}

int main() {
  // set up blank board
  // just a char array of 9 elements
  char board[9];
  for (int i = 0; i < 9; i++) {
    board[i] = ' ';
  }

  char *state = UNFINISHED;
  // while game isn't finished
  while (strcmp(state, UNFINISHED) == 0) {
    //   perform a turn
    //   check board configuration
    state = check_board(board);
  }
  // declare a winner
  printf("%s", state);

  return 0;
}
