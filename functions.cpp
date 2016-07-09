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

	memset(board, '.', sizeof(char) * BOARD_SIZE * BOARD_SIZE);

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

	cout<<endl;
}

std::pair<int,int> getPosition(std::string pos)
{
	pair<int, int> posPair;
	const char* firstChar = &pos.at(0);
	const char* secondChar = &pos.at(1);
		if ( (atoi(firstChar)) != 0)
		{
			posPair.first= atoi(firstChar) - 1;
			int castedChar = static_cast<int>(secondChar[0]);
			if(castedChar >= 65 && castedChar <=73) // 65 == A
			{
				posPair.second=castedChar - 64 - 1;
			}
			else
			{
				posPair.second=castedChar-96 - 1;  // 97 == a
			}
		}
		else
		{

			posPair.first= atoi(secondChar) - 1;
			int castedChar = static_cast<int>(firstChar[0]);
			if(castedChar >= 65 && castedChar <=73) // 65 == A
			{
				posPair.second=castedChar-64 - 1;
			}
			else
			{
				posPair.second=castedChar-96 - 1;  // 97 == a
			}

		}

		return posPair;
}

void move(std::string start, std::string end, char board[BOARD_SIZE][BOARD_SIZE] )
{
	if(start.length() != 2) cout<<"zla instrukcja, podaj pole startowe"<<endl;
	if(end.length() != 2) cout<<"zla instrukcja, podaj pole koncowe"<<endl;

	pair<int,int> startPos = getPosition(start);
	pair<int,int> endPos = getPosition(end);

#ifdef DEBUG
	cout<<startPos.first<<" "<<startPos.second<<endl;
	cout<<endPos.first<<" "<<endPos.second<<endl;
	cout<< board[startPos.first][startPos.second]<<endl;
	cout<<board[endPos.first][endPos.second]<<endl;
#endif

	board[endPos.first][endPos.second] = board[startPos.first][startPos.second];
	board[startPos.first][startPos.second] = '.';

	int startXPostoDrow;
	int startYPostoDrow;
	int endXPostoDrow;
	int endYPostoDrow;
	char chosenFigure;

	chosenFigure = board[endPos.first][endPos.second];

	startXPostoDrow=3+startPos.second*2;
	cout<<"sX: "<<startXPostoDrow;
	startYPostoDrow=17-startPos.first;
	cout<<"sY: "<<startYPostoDrow;

	endXPostoDrow=3+endPos.second*2;
	cout<<"eX: "<<endXPostoDrow;
	endYPostoDrow=17-endPos.first;
	cout<<"eY: "<<endYPostoDrow;

	gotoXY(startXPostoDrow,startYPostoDrow);
	printf(".");
	gotoXY(endXPostoDrow,endYPostoDrow);
	printf("%c",chosenFigure);

}

void instructions(){

	cout<<"Program do gry w szachy"<<endl;

	cout<<"Prosze podac pole startowe i pole koncowe ruchu";
}
