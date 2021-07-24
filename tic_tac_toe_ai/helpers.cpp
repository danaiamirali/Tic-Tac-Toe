#include "helpers.h"

std::vector<int> availableMoves = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

void setBoard(std::string board[3][3])
{
    int index = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = std::to_string(index);
            index++;
        }
    }
}

void printBoard(std::string board[3][3])
{
    system("CLS");
    // std::cout << "Player 1: (O) | Player 2:(X)\n\n";
    for (int rows = 0; rows < 3; rows++)
    {
        std::cout << "     |     |     " << std::endl;
        std::cout << "  " << board[rows][0] << "  |  " << board[rows][1] << "  |  " << board[rows][2] << std::endl;
        if (rows < 2)
        {
            std::cout << "_____|_____|_____" << std::endl;
        }
        else
        {
            std::cout << "     |     |     " << std::endl;
        }

    }
}

bool checkChoice(int choice)
{
    for (int i = 0; i < availableMoves.size(); i++)
    {
        if (choice == availableMoves[i])
        {
            return true;
        }
    }
    return false;
}

void simulateRound(std::string board[3][3], int player)
{

    int choice;
    printBoard(board);
    if (player == 1)
    {
        std::cout << "O's turn. Select a tile:\n";
    }
    else if (player == 2)
    {
        std::cout << "X's turn. Select a tile:\n";
    }
    do
    { 
        std::string inp;
        std::getline(std::cin, inp);
        try
        {
            std::stringstream convert(inp);
            convert >> choice;
            if (choice == 0)
            {
                throw 500;
            }
        }
        catch(int errorCode)
        {
            std::cerr << "Invalid Input, try again\n";
        }
    } while (!checkChoice(choice));
    for (int i = 0; i < availableMoves.size(); i++)
    {
        if (choice == availableMoves[i])
        {
            availableMoves.erase(availableMoves.begin() + i);
        }
    }
    for (int rows = 0; rows < 3; rows++)
    {
        for (int columns = 0; columns < 3; columns++)
        {
            if (board[rows][columns]== std::to_string(choice))
            {
                if (player == 1)
                {
                    board[rows][columns] = "O";
                }
                else
                {
                    board[rows][columns] = "X";
                }
            }
        }
    }
    // std::cout << "Player " << player << " plays on tile " << choice << std::endl;
}

char winningLetter;
int gameStatus(std::string board[3][3])
{
    // Check for win
    for (int rows = 0; rows < 3; rows++)
    {
        for (int columns = 0; columns < 3; columns++)
        {
            winningLetter = board[rows][columns][0];
            if (rows == 0)
            {
                // Checking for UP/DOWN win
                if (board[rows][columns] == board[rows + 1][columns] && board[rows][columns] == board[rows + 2][columns])
                {
                    return 1;
                }
                // Checking for diagonal win
                if (columns == 0)
                {
                    
                    if (board[rows][columns] == board[rows + 1][columns + 1] && board[rows][columns] == board[rows + 2][columns + 2])
                    {
                        return 1;
                    }
                }
                else if (columns == 2)
                {
                    if (board[rows][columns] == board[rows + 1][columns - 1] && board[rows][columns] == board[rows + 2][columns - 2])
                    {
                        return 1;
                    }
                }
            }
            if (columns == 0)
            {
                // Checking for LEFT/RIGHT win
                if (board[rows][columns] == board[rows][columns + 1] && board[rows][columns] == board[rows][columns + 2])
                {
                    return 1;
                }
            }
            
        }
    }
    // Check for tie
    int filledCount = 0;
    for (int rows = 0; rows < 3; rows++)
    {
        for (int columns = 0; columns < 3; columns++)
        {
            if (board[rows][columns] == "X" || board[rows][columns] == "O")
            {
                filledCount++;
            }
        }
    }
    if (filledCount == 9)
    {
        return 2; // Game tie
    }
    // Else, the game shall continue
    return 0;
}