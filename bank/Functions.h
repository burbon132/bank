#pragma once
#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_
#define _CRT_SECURE_NO_WARNINGS
#include "List.h"
#include "deposit.h"
#include <stdlib.h>
#include <Windows.h>
using namespace std;
void MoneyCheck(List& lst, double Money);
void SearchByHuman(List& lst,List& newlst, char* Name, char* LastName);
void DeleteByMoney(List& lst, double Money);
void CheckDate(List& lst, int Date);
void SortList(List& lst);
void Save2Disk(List& lst);
void Read4Disk(List& lst);
//void MainInterface();
void OptionalInterface();
#endif // !_FUNCTIONS_N_