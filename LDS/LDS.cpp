#include "LDS.hpp"
#include "globals.hpp"
using namespace std;

LDS::LDS() {
	first = nullptr;
	last = nullptr;
}

Elem *LDS::find(int x) {
	Elem *temp = new Elem;
	Elem *out = new Elem;
	temp = first;
	while (temp != nullptr) {
		if (temp->inf == x) {
			out = temp;
			return out;
		}
		temp = temp->next;
	}
	return nullptr;
}

bool LDS::boolFind(int x) {
	Elem *temp = new Elem;
	bool t = false;
	temp = first;
	while (temp != nullptr) {
		if (temp->inf == x) t = true;
		temp = temp->next;
	}
	return t;
}

Elem* LDS::next(int val){
	Elem *p = first;
	while (p->inf != val) p = p->next;
	return p;
}

void LDS::add_first(int elem) {
	if (first == nullptr) {
		first = (last = new Elem());
		first->inf = (last->inf = elem);
	}
	else {
		Elem *frst = new Elem();
		frst->inf = elem;
		frst->next = first;
		first->prev = frst;
		first = frst;
	}
}

void LDS::add_last(int elem) {
	if (first == nullptr) {
		first = (last = new Elem());
		first->inf = (last->inf = elem);
	}
	else {
		Elem *lst = new Elem();
		lst->inf = elem;
		lst->prev = last;
		last->next = lst;
		last = lst;
	}
}

void LDS::add(int x, Elem *next) {
	Elem *temp = new Elem;
	Elem *p = new Elem;
	p = next->next;
	next->next = temp;
	temp->inf = x;
	temp->next = p;
	temp->prev = next;
	if (p != nullptr) p->prev = temp;
}

void LDS::del_first() {
	if (first == nullptr) return;
	if (first == last) {
		first = (last = nullptr);
		return;
	}
	first = (first->next);
	delete first->prev;
	first->prev = nullptr;
}

void LDS::del_last() {
	if (first == last) {
		first = (last = nullptr);
		return;
	}
	last = last->prev;
	delete last->next;
	last->next = nullptr;
}

void LDS::del(int x) {
	Elem *temp = first;
	while (temp->inf != x) temp = temp->next;
	if (temp == nullptr) return;

	Elem *prev = temp->prev;
	Elem *next = temp->next;
	if (prev != nullptr) prev->next = next;
	if (next != nullptr) next->prev = prev; 
	delete temp;
}

void LDS::print() {
	Elem *temp = first;
	if (temp != nullptr) {
		while (temp != nullptr) {
			cout << temp->inf << " ";
			temp = temp->next;
		}
	}
	else cout << "ЛДС пуст!\n";
}

void LDS::choice() {
	int cmd, cmd2;
	cout << "Введите номер команды: ";
	cin >> cmd;

	if (cmd == 1) {
		cout << "Введите значение нового элемента ЛДС: ";
		int val;
		cin >> val;

		cout << "\t1) Добавить это значение в начало ЛДС\n";
		cout << "\t2) Добавить это значение в конец ЛДС\n";
		cout << "\t3) Добавить это значение перед существующим элементом ЛДС\n";
		cout << "Введите номер команды: ";

		cin >> cmd2;
		if (cmd2 == 1) {
			cout << "\t\t1) Добавить это значение в начало ЛДС слева\n";
			cout << "\t\t2) Добавить это значение в начало ЛДС справа\n";

			int cmd3;
			cout << "Введите номер команды: ";
			cin >> cmd3;

			if (cmd3 == 1) {
				this->add_first(val);
				cout << "Новый элемент добавлен!\n";
			}
			if (cmd3 == 2) {
				this->add_last(val);
				cout << "Новый элемент добавлен!\n";
			}
			else if (cmd3 != 1 && cmd3 != 2) err();
		}
		else if (cmd2 == 2) {
			cout << "\t\t1) Добавить это значение в конец ЛДС слева\n";
			cout << "\t\t2) Добавить это значение в конец ЛДС справа\n";

			int cmd3;
			cout << "Введите номер команды: ";
			cin >> cmd3;

			if (cmd3 == 1) {
				this->add_last(val);
				cout << "Новый элемент добавлен!\n";
			}
			if (cmd3 == 2) {
				this->add_first(val);
				cout << "Новый элемент добавлен!\n";
			}
			else if (cmd3 != 1 && cmd3 != 2) err();
		}
		else if (cmd2 == 3) {
			print();
			cout << "\t\tПеред каким элементом вы хотите добавить новое значение?\n";
			
			int val2;
			cin >> val2;
			this->add(val, find(val2));
			cout << "\t\tНовый элемент добавлен!\n";
		}
		
		val = 0;
		cmd2 = 0;
		menu();
		choice();
	}

	if (cmd == 2) {
		if (first != nullptr) {
			cout << "\t1) Удалить первый элемент из ЛДС\n";
			cout << "\t2) Удалить последний элемент из ЛДС\n";
			cout << "\t3) Удалить элемент по значению\n";
			cout << "Введите номер команды: ";
			cin >> cmd2;

			if (cmd2 == 1) {
				cout << "\t\t1) Удалить первый элемент слева\n";
				cout << "\t\t2) Удалить первый элемент справа\n";
				cout << "Введите номер команды: ";

				int cmd3;
				cin >> cmd3;

				if (cmd3 = 1) {
					this->del_first();
					cout << "Выбранный элемент удалён!\n";
				}
				else if (cmd3 == 2) {
					this->del_last();
					cout << "Выбранный элемент удалён!\n";
				}
				else if (cmd3 != 1 && cmd3 != 2) err();
			}

			else if (cmd2 == 2){
				cout << "\t1) Удалить последний элемент слева\n";
				cout << "\t2) Удалить последний элемент справа\n";
				cout << "Введите номер команды: ";

				int cmd3;
				cin >> cmd3;

				if (cmd3 = 1) {
					this->del_last();
					cout << "Выбранный элемент удалён!\n";
				}
				else if (cmd3 == 2) {
					this->del_first();
					cout << "Выбранный элемент удалён!\n";
				}
				else if (cmd3 != 1 && cmd3 != 2) err();
			}

			else if (cmd2 == 3) {
				cout << "\tВведите значение элемента, которое хотите удалить: ";
				int val;
				cin >> val;

				if (boolFind(val)) {
					del(val);
					cout << "Выбранный элемент удалён!\n";
				}
				else cout << "Элемента с таким значением не найдено!\n";
			}
		}
		else cout << "ЛДС пуст!\n";
		menu();
		choice();
	}

	if (cmd == 3) {
		this->print();
		menu();
		choice();
	}
}