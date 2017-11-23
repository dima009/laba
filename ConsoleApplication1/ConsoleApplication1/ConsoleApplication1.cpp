// ������������ ������ #1 �� ����������������.

// ������� 2. ������� 7. ��-51. ��������� ����� ������������.

//��� ������ �� N ������������ �����. � ������� �������������� �������� �������� ����������� ������������� �������.

//����� ������, ������ �� ���� ��� ��������, ������� ����� t. �������������� � ����� ������� �������� ��������� ����������� ����� � �������� �������.

//���� ��������, ������������� �� ������ ������� ���������, ����������� � ������� �����������, �� ����� ����� ��������� �������, ������������� �� ���������� ������������� ��������.

//������� �� ������� ��������, ��� ���� �� ��������� �� ������ ������������ ��������. ������������� �� �������� ����� ������� ����� ���������� � ��������� ��������� i1 � i22.

#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include "stdafx.h"

using namespace std;

template <class T>
void Sort(T& arrayPtr);

void out(int var);

int main() {
	vector <int> numbers; // ������ � ������� �������.
	int n; // ����������� ������������ ����� .
	int mini, l; // ����������� ������������� �����, ��������� �����
	int p; // ���������� ������ �����.
	int t; // ���������.

	vector <int> copy; // ������, ��� ���� ������� ��������, � �������, ���� �� �������� �� ������ ������������ ��������.
	vector <int> szht;

	cout << "How many numbers you want?\n|> ";
	cin >> n;

	cout << "Entering numbers with 'enter' (stop).\n";

	for (int k = 0; k < n; k++) {
		cout << "#" << k + 1 << ": ";
		cin >> l;
		numbers.push_back(l);
	}
	copy = numbers;
	int i, sum = 0; // ������ �����, ����� ��������� ������������� �� �����������

	for (i = 0; i < numbers.size(); i++)
		if (numbers[i] == 0) {
			if (i < numbers.size() - 2)
				if (numbers[i + 1] < numbers[i + 2]) {
					sum += numbers[i + 1];
					for (int j = i + 2; j < numbers.size(); j++) {
						if (numbers[j] <= numbers[j - 1])
							break;
						else sum += numbers[j];
					}
				}
			break;
		}

	cout << "\nResult:\n SUM = " << sum << "\n";

	int max;
	for (i = 0, max = numbers[0]; i < numbers.size(); i++)
		if (numbers[i] > max) max = numbers[i];

	for (i = 1, mini = max; i < numbers.size(); i++) // ����� ������������ ��������������
		if (numbers[i]<mini && numbers[i] > 0)
			mini = numbers[i];

	copy = numbers; // ����������� ������� �����

	for (i = 0; i < copy.size(); i++) // ����� ������� �������������� � ��� �������������
		if (copy[i] < 0)
			copy[i] += mini;

	cout << " Result after sum with +min:\n";
	for_each(copy.begin(), copy.end(), out);
	cout << endl;

	copy = numbers;

	cout << "\n Enter t: ";
	cin >> t;

	int count; // ����� ����������� ��������� ������� t
	for (i = 0, count = 0; i < numbers.size() - count; i++)
		if ((numbers[i] % t) == 0) { // �������� �� ��������� t
			count++; // ����������� �������� ��������� ������� t ���������
			for (int j = i; j < numbers.size() - 1; j++)
				numbers[j] = numbers[j + 1]; // ����� ������� � �������� ���������� ��������
			i--;
			numbers[numbers.size() - count] = 0; // ���������� ����� ������� ������
		}

	for_each(numbers.begin(), numbers.end(), out);
	cout << endl;

	int min; // ����������� ��������
	bool sign_min = 0;// ���� ������������: 0 = +, 1 = -
	for (i = 0, min = copy[0]; i < copy.size(); i++)// ����� ���
		if (numbers[i] < min) min = numbers[i];

	if (min < 0) sign_min = 1;

	for (i = 0; i < copy.size(); i++) // �������� ��������� �� ������ �� �����
		if (((copy[i]<0) ? 1 : 0) != sign_min) {
			copy.erase(copy.begin() + i);
			i--;
		}

	cout << " Result after sign:\n";
	for_each(copy.begin(), copy.end(), out);
	cout << endl;

	copy = numbers;

	Sort(copy); // ���������� �� ��������

	cout << " Result after sorting:\n";
	for_each(copy.begin(), copy.end(), out);
	cout << endl;
	system("pause");
	return 0;
}

void out(int var) {
	cout << var << " ";
}

template <class T>
void Sort(T &arrayPtr) // ���������� ���������
{
	int temp, // ��������� ���������� ��� �������� �������� �������� ������������ �������
		item; // ������ ����������� ��������
	for (int counter = 1; counter < arrayPtr.size(); counter++)
	{
		temp = arrayPtr[counter]; // �������������� ��������� ���������� ������� ��������� �������� �������
		item = counter - 1; // ���������� ������ ����������� �������� �������
		while (item >= 0 && arrayPtr[item] < temp) // ���� ������ �� ����� 0 � ���������� ������� ������� ������ ��������
		{
			arrayPtr[item + 1] = arrayPtr[item]; // ������������ ��������� �������
			arrayPtr[item] = temp;
			item--;
		}
	}
}
