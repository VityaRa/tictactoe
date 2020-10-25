#include <iostream>

using namespace std;

#define Row_Count 7
#define Col_Count 11

enum Game_State
{
	InGame,
	End
};

void Error()
{
	cout << "Sorry, try another one please" << "\n";
}
void Print_Field(char(&Array)[Row_Count][Col_Count])
{
	for (int i = 0; i < Row_Count; i++)
	{
		for (int j = 0; j < Col_Count; j++)
			cout << Array[i][j];
		cout << "\n";
	}
}

void Normal_Start(char(&Array)[Row_Count][Col_Count])
{
	system("cls");
	Print_Field(Array);
}
void Error_Start(char(&Array)[Row_Count][Col_Count])
{
	system("cls");
	Print_Field(Array);
	Error();
}

//void Player_Chose(int Chose, char(&Array)[Row_Count][Col_Count], bool Used_Cell[], char Symbol)
//{
//	switch (Chose)
//	{
//	case '1':
//		if (Used_Cell[0] == false)
//		{
//			Array[1][2] = Symbol;
//			Used_Cell[0] = true;
//		}
//		else Error();
//		break;
//
//	case '2':
//		if (Used_Cell[1] == false)
//		{
//			Array[1][5] = Symbol;
//			Used_Cell[1] = true;
//		}
//		else Error();
//		break;
//	case '3':
//		if (Used_Cell[2] == false)
//		{
//			Array[1][8] = Symbol;
//			Used_Cell[2] = true;
//		}
//		else Error();
//		break;
//	case '4':
//		if (Used_Cell[3] == false)
//		{
//			Array[3][2] = Symbol;
//			Used_Cell[3] = true;
//		}
//		else Error();
//		break;
//	case '5':
//		if (Used_Cell[4] == false)
//		{
//			Array[3][5] = Symbol;
//			Used_Cell[4] = true;
//		}
//		else Error();
//		break;
//	case '6':
//		if (Used_Cell[5] == false)
//		{
//			Array[3][8] = Symbol;
//			Used_Cell[5] = true;
//		}
//		else Error();
//		break;
//	case '7':
//		if (Used_Cell[6] == false)
//		{
//			Array[5][2] = Symbol;
//			Used_Cell[6] = true;
//		}
//		else Error();
//		break;
//	case '8':
//		if (Used_Cell[7] == false)
//		{
//			Array[5][5] = Symbol;
//			Used_Cell[7] = true;
//		}
//		else Error();
//		break;
//
//	case '9':
//		if (Used_Cell[8] == false)
//		{
//			Array[5][8] = Symbol;
//			Used_Cell[8] = true;
//		}
//		else Error();
//		break;
//	default:
//		Error();
//		break;
//	}
//}

bool Game_State_Check(bool Used_Cell[], const int Array_size)
{
	int k = 0;
	for (int i = 0; i < Array_size; i++)
	{
		if (Used_Cell[i] == 1)
			k++;
	}
	return k == 9;
}

bool Horizontal_Check(char(&Array)[Row_Count][Col_Count], char Symbol)
{
	int Xcount = 0;
	for (int i = 1; i <= Row_Count - 2; i += 2)
	{

		for (int j = 2; j <= Col_Count - 2; j += 3)
		{
			if (Array[i][j] == Symbol)
				Xcount++;
		}
		if (Xcount == 3)
			return true;
		else Xcount = 0;
	}
	return false;
}
bool Vertical_Check(char(&Array)[Row_Count][Col_Count], char Symbol)
{
	int Xcount = 0;
	for (int j = 2; j <= Col_Count - 2; j += 3)
	{
		for (int i = 1; i <= Row_Count - 2; i += 2)
		{
			if (Array[i][j] == Symbol)
				Xcount++;
		}
		if (Xcount == 3)
			return true;
		else Xcount = 0;
	}
	return false;
}
bool Diagonal_Check(char(&Array)[Row_Count][Col_Count], char Symbol)
{
	int Xcount = 0;
	if (Array[1][2] == Symbol)
		Xcount++;
	if (Array[3][5] == Symbol)
		Xcount++;
	if (Array[5][8] == Symbol)
		Xcount++;
	if (Xcount == 3)
		return true;
	else Xcount = 0;

	if (Array[1][8] == Symbol)
		Xcount++;
	if (Array[3][5] == Symbol)
		Xcount++;
	if (Array[5][2] == Symbol)
		Xcount++;
	if (Xcount == 3)
		return true;
	else Xcount = 0;
	return false;

}
bool Win_Check(char(&Array)[Row_Count][Col_Count], char Symbol)
{
	if (Horizontal_Check(Array, Symbol) || Vertical_Check(Array, Symbol) || Diagonal_Check(Array, Symbol))
		return true;
	else return false;
}

void Replace(char(&Array)[Row_Count][Col_Count], char Symbol, string Chose)
{
	if (Chose == "1\0")
		Array[1][2] = Symbol;
	else
		if (Chose == "2\0")
			Array[1][5] = Symbol;
		else
			if (Chose == "3\0")
				Array[1][8] = Symbol;
			else 
				if (Chose == "4\0")
					Array[3][2] = Symbol;
				else
					if (Chose == "5\0")
						Array[3][5] = Symbol;
					else
						if (Chose == "6\0")
							Array[3][8] = Symbol;
						else
							if (Chose == "7\0")
								Array[5][2] = Symbol;
							else
								if (Chose == "8\0")
									Array[5][5] = Symbol;
								else
									if (Chose == "9\0")
										Array[5][8] = Symbol;
									else
									{
										Error();
									}




	
}
bool Repeat_Valid(bool *Used_Cell, string Place)
{
	bool Times;
	if (Place == "1")
	{
		Times = Used_Cell[0];
		Used_Cell[0] = true;
		return Times;
	}
	if (Place == "2")
	{
		Times = Used_Cell[1];
		Used_Cell[1] = true;
		return Times;
	}
	if (Place == "3")
	{
		Times = Used_Cell[2];
		Used_Cell[2] = true;
		return Times;
	}
	if (Place == "4")
	{
		Times = Used_Cell[3];
		Used_Cell[3] = true;
		return Times;
	}
	if (Place == "5")
	{
		Times = Used_Cell[4];
		Used_Cell[4] = true;
		return Times;
	}
	if (Place == "6")
	{
		Times = Used_Cell[5];
		Used_Cell[5] = true;
		return Times;
	}
	if (Place == "7")
	{
		Times = Used_Cell[6];
		Used_Cell[6] = true;
		return Times;
	}
	if (Place == "8")
	{
		Times = Used_Cell[7];
		Used_Cell[7] = true;
		return Times;
	}
	if (Place == "9")
	{
		Times = Used_Cell[8];
		Used_Cell[8] = true;
		return Times;
	}
	/*switch (Place)
	{
	case "1":
		Times = Used_Cell[0];
		Used_Cell[0] = true;
		return Times;
	case '2':
		Times = Used_Cell[1];
		Used_Cell[1] = true;
		return Times;
	case '3':
		Times = Used_Cell[2];
		Used_Cell[2] = true;
		return Times;
	case '4':
		Times = Used_Cell[3];
		Used_Cell[3] = true;
		return Times;
	case '5':
		Times = Used_Cell[4];
		Used_Cell[4] = true;
		return Times;
	case '6':
		Times = Used_Cell[5];
		Used_Cell[5] = true;
		return Times;
	case '7':
		Times = Used_Cell[6];
		Used_Cell[6] = true;
		return Times;
	case '8':
		Times = Used_Cell[7];
		Used_Cell[7] = true;
		return Times;
	case '9':
		Times = Used_Cell[8];
		Used_Cell[8] = true;
		return Times;
	}*/
}
bool Valid_Input(string Input)
{
	return (Input == "1" || Input == "2" || Input == "3" || Input == "4" || Input == "5" || Input == "6" || Input == "7" || Input == "8" || Input == "9");
}
bool String_Check(string str)
{
	return str[1] == '\0';
}

int main()
{
	int State = InGame;
	string Player_Chosef;
	const int Array_Size = 9;
	bool Used_Cell[Array_Size] = { 0 };
	char Symbol;
	char Field[Row_Count][Col_Count] =
	{
		'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*',
		'*', '*', '1', '*', '*', '2', '*', '*', '3', '*', '*',
		'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*',
		'*', '*', '4', '*', '*', '5', '*', '*', '6', '*', '*',
		'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*',
		'*', '*', '7', '*', '*', '8', '*', '*', '9', '*', '*',
		'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'
			};
	bool Guard = false;

	int move = 1;
	while (State != End)
	{
		if (!Guard)
		{
			Normal_Start(Field);
		}
		else
		{
			Error_Start(Field);
			Guard = false;
		}

		if (move % 2 == 1)
			Symbol = 'X';
		else Symbol = 'O';

		cout << "Turn: " << Symbol << "\n";

		cin >> Player_Chosef;

		if (Valid_Input(Player_Chosef) == false || String_Check(Player_Chosef) == false)
		{
			Guard = true;
			continue;
		}
		else
		{
			if (!Repeat_Valid(Used_Cell, Player_Chosef))
			{
				Replace(Field, Symbol, Player_Chosef);
				move++;
			}
			else
			{
				Guard = true;
				continue;
			}
		}


		if (Win_Check(Field, Symbol))
			{
				State = End;
				Normal_Start(Field);
				cout << "\n" << Symbol << " wins!!!" << "\n";
				break;
			}
		else
			if (Game_State_Check(Used_Cell, Array_Size))
			{
				State = End;
				Normal_Start(Field);
				cout << "\n" << "No winner" << "\n";
				break;
			}
			
	}




}