#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Date.h"
using namespace std;


class Storage {
	friend vector <Storage> open_db(string);
	friend void table_output(vector <Storage>&);
	friend void close_db(vector <Storage>&, string);
	string name;
	float cost;
	int amount;
	int section_number;
	Date date;
	int count = 0;
public:
	// конструктор к
	Storage(string name = "", int cost = 0, float amount = 0, int selection_number = 0) {
		this->name = name;
		this->cost = cost;
		this->amount = amount;
		this->section_number = selection_number;
		this->count = count;
		count++;
	}

	//сравнение номера секции
	bool compare_section_number(int section_number) {
		return this->section_number == section_number;
	}

	// перегрузка оператора присваивания
	Storage& operator= (const Storage& right) {
		name = right.name;
		cost = right.cost;
		amount = right.cost;
		section_number = right.section_number;
		date = right.date;
		return *this;
	}

	// присваивание даты
	void set_date(Date date) {
		this->date = date;
	}

	void print_info() {
		cout << "Название    : " << name;
		cout << "\nСтоимость   : " << cost;
		cout << "\nКоличество  : " << amount;
		cout << "\nНомер секции: " << section_number;
		cout << "\nДата        : ";
		date.date_output();
	}

	void set_info() {
		cout << "Введите название: ";
		getline(cin, name);
		cout << "\nВведите стоимость: ";
		cin >> cost;
		cout << "\nВведите количество: ";
		cin >> amount;
		cout << "\nВведите номер секции: ";
		cin >> section_number;
		cin.ignore();
		date.set_info();
	}
};
