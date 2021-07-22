#include "helpers.h"

int main()
{
    std::string board[3][3];
    setBoard(board);

    int playerActive = 1;
    int playerDormant = 2;
    
    do
    {
        simulateRound(board, playerActive);
        std::swap(playerActive, playerDormant);
    } 
    while (gameStatus(board) == 0);

    printBoard(board);
    std::cout << "Player " << playerActive << " wins!\n";

    return 0;
}