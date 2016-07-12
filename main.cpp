#include "functions.h"

using namespace std;

int main(int argc, char* argv[])
{

	menu();

	char* b = new char[BOARD_SIZE * BOARD_SIZE];
	init((char(*)[BOARD_SIZE])b);
	draw((char(*)[BOARD_SIZE])b);

    checkMove("      z9   *%@#$ Z6    ");
    cin.ignore();
    exit(1);

	string startPosition;
	string endPosition;

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
