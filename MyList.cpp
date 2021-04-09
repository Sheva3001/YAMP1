#include "MyList.h"
#include <iostream>
#include <fstream>

using namespace std;

List::List() : head(0), count(0) {};

List::~List()
{
	//clear(head); 
}

void List::init(Node*& head)
{
	head = NULL;
}

bool List::isEmpty(Node* head)
{
	return head == 0;
}

void List::addToHead(Node*& head, Data elem)
{
	Node* p = new Node;
	p->data = elem;
	p->next = head;
	head = p;
}

void List::addAfterNode(Node* pNode, Data elem)
{
	Node* p = new Node;
	p->data = elem;
	p->next = pNode->next;
	pNode->next = p;
}

void List::deleteFromHead(Node*& head)
{
	Node* p = head;
	head = head->next;
	p->next = 0;
	delete p;
}

void List::deleteAfterNode(Node* pNode)
{
	if (pNode != 0)
	{
		Node* p = pNode->next;
		pNode->next = p->next;
		p->next = 0;
		delete p;
	}
}

void List::clear(Node*& head)
{
	while (!isEmpty(head))
		deleteFromHead(head);
	delete head;
}

void List::printList()
{
	Node* p = head;
	while (p != NULL)
	{
		cout << p->data << endl;
		p = p->next;
	}
}

void List::print(Node* head)
{
	if (head == 0)
		cout << endl;
	else
	{
		cout << head->data << " "; //используем перегрузку вывода
		print(head->next);
	}
}

List::Node* List::getHead()
{
	return head;
}

int List::getCount()
{
	return count;
}

void List::createFromHead(Node*& head, ifstream& input)
{
	init(head);
	Data elem;
	while (input >> elem)			//используем перегрузку ввода 
		addToHead(head, elem);
}

void List::createFromTail(Node*& head)
{
	init(head);
	Node* tail = head;
	int n;
	cout << "¬ведите количество элементов: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		Data elem;
		cout << endl << "¬ведите элемент: ";
		cin >> elem;
		if (isEmpty(head))
		{
			addToHead(head, elem);
			tail = head;
		}
		else
		{
			addAfterNode(tail, elem);
			tail = tail->next;
		}
	}
}