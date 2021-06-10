#include "globals.hpp"
using namespace std;

void menu() {
	cout << "\n1) Добавить элемент в ЛДС\n";
	cout << "2) Удалить элемент из ЛДС\n";
	cout << "3) Вывести ЛДС\n";
	cout << "0) Выйти из программы\n\n";
}

void err() {
	cout << "\nТакая команда не найдена!\n";
}