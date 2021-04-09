#pragma once
#include "Data.h"
#include <iostream>
#include <fstream>

using namespace std;

class List
{
protected:
	struct Node
	{
		Data data;
		Node* next;
	};

	Node* head;
	int count;

public:
	List();												//конструктор по умолчанию
	~List();											//деструктор
	void init(Node*& head);						 	//инициалиция
	bool isEmpty(Node* head);							//проверка на пустоту 
	void addToHead(Node*& head, Data elem);			//добавление в начало
	void addAfterNode(Node* pNode, Data elem);			//добавление после заданного элемента
	void deleteFromHead(Node*& head);					//удаление с начала списка 
	void deleteAfterNode(Node* pNode);					//удаление после заданного элемента 
	void clear(Node*& head);							//очистка списка 
	void printList();									//печать списка
	void print(Node* head);							//рекурсивная печать списка 	

	Node* getHead();									//получение значений полей класса
	int getCount();

	void createFromHead(Node*& head, ifstream& input);	//формирование списка в прямом порядке 
	void createFromTail(Node*& head);					//формирование списка в обратном порядке 
};
