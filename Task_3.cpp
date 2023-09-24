#include<Windows.h>
#include<iostream>
#include<string>
using namespace std;
#define endl '\n'

void Bedo()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
}
void grid_reset(char grid[3][3]) 
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)      // This function resets all the grid's positions
			grid[i][j] = ' ';
}
bool space_check(char grid[3][3])
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)		// This function checks whether is there a space or not
			if (grid[i][j] == ' ')
				return true;
	return false;
}
bool check_for_win(char grid[3][3])		// This function checks for wining case
{
	if ((grid[0][0] == grid[0][1] && grid[0][1] == grid[0][2] && grid[0][1] != ' ') ||
		(grid[1][0] == grid[1][1] && grid[1][1] == grid[1][2] && grid[1][1] != ' ') ||
		(grid[2][0] == grid[2][1] && grid[2][1] == grid[2][2] && grid[2][1] != ' ') ||
		(grid[0][0] == grid[1][0] && grid[1][0] == grid[2][0] && grid[1][0] != ' ') ||
		(grid[0][1] == grid[1][1] && grid[1][1] == grid[2][1] && grid[1][1] != ' ') ||
		(grid[0][2] == grid[1][2] && grid[1][2] == grid[2][2] && grid[1][2] != ' ') ||
		(grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[1][1] != ' ') ||
		(grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[1][1] != ' '))
		return true;
	return false;
}
bool check_for_draw(char grid[3][3])	// This function checks for draw case
{
	bool free_space = space_check(grid), check_win = check_for_win(grid);
	if (!free_space && !check_win)
		return true;
	return false;
}
string check_game_status(char grid[3][3], char player_1 = ' ', char player_2 = ' ')
{
	bool check_win = check_for_win(grid), check_draw = check_for_draw(grid);
	if (check_win)
	{
		if (player_1 != ' ')
			return "Player_1 wins !!";	// This function returns the state of the game
		return "Player_2 wins !!";
	}
	else if (check_draw)
		return "Draw !!";
	return "Ongoing game !!";
}
void update_board(char grid[3][3], HANDLE& hConsole, WORD& orginalAttributes)	//This function updates the boaard continuously 
{
	int row = 0, column = 0;
	// ************************************************************* Row_1_Drawing
	SetConsoleTextAttribute(hConsole, orginalAttributes);					  cout << "  ";
	if (grid[row][column] == 'X')
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED);  cout << "X";
	}
	else if (grid[row][column] == 'O')
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED); cout << "O";
	}
	else																	  cout << " ";
	column++;
	SetConsoleTextAttribute(hConsole, orginalAttributes);					  cout << "  |";

	SetConsoleTextAttribute(hConsole, orginalAttributes);					  cout << "  ";
	if (grid[row][column] == 'X')
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED);  cout << "X";
	}
	else if (grid[row][column] == 'O')
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED); cout << "O";
	}
	else																	  cout << " ";
	column++;
	SetConsoleTextAttribute(hConsole, orginalAttributes);					  cout << "  |";

	SetConsoleTextAttribute(hConsole, orginalAttributes);					  cout << "  ";
	if (grid[row][column] == 'X')
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED);  cout << "X";
	}
	else if (grid[row][column] == 'O')
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED); cout << "O";
	}
	else																	  cout << " ";
	row++;
	column = 0;
	SetConsoleTextAttribute(hConsole, orginalAttributes);
	cout << endl << "-----+-----+-----" << endl;

	// ************************************************************* Row_2_Drawing
	SetConsoleTextAttribute(hConsole, orginalAttributes);					  cout << "  ";
	if (grid[row][column] == 'X')
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED);  cout << "X";
	}
	else if (grid[row][column] == 'O')
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED); cout << "O";
	}
	else																	  cout << " ";
	column++;
	SetConsoleTextAttribute(hConsole, orginalAttributes);					  cout << "  |";
	SetConsoleTextAttribute(hConsole, orginalAttributes);					  cout << "  ";
	if (grid[row][column] == 'X')
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED);  cout << "X";
	}
	else if (grid[row][column] == 'O')
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED); cout << "O";
	}
	else																	  cout << " ";
	column++;
	SetConsoleTextAttribute(hConsole, orginalAttributes);					  cout << "  |";
	SetConsoleTextAttribute(hConsole, orginalAttributes);					  cout << "  ";
	if (grid[row][column] == 'X')
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED);  cout << "X";
	}
	else if (grid[row][column] == 'O')
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED); cout << "O";
	}
	else																	  cout << " ";
	row++;
	column = 0;
	SetConsoleTextAttribute(hConsole, orginalAttributes);
	cout << endl << "-----+-----+-----" << endl;

	// ************************************************************* Row_3_Drawing
	SetConsoleTextAttribute(hConsole, orginalAttributes);					  cout << "  ";
	if (grid[row][column] == 'X')
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED);  cout << "X";
	}
	else if (grid[row][column] == 'O')
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED); cout << "O";
	}
	else																	  cout << " ";
	column++;
	SetConsoleTextAttribute(hConsole, orginalAttributes);					  cout << "  |";
	SetConsoleTextAttribute(hConsole, orginalAttributes);					  cout << "  ";
	if (grid[row][column] == 'X')
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED);  cout << "X";
	}
	else if (grid[row][column] == 'O')
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED); cout << "O";
	}
	else																	  cout << " ";
	column++;
	SetConsoleTextAttribute(hConsole, orginalAttributes);					  cout << "  |";
	SetConsoleTextAttribute(hConsole, orginalAttributes);					  cout << "  ";
	if (grid[row][column] == 'X')
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED);  cout << "X";
	}
	else if (grid[row][column] == 'O')
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED); cout << "O";
	}
	else																	  cout << " ";
	cout << endl;
}
bool player_1_move(char grid[3][3], char player_1, HANDLE& hConsole, WORD& originalAttributes)
{
	int row, column;
	do
	{
		cout << "Enter a position's number correctly player_1 !!:" << endl;
		cin >> row >> column;
	} while (row > 2 || column > 2);			// This function performs the move of player_1
	bool free_space = space_check(grid);
	if (grid[row][column] != ' ')
	{
		if (free_space)
		{
			do
			{
				cout << "Enter a free position's number correctly:" << endl;
				cin >> row >> column;
			} while (row > 2 || column > 2 || grid[row][column] != ' ');
			grid[row][column] = player_1;
			update_board(grid, hConsole, originalAttributes);
			return true;
		}
		else
		{
			update_board(grid, hConsole, originalAttributes);
			return false;
		}
	}
	else
	{
		grid[row][column] = player_1;
		update_board(grid, hConsole, originalAttributes);
	}
	return true;

}
bool player_2_move(char grid[3][3], char player_2, HANDLE& hConsole, WORD& originalAttributes)
{

	int row, column;							// This function performs the move of player_2
	do
	{
		cout << "Enter a position's number correctly player_2 !!:" << endl;
		cin >> row >> column;
	} while (row > 2 || column > 2);
	bool free_space = space_check(grid);
	if (grid[row][column] != ' ')
	{
		if (free_space)
		{
			do
			{
				cout << "Enter a free position's number correctly:" << endl;
				cin >> row >> column;
			} while (row > 2 || column > 2 || grid[row][column] != ' ');
			grid[row][column] = player_2;
			update_board(grid, hConsole, originalAttributes);
			return true;
		}
		else
		{
			update_board(grid, hConsole, originalAttributes);
			return false;
		}
	}
	else
	{
		grid[row][column] = player_2;
		update_board(grid, hConsole, originalAttributes);
	}
	return true;
}
void draw_grid()
{													// This functios draws the grid initially
	cout << "  00  |  01  |  02  " << endl;
	cout << "------+------+------" << endl;
	cout << "  10  |  11  |  12  " << endl;
	cout << "------+------+------" << endl;
	cout << "  20  |  21  |  22  " << endl;
}
void tic_tac_toe()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	WORD originalAttributes = consoleInfo.wAttributes;
	char grid[3][3] = { {' ',' ',' '}, {' ',' ',' '},{' ',' ',' '} };
	char choice, player_1, player_2;
	bool player_x = false, player_o = false, game_status = false;

	cout << "******************************************* Welcome to TIC-TAC-TOE Game !! *******************************************" << endl;
	cout << "It's time to take turns :" << endl << "Player_1 !! .. Do you want to be ";
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED);	    cout << "X ";
	SetConsoleTextAttribute(hConsole, originalAttributes);	cout << "or ";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);	    cout << "O";
	SetConsoleTextAttribute(hConsole, originalAttributes);					    cout << " ?" << endl;
	cin >> choice;
	if (choice == 'X')
	{
		cout << "Player_1 plays with ";
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED);	cout << "X ";
		SetConsoleTextAttribute(hConsole, originalAttributes);					cout << "and player_2 with ";
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);	cout << "O";
		SetConsoleTextAttribute(hConsole, originalAttributes);					cout << endl;
		player_1 = 'X';
		player_2 = 'O';
	}
	else
	{
		cout << "Player_1 plays with ";
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);	cout << "O ";
		SetConsoleTextAttribute(hConsole, originalAttributes);					cout << "and player_2 with ";
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED);	cout << "X";
		SetConsoleTextAttribute(hConsole, originalAttributes);					cout << endl;
		player_1 = 'O';
		player_2 = 'X';
	}
	cout << endl << "Here is the grid initially for knowing the position's numbering :" << endl << endl;
	draw_grid();
	cout << endl << "Who wants to start ";
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED);		cout << "X ";
	SetConsoleTextAttribute(hConsole, originalAttributes);	cout << "or ";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);		cout << "O ";
	SetConsoleTextAttribute(hConsole, originalAttributes);						cout << "?" << endl;
	cin >> choice;
	if (choice == 'X')
		player_x ^= 1;
	else
		player_o ^= 1;

	cout << endl << "_____Lets'go !!!_____" << endl;
	game_status ^= 1;
	while (game_status)
	{
		string check_game;
		if (player_x)
		{
			if (player_1 == 'X')
			{
				player_1_move(grid, player_1, hConsole, originalAttributes);
				check_game = check_game_status(grid, player_1);
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				cout << check_game << endl;
				SetConsoleTextAttribute(hConsole, originalAttributes);
			}
			else
			{
				player_2_move(grid, player_2, hConsole, originalAttributes);
				check_game = check_game_status(grid, ' ', player_2);
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				cout << check_game << endl;
				SetConsoleTextAttribute(hConsole, originalAttributes);
			}
			player_x ^= 1;
			player_o ^= 1;
		}
		else
		{
			if (player_1 == 'O')
			{
				player_1_move(grid, player_1, hConsole, originalAttributes);
				check_game = check_game_status(grid, player_1);
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				cout << check_game << endl;
				SetConsoleTextAttribute(hConsole, originalAttributes);
			}
			else
			{
				player_2_move(grid, player_2, hConsole, originalAttributes);
				check_game = check_game_status(grid, ' ', player_2);
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				cout << check_game << endl;
				SetConsoleTextAttribute(hConsole, originalAttributes);
			}
			player_x ^= 1;
			player_o ^= 1;
		}
		if (check_game == "Player_1 wins !!" || check_game == "Player_2 wins !!" || check_game == "Draw !!")
		{
			cout << "Do you want to play again ? (y,n)" << endl;
			cin >> choice;
			if (choice == 'n' || choice == 'N')
			{
				game_status ^= 1;
				cout << SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
				cout << "Baa Bye !!" << endl;
				SetConsoleTextAttribute(hConsole, originalAttributes);
			}
			else
			{
				player_x = player_o = false;
				grid_reset(grid);
				cout << "It's time to take turns :" << endl << "Player_1 !! .. Do you want to be ";
				SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED);	    cout << "X ";
				SetConsoleTextAttribute(hConsole, originalAttributes);	cout << "or ";
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);	    cout << "O";
				SetConsoleTextAttribute(hConsole, originalAttributes);					    cout << " ?" << endl;
				cin >> choice;
				if (choice == 'X')
				{
					cout << "Player_1 plays with ";
					SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED);	cout << "X ";
					SetConsoleTextAttribute(hConsole, originalAttributes);					cout << "and player_2 with ";
					SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);	cout << "O";
					SetConsoleTextAttribute(hConsole, originalAttributes);					cout << endl;
					player_1 = 'X';
					player_2 = 'O';
				}
				else
				{
					cout << "Player_1 plays with ";
					SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);	cout << "O ";
					SetConsoleTextAttribute(hConsole, originalAttributes);					cout << "and player_2 with ";
					SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED);	cout << "X";
					SetConsoleTextAttribute(hConsole, originalAttributes);					cout << endl;
					player_1 = 'O';
					player_2 = 'X';
				}
				cout << endl << "Who wants to start ";
				SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED);		cout << "X ";
				SetConsoleTextAttribute(hConsole, originalAttributes);	cout << "or ";
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);		cout << "O ";
				SetConsoleTextAttribute(hConsole, originalAttributes);						cout << "?" << endl;
				cin >> choice;
				if (choice == 'X')
					player_x ^= 1;
				else
					player_o ^= 1;

				cout << endl << "_____Lets'go !!!_____" << endl;
			}
		}
	}
}
int main()
{
	Bedo();
	int t = 1;
	while (t--);
	tic_tac_toe();
	system("pause");
}
