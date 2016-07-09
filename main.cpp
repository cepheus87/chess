/*
 * main.cpp
 *
 *  Created on: 08.07.2016
 *      Author: Tomek
 */

#include "functions.h"

using namespace std;

int main(int argc, char* argv[])
{

	instructions();

	char* b = new char[BOARD_SIZE * BOARD_SIZE];
	init((char(*)[BOARD_SIZE])b);
	draw((char(*)[BOARD_SIZE])b);

	string startPosition;
	string endPositon;
	char exit;

	do{

		gotoXY(0,21);
		cout<<"Podaj aktualna pozycje figury: ";
		cin>>startPosition;

		gotoXY(0,22);
		cout<<"Podaj pole na ktore wykonac ruch: ";
		cin>>endPositon;

		move(startPosition, endPositon, (char(*)[BOARD_SIZE])b);

		gotoXY(0,23);
		cout<<"Graj dalej lub nie - t/n: ";
		cin>>exit;

	}while(exit != 'n');
}
