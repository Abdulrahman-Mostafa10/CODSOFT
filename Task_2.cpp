#include<Windows.h>
#include<iostream>
#include<string>
using namespace std;
#define endl '\n'
typedef double long  ld;
void Bedo()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
}
void calculator_interface()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	WORD originalAtrributes = consoleInfo.wAttributes;
	ld n1, n2;
	char operation;
	string close_app = "no";
	cout << "***************************************** Welcome to our simple calculator !! *****************************************" << endl;
	do
	{
		cout << "Enter your desired two numbers respectively for having a correct result :" << endl;
		cin >> n1 >> n2;
		cout << "Enter your desired operation :" << endl;
		cin >> operation;
		switch (operation)
		{
		case '+':
			cout << "The result is " << n1 + n2 << endl;
			cout << "Do you want to close the app ?" << endl;
			cin >> close_app;
			break;
		case '-':
			cout << "The result is " << n1 - n2 << endl;
			cout << "Do you want to close the app ?" << endl;
			cin >> close_app;
			break;
		case '*':
			cout << "The result is " << n1 * n2 << endl;
			cout << "Do you want to close the app ?" << endl;
			cin >> close_app;
			break;
		case '/':
			cout << "The result is " << n1 / n2 << endl;
			cout << "Do you want to close the app ?" << endl;
			cin >> close_app;
			break;
		case '%':
			if (!n2)
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				cout << "Syntax error !!" << endl;
				SetConsoleTextAttribute(hConsole, originalAtrributes);
			}
			else
				cout << "The result is " << (int)n1 % (int)n2 << endl;
			cout << "Do you want to close the app ?" << endl;
			cin >> close_app;
			break;
		default:
			cout << "Please choose addition, subtraction, multiplication, divison or remainder operation" << endl;
			cout << "Do you want to close the app ?" << endl;
			cin >> close_app;
			break;
		}
	} while (close_app != "yes");

	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED);
	cout << endl << "Baa Bye !!" << endl;
	SetConsoleTextAttribute(hConsole, originalAtrributes);
}
int main()
{
	Bedo();
	int t = 1;
	while (t--)
		calculator_interface();
	system("pause");
}
