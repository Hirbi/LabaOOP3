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
	// ����������� ������
	Storage(string name = "", float cost = 0, int amount = 0, int selection_number = 0, Date date = Date(0, 0, 0)) {
		this->name = name;
		this->cost = cost;
		this->amount = amount;
		this->section_number = selection_number;
		this->count = count;
		this->date = date;
		count++;
	}

	//��������� ������ ������
	bool compare_section_number(int section_number) {
		return this->section_number == section_number;
	}

	// ���������� ��������� ������������
	Storage& operator= (const Storage& right) {
		name = right.name;
		cost = right.cost;
		amount = right.amount;
		section_number = right.section_number;
		date = right.date;
		return *this;
	}

	// ���������� ��������� ���������
	friend int operator>(const Storage& left, const Date& right) {
		return left.date > right;
	}

	// ������������ ����
	void set_date(Date date) {
		this->date = date;
	}
	// ��������������� ����� ����
	void print_date(){
		date.date_output();
	}

	// ������� ���������� � �������
	void print_info() {
		cout << "��������    : " << name;
		cout << "\n���������   : " << cost;
		cout << "\n����������  : " << amount;
		cout << "\n����� ������: " << section_number;
		cout << "\n����        : ";
		date.date_output();
	}

	// ������ ���������� �� �������
	void set_info() {
		cout << "������� ��������: ";
		getline(cin, name);
		cout << "������� ���������: ";
		cin >> cost;
		cout << "������� ����������: ";
		cin >> amount;
		cout << "������� ����� ������: ";
		cin >> section_number;
		cout << "������� ���� � ������� \"�� �� ��\": ";
		cin >> date;
	}
};
