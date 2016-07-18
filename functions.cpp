#include"functions.h"
#include"chesspieceFunc.h"


using namespace std;

#ifdef _WIN32

#define MOVE_X_LINUX_CORRECTION 0

	void gotoXY(short x, short y)
	{
		COORD coord = {x, y};
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}

#else

#define MOVE_X_LINUX_CORRECTION 1

	void gotoXY(short x, short y)
	{
		cout << "\033[" << y << ";" << x << "f" << flush;
	}

#endif

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
	short firstLine = 4;

    gotoXY(0, firstLine);

    char fieldName = 'A';	//Zmienna uzyta do wypisania rzedu liter, okreslajacych poszczegolne pola szachownicy


	cout<< "   ";

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		cout << fieldName << " ";
		fieldName++;
	}
	cout << endl << "  ----------------" << endl;

	for (int i = BOARD_SIZE - 1; i >= 0; i--)
	{

		cout << i+1 << "| ";

		for (unsigned j = 0; j < BOARD_SIZE; j++)
		{

			cout << board[i][j]<<" ";
		}

		cout << "|" << i+1 << endl;
	}

	fieldName = 'A';	//Zmienna uzyta do wypisania rzedu liter, okreslajacych poszczegolne pola szachownicy
	cout << "  ----------------" << endl;
	cout<< "   ";

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		cout << fieldName << " ";
		fieldName++;
	}

	cout<<endl;
}


std::pair<bool, std::string> checkMove(std::string positions, char board[BOARD_SIZE][BOARD_SIZE])
{
	string quantityOfCharacters="";
	pair<bool, string> moveCorrectness(true, "");

	for(size_t i = 0; i < positions.length(); i++ )
	{
		if(isalpha(positions[i])){
			quantityOfCharacters+= positions[i];
		}
		if(isdigit(positions[i])){
			quantityOfCharacters+= positions[i];
		}

	}

	#ifdef DEBUG
		cout << "quantityOfCharacters: "<<quantityOfCharacters<<endl;
	#endif

	if(quantityOfCharacters.length()!=4){

		if(quantityOfCharacters.length()==3||quantityOfCharacters.length()==2)
		            {
		            cout<<"Wprowadziles " <<quantityOfCharacters.length()<<" znaki typu litera lub cyfra, powinny byc 4!";
		            }else if (quantityOfCharacters.length()==0)
		            {
		            cout<<"Wprowadziles " <<quantityOfCharacters.length()<<" liter i cyfr, powinny byc 4!";
		            }else if (quantityOfCharacters.length()==1)
		            {
		            cout<<"Wprowadziles " <<quantityOfCharacters.length()<<" litere lub cyfre, powinny byc 4!";
		            } else{
		            cout<<"Wprowadziles " <<quantityOfCharacters.length()<<" znakow typu litera lub cyfra, powinny byc tylko 4!";
		            }

		moveCorrectness.first= false;
		return moveCorrectness;
	}

	bool checkChar = true;

	for(size_t i = 0; i < quantityOfCharacters.length(); i++)
	{
		if ( i%2 == 0 )
		{
			if ( (atoi(&quantityOfCharacters[i])) == 0)
			{

				char castedChar = quantityOfCharacters[i];

				if(!((castedChar >= 'A' && castedChar <='A'+BOARD_SIZE)||(castedChar >= 'a' && castedChar <= 'a'+BOARD_SIZE))) // 65 == A
				{
					cout << "Litera na pozycji " << i+1 << " powinna byc z zakresu A-H lub a-h!" << endl;
					checkChar = false;
				}

			}else{

				cout<<"Znak "<<i+1<<" powinien byc litera a jest cyfra!"<<endl;
				moveCorrectness.first= false;

			}
		}
		else
		{

			if ( ( atoi(&quantityOfCharacters[i] ) < 1 )||( atoi(&quantityOfCharacters[i])>8 ) )
			{

				cout << "Liczba na pozycji " << i+1 << " powinna byc z zakresu 1-8!" << endl;
				checkChar = false;

			}
		}

	}

	std::string startPosition = quantityOfCharacters.substr(0,2);
	pair<int,int> startPos = getPosition(startPosition);

		if (isEmpty(startPos, board))
		{
	    cout<<"To pole jest puste."<<endl;
	    moveCorrectness.first= false;
	    return moveCorrectness;
		}

	if (checkChar == false)
	{
		moveCorrectness.first= false;
		return moveCorrectness;
	}

	moveCorrectness.second=quantityOfCharacters;
	return moveCorrectness;
}

std::pair<int,int> getPosition(std::string pos)
{
	pair<int, int> posPair;
	const char* firstChar = &pos.at(0);
	const char* secondChar = &pos.at(1);
		if ( (atoi(firstChar)) != 0)
		{
			posPair.first= atoi(firstChar) - 1;
			char castedChar = secondChar[0];
			if(castedChar >= 'A' && castedChar <='H') // 65 == A
			{
				posPair.second = castedChar - 'A';
			}
			else
			{
				posPair.second = castedChar - 'a';  // 97 == a
			}
		}
		else
		{

			posPair.first= atoi(secondChar) - 1;
			char castedChar = firstChar[0];

			if(castedChar >= 'A' && castedChar <= 'H') // 65 == A
			{
				posPair.second=castedChar - 'A';
			}
			else
			{
				posPair.second=castedChar - 'a';  // 97 == a
			}

		}

		return posPair;
}


void move(std::pair<int,int> startPos, std::pair<int,int> endPos, char board[BOARD_SIZE][BOARD_SIZE], bool &player )
{



	#ifdef DEBUG
		cout<<startPos.first<<" "<<startPos.second<<endl;
		cout<<endPos.first<<" "<<endPos.second<<endl;
		cout<< board[startPos.first][startPos.second]<<endl;
		cout<<board[endPos.first][endPos.second]<<endl;
	#endif


		bool copyPlayer = player;
		if(checkPlayer(startPos,board,player)&&(isAllowed(endPos,board,copyPlayer)))
		{
			player = !player;

			board[endPos.first][endPos.second] = board[startPos.first][startPos.second];
			board[startPos.first][startPos.second] = '.';

			int startXPostoDrow;
			int startYPostoDrow;
			int endXPostoDrow;
			int endYPostoDrow;
			char chosenFigure;

			chosenFigure = board[endPos.first][endPos.second];

			unsigned int quantityLeftSpace = 3;
			unsigned int lastBoardLine = 13;

			startXPostoDrow = quantityLeftSpace + startPos.second * 2 + MOVE_X_LINUX_CORRECTION;
			startYPostoDrow = lastBoardLine - startPos.first;

			#ifdef DEBUG
				cout<<"sX: "<<startXPostoDrow;
				cout<<"sY: "<<startYPostoDrow;
			#endif

			endXPostoDrow = quantityLeftSpace + endPos.second * 2 + MOVE_X_LINUX_CORRECTION;
			endYPostoDrow = lastBoardLine - endPos.first;

			#ifdef DEBUG
				cout<<"eX: "<<endXPostoDrow;
				cout<<"eY: "<<endYPostoDrow;
			#endif

			gotoXY(startXPostoDrow,startYPostoDrow);
			printf(".");
			gotoXY(endXPostoDrow,endYPostoDrow);
			printf("%c",chosenFigure);

			//cout<<"Pionek z pozycji: "<<start<<", zostal przeniesiony na pole: "<<end<<endl;
	}
}
void move(std::string start, std::string end, char board[BOARD_SIZE][BOARD_SIZE],bool &player )
{
  	pair<int,int> startPos = getPosition(start);
  	pair<int,int> endPos = getPosition(end);
  	move(startPos, endPos, board, player);
}

bool checkPlayer(std::pair<int,int> startPos, char board[BOARD_SIZE][BOARD_SIZE], bool& player)
{

	if (player)
	{
		if( (board[startPos.first][startPos.second] >= 'A') && (board[startPos.first][startPos.second] <= 'Z') )
		{

			return true;

		}
		else
		{

			cout << "Nie twoja figura"<<endl;
			return false;

		}

	}else{

		if( (board[startPos.first][startPos.second] >= 'a') && (board[startPos.first][startPos.second] <= 'z') )
		{
			return true;

		}
		else
		{

			cout << "Nie twoja figura"<<endl;
			return false;

		}
	}
}

bool isAllowed(std::pair<int,int> endPos, char board[BOARD_SIZE][BOARD_SIZE], bool player)
{

	if (player)
	{
		if( (board[endPos.first][endPos.second] >= 'A') && (board[endPos.first][endPos.second] <= 'Z') )
		{
			cout<<"Nie mozesz wykonac ruchu na swoje pole."<<endl;

			return false;

		}
		else
		{

			return true;
		}


	}else{


		if( (board[endPos.first][endPos.second] >= 'a') && (board[endPos.first][endPos.second] <= 'z') )
		{
			cout<<"Nie mozesz wykonac ruchu na swoje pole."<<endl;

			return false;

		}
		else
		{

			return true;

		}
	}
}

//Funkcja wypisywania instrukcji do gry w szachy
void menu()
{
	short centerPosition = 10;

	gotoXY(centerPosition,0); //wysrodkowanie
    cout<<"Witaj w programie szachowym!"<<endl;
    cout<<"Aby wyswietlic instrukcje gry wpisz polecenie 'HELP'"<<endl;
    cout<<"Aby zakonczyc rozgrywke wpisz polecenie 'QUIT'"<<endl;

}

void help(){

#ifndef _WIN32
#define LINUX_HELP_CORRECTION -1
#else
#define LINUX_HELP_CORRECTION 0
#endif
            cout<<"Ruch wybranej figury dokonujemy poprzez podanie jej wspolrzednych\n";
            cout<<"odpowiadajacych pozycji na szachownicy. Pierwsza wspolrzedna - duza\n";
            cout<<"litera, odpowiada kolumnie a druga liczba odpowiada wierszowi.\n";
            cout<<"Przykladowo wspolrzedne A1 odpowiadaja polu w pierwszym rzedzie i\n";
            cout<<"pierszej kolumnie. Uzytkownik moze podawac wspolrzedne zarowno malymi\n";
            cout<<"jak i duzymi literami. Ruchy wykonujemy do rezygnacji z gry."<<endl;
            cout<<endl<<"Wcisnij ENTER by powrocic do gry"<<endl;

            //Oczekiwanie na enter
            while (getchar() != '\n'){}



            short firstLineToClear = 17 + LINUX_HELP_CORRECTION;
            int quantityLineToClear = 10;

            for (int i=0; i <= quantityLineToClear; i++)
            {
            	clearLine(firstLineToClear+i);
            }
}


bool isEmpty(std::pair<int,int> endPos, char board[BOARD_SIZE][BOARD_SIZE] ){
  if( board[endPos.first][endPos.second] == '.') return true;
  else return false;
}

std::string checkCommands(std::string command)
{
    string temporaryCommand="";
    std::string modyfiedCommand="";
	for(size_t i = 0; i < command.length(); i++ )
	{
		if(isalpha(command[i])){
                if(isupper(command[i]))
                {
                     command[i]=tolower(command[i]);
                }
			temporaryCommand+= command[i];
		}

	}
	return temporaryCommand;
}

void clearLine(short y)
{
	short consoleWidth = 128;

	gotoXY(0, y);
	cout << setw(consoleWidth) << " ";
	gotoXY(0, y);
}
