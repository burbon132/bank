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

	//�������� ������� �������� � ������
	void pop_front();

	//���������� �������� � ����� ������
	void push_back(Deposit deposit);

	// �������� ������
	void clear();

	// �������� ���������� ��������� � ������
	int GetSize() { return Size; }

	// ������������� �������� [] 
	Deposit& operator[](const int index);

	//���������� �������� � ������ ������
	void push_front(Deposit deposit);

	//�������� �������� � ������ �� ���������� �������
	void removeAt(int index);

	//�������� ���������� �������� � ������
	void pop_back();

	//������ �������� ������ �������
	void Swap(List& lst, int index1, int index2);

	//���������� �������� � ������ ������ ��� ������ � �����
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