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
void move(std::string, std::string, char [BOARD_SIZE][BOARD_SIZE],bool &);
void move2(std::pair<int,int>, std::pair<int,int>, char [BOARD_SIZE][BOARD_SIZE] );
std::pair<int,int> getPosition(std::string);
std::pair<bool,std::string> checkMove(std::string);
bool checkPlayer(std::pair<int,int>, char [BOARD_SIZE][BOARD_SIZE], bool &);
bool isAllowed(std::pair<int,int>, char [BOARD_SIZE][BOARD_SIZE], bool);

#endif /* FUNCTIONS_H_ */
