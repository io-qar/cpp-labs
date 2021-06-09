#include <iostream>
#include <Windows.h>
using namespace std;

void printMenu() {
    cout << "\n1) Ввод графа по индивидуальному варианту\n";
    cout << "2) Ввод графа с клавиатуры\n";
    cout << "0) Выход из программы\n\n";
}

int M[6][6] = {
    {0, 2, 6, 4, 0, 0},
    {2, 0, 0, 7, 8, 0},
    {6, 0, 0, 8, 0, 5},
    {4, 7, 8, 0, 2, 8},
    {0, 8, 0, 2, 0, 4},
    {0, 0, 5, 8, 4, 0},
};

int **input_tree(int* n) {
    int **A = nullptr;
    int com;
    bool flag = true;

    while (flag) {
        cout << "Введите номер команды: ";
        cin >> com;

        switch (com) {
        case 1:
            *n = 6;
            A = new int *[*n];
            for (int i = 0; i < *n; i++) {
                A[i] = new int[*n];
                for (int j = 0; j < *n; j++) A[i][j] = M[i][j];
            }
            flag = false;
            printMenu();
            break;
        case 2:
            cout << "Введите количество вершин (размерность матрицы): ";
            cin >> *n;
            A = new int *[*n];
            cout << "Введите матрицу по элементам: ";
            for (int i = 0; i < *n; i++) {
                A[i] = new int[*n];
                for (int j = 0; j < *n; j++) {
                    cout << "A[" << i + 1 << "][" << j + 1 << "] = ";
                    cin >> A[i][j];
                }
            }
            flag = false;
            printMenu();
            break;
        case 0:
            flag = false;
            break;
        default:
            cout << "Введите корректное число!\n";
            break;
        }
    }
    return A;
}

void output_matrix(int **A, int n) {
    cout << "Матрица смежности графа с " << n << " вершинами:\n\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << A[i][j] << " ";
        cout << endl;
    }
}

void output_tree(int **A, int n) {
    int sum = 0;
    int no_edge = 0;
    int x, y, min;
    bool *selected = new bool[n];
    for (int i = 0; i < n; i++) selected[i] = false;
    selected[0] = true;
    cout << "Результат построения дерева:\n";
    cout << "[Ребро1]---Вес---[Ребро2]";
    while (no_edge < n - 1) {
        min = 999;
        x = 0;
        y = 0;
        for (int i = 0; i < n; i++) if (selected[i])
        for (int j = 0; j < n; j++) if (!selected[j] && A[i][j]) if (min > A[i][j]) {
            min = A[i][j];
            x = i;
            y = j;
        }
        if (x + 1 == 1) cout << endl;
        else if (x + 1 == 2) cout << "          ";
        else if (x + 1 == 4) cout << "          ";
        else if (x + 1 == 5) cout << "                    ";
        else if (x + 1 == 6) cout << "                              ";
        cout << "[" << x + 1 << "]---" << A[x][y] << "---[" << y + 1 << "]";
        cout << endl;
        sum += A[x][y];
        selected[y] = true;
        no_edge++;
    }
    cout << "Вес оставного дерева: " << sum << endl;
}

int main() {
    setlocale(LC_ALL, "RUS");
    int n;
    printMenu();
    int **A = input_tree(&n);
    output_matrix(A, n);
    output_tree(A, n);
    return 0;
}