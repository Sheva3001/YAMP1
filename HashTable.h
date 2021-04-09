#pragma once
#include "Data.h"
#include "MyList.h" 
#include <string> 
#include <fstream>

using namespace std;

const int maxSize = 500;

class ListTable : public List {	// ������
public:
	bool searchElem(Data elem) {
		bool flag = false;
		Node* p = head;
		while (p->data == elem || !(isEmpty(p))) {
			p = p->next;
			flag = true;
		}
		return flag;
	}

	bool insertElem(Data elem) {
		int count = getCount();
		bool flag = false;

		addToHead(head, elem);		// ������ head

		if (count != getCount())	// ��������� ���������� ���������
			flag = true;

		return flag;				//���� flag = false, �� �������� � head
	}

	bool deleteElem(Data elem) {
		bool flag = false;
		Node* p = head;

		while (!(isEmpty(p))) {
			if (p->data != elem)
				p = p->next;
			else {
				if (p == head)
					deleteFromHead(p);
				else
					deleteAfterNode(p);

				flag = true;
			}
		}
		return flag;
	}
};

class HashTable {
	ListTable table[maxSize];
	int size;

public:
	HashTable(int Size) : size(Size) {
		ListTable* table = new ListTable[size];
	}

	~HashTable() {
		delete[]table;
	}

	ListTable* getTable() {
		return table;
	}

	int getSize() {
		return size;
	}

	int hash(Data data) {				//���������� ������ ������ i, ��������� �� �������
		string key = data.getKey();

		const int p = 53;
		long int hash = 0, p_pow = 1;

		for (int i = 0; i < key.length(); i++) {
			hash += ((key[i] - 'a' + 1) * p_pow) % size;
			p_pow *= p;
		}
		return hash % size; //����� �� ����� �� ������ ������� 
	}

	int search(Data& data) {
		int h = hash(data);
		return table[h].searchElem(data);
	}

	bool insert(Data& data) {
		int h = hash(data);
		return table[h].insertElem(data);
	}

	bool retrieve(Data& data) {
		int h = hash(data);
		return table[h].deleteElem(data);
	}

	void print() {
		cout << "��� �������:" << endl;
		for (int i = 0; i < size; i++)
			table[i].printList();
	}
};