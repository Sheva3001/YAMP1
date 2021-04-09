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
	List();												//����������� �� ���������
	~List();											//����������
	void init(Node*& head);						 	//�����������
	bool isEmpty(Node* head);							//�������� �� ������� 
	void addToHead(Node*& head, Data elem);			//���������� � ������
	void addAfterNode(Node* pNode, Data elem);			//���������� ����� ��������� ��������
	void deleteFromHead(Node*& head);					//�������� � ������ ������ 
	void deleteAfterNode(Node* pNode);					//�������� ����� ��������� �������� 
	void clear(Node*& head);							//������� ������ 
	void printList();									//������ ������
	void print(Node* head);							//����������� ������ ������ 	

	Node* getHead();									//��������� �������� ����� ������
	int getCount();

	void createFromHead(Node*& head, ifstream& input);	//������������ ������ � ������ ������� 
	void createFromTail(Node*& head);					//������������ ������ � �������� ������� 
};
