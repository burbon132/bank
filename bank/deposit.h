#pragma once
#ifndef _DEPOSIT_H_
#define _DEPOSIT_H_
#include <fstream>
#include <iostream>
#include <stdlib.h>
struct Deposit
{
public:
	Deposit();
	Deposit(char* Name, char* LastName, char* TrainingDirection, int NumberGroup, int day, int month, int year);
	Deposit(char* Name, char* LastName, char* TrainingDirection, int NumberGroup, int day, int month, int year, int q);

	void SetName(char* Name);
	void SetLastName(char* LastName);
	void SetTrainingDirection(char* TrainingDirection);
	void SetNumderGroup(int NumderGroup);
	void SSetDay(int day);
	void SSetMonth(int month);
	void SSetYear(int year);

	char* GetName();
	char* GetLastName();
	char* GetTrainingDirection();
	int	  GetNumberGroup();
	int	  GGetDay();
	int	  GGetMonth();
	int	  GGetYear();

	friend ostream& operator<<(ostream& out, Deposit& student);

protected:
	char* Name = new char[15]; // Имя из 15 символов
	char* LastName = new char[15]; // Фамилия из 15 символов
	char* TrainingDirection = new char[5]; // Направление подготовки из 5 символов
	int   NumberGroup; // номер группы

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