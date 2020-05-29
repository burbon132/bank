#pragma once
#ifndef _DEPOSIT_H_
#define _DEPOSIT_H_
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <stdlib.h>
using namespace std;
struct Deposit
{
public:
	Deposit();
	Deposit(char* Name, char* LastName, double Money, int NumberCount, int day, int month, int year);
	Deposit(char* Name, char* LastName, double Money, int NumberCount, int day, int month, int year, int q);

	void SetName(char* Name);
	void SetLastName(char* LastName);
	void SetMoney(double Money);
	void SetNumberCount(int NumberCount);
	void SSetDay(int day);
	void SSetMonth(int month);
	void SSetYear(int year);

	char* GetName();
	char* GetLastName();
	double GetMoney();
	int	  GetNumberCount();
	int	  GGetDay();
	int	  GGetMonth();
	int	  GGetYear();

	friend ostream& operator<<(ostream& out, Deposit& student);

protected:
	char* Name = new char[15]; // Имя из 15 символов
	char* LastName = new char[15]; // Фамилия из 15 символов
	double Money; // Направление подготовки из 5 символов
	int NumberCount; // номер счёта

	class DataBir
	{
	public:
		int	 GetDay();
		int	 GetMonth();
		int	 GetYear();

		void SetDay(int day);
		void SetMonth(int month);
		void SetYear(int year);
	
		DataBir();
		DataBir(int day, int month, int year);
		private:
		int day;
		int month;
		int year;
	};
	DataBir BD;
};
#endif  // !_DEPOSIT_H_