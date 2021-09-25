#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Storage.h"
using namespace std;


class Date {

	friend class Storage;
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
	// ���������� ��������� >>
	friend istream& operator>> (istream& is, Date& right) {
		is >> right.day;
		is >> right.month;
		is >> right.year;
		return is;
	}

	// ���������� ��������� <<
	friend ostream& operator<< (ostream& os, const Date& right) {
		return os << right.day << " " << right.month << " " << right.year;
	}

	// ���������� ��������� ���������
	friend int operator>(const Date& left, const Date& right) {
		if (left.year > right.year)
			return true;
		else if (left.year == right.year)
			if (left.month > right.month)
				return true;
			else if (left.month == right.month && left.day > right.day)
				return true;
		return false;
	}

	// ��������������� �����
	void date_output() {
		printf("%#02d:%#02d:%#02d", day, month, year);
	}
	// ������ ���������� � �������
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
