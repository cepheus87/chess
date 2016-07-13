/*
 * chesspieceFunc.cpp
 *
 *  Created on: 13.07.2016
 *      Author: Cepheus
 */

#include<utility>
#include"chesspieceFunc.h"


using namespace std;

bool moveEngine(std::pair<int,int> startPos, std::pair<int,int> endPos, char board[BOARD_SIZE][BOARD_SIZE] ){

  char c = board[startPos.first][startPos.second];

  bool returnStatement = true;

  switch(c){

  case 'p':
  case 'P':
    returnStatement = movePawn();
    break;

  case 'r':
  case 'R':
    returnStatement = moveRook();
    break;

  case 'n':
  case 'N':
    returnStatement = moveKnight();
    break;

  case 'b':
  case 'B':
    returnStatement = moveBishop();
    break;

  case 'q':
  case 'Q':
    returnStatement = moveQueen();
    break;

  case 'k':
  case 'K':
    returnStatement = moveKing(startPos, endPos, board );
    break;

  default :
    cout<<"Pole startowe jest puste"<<endl;
    returnStatement = false;
    break;
  }

  return returnStatement;

}

bool isEmpty(std::pair<int,int> endPos, char board[BOARD_SIZE][BOARD_SIZE] ){
  if( board[endPos.first][endPos.second] == '.') return true;
  else return false;
}


bool movePawn(){
  cout<<"I'm pawn"<<endl;
  cout<<"brak implementacji"<<endl;
  return false;
}

bool moveRook(){
    cout<<"I'm rook"<<endl;
  cout<<"brak implementacji"<<endl;
  return false;
}

bool moveKnight(){
  cout<<"I'm knight"<<endl;
  cout<<"brak implementacji"<<endl;
  return false;
}

bool moveBishop(){
  cout<<"I'm bishop"<<endl;
  cout<<"brak implementacji"<<endl;
  return false;
}

bool moveQueen(){
  cout<<"I'm queen"<<endl;
  cout<<"brak implementacji"<<endl;
  return false;
}

bool moveKing(std::pair<int,int> startPos, std::pair<int,int> endPos, char board[BOARD_SIZE][BOARD_SIZE] ){

  if(! isEmpty(endPos, board) ){
    cout<<"do krola trzeba jeszcze dodac sprawdzanie czy nie bije wlasnej figury"<<endl;
  }
   


  if( abs(endPos.first - startPos.first) <= 1 && abs(endPos.second - startPos.second) <=1 ){
    move2(startPos, endPos, board);
    return true;
  }
  else{
    cout<<"To nie jest dozwolony ruch krolem"<<endl;
    return false;
  }

}


// assumption board[X][Y]  -> getPosition zwraca  first int == x, second int ==y



