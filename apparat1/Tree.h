#pragma once
#include <iostream>
#include "NetworkHardWare.h"

using namespace std;
class Tree {
	struct Node {
		NetworkHardware* data = NULL;
		Node* left;
		Node* right;
	};
private:
	Node* root;
	int count = 0;
	void straight(Node* node);
	void Search(Node*& node, int m);
	void Delete(Node*& node);

public:
	Tree();
	~Tree();
	void Add(NetworkHardware* data);// ����������
	void Show();//����� �����������
	void Search_Memory(int m);// ������ �� ������ ������
	void Sorting();
};

