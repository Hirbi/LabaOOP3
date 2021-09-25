#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <windows.h>
#include "Storage.h"
#include "Date.h"
using namespace std;


// ����� � ��������� ����
void table_output(vector <Storage>& storage_list) {
	cout << setw(18) << "��������" << "|";
	cout << setw(18) << "���������" << "|";
	cout << setw(18) << "��� ����������" << "|";
	cout << setw(18) << "����� �����������" << "|";
	cout << setw(18) << "��� �����������" << "|";
	cout << setw(18) << "��������� ������" << "|\n";
	for (int i = 0; i < storage_list.size(); i++)
	{
		cout << setw(18) << storage_list[i].name << "|";
		cout << setw(18) << storage_list[i].cost << "|";
		cout << setw(18) << storage_list[i].amount << "|";
		cout << setw(18) << storage_list[i].section_number << "|";
		// cout << setw(18) << storage_list[i].date << "|";
		cout << "\n";
		//���� ���������� ����������� ���������� ��������, ������� ��������� ��������� ��������� ������
	}
	return;
}

// ��������� ��
vector <Storage> open_db(string db_name) {
	fstream f(db_name);
	vector <Storage> storage_list;
	int size;
	f >> size;
	for (int i = 0; i < int(size); i++) {
		Storage x;
		// f >> x.ind1;
		storage_list.push_back(x);
	}
	f.close();
	return(storage_list);
}

//�������� ��
void close_db(vector <Storage>& storage_list, string db_name) {
	fstream f(db_name, ios::out);
	f << storage_list.size() << "\n";
	for (int i = 0; i < storage_list.size(); i++) {
		f << storage_list[i].name << "\n";
	}
	f.close();
}


// ����� ���� � �������
void menu() {
	cout << "\n����:\n";
	cout << "1 - ��� ������ ������ �� ���� ������� �� ������\n";
	cout << "2 - ��� ���������� ������ ������\n";
	// cout << "5 - ���������� �� ����\n";
	cout << "0 - �����\n";
}


// ���������� ��������� � �����
//bool operator>(const Storage& left, const Date& right) {
//	if (left.date.year > right.year)
	//	return left.date.year > right.year;
	//return true;
//}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector <Storage> storage_list;
	int is_stop;
	do {
		menu();
		cin >> is_stop;
		cin.ignore();
		switch (is_stop) {
		case 1:
			if (storage_list.size())
				table_output(storage_list);
			else
				cout << "� ���� ������ ������ ��� :(\n";
			break;
		
		default:
			cout << "���-�� �� ���, ��������";
			break;
		}
	} while (is_stop);
	cout << "�� �������, ��������";

}