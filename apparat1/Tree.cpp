#include <iostream>
#include <string>
#include "Tree.h"
#include "time.h"

#pragma once


using namespace std;

void Tree::straight(Node* node) {
	if (node != NULL) {
		cout << *node->data << " ";
		straight(node->left);
		straight(node->right);
	}
};
Tree::Tree() {
	root = NULL;
};
//удаление 
void Tree::Delete(Node*& node) {
	if (node != NULL)    // если дерево не пустое
	{
		Delete(node->left);   // рекурсивно удаляем левую ветку
		Delete(node->right);  // рекурсивно удаляем правую ветку
		delete node;           // удаляем корень
	}
}
//добавление в дерево
void Tree::Add(NetworkHardware* data) {
	if (root == NULL) {
		root = new Node;
		root->data = data;
		root->left = NULL;
		root->right = NULL;
	}
	else {
		Node* tmp = root;
		while (root->left != NULL && root->right != NULL) {
			if (rand() % 2 == 0) {
				if (tmp->left != NULL) {
					tmp = tmp->left;
				}
				else
					break;
			}
			else {
				if (tmp->right != NULL) {
					tmp = tmp->right;
				}
				else
					break;
			}
		}
		if (tmp->left == NULL) {
			tmp->left = new Node;
			tmp = tmp->left;
		}
		else {
			tmp->right = new Node;
			tmp = tmp->right;
		}
		tmp->data = data;
		tmp->left = NULL;
		tmp->right = NULL;
	}
	count++;
}
//вывод дерева
void Tree::Show() {
	straight(root);
	cout << "Количество узлов в дереве = " << count << endl;
}
// поиск 
void Tree::Search(Node*& node, int m) {
	if (node != NULL) {
		if (*node->data == m) node->data->print();
		Search(node->left, m);
		Search(node->right, m);
	}
}
void Tree::Search_Memory(int m) {
	Search(root, m);
}
//сортировка
void Tree::Sorting() {
	if (root == NULL)return;
	bool swapped;
	do {
		Node* tmp = root;
		swapped = false;
		while (tmp->left != NULL || tmp->right != NULL) {
			if (tmp->left != NULL && tmp->data->getPortNumber() > tmp->left->data->getPortNumber()) {
				swap(tmp->data, tmp->left->data);
				swapped = true;
			}
			if (tmp->right != NULL && *tmp->data > *tmp->right->data) {
				swap(tmp->data, tmp->right->data);
				swapped = true;
			}
			if (tmp->left != NULL) {
				tmp = tmp->left;
			}
			else {
				tmp = tmp->right;
			}
		}
	} while (swapped);
}
Tree::~Tree() // диструктор
{
	Delete(root);
}
