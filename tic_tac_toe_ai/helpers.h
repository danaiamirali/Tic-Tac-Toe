#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <array>

extern char winningLetter;
void setBoard(std::string board[3][3]);
void printBoard(std::string board[3][3]);
void simulateRound(std::string board[3][3], int player);
int gameStatus(std::string board[3][3]);