// Лабораторная работа #1 по Программированию.

// Задание 2. Вариант 7. ВМ-51. Пилипенко Денис Владимирович.

//Дан массив из N вещественных чисел. К каждому отрицательному элементу добавить минимальный положительный элемент.

//Сжать массив, удалив из него все элементы, кратные числу t. Освободившиеся в конце массива элементы заполнить количеством нулей в исходном массиве.

//Если элементы, расположенные за первым нулевым элементом, упорядочены в порядке возрастания, то найти сумму элементов массива, расположенных до последнего максимального элемента.

//Удалить из массива элементы, чей знак не совпадает со знаком минимального элемента. Отсортировать по убыванию часть массива между элементами с заданными индексами i1 и i22.

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
	vector <int> numbers; // Массив с данными числами.
	int n; // Колличество вещественных чисел .
	int mini, l; // Минимальное положительное число, введенное число
	int p; // Количество пустых ячеек.
	int t; // Кратность.

	vector <int> copy; // Массив, где были удалены элементы, в которых, знак не совпадал со знаком минимального элемента.
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
	int i, sum = 0; // индекс цикла, сумма элементов расположенных по возрастанию

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

	for (i = 1, mini = max; i < numbers.size(); i++) // поиск минимального положительного
		if (numbers[i]<mini && numbers[i] > 0)
			mini = numbers[i];

	copy = numbers; // копирование массива чисел

	for (i = 0; i < copy.size(); i++) // сумма каждого отрицательного с мин положительным
		if (copy[i] < 0)
			copy[i] += mini;

	cout << " Result after sum with +min:\n";
	for_each(copy.begin(), copy.end(), out);
	cout << endl;

	copy = numbers;

	cout << "\n Enter t: ";
	cin >> t;

	int count; // число встреченных элементов кратных t
	for (i = 0, count = 0; i < numbers.size() - count; i++)
		if ((numbers[i] % t) == 0) { // проверка на кратность t
			count++; // наращивание счетчика найденных кратных t элементов
			for (int j = i; j < numbers.size() - 1; j++)
				numbers[j] = numbers[j + 1]; // сдвиг массива и удаление найденного элемента
			i--;
			numbers[numbers.size() - count] = 0; // заполнение конца массива нулями
		}

	for_each(numbers.begin(), numbers.end(), out);
	cout << endl;

	int min; // минимальное значение
	bool sign_min = 0;// знак минимального: 0 = +, 1 = -
	for (i = 0, min = copy[0]; i < copy.size(); i++)// поиск мин
		if (numbers[i] < min) min = numbers[i];

	if (min < 0) sign_min = 1;

	for (i = 0; i < copy.size(); i++) // удаление элементов не схожих по знаку
		if (((copy[i]<0) ? 1 : 0) != sign_min) {
			copy.erase(copy.begin() + i);
			i--;
		}

	cout << " Result after sign:\n";
	for_each(copy.begin(), copy.end(), out);
	cout << endl;

	copy = numbers;

	Sort(copy); // сортировка по убыванию

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
void Sort(T &arrayPtr) // сортировка вставками
{
	int temp, // временная переменная для хранения значения элемента сортируемого массива
		item; // индекс предыдущего элемента
	for (int counter = 1; counter < arrayPtr.size(); counter++)
	{
		temp = arrayPtr[counter]; // инициализируем временную переменную текущим значением элемента массива
		item = counter - 1; // запоминаем индекс предыдущего элемента массива
		while (item >= 0 && arrayPtr[item] < temp) // пока индекс не равен 0 и предыдущий элемент массива больше текущего
		{
			arrayPtr[item + 1] = arrayPtr[item]; // перестановка элементов массива
			arrayPtr[item] = temp;
			item--;
		}
	}
}
