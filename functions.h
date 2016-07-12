#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <utility>
#include <cstdio>
#include <sstream>
#include <cctype>

#ifdef _WIN32
    #include <windows.h>
#endif

const int BOARD_SIZE = 8;

// Figury na szachownicy
//const int pawn = 10;
//const int bishop = 35;
//const int knight = 30;
//const int rook = 50;
//const int queen = 90;
//const int king = 200;

void gotoXY(short,short);
void init(char[BOARD_SIZE][BOARD_SIZE]);
void draw(char[BOARD_SIZE][BOARD_SIZE]);
void menu();
std::string instructions_F(std::string msg_F,std::string msg_Err);
std::string instructions_S(std::string msg_S,std::string msg_Err);
void move(std::string start, std::string end, char board[BOARD_SIZE][BOARD_SIZE] );
std::pair<int,int> getPosition(std::string);
bool checkMove(std::string);

#endif /* FUNCTIONS_H_ */

