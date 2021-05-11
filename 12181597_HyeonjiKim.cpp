#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Node {
public:
	int num; // Patient number
	string name; // Patient name
	string phoneNum; // Phone number
	pair<int, int> address; // {x, y}
	vector<pair<string, int>> records; //Medical records. this includes {disease name, cost}
	Node* left; // left child
	Node* right; // right child
	Node* parent;
	char color;

	Node(int nu, string na, string ph, int x, int y, string di, int co) {
		this->num = nu;
		this->name = na;
		this->phoneNum = ph;
		this->address.first = x;
		this->address.second = y;
		pair<string, int> tmp = { di, co };
		this->records.push_back(tmp);
		this->left = NULL;
		this->right = NULL;
		this->parent = NULL;
		this->color = 'R'; // 'R':Red, 'B':Black
	}
};

class RBtree {
public:
	Node* root;
	RBtree() {
		this->root = NULL;
	}

	void insert(Node* newNode) {
		if (root == NULL) {
			newNode->color = 'B'; // Root Property: the root is black
			root = newNode;
			cout << 0 << 1 << "\n";
			return;
		}
		int depth = 0;
		Node* parent = NULL;
		Node* current = root;
		while (current != NULL) {
			parent = current;
			if (newNode->num < parent->num)
				current = current->left;
			else
				current = current->right;

			//depthÃß°¡ÇØ¾ßµÊ
		}

		if (key < parent->key)
			parent->left = newNode;
		else
			parent->right = newNode;
	}
	void find(int k) {

	}
	void addition(int k, string di, int c) {

	}
	void epidemic(string di) {

	}

	void restructure() {

	}
	void recolor() {

	}
};

int main() {
	int t;
	char requirement;
	cin >> t;

	while (t--) {
		cin >> requirement;
		switch (requirement) {
		case 'I':
			break;
		case 'F':
			break;
		case 'A':
			break;
		case 'E':
			break;
		}
	}
}