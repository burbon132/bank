#include "deposit.h"

Deposit::Deposit()
{
	strcpy(this->Name, "Unknown");
	strcpy(this->LastName, "Unknown");
	this->Money = 0.0;
	this->NumberCount = 0;
	Deposit::DataBir::DataBir();
}

Deposit::Deposit(char* Name, char* LastName, double Money, int NumberCount, int day, int month, int year)
{
	this->Name = Name;
	this->LastName = LastName;
	this->Money = Money;
	this->NumberCount = NumberCount;
	BD.SetDay(day);
	BD.SetMonth(month);
	BD.SetYear(year);
}

Deposit::Deposit(char* Name, char* LastName, double Money, int NumberCount, int day, int month, int year, int q)
{
	char* arrN = new char[strlen(Name) + 1];
	for (int i = 0; i < strlen(Name) + 1; i++) { arrN[i] = Name[i]; }
	char* arrLN = new char[strlen(LastName) + 1];
	for (int i = 0; i < strlen(LastName) + 1; i++) { arrLN[i] = LastName[i]; }
	this->Name = arrN;
	this->LastName = arrLN;
	this->Money = Money;
	this->NumberCount = NumberCount;
	BD.SetDay(day);
	BD.SetMonth(month);
	BD.SetYear(year);
}

Deposit::DataBir::DataBir()
{
	this->day = 1;
	this->month = 1;
	this->year = 1970;
}

Deposit::DataBir::DataBir(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

//////////////////////////////////////////////////////////////SETTERS/////////////////////////////////////////////////////////////////

void Deposit::SetName(char* Name)
{
	this->Name = Name;
}

void Deposit::SetLastName(char* LastName)
{
	this->LastName = LastName;
}

void Deposit::SetMoney(double Money)
{
	this->Money = Money;
}

void Deposit::SetNumberCount(int NumberCount)
{
	this->NumberCount = NumberCount;
}

void Deposit::SSetDay(int day)
{
	this->BD.SetDay(day);
}

void Deposit::SSetMonth(int month)
{
	this->BD.SetDay(month);
}

void Deposit::SSetYear(int year)
{
	this->BD.SetDay(year);
}

void Deposit::DataBir::SetDay(int day)
{
	this->day = day;
}

void Deposit::DataBir::SetMonth(int month)
{
	this->month = month;
}

void Deposit::DataBir::SetYear(int year)
{
	this->year = year;
}

//////////////////////////////////////////////////////////////GETTERS/////////////////////////////////////////////////////////////////

char* Deposit::GetName()
{
	return this->Name;
}

char* Deposit::GetLastName()
{
	return this->LastName;
}

double Deposit::GetMoney()
{
	return this->Money;
}

int Deposit::GetNumberCount()
{
	return this->NumberCount;
}

int Deposit::GGetDay()
{
	return BD.GetDay();
}

int Deposit::GGetMonth()
{
	return BD.GetMonth();
}

int Deposit::GGetYear()
{
	return BD.GetYear();
}

int Deposit::DataBir::GetDay()
{
	return this->day;
}

int Deposit::DataBir::GetMonth()
{
	return this->month;
}

int Deposit::DataBir::GetYear()
{
	return this->year;
}

/////////////////////////////////////////////////////////////OPERATORS/////////////////////////////////////////////////////////////////

ostream& operator<<(ostream& out, Deposit& student)
{
	out << "Студент:" << endl << student.GetLastName() << endl << student.GetName() << endl << student.GetMoney() << endl << student.GetNumberCount() << endl << student.BD.GetDay() << "." << student.BD.GetMonth() << "." << student.BD.GetYear() << endl << endl;
	return out;
}