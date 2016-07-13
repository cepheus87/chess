/*
 * chesspieceFunc.h
 *
 *  Created on: 13.07.2016
 *      Author: Cepheus
 */

#ifndef CHESSPIECEFUNC_H_
#define CHESSPIECEFUNC_H_

#include"functions.h"
#include<utility>

bool moveEngine(std::pair<int,int> startPos, std::pair<int,int> endPos, char board[BOARD_SIZE][BOARD_SIZE] );

bool movePawn();
bool moveRook();
bool moveKnight();
bool moveBishop();
bool moveQueen();
bool moveKing(std::pair<int,int> startPos, std::pair<int,int> endPos, char board[BOARD_SIZE][BOARD_SIZE] );

bool isEmpty(std::pair<int,int> endPos, char board[BOARD_SIZE][BOARD_SIZE] );


#endif /* CHESSPIECEFUNC_H_ */
