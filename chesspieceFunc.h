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

bool isKnight(std::pair<int,int> startPos, char board[BOARD_SIZE][BOARD_SIZE]);
bool knightMove(std::pair<int,int>, std::pair<int,int>, char board[BOARD_SIZE][BOARD_SIZE]);



#endif /* CHESSPIECEFUNC_H_ */
