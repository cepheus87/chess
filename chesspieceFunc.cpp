/*
 * chesspieceFunc.cpp
 *
 *  Created on: 13.07.2016
 *      Author: Cepheus
 */

#include<utility>
#include"chesspieceFunc.h"


using namespace std;

// assumption board[X][Y]  -> getPosition zwraca  first int == x, second int ==y

bool isKnight(std::pair<int,int> startPos, char board[BOARD_SIZE][BOARD_SIZE]){
	if(board[startPos.first][startPos.second] == 'n' || board[startPos.first][startPos.second] == 'N' ){
		return true;
	}
	else{
		return false;
	}
}

bool knightMove(std::pair<int,int> startPos, std::pair<int,int> endPos, char board[BOARD_SIZE][BOARD_SIZE] )
{

	return true;
}


