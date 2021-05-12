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
			cout << 0 << " " << 1 << "\n";
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
			depth++;
		}

		newNode->parent = parent;
		if (newNode->num < parent->num)
			parent->left = newNode;
		else
			parent->right = newNode;

		while (Double Red) { 	// Double Red
			if (parent == parent->parent->left) {
				// parent's sibling color check
				if (parent->parent->right->color == 'B') {
					//restructure
					if (newNode == parent->left) { //middle: parent
						//Node* t1 = newNode->left;
						//Node* t2 = newNode->right;
						//Node* t3 = parent->right;
						//Node* t4 = parent->parent->right;
						parent->parent->color = 'R';
						parent->color = 'B';
						parent->parent->left = parent->right;
						parent->right = parent->parent;
						parent->parent = parent->parent->parent;
						parent->parent->parent = parent;
						depth--;
						break;
					}
					else { // middle: newNode
						parent->parent->color = 'R';
						newNode->color = 'B';
						parent->right = newNode->left;
						parent->parent->left = newNode->right;
						newNode->left = parent;
						newNode->right = parent->parent;
						parent->parent = newNode;
						parent->parent->parent = newNode;
						depth = depth - 2;
						break;
					}
				}
				else { // Red
					//recolor
				}
			}
			else if (parent == parent->parent->right) {
				if (parent->parent->left->color == 'B') {
					//restructure
					if (newNode == parent->left) { // middle: newNode
						parent->parent->color = 'R';
						newNode->color = 'B';
						newNode->left = parent->parent;
						newNode->right = parent;
						parent->parent->right = newNode->left;
						parent->left = newNode->right;
						parent->parent = newNode;
						parent->parent->parent = newNode;
						depth = depth - 2;
						break;
					}
					else { // middle: parent
						parent->parent->color = 'R';
						parent->color = 'B';
						parent->parent->right = parent->left;
						parent->left = parent->parent;
						parent->parent = parent->parent->parent;
						parent->parent->parent = parent;
						depth--;
						break;
					}
				}
				else { // Red
					//recolor
				}
			}
		}
		cout << depth << " " << 1 << "\n";
	}
	void find(int k) {

	}
	void addition(int k, string di, int c) {

	}
	void epidemic(string di) {

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