/*
 * functions.cpp
 *
 *  Created on: 08.07.2016
 *      Author: Tomek
 */


#include"functions.h"

using namespace std;

void gotoXY(short x, short y)
{
	COORD coord = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

void init(char board[BOARD_SIZE][BOARD_SIZE])
{
    const char figuresRow[BOARD_SIZE] = {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'};

	memset(board, ' ', sizeof(char) * BOARD_SIZE * BOARD_SIZE);

    for (unsigned i = 0; i < BOARD_SIZE; i++)
        board[0][i] = figuresRow[i];

    for (unsigned i = 0; i < BOARD_SIZE; i++)
        board[1][i] = 'P';

    for (unsigned i = 0; i < BOARD_SIZE; i++)
        board[BOARD_SIZE - 2][i] = 'p';

    for (unsigned i = 0; i < BOARD_SIZE; i++)
        board[BOARD_SIZE - 1][i] = tolower(figuresRow[i]);

}

void draw(char board[BOARD_SIZE][BOARD_SIZE])
{
    gotoXY(0, 10);
	for (int i = BOARD_SIZE - 1; i >= 0; i--) {
		cout << i+1 << "| ";
		for (unsigned j = 0; j < BOARD_SIZE; j++) {
			cout << board[i][j]<<" ";
		}
		cout << endl;
	}

	char fieldName = 'A';	//Zmienna uzyta do wypisania rzedu liter, okreslajacych poszczegolne pola szachownicy
	cout << "  ----------------" << endl;
	cout<< "   ";

	for (int i = 0; i < 8; i++)
	{
		cout << fieldName << " ";
		fieldName++;
	}
}

void instructions(){

	cout<<"Program do gry w szachy"<<endl;

	cout<<"Tu bêdzie instrukcja jak grac..."<<endl<<endl;
}
