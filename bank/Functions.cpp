#include "Functions.h"


void MoneyCheck(List& lst, double Money)
{
	for (int i = 0; i < lst.GetSize(); i++) {
		if (lst[i].GetMoney() > Money) {
			cout << lst[i];
		}
	}
}

void SearchByHuman(List& lst, List& newlst, char* Name, char* LastName)
{
	for (int i = 0; i < lst.GetSize(); i++)
	{
		if ((strcmp(lst[i].GetName(), Name) == 0) && (strcmp(lst[i].GetLastName(), LastName) == 0))
		{
			newlst.push_front(lst[i]);
			cout << lst[i];
		}

	}
}

void DeleteByMoney(List& lst, double Money)
{
	for (int i = 0; i < lst.GetSize(); i++)
	{
		if (lst[i].GetMoney() < Money)
		{
			lst.removeAt(i);
		}
	}
}

void CheckDate(List& lst, int Date)
{
	for (int i = 0; i < lst.GetSize(); i++)
	{
		if (Date < lst[i].GGetYear() * 10000 + lst[i].GGetMonth() * 100 + lst[i].GGetDay())
		{
			cout << lst[i];
		}
	}
	cout << endl;
}

void SortList(List& lst)
{
	int k = 0;
	for (int i = 0; i < lst.GetSize() - 1; i++)
	{
		for (int j = i; j < lst.GetSize() - 1; j++)
		{
			char* st1 = lst[j].GetLastName();
			char* st2 = lst[j + 1].GetLastName();
			if ((int)st1[0] > (int)st2[0])
			{
				lst.Swap(lst, j, j + 1);
			}
			if ((int)st1[0] == (int)st2[0])
			{
				while ((int)st1[k] == (int)st2[k])
				{
					k++;
				}
				if ((int)st1[k] > (int)st2[k]) {
					lst.Swap(lst, j, j + 1);
				}
			}
			k = 0;
		}
		k = 0;
	}
}

void Save2Disk(List& lst)
{
	string path;
	cout << "������� �������� �����" << endl;
	cin >> path;
	ofstream fout;
	fout.open(path);
	for (int i = 0; i < lst.GetSize(); i++)
	{
		fout.write(lst[i].GetName(), strlen(lst[i].GetName()));
		if (strlen(lst[i].GetName()) < 8) {
			fout << "\t";
		}
		fout << "\t";

		fout.write(lst[i].GetLastName(), strlen(lst[i].GetLastName()));
		if (strlen(lst[i].GetLastName()) < 8) {
			fout << "\t";
		}
		fout << "\t";

		fout << lst[i].GetMoney() << "\t";
		fout << "\t";
		fout << lst[i].GetNumberCount() << "\t";
		fout << lst[i].GGetDay() << ".";
		fout << lst[i].GGetMonth() << ".";
		fout << lst[i].GGetYear() << endl;
	}
	fout.close();
	cout << endl;
}

void Read4Disk(List& lst)
{
	cout << "������� ���� � �������� �����" << endl << endl;
	string path;
	cin >> path;
	ifstream fin;
	fin.open(path);
	int i = 0, j = 0;;
	char* Name = new char;
	char* LastName = new char;
	char trash;
	double Money;
	int NumberCount;
	int day;
	int month;
	int year;
	while (!fin.eof())
	{
		fin >> Name >> LastName >> Money >> NumberCount >> day >> trash >> month >> trash >> year;
		if (strcmp(Name, "") == 0)
			break;
		lst.push_front(Deposit(Name, LastName, Money, NumberCount, day, month, year, 0));
	}
	fin.close();
	cout << endl;
}

/*
void MainInterface()
{
	int MenuBtn;
	while (true)
	{
		cout << "������� ����� ������� ������ ����:" << endl << endl;
		cout << "1) ������� ����� ������ ���������" << endl;
		cout << "2) ��������� ������ � �����" << endl;
		cout << "3) ����� �� ���������" << endl << endl;

		cin >> MenuBtn;
		switch (MenuBtn)
		{
		case(1):
		{
			system("cls");
			List lst;
			OptionalInterface(lst);
			break;
		}
		case(2):
		{
			system("cls");
			List lst;
			Read4Disk(lst);
			system("cls");
			OptionalInterface(lst);
			break;
		}
		case(3):
		{
			exit(1);
		}
		default:
			cout << "ERROR404: ����� �� ������� xDD" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}
*/

void OptionalInterface()
{
	system("cls");
	bool sas = true;
	int MenuBtn;
	List lst;
	while (sas)
	{
		cout << "����� ������ ������ ���������? ������� � �����:" << endl << endl;
		cout << "1) �������� ����" << endl;
		cout << "2) ������� ����" << endl;
		cout << "3) ����������� ������ �� ��������" << endl;
		cout << "4) ����� ��� ����� ��������� �������(�� ����� � �������)" << endl;
		cout << "5) ���������� ��� ����� � ������ ������ ��������" << endl;
		cout << "6) ����� � ������� ��� ����� � ������ ������ ��������" << endl;
		cout << "7) ����� ��� ����� �������� ����� �������� ����" << endl;
		cout << "8) ��������� ������" << endl;
		cout << "9) ������� ������" << endl;
		cout << "10) �������� ������" << endl;
		cout << "11) ����� �� ���������" << endl << endl;

		cin >> MenuBtn;
		switch (MenuBtn)
		{
		case(1):
		{
			system("cls");
			int counter;
			char* Name = new char;
			char* LastName = new char;
			char trash;
			double Money;
			int NumberCount;
			int day;
			int month;
			int year;
			cout << "����� ���������� ������ ������ ��������?" << endl << endl; cin >> counter;
			system("cls");
			cout << "������� ������ � �����" << endl;
			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);
			for (int i = 0; i < counter; i++)
			{

				cout << "�������: "; cin >> LastName;
				cout << "���: "; cin >> Name;
				cout << "����� �� �����: "; cin >> Money;
				cout << "����� �����: "; cin >> NumberCount;
				cout << "���� �������� ����� (��.��.����) "; cin >> day >> trash >> month >> trash >> year;
				lst.push_front(Deposit(Name, LastName, Money, NumberCount, day, month, year, 0));
				system("pause");
				system("cls");
			}
			SetConsoleCP(866);
			SetConsoleOutputCP(866);
			break;
		}
		case(2):
		{
			if (lst.GetSize() != 0)
			{
				system("cls");
				for (int i = 0; i < lst.GetSize(); i++) {
					cout << "���������� �����: " << i << endl << lst[i];

				}
				int index;
				cout << "������� ���������� ����� ����� ��� ��� �������� "; cin >> index;
				lst.removeAt(index);
				cout << "������� ���������" << endl;
				system("pause");
				system("cls");
				break;
			}
			else
			{
				system("cls");
				cout << "����� �����������" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		case(3):
		{
			if (lst.GetSize() != 0)
			{
				SortList(lst);
				break;
			}
			else
			{
				system("cls");
				cout << "����� �����������" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		case(4):
		{
			if (lst.GetSize() != 0)
			{
				system("cls");
				char* SearchName = new char;
				char* SearchLastName = new char;
				List newlst;
				SetConsoleCP(1251);
				SetConsoleOutputCP(1251);
				cout << "���: "; cin >> SearchName;
				cout << "�������: "; cin >> SearchLastName;
				SearchByHuman(lst, newlst, SearchName, SearchLastName);
				SetConsoleCP(866);
				SetConsoleOutputCP(866);
				Save2Disk(newlst);
				system("pause");
				system("cls");
				break;
			}
			else
			{
				system("cls");
				cout << "����� �����������" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		case(5):
		{
			if (lst.GetSize() != 0)
			{
				system("cls");
				double NeedfulMoney;
				cout << "������� �����" << endl;
				cin >> NeedfulMoney;
				MoneyCheck(lst, NeedfulMoney);
				system("pause");
				system("cls");
				break;
			}
			else
			{
				system("cls");
				cout << "����� �����������" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		case(6):
		{
			if (lst.GetSize() != 0)
			{

				system("cls");
				double NeedfulMoney;
				cout << "������� �����" << endl;
				cin >> NeedfulMoney;
				DeleteByMoney(lst, NeedfulMoney);
				system("pause");
				system("cls");
				break;
			}
			else
			{
				system("cls");
				cout << "����� �����������" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		case(7):
		{
			if (lst.GetSize() != 0)
			{

				system("cls");
				int Day;
				int Month;
				int Year;
				int Number;
				char trash;
				cout << "������� ���� �������� �����(��.��.����)" << endl;
				cin >> Day >> trash >> Month >> trash >> Year;
				Number = Year * 10000 + Month * 100 + Day;
				CheckDate(lst, Number);
				system("pause");
				system("cls");
				break;
			}
			else
			{
				system("cls");
				cout << "����� �����������" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		case(8):
		{
			system("cls");
			List lst;
			Read4Disk(lst);
			system("cls");
			break;
		}
		case(9):
		{
			if (lst.GetSize() != 0)
			{
				system("cls");
				for (int i = 0; i < lst.GetSize(); i++) {
					cout << lst[i];
				}
				system("pause");
				system("cls");
				break;
			}
			else
			{
				system("cls");
				cout << "����� �����������" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		case(10):
		{
			if (lst.GetSize() != 0)
			{
				system("cls");
				lst.clear();
				cout << "�������\n" << endl;
				system("pause");
				system("cls");
				break;
			}
			else
			{
				system("cls");
				cout << "����� �����������" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		case(11):
		{
			system("cls");
			Save2Disk(lst);
			sas = false;
			break;
		}
		default:
			system("cls");
			cout << "������� �� �������" << endl;
			system("pause");
			system("cls");
			break;
		}

	}
}