#include<Windows.h>
#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
using namespace std;
#define endl '\n'

void Bedo()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
}
bool The_Game(string name, HANDLE& hConsole, WORD& originalAttributes, bool& first_trial)
{
	bool found = false;
	int trial = 1, guess;
	srand(time(0));

	if (!first_trial)
	{
		cout << endl << "The game's rules is to guess a number ranges from 1 to 30" <<
			" ... you have only 8 chances to guess the number right, if you are higher or lower by 20 inclusive a red signal appears, if you are higher or lower by 10 to 19 inclusive a blue signal appears and a green signal appears if you are higher or lower by 5 to 9 inclusive" << endl;
		first_trial ^= 1;
	}

	cout << endl << "Be ready " << name << " .. It starts after ";
	for (int i = 3; i > 0; i--)
		cout << i << " ";
	cout << endl << endl;

	int goofy_number = 1 + (rand() % 30);

	while (!found && trial < 9)
	{
		cout << "Trial - " << trial << " .. What's your guess !!" << endl;
		cin >> guess;
		if (guess == goofy_number)
			found ^= 1;
		else
		{
			trial++;
			if (abs(guess - goofy_number) >= 20)
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				cout << "RED FLAG RAISED !!" << endl;
				SetConsoleTextAttribute(hConsole, originalAttributes);
			}
			else if (abs(guess - goofy_number) >= 10)
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
				cout << "BLUE FLAG RAISED !!" << endl;
				SetConsoleTextAttribute(hConsole, originalAttributes);
			}
			else if (abs(guess - goofy_number) < 10)
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
				cout << "GREEN FLAG RAISED !!" << endl;
				SetConsoleTextAttribute(hConsole, originalAttributes);
			}
		}
	}
	if (trial > 8)
		cout << "OOPS !! .. You ran out of trials" << endl;

	return found;
}
void game_interface()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	WORD originalAttributes = consoleInfo.wAttributes;
	string name, answer;
	bool end_of_game = false, first_trial = false;

	cout << "*************************************** Welcome to the number gussing game !! ***************************************" << endl <<
		"What's your name buddy ?" << endl;

	std::getline(cin, name);
	cout << "Well Dear " << name << " ... Do you want to start to play !!?" << endl;
	cin >> answer;

	while (answer == "yes" || answer == "Yes" || answer == "y" || answer == "Y")
	{
		end_of_game = The_Game(name, hConsole, originalAttributes, first_trial);
		if (end_of_game)
		{
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);
			cout << endl << "WOOOOOW, You gussed it right " << name << endl;
		}
		else
		{
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			cout << endl << "You failed !! .. Sorry for that " << name << endl;
		}
		SetConsoleTextAttribute(hConsole, originalAttributes);
		cout << "Do you want to play again ?" << endl;
		cin >> answer;
	}
	if (answer == "No" || answer == "no" || answer == "n" || answer == "N")
		cout << "OH NO, Sorry for that " << name << " ... Good Bye Then !!" << endl;
}
int main()
{
	Bedo();
	int t = 1;
	while (t--)
		game_interface();
	system("pause");
}
