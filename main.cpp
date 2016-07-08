/*
 * main.cpp
 *
 *  Created on: 08.07.2016
 *      Author: Tomek
 */

#include"functions.h"

using namespace std;

// Macierz przechowujaca poczatkowe rozstawienie szachownicy
//const char startup[8][8] = {
//	{ rook, knight, bishop, queen, king, bishop, knight, rook },
//	{ pawn, pawn, pawn, pawn, pawn, pawn, pawn, pawn },
//	{ 0, 0, 0, 0, 0, 0, 0, 0 },
//	{ 0, 0, 0, 0, 0, 0, 0, 0 },
//	{ 0, 0, 0, 0, 0, 0, 0, 0 },
//	{ 0, 0, 0, 0, 0, 0, 0, 0 },
//	{ -pawn, -pawn, -pawn, -pawn, -pawn, -pawn, -pawn, -pawn },
//	{ -rook, -knight, -bishop, -queen, -king, -bishop,-knight, -rook }
//};

int main(int argc, char* argv[]){

	instructions();

	char* b = new char[BOARD_SIZE * BOARD_SIZE];
	init((char(*)[BOARD_SIZE])b);
	draw((char(*)[BOARD_SIZE])b);

}
