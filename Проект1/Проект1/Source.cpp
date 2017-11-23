#include <iostream>
#include <string>
using namespace std;

int main()
{
	string name;
	cout << "Name: Dmitry, Roman" << endl;
	
	cout << "Input name" << endl;
	cin >> name;
	if (name == "Dmitry") cout << "Hello Dmitry" << endl;
	else if (name == "Roman") cout << "Hello Roman" << endl;
	else cout << "Hello User" << endl;

	system("pause"); 
	return 0;
}