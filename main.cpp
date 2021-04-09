#include <iostream>
#include "HashTable.h"
#include <cstring>

void main() {
	setlocale(LC_ALL, "Russian");
	ifstream input("data.txt");

	if (!input.is_open())
		cout << "Ошибка открытия файла" << endl;
	else {
		HashTable hashTable(maxSize);
		Data data;
		while (!input.eof()) {
			input >> data;
			hashTable.insert(data);
		}
		Data d("Test", "test", "pdf", 11, 1, 1111, 11);
		hashTable.insert(d);
		hashTable.print();
	}
	system("pause");
	input.close();
}