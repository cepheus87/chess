/*
 * main.cpp
 *
 *  Created on: 08.07.2016
 *      Author: Tomek
 */

#include"functions.h"

using namespace std;

int main(int argc, char* argv[]){

	instructions();

	char* b = new char[BOARD_SIZE * BOARD_SIZE];
	init((char(*)[BOARD_SIZE])b);
	draw((char(*)[BOARD_SIZE])b);

	move("A1", "A3", (char(*)[BOARD_SIZE])b);

	draw((char(*)[BOARD_SIZE])b);
}
