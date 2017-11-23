#include <iostream>
#include <string>
using namespace std;

int main()
{
	string name;
	cout << "Name: Dmitry, Roman, Kol9, Vlad" << endl;
	
	cout << "Input name" << endl;
	cin >> name;
	if (name == "Dmitry") cout << "Hello Dmitry" << endl;
	else if (name == "Roman") cout << "Hello Roman" << endl;
	else if (name == "Kol9") cout << "Hello Kol9" << endl;

	else cout << "Hello User" << endl;

	system("pause"); 
	return 0;
}