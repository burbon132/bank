#include "List.h"

List::List()
{
	Size = 0;
	head = nullptr;
}

List::~List()
{
	clear();
}

void List::pop_front()
{
	Node* temp = head;
	head = head->pNext;
	delete temp;
	Size--;
}

void List::push_back(Deposit deposit)
{
	if (head == nullptr)
	{
		head = new Node(deposit);
	}
	else
	{
		Node* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node(deposit);
	}
	Size++;
}

void List::push_front(Deposit deposit)
{
	head = new Node(deposit, head);
	Size++;
}

void List::push_front_4_Read(Deposit& deposit)
{
	head = new Node(deposit, head);
	Size++;
}

void List::clear()
{
	while (Size)
	{
		pop_front();
	}
}

void List::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
		Size--;
	}
}

void List::pop_back()
{
	removeAt(Size - 1);
}

void List::Swap(List& lst, int index1, int index2)
{
	Deposit temp = lst[index1];
	lst[index1] = lst[index2];
	lst[index2] = temp;
}

Deposit& List::operator[](const int index)
{
	int counter = 0;
	Node* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->deposit;
		}
		current = current->pNext;
		counter++;
	}
}