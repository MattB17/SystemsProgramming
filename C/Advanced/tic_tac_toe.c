#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY ' '
#define PLAYER1 'O'
#define PLAYER2 'X'
#define UNFINISHED ""
#define TIE "Tie!\n"
#define P1WINS "Player O wins!\n"
#define P2WINS "Player X wins!\n"

void print_board(char *board) {
  for (int y = 0; y < 3; y++) {
    for (int x = 0; x < 3; x++) {
      printf(" %c", board[3 * y + x]);
      if (x < 2) {
        printf(" |");
      } else {
        printf("\n");
      }
    }
    if (y < 2) {
      printf("-----------\n");
    }
  }
}

void turn(char *board, char player) {
  int input = -1;
  while (input == -1) {
    // wait for request from player
    printf("Player %c> ", player);

    // receive request from player
    scanf(" %d", &input);
    if (input >= 1 && input <= 9 && board[input - 1] != EMPTY) {
      input = -1;
      printf("Please select an empty space.\n");
    }
  }
  
  // update board
  board[input - 1] = player;

  // display new board
  print_board(board);
}

// checks if all spots in the board are full
int board_filled(char *board) {
  for (int i = 0; i < 9; i++) {
    if (board[i] == EMPTY) {
      return 0;
    }
  }
  return 1;
}

int wins(char a, char b, char c) {
  return (a != EMPTY) && (a == b) && (a == c);
}

char *check_board(char *board) {
  char winner = EMPTY;
  // winning combinations through top right corner
  if (wins(board[0], board[1], board[2]) ||
      wins(board[0], board[3], board[6]) ||
      wins(board[0], board[4], board[8])) {
    winner = board[0];
  }

  // winning combinations through center
  if (winner == EMPTY &&
          (wins(board[3], board[4], board[5]) ||
           wins(board[1], board[4], board[7]) ||
           wins(board[2], board[4], board[6]))) {
    winner = board[4];
  }

  // winning combinations through bottom left corner
  if (winner == EMPTY &&
          (wins(board[6], board[7], board[8]) ||
           wins(board[2], board[5], board[8]))) {
    winner = board[8];
  }

  if (winner == PLAYER1) {
    return P1WINS;
  }

  if (winner == PLAYER2) {
    return P2WINS;
  }

  return UNFINISHED;
}

int main() {
  // set up blank board
  // just a char array of 9 elements
  char board[9];
  for (int i = 0; i < 9; i++) {
    board[i] = EMPTY;
  }

  printf(" 1 | 2 | 3 \n");
  printf("-----------\n");
  printf(" 4 | 5 | 6 \n");
  printf("-----------\n");
  printf(" 7 | 8 | 9 \n");
  printf("Please enter a square when prompted.\n\n");

  char *state = UNFINISHED;
  char player = PLAYER1;
  // while game isn't finished
  while (strcmp(state, UNFINISHED) == 0) {
    //   perform a turn
    turn(board, player);
    if (player == PLAYER1) {
      player = PLAYER2;
    } else {
      player = PLAYER1;
    }
    //   check board configuration
    state = check_board(board);
  }
  // declare a winner
  printf("%s", state);

  return 0;
}
