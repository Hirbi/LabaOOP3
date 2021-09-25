#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Date.h"
using namespace std;


class Storage {
	friend void open_db(vector <Storage>& storage_list, string db_name);
	friend void table_output(vector <Storage>& storage_list);
	friend void close_db(vector <Storage>& storage_list, string db_name);
	friend bool cmp_amount_sort(Storage left, Storage right);
	string name;
	float cost;
	int amount;
	int section_number;
	Date date;
	int count = 0;
public:
	// конструктор класса
	Storage(string name = "", float cost = 0, int amount = 0, int selection_number = 0, Date date = Date(0, 0, 0)) {
		this->name = name;
		this->cost = cost;
		this->amount = amount;
		this->section_number = selection_number;
		this->count = count;
		this->date = date;
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
		amount = right.amount;
		section_number = right.section_number;
		date = right.date;
		return *this;
	}

	// перегрузка оператора сравнения
	friend int operator>(const Storage& left, const Date& right) {
		return left.date > right;
	}

	// присваивание даты
	void set_date(Date date) {
		this->date = date;
	}
	// форматированный вывод даты
	void print_date(){
		date.date_output();
	}

	// вывести информацию в консоль
	void print_info() {
		cout << "Название    : " << name;
		cout << "\nСтоимость   : " << cost;
		cout << "\nКоличество  : " << amount;
		cout << "\nНомер секции: " << section_number;
		cout << "\nДата        : ";
		date.date_output();
	}

	// ввести информацию из консоли
	void set_info() {
		cout << "Введите название: ";
		getline(cin, name);
		cout << "Введите стоимость: ";
		cin >> cost;
		cout << "Введите количество: ";
		cin >> amount;
		cout << "Введите номер секции: ";
		cin >> section_number;
		cout << "Введите дату в формате \"дд мм гг\": ";
		cin >> date;
	}
};
