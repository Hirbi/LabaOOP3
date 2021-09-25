#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <windows.h>
#include "Storage.h"
#include "Date.h"
#include <algorithm>
using namespace std;


// вывод в табличном виде
void table_output(vector <Storage>& storage_list) {
	cout << setw(18) << "Название" << "|";
	cout << setw(18) << "Стоимость" << "|";
	cout << setw(18) << "Количество" << "|";
	cout << setw(18) << "Номер секции" << "|";
	cout << setw(18) << "Дата" << "|\n";
	for (int i = 0; i < storage_list.size(); i++)
	{
		cout << setw(18) << storage_list[i].name << "|";
		cout << setw(18) << storage_list[i].cost << "|";
		cout << setw(18) << storage_list[i].amount << "|";
		cout << setw(18) << storage_list[i].section_number << "|";
		cout << setw(10) << " ";
		storage_list[i].print_date();
		cout << "|\n";
	}
	return;
}

// обработка БД
void open_db(vector <Storage>& storage_list, string db_name) {
	fstream f(db_name);
	// vector <Storage> storage_list;
	int size;
	f >> size;
	f.ignore();
	for (int i = 0; i < int(size); i++) {
		Storage x;
		getline(f, x.name);
		// f >> x.name;
		f >> x.cost;
		f >> x.amount;
		f >> x.section_number;
		f >> x.date;
		f.ignore();
		//x.set_date(Date(day, month, year));
		storage_list.push_back(x);
	}
	f.close();
	// return(storage_list);
}

//закрытие БД
void close_db(vector <Storage>& storage_list, string db_name) {
	fstream f(db_name, ios::out);
	f << storage_list.size() << "\n";
	for (int i = 0; i < storage_list.size(); i++) {
		f << storage_list[i].name << "\n";
		f << storage_list[i].cost << "\n";
		f << storage_list[i].amount << "\n";
		f << storage_list[i].section_number << "\n";
		f << storage_list[i].date << "\n";
	}
	f.close();
}

// компаратор для сортировки
bool cmp_amount_sort(Storage left, Storage right) {
	return left.amount < right.amount;
}

// вывод меню в консоль
void menu() {
	cout << "\nМеню:\n";
	cout << "1 - вывод данных по всем товарам на складе\n";
	cout << "2 - добавление данных товара\n";
	cout << "3 - поиск по номеру секции\n";
	cout << "4 - сортировка по количеству\n";
	cout << "5 - поиск товаров поступивших после даты\n";
	cout << "0 - выход\n";
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Здравствуй, юзернейм";
	vector <Storage> storage_list, storage_later_date;
	Storage box;
	Date date;
	int section_number;
	bool not_found;
	string db_name = "db.txt";
	open_db(storage_list, db_name);	
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
				cout << "В базе данных ничего нет :(\n";
			break;
		case 2:
			box.set_info();
			storage_list.push_back(box);
			break;
		case 3:
			not_found = true;
			cout << "Введите номер секции для поиска:\n";
			cin >> section_number;
			cout << "Товары в секции " << section_number << ":\n";
			for (int i = 0; i < storage_list.size(); i++) {
				if (storage_list[i].compare_section_number(section_number)) {
					storage_list[i].print_info();
					not_found = false;
				}
			}
			if (not_found)
				cout << "Не найдены :(";
			break;
		case 4:
			sort(storage_list.begin(), storage_list.end(), cmp_amount_sort);
			cout << "Сортировка прошла успешно.\n";
			break;
		case 5:
			storage_later_date.clear();
			cout << "Введите дату в формате \"дд мм гг\": ";
			cin >> date;
			cout << "Товары поступившие после ";
			date.date_output();
			cout << ":\n";
			for (int i = 0; i < storage_list.size(); i++) {
				if (storage_list[i] > date) {
					storage_later_date.push_back(storage_list[i]);
					storage_list[i].print_info();
					cout << "\n\n";
				}
			}
			break;
		case 0:
			close_db(storage_list, db_name);
			break;
		default:
			cout << "Что-то не так, юзернейм";
			break;
		}
	} while (is_stop);
	cout << "До встречи, юзернейм";
}