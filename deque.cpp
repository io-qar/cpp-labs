#include <iostream>
using namespace std;

void menu() {
	cout << "\n1) Добавить элемент в дек\n";
	cout << "2) Удалить элемент из дека\n";
	cout << "3) Вывести дек слева направо\n";
	cout << "0) Выйти из программы\n\n";
}

void err() {
	cout << "\nТакая команда не найдена\n";
}

struct Elem {
	int inf;
	Elem *next = NULL;
	Elem *prev = NULL;
};

class Deque {
private:
	Elem *first, *last;
public:
	Deque() {
		first = NULL;
		last = NULL;
	}
	
	Elem *find(int x) {
		Elem *temp = new Elem;
		Elem *out = new Elem;
		
		temp = first;
		while (temp != NULL) {
			if (temp->inf == x) {
				out = temp;
				return out;
			}
			temp = temp->next;
		}
		return NULL;
	}
	
	bool bool_find(int x) {
		Elem *temp = new Elem;
		bool t = false;
		temp = first;
		
		while (temp != NULL) {
			if (temp->inf == x) t = true;
			temp = temp->next;
		}
		
		return t;
	}
	
	Elem *next(int val) {
		Elem *p = first;
		while (p->inf != val) p = p->next;
		return p;
	}
	
	void add_first(int elem) {
		if (first == NULL) {
			first = (last = new Elem());
			fisrt->inf = (last->inf = elem);
		} else {
			Elem *frst = new Elem();
			frst->inf = elem;
			frst->next = first;
			first->prev = frst;
			first = frst;
		}
	}
	
	void add_last(int elem) {
		
	}
}
