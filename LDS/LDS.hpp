#pragma once
#include <iostream>

struct Elem {
	int inf;
	Elem *next = nullptr;
	Elem *prev = nullptr;
};

class LDS {
private:
	Elem *first, *last;
public:
	LDS();

	Elem *find(int x);

	bool boolFind(int x);

	Elem* next(int val);

	void add_first(int elem);

	void add_last(int elem);

	void add(int x, Elem *next);

	void del_first();

	void del_last();

	void del(int x);

	void print();

	void choice();
};