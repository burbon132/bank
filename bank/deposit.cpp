#include "deposit.h"

Deposit::Deposit()
{
	this->Name = "Unknown";
	this->LastName = "Unknown";
	this->TrainingDirection = "Unknown";
	this->NumberGroup = 0;
	Deposit::DataBir::DataBir();
}

Deposit::Deposit(char* Name, char* LastName, char* TrainingDirection, int NumberGroup, int day, int month, int year)
{
	this->Name = Name;
	this->LastName = LastName;
	this->TrainingDirection = TrainingDirection;
	this->NumberGroup = NumberGroup;
	BD.SetDay(day);
	BD.SetMonth(month);
	BD.SetYear(year);
}

Deposit::Deposit(char* Name, char* LastName, char* TrainingDirection, int NumberGroup, int day, int month, int year, int q)
{
	char* arrN = new char[strlen(Name) + 1];
	for (int i = 0; i < strlen(Name) + 1; i++) { arrN[i] = Name[i]; }
	char* arrLN = new char[strlen(LastName) + 1];
	for (int i = 0; i < strlen(LastName) + 1; i++) { arrLN[i] = LastName[i]; }
	char* arrTD = new char[strlen(TrainingDirection) + 1];
	for (int i = 0; i < strlen(TrainingDirection) + 1; i++) { arrTD[i] = TrainingDirection[i]; }
	this->Name = arrN;
	this->LastName = arrLN;
	this->TrainingDirection = arrTD;
	this->NumberGroup = NumberGroup;
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

void Deposit::SetTrainingDirection(char* TrainingDirection)
{
	this->TrainingDirection = TrainingDirection;
}

void Deposit::SetNumderGroup(int NumderGroup)
{
	this->NumberGroup = NumberGroup;
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

char* Deposit::GetTrainingDirection()
{
	return this->TrainingDirection;
}

int Deposit::GetNumberGroup()
{
	return this->NumberGroup;
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
	out << "Студент:" << endl << student.GetLastName() << endl << student.GetName() << endl << student.GetTrainingDirection() << endl << student.GetNumberGroup() << endl << student.BD.GetDay() << "." << student.BD.GetMonth() << "." << student.BD.GetYear() << endl << endl;
	return out;
}