#include"functions.h"
#include"chesspieceFunc.h"


using namespace std;

#ifdef _WIN32

	void gotoXY(short x, short y)
	{
		COORD coord = {x, y};
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}

#else

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
    gotoXY(0, 4);

	for (int i = BOARD_SIZE - 1; i >= 0; i--) {
		cout << i+1 << "| ";
		for (unsigned j = 0; j < BOARD_SIZE; j++) {

			cout << board[i][j]<<" ";
		}
		cout << endl;
	}

	char fieldName = 'A';	//Zmienna uzyta do wypisania rzedu liter, okreslajacych poszczegolne pola szachownicy
	cout << "  ----------------" << endl;
	cout<< "   ";

	for (int i = 0; i < 8; i++)
	{
		cout << fieldName << " ";
		fieldName++;
	}

	cout<<endl;
}

std::pair<bool, std::string> checkMove(std::string positions)
{
	string tempPosition;
	pair<bool, string> moveCorrectness(true, "");

	for(size_t i = 0; i < positions.length(); i++ )
	{
		if(isalpha(positions[i])){
			tempPosition+= positions[i];
		}
		if(isdigit(positions[i])){
			tempPosition+= positions[i];
		}

	}

	#ifdef DEBUG
		cout << "tempPosition: "<<tempPosition<<endl;
	#endif

	if(tempPosition.length()!=4){
		cout<<"Wprowadziles " <<tempPosition.length()<<" liter i cyfr, powinny byc tylko 4!";
		moveCorrectness.first= false;
		return moveCorrectness;
	}

	bool checkChar = true;

	for(size_t i = 0; i < tempPosition.length(); i++)
	{
		if ( i%2 == 0 )
		{
			if ( (atoi(&tempPosition[i])) == 0)
			{

				int castedChar = static_cast<int>(tempPosition[i]);

				if(!((castedChar >= 'A' && castedChar <='A'+BOARD_SIZE)||(castedChar >= 'a' && castedChar <= 'a'+BOARD_SIZE))) // 65 == A
				{
					cout<<"Litera na pozycji "<<i+1<<" powinna byc z zakresu A-H lub a-h!"<<endl;
					checkChar = false;
				}

			}else{

				cout<<"Znak "<<i+1<<" powinien byc litera a jest cyfra!"<<endl;
				moveCorrectness.first= false;

			}
		}
		else
		{

			if ( ( atoi(&tempPosition[i] ) < 1 )||( atoi(&tempPosition[i])>8 ) )
			{

				cout<<"Liczba na pozycji "<<i+1<<" powinna byc z zakresu 1-8!"<<endl;
				checkChar = false;

			}
		}

	}

	if (checkChar == false)
	{
		moveCorrectness.first= false;
		return moveCorrectness;
	}

	moveCorrectness.second=tempPosition;
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
			int castedChar = static_cast<int>(secondChar[0]);
			if(castedChar >= 'A' && castedChar <='H') // 65 == A
			{
				posPair.second=castedChar - 64 - 1;
			}
			else
			{
				posPair.second=castedChar-96 - 1;  // 97 == a
			}
		}
		else
		{

			posPair.first= atoi(secondChar) - 1;
			int castedChar = static_cast<int>(firstChar[0]);

			if(castedChar >= 65 && castedChar <=73) // 65 == A
			{
				posPair.second=castedChar-64 - 1;
			}
			else
			{
				posPair.second=castedChar-96 - 1;  // 97 == a
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

	if (isEmpty(startPos, board))
	{

		cout<<"To pole jest puste."<<endl;

	}else{

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

			startXPostoDrow=3+startPos.second*2;
			startYPostoDrow=11-startPos.first;

			#ifdef DEBUG
				cout<<"sX: "<<startXPostoDrow;
				cout<<"sY: "<<startYPostoDrow;
			#endif

			endXPostoDrow=3+endPos.second*2;
			endYPostoDrow=11-endPos.first;

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
void menu(){
            gotoXY(10,0); //wysrodkowanie
            cout<<"Witaj w programie szachowym!"<<endl;
            cout<<"Aby wyswietlic instrukcje gry wpisz polecenie 'INSTRUCTION'"<<endl;
            cout<<"Aby zakonczyc rozgrywke wpisz polecenie 'QUIT'"<<endl;

}

void help(){

            cout<<"Ruch wybranej figury dokonujemy poprzez podanie jej wspolrzednych\n";
            cout<<"odpowiadajacych pozycji na szachownicy. Pierwsza wspolrzedna - duza\n";
            cout<<"litera, odpowiada kolumnie a druga liczba odpowiada wierszowi.\n";
            cout<<"Przykladowo wspolrzedne A1 odpowiadaja polu w pierwszym rzedzie i\n";
            cout<<"pierszej kolumnie. Uzytkownik moze podawac wspolrzedne zarowno malymi\n";
            cout<<"jak i duzymi literami. Ruchy wykonujemy do rezygnacji z gry."<<endl;
            cout<<endl<<"Wcisnij ENTER by powrocic do gry"<<endl;

            //Oczekiwanie na enter
            while (getchar() != '\n'){}

            for (int i=0; i<=10;i++)
		{
			clearLine(15+i);
		}
}


bool isEmpty(std::pair<int,int> endPos, char board[BOARD_SIZE][BOARD_SIZE] ){
  if( board[endPos.first][endPos.second] == '.') return true;
  else return false;
}

std::string checkCommands(std::string command)
{
    string temporaryCommand;
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
	gotoXY(0, y);
	cout << setw(128) << " ";
	gotoXY(0, y);
}

