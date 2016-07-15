#include "functions.h"
#include "chesspieceFunc.h"

using namespace std;

int main(int argc, char* argv[])
{
#ifndef _WIN32
system("clear");
#endif

	bool player = true;				// du¿e pionki

	menu();     //wypisanie instrukcji

	char* b = new char[BOARD_SIZE * BOARD_SIZE];
	init((char(*)[BOARD_SIZE])b);
	draw((char(*)[BOARD_SIZE])b);

	string startPosition;
	string endPosition;
	string command;
	string blank;
	char exit;

	std::string msg_Command="Prosze podac pole pionka i pole docelowe ruchu: ";
    std::string msg_Contin="Graj dalej lub nie - t/n: ";

	do{
        gotoXY(msg_Command.length(),22);
		cout<<"        ";

        gotoXY(0,25);
        blank.replace(0,msg_Contin.length()+1,msg_Contin.length()+1,' ');
		cout<<blank;

		gotoXY(0,23);
        blank.replace(0,0,20,' ');
		cout<<blank;

		gotoXY(0,24);
		cout<<blank;

		gotoXY(0,22);
        cout<<msg_Command;
		std::getline(std::cin,command);

		//Sprawdzanie poprawnosci wpisanej komendy
		pair<bool,string> moveCorrectness = checkMove(command);

    if(moveCorrectness.first){
    	startPosition = moveCorrectness.second.substr(0,2);
    	endPosition = moveCorrectness.second.substr(2,2);
    	move(startPosition, endPosition, (char(*)[BOARD_SIZE])b,player);   //jesli komenda poprawna - wykonaj ruch
    	//moveEngine(getPosition(startPosition), getPosition(endPosition), (char(*)[BOARD_SIZE])b );
        //Na razie zakomentowane - trzeba dopisac

    }
    else{
        //jesli komenda nie poprawna
    	gotoXY(0,24);
    	cout<<"Ruch nie zostanie wykonany. Podaj jeszcze raz potrzebne pola!"<<endl;
    }
        //Petla walidacji komendy wpisywanej w zapytanie o dalsza gre
        //Jesli wpisane brednie - program bedzie czekal na 't' lub 'n'
        do {
        gotoXY(msg_Contin.length(),25);
		cout<<"      ";
		gotoXY(0,25);
		cout<<msg_Contin;
		cin>>exit;
        }while(exit!='n'&&exit!='t');

		cin.ignore();
	}while(exit != 'n');
}
