#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10
#define MAX_SHIPS 4

void initializeBoard(char board[][BOARD_SIZE], char shipBoard[][BOARD_SIZE]);
void placeShips(char shipBoard[][BOARD_SIZE], int shipSizes[], int shipPositions[][4][2], int shipHits[]);
int isValidPlacement(char shipBoard[][BOARD_SIZE], int size, int row, int col, int direction);
void displayBoard(char board[][BOARD_SIZE]);
int processShot(char board[][BOARD_SIZE], char shipBoard[][BOARD_SIZE], int row, int col, int shipPositions[][4][2], int shipSizes[], int shipHits[], int shipSunk[]);
void saveShipsToFile(int shipPositions[][4][2], int shipSizes[]);
void logMove(int row, int col, int isHit);
void logGameEnd(int shots);
int checkGameOver(int shipsSunk);
int playAgain();

int main() {
    char board[BOARD_SIZE][BOARD_SIZE]; /* Board visible to player */
    char shipBoard[BOARD_SIZE][BOARD_SIZE]; /* Internal board with ship positions */
    int shipSizes[MAX_SHIPS] = {4, 3, 3, 2}; /* Sizes of the ships */
    int shipPositions[MAX_SHIPS][4][2]; /* Ship positions (up to 4 cells per ship) */
    int shipHits[MAX_SHIPS] = {0, 0, 0, 0}; /* Hits on each ship */
    int shipSunk[MAX_SHIPS] = {0, 0, 0, 0}; /* Whether ship is sunk */
    int shotCount = 0;
    int shipsSunk = 0;
    int row, col;
    int gameOver = 0;

    srand(time(NULL)); /* Seed random number generator */

    /* Initialize boards */
    initializeBoard(board, shipBoard);
    placeShips(shipBoard, shipSizes, shipPositions, shipHits);
    saveShipsToFile(shipPositions, shipSizes);

    /* Game loop */
    while (!gameOver) {
        displayBoard(board); /* Display the board to the player */

        printf("Enter coordinates for the shot (row col): ");
        
        /* Take user input for row and column */
        if (scanf("%d %d", &row, &col) != 2) {
            printf("Invalid input, please enter numbers for row and column.\n");
            while(getchar() != '\n'); /* Clear the input buffer */
            continue;
        }

        /* Validate the coordinates */
        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
            printf("Invalid coordinates! Please enter values between 0 and 9.\n");
            continue;
        }

        /* Process the shot and update the board */
        shotCount++;
        processShot(board, shipBoard, row, col, shipPositions, shipSizes, shipHits, shipSunk);

        /* Check if the game is over (all ships sunk) */
        shipsSunk = 0;
        for (int i = 0; i < MAX_SHIPS; i++) {
            if (shipSunk[i]) {
                shipsSunk++;
            }
        }

        gameOver = checkGameOver(shipsSunk);

        if (gameOver) {
            displayBoard(board);
            printf("All ships are sunk! Total shots: %d\n", shotCount);
            logGameEnd(shotCount);

            if (playAgain()) {
                /* Reset game */
                initializeBoard(board, shipBoard);
                for (int i = 0; i < MAX_SHIPS; i++) {
                    shipHits[i] = 0;
                    shipSunk[i] = 0;
                }
                placeShips(shipBoard, shipSizes, shipPositions, shipHits);
                saveShipsToFile(shipPositions, shipSizes);
                shotCount = 0;
                shipsSunk = 0;
                gameOver = 0;
            } else {
                break;
            }
        }
    }

    printf("Thank you for playing Battleship!\n");

    return 0;
}

/* Initialize both the player board and ship board */
void initializeBoard(char board[][BOARD_SIZE], char shipBoard[][BOARD_SIZE]) {
    int i, j; /* Declare variables outside the loop */
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '-'; /* Empty spot on the player’s board */
            shipBoard[i][j] = '-'; /* Empty spot on the internal ship board */
        }
    }
}

/* Place ships randomly on the board */
void placeShips(char shipBoard[][BOARD_SIZE], int shipSizes[], int shipPositions[][4][2], int shipHits[]) {
    int i, j, row, col, direction, validPlacement; /* Declare variables outside the loop */
    for (i = 0; i < MAX_SHIPS; i++) {
        int size = shipSizes[i];
        validPlacement = 0;
        while (!validPlacement) {
            row = rand() % BOARD_SIZE;
            col = rand() % BOARD_SIZE;
            direction = rand() % 2;

            if (isValidPlacement(shipBoard, size, row, col, direction)) {
                /* Place the ship */
                for (j = 0; j < size; j++) {
                    if (direction) { /* Horizontal */
                        shipBoard[row][col + j] = 'S';
                        shipPositions[i][j][0] = row;
                        shipPositions[i][j][1] = col + j;
                    } else { /* Vertical */
                        shipBoard[row + j][col] = 'S';
                        shipPositions[i][j][0] = row + j;
                        shipPositions[i][j][1] = col;
                    }
                }
                validPlacement = 1;
            }
        }
        shipHits[i] = 0; /* Reset hit count for the ship */
    }
}

/* Check if a ship can be placed at the given position */
int isValidPlacement(char shipBoard[][BOARD_SIZE], int size, int row, int col, int direction) {
    int i; /* Declare variable outside the loop */
    if (direction) { /* Horizontal */
        if (col + size > BOARD_SIZE) return 0;
    } else { /* Vertical */
        if (row + size > BOARD_SIZE) return 0;
    }

    for (i = 0; i < size; i++) {
        if (direction && shipBoard[row][col + i] == 'S') return 0; /* Check horizontal */
        if (!direction && shipBoard[row + i][col] == 'S') return 0; /* Check vertical */
    }

    return 1; /* Valid placement */
}

/* Display the game board */
void displayBoard(char board[][BOARD_SIZE]) {
    int i, j; /* Declare variables outside the loop */
    printf("  0 1 2 3 4 5 6 7 8 9\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

/* Process a shot */
int processShot(char board[][BOARD_SIZE], char shipBoard[][BOARD_SIZE], int row, int col, int shipPositions[][4][2], int shipSizes[], int shipHits[], int shipSunk[]) {
    int i, j; /* Declare variables outside the loop */
    if (shipBoard[row][col] == 'S') {
        board[row][col] = 'X';
        shipBoard[row][col] = 'X';
        printf("HIT!\n");

        for (i = 0; i < MAX_SHIPS; i++) {
            for (j = 0; j < shipSizes[i]; j++) {
                if (shipPositions[i][j][0] == row && shipPositions[i][j][1] == col) {
                    shipHits[i]++;
                    if (shipHits[i] == shipSizes[i] && !shipSunk[i]) {
                        shipSunk[i] = 1;
                        printf("Ship %d sunk!\n", i + 1);
                    }
                    break;
                }
            }
        }
        logMove(row, col, 1);
        return 1;
    } else {
        board[row][col] = 'O';
        printf("MISS!\n");
        logMove(row, col, 0);
        return 0;
    }
}

/* Log the shot in the log file */
void logMove(int row, int col, int isHit) {
    FILE *logFile; /* Declare logFile variable outside the function */
    logFile = fopen("battleship_log.txt", "a");
    if (logFile != NULL) {
        fprintf(logFile, "Shot: %d %d - %s\n", row, col, isHit ? "HIT" : "MISS");
        fclose(logFile);
    }
}

/* Log the game end in the log file */
void logGameEnd(int shots) {
    FILE *logFile; /* Declare logFile variable outside the function */
    logFile = fopen("battleship_log.txt", "a");
    if (logFile != NULL) {
        fprintf(logFile, "Game Over! Total shots: %d\n", shots);
        fclose(logFile);
    }
}

/* Check if the game is over (all ships sunk) */
int checkGameOver(int shipsSunk) {
    return shipsSunk == MAX_SHIPS;
}

/* Ask the player if they want to play again */
int playAgain() {
    char choice; /* Declare variable outside the function */
    printf("Press 'Y' to play again or 'X' to exit: ");
    scanf(" %c", &choice);
    return choice == 'Y' || choice == 'y';
}

