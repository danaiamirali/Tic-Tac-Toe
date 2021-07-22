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
    if (gameStatus(board) == 1)
    {
        std::cout << "Player " << playerDormant << " wins!\n";
    }
    else
    {
        std::cout << "Tie! Nobody wins!\n";
    }

    return 0;
}