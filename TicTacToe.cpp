#include <iostream>

// Functions
void Draw();
void Turn();
void Check();

// Globals
int Player1 = 0;
int Player2 = 0;

// Turns
int previousTurn = 0;
int currentTurn = 0;
int currentP = 0;

int coordX = 0;
int coordY = 0;

// Board
int board[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};

int main() {
    std::cout << "Tic-Tac-Toe (Ben Archard)\n";
    std::cout << "Player 1: ";
    std::cin >> Player1;
    std::cout << "Player 2: ";
    std::cin >> Player2;


    previousTurn = 2;
    currentTurn = 1;

    Draw();
}

void Turn() {
    switch (currentTurn) {
        case 1:
            {
                currentP = Player1;

                std::cout << "Player 1 (" << Player1 << ")" << ", enter co-ordinate X: ";
                std::cin >> coordX;
                std::cout << "Enter co-ordinate Y: ";
                std::cin >> coordY;

                Check();
            }
        case 2:
        {
            currentP = Player2;

            std::cout << "Player 2 (" << Player2 << ")" << ", enter co-ordinate X: ";
            std::cin >> coordX;
            std::cout << "Enter co-ordinate Y: ";
            std::cin >> coordY;

            Check();
        }
    }
}

void Check() {
    std::cout << currentP << std::endl;
    if (board[coordX][coordY] == 0) {
        board[coordX][coordY] = currentP;

        // Flats

        if (board[0][0] == currentP && board[0][1] == currentP && board[0][2] == currentP) {
            std::cout << currentP << ", You win! (Top Row)";
            exit(0);
        } else if (board[1][0] == currentP && board[1][1] == currentP && board[1][2] == currentP) {
            std::cout << currentP << ", You win! (Middle Row)";
            exit(0);
        } else if (board[2][0] == currentP && board[2][1] == currentP && board[2][2] == currentP) {
            std::cout << currentP << ", You win! (Bottom Row)";
            exit(0);
        }

        // Rows

        if (board[0][0] == currentP && board[1][0] == currentP && board[2][0] == currentP){
            std::cout << currentP << ", You win! (Left Row)";
            exit(0);
        } else if (board[0][1] == currentP && board[1][1] == currentP && board[2][1] == currentP) {
            std::cout << currentP << ", You win! (Middle Row)";
            exit(0);
        } else if (board[0][2] == currentP && board[1][2] == currentP && board[2][2] == currentP) {
            std::cout << currentP << ", You win! (Right Row)";
            exit(0);
        }

        // Diags

        if (board[0][0] == currentP && board[1][1] == currentP && board[2][2] == currentP){
            std::cout << currentP << ", You win! (Left Diag)" << board[0][0] << board[1][1] << board[2][2];
            exit(0);
        } else if (board[0][2] == currentP && board[1][1] == currentP && board[2][0] == currentP){
            std::cout << currentP << ", You win! (Right Diag) ";
            exit(0);
        }

        if (board[0][0] != 0 && board[0][1] != 0 && board[0][2] != 0 && board[1][0] != 0 && board[1][1] != 0 && board[1][2] != 0 && board[2][0] != 0 && board[2][1] != 0 && board[2][2] != 0) {
            std::cout << "It's a draw";
            exit(0);
        }
    }

    switch (currentTurn) {
        case 1:
            currentTurn = 2;
            break;
        case 2:
            currentTurn = 1;
            break;
    }

    Draw();
}

void Draw() {
    std::cout << "-------------\n";
    std::cout << "| " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " |" << std::endl;
    std::cout << "|-----------|" << std::endl;
    std::cout << "| " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " | " << std::endl;
    std::cout << "|-----------|" << std::endl;
    std::cout << "| " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " | " << std::endl;
    std::cout << "|-----------|" << std::endl;

    Turn();
}