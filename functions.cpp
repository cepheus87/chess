#include"functions.h"

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
    gotoXY(0, 10);
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
		cout<<"Wprowadziles" <<tempPosition.length()<<", powinno byc 4!";
		moveCorrectness.first= false;
		return moveCorrectness;
	}

	bool checkChar = true;

	for(size_t i = 0; i < tempPosition.length(); i++)
	{
		if ( i%2 == 0 ){
			if ( (atoi(&tempPosition[i])) == 0)
			{

				int castedChar = static_cast<int>(tempPosition[i]);
					if(!((castedChar >= 65 && castedChar <=65+BOARD_SIZE)||(castedChar >= 97 && castedChar <= 97+BOARD_SIZE))) // 65 == A
					{
						cout<<"Litera na pozycji "<<i+1<<" powinna byc z zakresu A-H lub a-h!"<<endl;
						checkChar = false;
					}
			}else{
				cout<<"Znak "<<i+1<<" powinien byc litera a jest cyfra!"<<endl;
				moveCorrectness.first= false;
			}


		}else{

			if ( ( atoi(&tempPosition[i] ) < 1 )||( atoi(&tempPosition[i])>8 ) ){

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

	if(tempPosition.at(0) == tempPosition.at(2) && tempPosition.at(1) == tempPosition.at(3)){
	  cout<<"Pole startowe i koncowe jest takie samo!"<<endl; 
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
			if(castedChar >= 65 && castedChar <=73) // 65 == A
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

void move(std::string start, std::string end, char board[BOARD_SIZE][BOARD_SIZE] )
{

  	pair<int,int> startPos = getPosition(start);
  	pair<int,int> endPos = getPosition(end);

#ifdef DEBUG
	cout<<startPos.first<<" "<<startPos.second<<endl;
	cout<<endPos.first<<" "<<endPos.second<<endl;
	cout<< board[startPos.first][startPos.second]<<endl;
	cout<<board[endPos.first][endPos.second]<<endl;
#endif

	board[endPos.first][endPos.second] = board[startPos.first][startPos.second];
	board[startPos.first][startPos.second] = '.';

	int startXPostoDrow;
	int startYPostoDrow;
	int endXPostoDrow;
	int endYPostoDrow;
	char chosenFigure;

	chosenFigure = board[endPos.first][endPos.second];

	startXPostoDrow=3+startPos.second*2;
	startYPostoDrow=17-startPos.first;

#ifdef DEBUG
	cout<<"sX: "<<startXPostoDrow;
	cout<<"sY: "<<startYPostoDrow;
#endif

	endXPostoDrow=3+endPos.second*2;
	endYPostoDrow=17-endPos.first;

#ifdef DEBUG
	cout<<"eX: "<<endXPostoDrow;
	cout<<"eY: "<<endYPostoDrow;
#endif

	gotoXY(startXPostoDrow,startYPostoDrow);
	printf(".");
	gotoXY(endXPostoDrow,endYPostoDrow);
	printf("%c",chosenFigure);

}

void move2(std::pair<int,int> startPos, std::pair<int,int> endPos, char board[BOARD_SIZE][BOARD_SIZE] )
{


#ifdef DEBUG
	cout<<startPos.first<<" "<<startPos.second<<endl;
	cout<<endPos.first<<" "<<endPos.second<<endl;
	cout<< board[startPos.first][startPos.second]<<endl;
	cout<<board[endPos.first][endPos.second]<<endl;
#endif

	board[endPos.first][endPos.second] = board[startPos.first][startPos.second];
	board[startPos.first][startPos.second] = '.';

	int startXPostoDrow;
	int startYPostoDrow;
	int endXPostoDrow;
	int endYPostoDrow;
	char chosenFigure;

	chosenFigure = board[endPos.first][endPos.second];

	startXPostoDrow=3+startPos.second*2;
	startYPostoDrow=17-startPos.first;

#ifdef DEBUG
	cout<<"sX: "<<startXPostoDrow;
	cout<<"sY: "<<startYPostoDrow;
#endif

	endXPostoDrow=3+endPos.second*2;
	endYPostoDrow=17-endPos.first;

#ifdef DEBUG
	cout<<"eX: "<<endXPostoDrow;
	cout<<"eY: "<<endYPostoDrow;
#endif

	gotoXY(startXPostoDrow,startYPostoDrow);
	printf(".");
	gotoXY(endXPostoDrow,endYPostoDrow);
	printf("%c",chosenFigure);

}


void menu(){
            cout<<"Program do gry w szachy"<<endl<<endl;
            cout<<"Ruch wybranej figury dokonujemy poprzez podanie jej wspolrzednych\n";
            cout<<"odpowiadajacych pozycji na szachownicy. Pierwsza wspolrzedna - duza\n";
            cout<<"litera, odpowiada kolumnie a druga liczba odpowiada wierszowi.\n";
            cout<<"Przykladowo wspolrzedne A1 odpowiadaja polu w pierwszym rzedzie i\n";
            cout<<"pierszej kolumnie. Uzytkownik moze podawac wspolrzedne zarowno malymi\n";
            cout<<"jak i duzymi literami. Ruchy wykonujemy do rezygnacji z gry."<<endl;

}

string instructions_F(std::string msg_F, std::string msg_Err){
		char c_letterF;
		short int si_digitF;

		while(1)
		{
        gotoXY(0,21);
		cout<<msg_F; //cout<<"Prosze podac pole figury, ktora chcesz poruszyc: ";
		cin>>c_letterF>>si_digitF;

		if((c_letterF<'A' || c_letterF>'A'+BOARD_SIZE-1) || (si_digitF<0 || si_digitF>BOARD_SIZE) || !cin.good())
		{
			cin.clear();
			cin.sync();
			cout<<msg_Err<<endl;  //cout<<"Bledna wspolrzedna pionka!!!"<<endl;
			gotoXY(msg_Err.length(),22);
		    cout<<"                      ";
		    gotoXY(msg_F.length(),21);
		    cout<<"        ";
			continue;
		}
		break;
		}

		std::string s_fig (1,c_letterF);
		stringstream ss;
		ss << si_digitF;
		s_fig += ss.str();

		return s_fig;
}

string instructions_S(std::string msg_S, std::string msg_Err){
		char c_letterS;
		short int si_digitS;

		while(1)
		{
        gotoXY(0,22);
		cout<<msg_S;    //cout<<"Prosze podac pole gdzie przesunac figure: ";
		cin>>c_letterS>>si_digitS;
		if((c_letterS<'A' || c_letterS>'A'+BOARD_SIZE-1) || (si_digitS<0 || si_digitS>BOARD_SIZE) || !cin.good())
				{
					cout<<msg_Err<<endl;  //cout<<"Bledna wspolrzedna pola!!!!"<<endl;
					cin.clear();
					cin.sync();
                    gotoXY(msg_Err.length(),23);
                    cout<<"     ";
                    gotoXY(msg_S.length(),22);
                    cout<<"   ";
					continue;
				}
				break;
				}

		std::string s_sqr (1,c_letterS);
		stringstream ss;
		ss << si_digitS;
		s_sqr += ss.str();

		return s_sqr;
}
