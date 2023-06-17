#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10
#define NUM_SHIPS 5

// Function to print the grid
void printGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    printf("  ");
    for (int i = 0; i < GRID_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < GRID_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a ship can be placed at a given position
int canPlaceShip(char grid[GRID_SIZE][GRID_SIZE], int x, int y, int size, char orientation) {
    if (orientation != 'h' && orientation != 'v') {
        return 0; // Invalid orientation
    }
    if (orientation == 'h') {
        if (y + size > GRID_SIZE) {
            return 0; // Ship exceeds grid boundaries
        }
        for (int i = y; i < y + size; i++) {
            if (grid[x][i] != '-') {
                return 0; // Collision with another ship
            }
            if (x > 0 && grid[x - 1][i] != '-') {
                return 0; // Collision with another ship horizontally
            }
            if (x < GRID_SIZE - 1 && grid[x + 1][i] != '-') {
                return 0; // Collision with another ship horizontally
            }
            if (i > 0 && grid[x][i - 1] != '-') {
                return 0; // Collision with another ship vertically
            }
            if (i < GRID_SIZE - 1 && grid[x][i + 1] != '-') {
                return 0; // Collision with another ship vertically
            }
        }
    } else if (orientation == 'v') {
        if (x + size > GRID_SIZE) {
            return 0; // Ship exceeds grid boundaries
        }
        for (int i = x; i < x + size; i++) {
            if (grid[i][y] != '-') {
                return 0; // Collision with another ship
            }
            if (y > 0 && grid[i][y - 1] != '-') {
                return 0; // Collision with another ship horizontally
            }
            if (y < GRID_SIZE - 1 && grid[i][y + 1] != '-') {
                return 0; // Collision with another ship horizontally
            }
            if (i > 0 && grid[i - 1][y] != '-') {
                return 0; // Collision with another ship vertically
            }
            if (i < GRID_SIZE - 1 && grid[i + 1][y] != '-') {
                return 0; // Collision with another ship vertically
            }
        }
    }
    return 1; // Valid placement
}

// Function to place a ship at a given position
void placeShip(char grid[GRID_SIZE][GRID_SIZE], int x, int y, int size, char orientation) {
    if (orientation == 'h') {
        for (int i = y; i < y + size; i++) {
            grid[x][i] = 'S';
        }
    } else if (orientation == 'v') {
        for (int i = x; i < x + size; i++) {
            grid[i][y] = 'S';
        }
    }
}

// Function to randomly place the computer's ships
void placeComputerShips(char computerGrid[GRID_SIZE][GRID_SIZE]) {
    srand(time(NULL));
    for (int i = 0; i < NUM_SHIPS; i++) {
        int size = 5 - i;
        char orientation = rand() % 2 == 0 ? 'h' : 'v';
        int x, y;
        do {
            x = rand() % GRID_SIZE;
            y = rand() % GRID_SIZE;
        } while (!canPlaceShip(computerGrid, x, y, size, orientation));
        placeShip(computerGrid, x, y, size, orientation);
    }
}

// Function to get the player's move
void getPlayerMove(int *x, int *y) {
    printf("\n>>> Enter your move (x y): ");
    scanf("%d %d", y, x);
    getchar();
}

// Function to check if a move is valid
int isValidMove(char grid[GRID_SIZE][GRID_SIZE], int x, int y) {
    if (x < 0 || x >= GRID_SIZE || y < 0 || y >= GRID_SIZE) {
        return 0;
    }
    if (grid[x][y] == '-' || grid[x][y] == 'S') {
        return 1;
    }
    return 0;
}

// Function to check if the game is over
int isGameOver(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == 'S') {
                return 0;
            }
        }
    }
    return 1;
}

// Function to play the game
void playGame() {
    char playerGrid[GRID_SIZE][GRID_SIZE];
    char computerGrid[GRID_SIZE][GRID_SIZE];
    char mainGrid [GRID_SIZE][GRID_SIZE];

    // Initialize the grids
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            playerGrid[i][j] = '-';
            computerGrid[i][j] = '-';
            mainGrid[i][j] = '-';
        }
    }

    // Place the player's ships
    printf(">>> Place your ships:\n\n");
    printGrid(playerGrid);
    for (int i = 0; i < NUM_SHIPS; i++) {
        int size = 5 - i;
        char orientation;
        int x, y;
        do {
            printf("\n>>> Enter the position and orientation of your ship of size %d (x y h/v): ", size);
            if (scanf("%d %d %c", &y, &x, &orientation) != 3) {
                while (getchar() != '\n'); // Clear input buffer
                system("cls");
                printf(">>> Invalid input. Try again.\n\n");
                printGrid(playerGrid);
                continue;
            }
        } while (!canPlaceShip(playerGrid, x, y, size, orientation));
        placeShip(playerGrid, x, y, size, orientation);
        system("cls");
        printf(">>> Place your ships:\n\n");
        printGrid(playerGrid);
    }

    // Place the computer's ships
    system("cls");
    printf(">>> Computer is placing its ships.\n");
    sleep(1);
    system("cls");
    printf(" >> Computer is placing its ships.\n");
    sleep(1);
    system("cls");
    printf("> > Computer is placing its ships.\n");
    sleep(1);
    system("cls");
    printf(">>  Computer is placing its ships.\n");
    sleep(1);
    system("cls");
    printf(">>> Computer is placing its ships.\n");
    sleep(1);
    system("cls");
    printf(" >> Computer is placing its ships.\n");
    sleep(1);
    system("cls");
    printf("> > Computer is placing its ships.\n");
    sleep(1);
    system("cls");
    printf(">>  Computer is placing its ships.\n");
    sleep(1);
    system("cls");
    printf(">>> Computer is placing its ships.\n");
    sleep(1);
    placeComputerShips(computerGrid);
    system("cls");

    // Play the game
    int playerTurn = 1; // Variable to keep track of the player's turn
    while (1) {
        if (playerTurn) {
            // Player's turn
            printf(">>> Player's turn:\n\n");
            printGrid(mainGrid);
            int x, y;
            do {
                getPlayerMove(&x, &y);
                if (!isValidMove(computerGrid, x, y)) {
                    system("cls");
                    printf(">>> Invalid move. Try again.\n\n");
                    printGrid(mainGrid);
                }
            } while (!isValidMove(computerGrid, x, y));
            if (computerGrid[x][y] == 'S') {
                system("cls");
                printf(">>> Acknowledged!\n");
                sleep(1);
                system("cls");
                printf(">>> The flight of a projectile.\n");
                sleep(1);
                system("cls");
                printf(" >> The flight of a projectile.\n");
                sleep(1);
                system("cls");
                printf("> > The flight of a projectile.\n");
                sleep(1);
                system("cls");
                printf(">>  The flight of a projectile.\n");
                sleep(1);
                system("cls");
                printf(">>> The flight of a projectile.\n");
                sleep(1);
                system("cls");
                printf(">>> Hit!\n");
                sleep(1);
                system("cls");
                computerGrid[x][y] = 'X';
                mainGrid[x][y] = 'X';
                playerTurn = 1; // Player hits again
            } else {
                system("cls");
                printf(">>> Acknowledged!\n");
                sleep(1);
                system("cls");
                printf(">>> The flight of a projectile.\n");
                sleep(1);
                system("cls");
                printf(" >> The flight of a projectile.\n");
                sleep(1);
                system("cls");
                printf("> > The flight of a projectile.\n");
                sleep(1);
                system("cls");
                printf(">>  The flight of a projectile.\n");
                sleep(1);
                system("cls");
                printf(">>> The flight of a projectile.\n");
                sleep(1);
                system("cls");
                printf(">>> Miss!\n");
                sleep(1);
                system("cls");
                computerGrid[x][y] = 'O';
                mainGrid[x][y] = 'O';
                playerTurn = 0; // Player's turn ends, computer's turn starts
            }
            if (isGameOver(computerGrid)) {
                printf(">>> Player wins!\n");
                sleep(1);
                system("cls");
                break;
            }
        } else {
            // Computer's turn
            printf(">>> Computer's turn\n");
            sleep(1);
            system("cls");
            int computerX, computerY;
            do {
                computerX = rand() % GRID_SIZE;
                computerY = rand() % GRID_SIZE;
            } while (!isValidMove(playerGrid, computerX, computerY));
            if (playerGrid[computerX][computerY] == 'S') {
                system("cls");
                printf(">>> A projectile is coming!\n");
                sleep(1);
                system("cls");
                printf(">>> The flight of a projectile.\n");
                sleep(1);
                system("cls");
                printf(" >> The flight of a projectile.\n");
                sleep(1);
                system("cls");
                printf("> > The flight of a projectile.\n");
                sleep(1);
                system("cls");
                printf(">>  The flight of a projectile.\n");
                sleep(1);
                system("cls");
                printf(">>> The flight of a projectile.\n");
                sleep(1);
                system("cls");
                printf(">>> Hit!\n");
                sleep(1);
                system("cls");
                playerGrid[computerX][computerY] = 'X';
                playerTurn = 0; // Computer hits again
            } else {
                system("cls");
                printf(">>> A projectile is coming!\n");
                sleep(1);
                system("cls");
                printf(">>> The flight of a projectile.\n");
                sleep(1);
                system("cls");
                printf(" >> The flight of a projectile.\n");
                sleep(1);
                system("cls");
                printf("> > The flight of a projectile.\n");
                sleep(1);
                system("cls");
                printf(">>  The flight of a projectile.\n");
                sleep(1);
                system("cls");
                printf(">>> The flight of a projectile.\n");
                sleep(1);
                system("cls");
                printf(">>> Miss!\n");
                sleep(1);
                system("cls");
                playerGrid[computerX][computerY] = 'O';
                playerTurn = 1; // Computer's turn ends, player's turn starts
            }
            if (isGameOver(playerGrid)) {
                printf(">>> Computer wins!\n");
                sleep(1);
                system("cls");
                break;
            }
        }
    }
}



int main() {
    int choice;
    do {
        printf("    < SEA BATTLE >\n");
        printf("----------------------\n");
        printf("  Main Menu:\n");
        printf("----------------------\n");
        printf("  1. Start Game\n");
        printf("  2. Quit\n");
        printf("----------------------\n");
        printf("  Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                system("cls");
                playGame();
                break;
            case 2:
                system("cls");
                printf(">>> Exiting the game.\n");
                sleep(1);
                system("cls");
                printf(" >> Exiting the game.\n");
                sleep(1);
                system("cls");
                printf("> > Exiting the game.\n");
                sleep(1);
                system("cls");
                printf(">>  Exiting the game.\n");
                sleep(1);
                system("cls");
                printf(">>> Exiting the game.\n");
                sleep(1);
                break;
            default:
                system("cls");
                printf(">>> Invalid choice. Try again.\n \n");
                
        }
    } while (choice != 2);

    return 0;
}