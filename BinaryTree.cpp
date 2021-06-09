#include <iostream>
using namespace std;

struct Node {
    double data;
    Node *right = NULL;
    Node *left = NULL;

    bool isLeaf() {
        if (this->right == NULL && this->left == NULL) return true;
        else return false;
    }
};

class Tree {
    Node *right, *left;
public:
    Node *head = NULL;
    double sumL, sumR = 0;

    Tree() {
        this->right = NULL;
        this->left = NULL;
    }
    
    void add(double data) {
        Node *node = new Node;

        if (head == NULL) {
            node->data = data;
            node->left = NULL;
            node->right = NULL;
            head = node;
            cout << "Новый узел создан!\n";
        }
        else {
            node = head;
            Node *next = new Node;

            while (true) {
                if (data > node->data) {
                    if (node->right != NULL) node = node->right;
                    else {
                        node->right = new Node;
                        node->right->data = data;
                        break;
                    }
                    cout << "Новый узел создан!\n";
                }

                else if (data < node->data) {
                    if (node->left != NULL) node = node->left;
                    else {
                        node->left = new Node;
                        node->left->data = data;
                        break;
                    }
                    cout << "Новый узел создан!\n";
                }

                else {
                    cout << "Узел с таким значением уже существует!\n";
                    break;
                }
            }
        }
    }

    void checkForPrint() {
        if (head != NULL) print(head, 0);
        else cout << "Дерево пусто!\n";
    }

    void print(Node *node, int depth) {
        if (node == NULL) return;
        print(node->right, depth + 1);
        for (int i = 0; i < depth; ++i) cout << " ";
        cout << node->data << "\n";
        print(node->left, depth + 1);
    }

    void PrintSum() {
        summL(head);
        summR(head);
        cout << "Сумма листьев дерева равна " << sumL + sumR << endl;
    }

    double summL(Node *node) {
        if (node->isLeaf()) sumL += node->data;
        else return summL(node->left);
    }

    double summR(Node *node) {
        if (node->isLeaf()) sumR += node->data;
        else return summR(node->right);
    }
};

void menu() {
    cout << "1) Вставка нового узла\n";
    cout << "2) Симметричный вывод дерeва\n";
    cout << "3) Вывод суммы значений листьев\n";
    cout << "0) Выход из программы\n\n";
}

void Choice(Tree tree) {
    int cmd;
    cin >> cmd;

    if (cmd == 1) {
        cout << "Введите значение нового узла: ";
        double data;
        cin >> data;
        tree.add(data);
        menu();
        Choice(tree);
    }
    
    else if (cmd == 2) {
        tree.checkForPrint();
        menu();
        Choice(tree);
    }

    else if (cmd == 3) {
        tree.PrintSum();
        menu();
        Choice(tree);
    }

    else if (cmd == 0) {
        return;
    }

    else {
        cout << "Такой команды не существует!\n";
        menu();
        Choice(tree);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    Tree a;
    menu();
    Choice(a);
    return 0;
}