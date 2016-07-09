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

	string start;
	string end;
	char exit;

	do{

		cout<<"\nPodaj aktualn¹ pozycjê figury: ";
		cin>>start;

		cout<<"Podaj pole na które wykonac ruch: ";
		cin>>end;

		move(start, end, (char(*)[BOARD_SIZE])b);
		draw((char(*)[BOARD_SIZE])b);

		cout<<endl;
		cout<<"Graj dalej lub nie - t/n: ";
		cin>>exit;

	}while(exit != 'n');
}
