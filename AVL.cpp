#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
	int key, height;
	Node *left, *right;
};

Node *new_node(int key) {
	Node *node = new Node();
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;

	return node;
}

int get_height(Node *node) {
	if (node == NULL) return 0;
	return node->height;
}

int get_balance(Node *node) {
	if (node == NULL) return 0;
	return get_height(node->left) - get_height(node->right);
}

Node *leftRotate(Node *x) {
	Node *y = x->right;
	Node *temp = y->left;

	y->left = x;
	x->right = temp;

	x->height = max(get_height(x->left), get_height(x->right)) + 1;
	y->height = max(get_height(y->left), get_height(y->right)) + 1;

	return y;
}

Node *rightRotate(Node *x) {
	Node *y = x->left;
	Node *temp = y->right;

	y->right = x;
	x->left = temp;

	x->height = max(get_height(x->left), get_height(x->right)) + 1;
	y->height = max(get_height(y->left), get_height(y->right)) + 1;

	return y;
}

Node *insert(Node *node, int key) {
	if (node == NULL) {
		return new_node(key);
	}
	
	if (key < node->key) {
		node->left = insert(node->left, key);
	}
	else if (key > node->key) {
		node->right = insert(node->right, key);
	}
	else {
		return node;
	}

	node->height = 1 + max(get_height(node->left), get_height(node->right));
	int balance = get_balance(node);

	//L-L
	if (balance > 1 && key < node->left->key) {
		return rightRotate(node);
	}
	//L-R
	if (balance > 1 && key > node->left->key) {
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	//R-R
	if (balance < -1 && key > node->right->key) {
		return leftRotate(node);
	}
	//R-L
	if (balance < -1 && key < node->right->key) {
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

Node *minValueNode(Node *node) {
	Node *current = node;

	while (current->left != NULL) {
		current = current->left;
	}

	return current;
}

Node *deleteNode(Node *root, int key) {
	if (root == NULL) {
		return root;
	}
	if (key < root->key) {
		root->left = deleteNode(root->left, key);
	}
	else if (key > root->key) {
		root->right = deleteNode(root->right, key);
	}

	else {
		if ((root->left == NULL) || (root->right == NULL)) {
			Node *temp = root->left ? root->left : root->right;

			if (temp == NULL) {
				temp = root;
				root = NULL;
			}
			else {
				*root = *temp;
			}	   
			delete temp;
		}
		else
		{
			Node *temp = minValueNode(root->right);
			root->key = temp->key;
			root->right = deleteNode(root->right, temp->key);
		}
	}

	if (root == NULL)
		return root;

	root->height = 1 + max(get_height(root->left), get_height(root->right));

	int balance = get_balance(root);

	if (balance > 1 && get_balance(root->left) >= 0) {
		return rightRotate(root);
	}
	if (balance > 1 && get_balance(root->left) < 0) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	// П П поворот
	if (balance < -1 && get_balance(root->right) <= 0)
		return leftRotate(root);

	// П Л поворот
	if (balance < -1 && get_balance(root->right) > 0) {
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

void printTree(Node *s, int level) {
	if (s) {
		printTree(s->right, level + 1);
		for (int i = 0; i < level; ++i) cout << "    ";
		cout << s->key << endl;
		printTree(s->left, level + 1);
	}
}

void menu(){
    cout << "\n1) Вставить узел\n";
	cout << "2) Удалить узел\n";
	cout << "3) Вывести дерево\n";
	cout << "0) Выйти из программы\n\n";
}

int main() {
    setlocale(LC_ALL, "RU");
	Node *root = NULL;
    menu();
	int n = 0;
	do
	{
		cout << "Введите номер команды: ";
		cin >> n;

		switch (n) {
		case 1:
			int new_node;
			cout << "Введите значение нового узла: ";
			cin >> new_node;
			root = insert(root, new_node);
			cout << "Новый узел успешно добавлен!\n";
            menu();
			break;
		case 2:
			int del_node;
			cout << "Введите значение узла, который хотите удалить: ";
			cin >> del_node;
			root = deleteNode(root, del_node);
			cout << "Узел успешно удалён!\n";
            menu();
			break;
		case 3:
			printTree(root, 0);
            menu();
			break;
		case 0:
			break;
		default:
			break;
		}
	} while (n != 0);
}