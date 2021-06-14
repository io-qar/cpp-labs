#include <iostream>
using namespace std;

void menu(){
    cout << "\n\n1) Граф, заданный вариантом\n";
    cout << "2) Произвольный граф\n";
    cout << "0) Выход из программы\n";
}

int V[8][8] = {
	{0, 23, 12, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX},
	{23, 0, 25, INT_MAX, 22, INT_MAX, INT_MAX, 35},
	{12, 25, 0, 18, INT_MAX, INT_MAX, INT_MAX, INT_MAX},
	{INT_MAX, INT_MAX, 18, 0, INT_MAX, 20, INT_MAX, INT_MAX},
	{INT_MAX, 22, INT_MAX, INT_MAX, 0, 23, 14, INT_MAX},
	{INT_MAX, INT_MAX, INT_MAX, 20, 23, 0, 24, INT_MAX},
	{INT_MAX, INT_MAX, INT_MAX, INT_MAX, 14, 24, 0, 16},
	{INT_MAX, 35, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 16, 0}
};

void Floid();

void choice() {
	int com;
    cout << "Введите номер команды: ";
    cin >> com;

    switch (com)
    {
    case 1:
        Floid();
        menu();
        choice();
        break;
    case 2:
        cout << "Введите количество вершин графа: ";
        int n;
        cin >> n;
        cout << "Введите матрицу смежности:\n";
        int **d = new int *[n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++){
                cout << "V[" << i + 1 << "][" << j + 1 << "] = ";
                cin >> d[i][j];
            }
        }
        for (int k=0; k<n; ++k) {
	        for (int i=0; i<n; ++i){
		        for (int j=0; j<n; ++j){
			        if (d[i][k] < INT_MAX && d[k][j] < INT_MAX)
				        if(d[i][k]+d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
        cout << "Введите номер первой вершины: ";
        int x, y;
        cin >> x;
        cout << "Введите номер второй вершины: ";
        cin >> y;
        cout << d[x+1][y+1] << endl;
        menu();
        choice();
        break;
    default:
        cout << "Команды с таким номером не существует!\n\n";
        break;
    }
}

void Floid() {
    int n = 8;
	for (int k=0; k<n; ++k)
	    for (int i=0; i<n; ++i)
		    for (int j=0; j<n; ++j)
			    if (V[i][k] < INT_MAX && V[k][j] < INT_MAX)
				    if (V[i][k]+V[k][j] < V[i][j])
                        V[i][j] = V[i][k] + V[k][j];
    cout << "Введите номер первой вершины: ";
    int x, y;
    cin >> x;
    cout << "Введите номер второй вершины: ";
    cin >> y;
    cout << V[x+1][y=1] << endl;
}

int main() {
	setlocale(LC_ALL, "RUS");
	menu();
	choice();
}
