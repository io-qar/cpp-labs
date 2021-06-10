#include <iostream>
#include "LDS.hpp"
#include "globals.hpp"
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	LDS *lds = new LDS;
	menu();
	lds->choice();
}
