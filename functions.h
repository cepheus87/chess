/*
 * functions.h
 *
 *  Created on: 08.07.2016
 *      Author: Tomek
 */

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <cstring>


#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

const int BOARD_SIZE = 8;

void gotoXY(short,short);
void init(char[BOARD_SIZE][BOARD_SIZE]);
void draw(char[BOARD_SIZE][BOARD_SIZE]);
void instructions();



#endif /* FUNCTIONS_H_ */
