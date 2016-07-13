#include "functions.h"
#include "chesspieceFunc.h"

using namespace std;

int main(int argc, char* argv[])
{

#ifndef _WIN32
  system("clear");
#endif

	menu();

	char* b = new char[BOARD_SIZE * BOARD_SIZE];
	init((char(*)[BOARD_SIZE])b);
	draw((char(*)[BOARD_SIZE])b);


    string startPosition;
    string endPosition;


    // Stworzylem pliki chesspieceFunc.xxx Tam oddzielnie beda funkcje dla pionkow - przyda sie pozniej ze wzgledu na pisanie obiektowe
    // Tam zaczalem myslec nad funkcjami do ruchu poszczegolnych figur z zalozeniem, ze jezeli ruch jest poprawny to zwraca true, jezeli nie to false

    //  w jakiejs petli to trzeba puscic :)
    pair<bool,string> moveCorrectness = checkMove("      E1   *%@#$ F2    ");

    if(moveCorrectness.first){
    	startPosition = moveCorrectness.second.substr(0,2);
    	endPosition = moveCorrectness.second.substr(2,2);
	//    	cout<<startPosition<<" "<<endPosition<<endl;

	moveEngine(getPosition(startPosition), getPosition(endPosition), (char(*)[BOARD_SIZE])b );

    }
    else{
    // do poprawiania ruchu
    }



    cin.ignore();
    exit(1);
	char exit;

	std::string msg_F="Prosze podac pole figury, ktora chcesz poruszyc: ";
    std::string msg_S="Prosze podac pole gdzie przesunac figure: ";
    std::string msg_Err="Podano bledna wspolrzedna!";
    std::string msg_Contin="Graj dalej lub nie - t/n: ";


	do{

		gotoXY(msg_F.length(),21);
		cout<<"        ";
		gotoXY(msg_S.length(),22);
		cout<<"        ";
		gotoXY(msg_Contin.length(),23);
		cout<<"          ";

		startPosition=instructions_F(msg_F,msg_Err);
		endPosition=instructions_S(msg_S,msg_Err);


		move(startPosition, endPosition, (char(*)[BOARD_SIZE])b);

		gotoXY(0,23);
		cout<<msg_Contin;
		cin>>exit;

	}while(exit != 'n');
}
