#pragma once
#ifndef _LIST_H_
#define _LIST_H_
#define _CRT_SECURE_NO_WARNINGS
#include "deposit.h"
class List
{
public:
	List();
	~List();

	//удаление первого элемента в списке
	void pop_front();

	//добавление элемента в конец списка
	void push_back(Deposit deposit);

	// очистить список
	void clear();

	// получить количество елементов в списке
	int GetSize() { return Size; }

	// перегруженный оператор [] 
	Deposit& operator[](const int index);

	//добавление элемента в начало списка
	void push_front(Deposit deposit);

	//удаление элемента в списке по указанному индексу
	void removeAt(int index);

	//удаление последнего элемента в списке
	void pop_back();

	//ћен€ет элементы списка местами
	void Swap(List& lst, int index1, int index2);

	//добавление элемента в начало списка дл€ чтени€ с диска
	void push_front_4_Read(Deposit& deposit);

private:
	class Node
	{
	public:
		Node* pNext;
		Deposit deposit;
		Node(Deposit deposit = Deposit(), Node* pNext = nullptr)
		{
			this->deposit = deposit;
			this->pNext = pNext;
		}
	};
	friend void SortList(List& lst);
	int Size;
	Node* head;
};
#endif // !_LIST_H_