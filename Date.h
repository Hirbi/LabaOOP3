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
	// конструктор
	Date(int day = 0, int month = 0, int year = 0) {
		this->day = day;
		this->month = month;
		this->year = year;
	}

	// перегрузка оператора присваивани€
	Date& operator= (const Date& right) {
		day = right.day;
		month = right.month;
		year = right.year;
		return *this;
	}
	// перегрузка оператора >>
	friend istream& operator>> (istream& is, Date& right) {
		is >> right.day;
		is >> right.month;
		is >> right.year;
		return is;
	}

	// перегрузка оператора <<
	friend ostream& operator<< (ostream& os, const Date& right) {
		return os << right.day << " " << right.month << " " << right.year;
	}

	// перегрузка оператора сравнени€
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

	// форматированный вывод
	void date_output() {
		printf("%#02d:%#02d:%#02d", day, month, year);
	}
	// ввести информацию с консоли
	void set_info() {
		cout << "¬ведите день: ";
		cin >> day;
		cout << "\n¬ведите мес€ц: ";
		cin >> month;
		cout << "\n¬ведите год: ";
		cin >> year;
		cin.ignore();
	}
};
