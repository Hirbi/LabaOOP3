#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Storage.h"
using namespace std;


class Date {
	// friend bool operator>(const Storage& left, const Date& right);
	friend class Storage;
	friend void close_db(vector <Storage>&, string);
	friend void table_output(vector <Storage>&);
	// friend vector <Storage> open_db(string);
	int day;
	int month;
	int year;
public:
	// �����������
	Date(int day = 0, int month = 0, int year = 0) {
		this->day = day;
		this->month = month;
		this->year = year;
	}
	// ���������� ��������� ������������
	Date& operator= (const Date& right) {
		day = right.day;
		month = right.month;
		year = right.year;
		return *this;
	}
	friend ostream& operator<< (ostream& os, const Date& right) {
		return os << right.day << " " << right.month << " " << right.year;
	}
	// ��������������� �����
	void date_output() {
		printf("%#02d:%#02d:%#02d\n", day, month, year);
	}
	void set_info() {
		cout << "������� ����: ";
		cin >> day;
		cout << "\n������� �����: ";
		cin >> month;
		cout << "\n������� ���: ";
		cin >> year;
		cin.ignore();
	}
};
