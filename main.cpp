#include "functions.h"
#include"chesspieceFunc.h"


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
	char exit = 'n';
	std::string msg_Command;

	do
	{
		for (int i=0; i<=5;i++)
		{
			clearLine(17+i);
		}

		if (player)
            {
                msg_Command = "BIALY: Prosze podac polecenie lub pole pionka i pole docelowe ruchu: ";
            }
            else
            {
                msg_Command = "CZARNY: Prosze podac polecenie lub pole pionka i pole docelowe ruchu: ";
            }

		gotoXY(0,17);
        cout<<msg_Command;
		std::getline(std::cin,command);
		std::string modyfiedCommand=checkCommands(command);

        if (modyfiedCommand=="help")
            {
                clearLine(17);
                gotoXY(0,17);
                help();
            }else if (modyfiedCommand=="quit")
                {
                clearLine(17);
                gotoXY(0,17);
                cout <<"Wyjscie z gry"<<endl;
                exit='t';
            } else {

                //Sprawdzanie poprawnosci wpisanej komendy
                pair<bool,string> moveCorrectness = checkMove(command,(char(*)[BOARD_SIZE])b);

                if(moveCorrectness.first){
                startPosition = moveCorrectness.second.substr(0,2);
                endPosition = moveCorrectness.second.substr(2,2);
                move(startPosition, endPosition, (char(*)[BOARD_SIZE])b,player);   //jesli komenda poprawna - wykonaj ruch
                //moveEngine(getPosition(startPosition), getPosition(endPosition), (char(*)[BOARD_SIZE])b );
                //Na razie zakomentowane - trzeba dopisac
                } else {
                //jesli komenda nie poprawna
                gotoXY(0,19);
                cout<<"Ruch nie zostanie wykonany. Podaj jeszcze raz potrzebne pola!"<<endl;
                }

                gotoXY(0,20);
                cout << "Nacisnij ENTER aby kontynulowac...";

                //Oczekiwanie na enter
                while (getchar() != '\n'){}
            }
	}while(exit != 't');
}

