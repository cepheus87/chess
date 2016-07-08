/*
 * functions.h
 *
 *  Created on: 08.07.2016
 *      Author: Tomek
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <cstring>
#include <string>
#include <utility>

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
void instructions();
void move(std::string start, std::string end, char board[BOARD_SIZE][BOARD_SIZE] );
std::pair<int,int> getPosition(std::string pos);

#endif /* FUNCTIONS_H_ */
