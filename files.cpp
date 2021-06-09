#include <windows.h>
#include <iostream>
#include <sstream>
#include <string>
#include <bitset>
#include <fstream>
using namespace std;

string readFile() {
    string data;
    ifstream fin;

    fin.open("library.txt");
    fin >> data;

    stringstream sstream(data);
    string output;
    while (sstream.good()) {
        bitset<8> bits;
        sstream >> bits;
        char c = char(bits.to_ulong());
        if (c == '?') {
            output += ", ";
            continue;
        }
        output += c;
    }
    fin.close();
    return output;
}

void writeToFile() {
    string num, name, adress;
    ofstream fout;
    fout.open("library.txt", ios::app);
    cout << "Введите данные читателя (номер, имя и адрес): ";
    getline(cin, num);
    getline(cin, name);
    getline(cin, adress);
    name = "?" + name + "?";
    adress = adress + "\n";
    for (size_t i = 0; i < num.size(); ++i) fout << bitset<8>(num.c_str()[i]);
    for (size_t i = 0; i < name.size(); ++i) fout << bitset<8>(name.c_str()[i]);
    for (size_t i = 0; i < adress.size(); ++i) fout << bitset<8>(adress.c_str()[i]);
    fout.close();
}

void find(int key) {
    string data = readFile();
    stringstream sstream(data);
    string person;
    while (getline(sstream, person)) {
        if (stoi(person.substr(0, 5)) == key) {
            cout << person << endl;
            break;
        }
    }
}

void remove(int key) {
    string data = readFile();
    stringstream sstream(data);
    data = "";
    string person;
    while (getline(sstream, person)) {
        if (person.size() < 10) break;
            if (stoi(person.substr(0, 5)) == key) {
                continue;
            }
        data += person;
        data += "\n";
    }
    ofstream fout;
    fout.open("library.txt");
    for (size_t i = 0; i < data.size(); ++i) fout << bitset<8>(data.c_str()[i]);
    fout.close();
}

void printMenu() {
    cout << "\n1) Записать абонемент в библиотеку\n";
    cout << "2) Распечатать все абонементы\n";
    cout << "3) Найти абонемент по ключу\n";
    cout << "4) Удалить абонемент по ключу\n";
    cout << "0) Завершить программу\n";
}

int main() {
    setlocale(LC_ALL,"Russian");
    int command = 0, key;

    while (command != 9) {
        printMenu();
        cin >> command;
        switch (command) {
            case 1:
                writeToFile();
                break;
            case 2:
                cout << readFile();
                break;
            case 3:
                cout << "Введите ключ: ";
                cin >> key;
                find(key);
                break;
            case 4:
                cout << "Введите ключ: ";
                cin >> key;
                remove(key);
                cout << "Абонемент удалён";
                break;
            case 0:
                break;
            default:
                cout << "Команда с таким номером не существует\n";
                break;
        }
    }
}