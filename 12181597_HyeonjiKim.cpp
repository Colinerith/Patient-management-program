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

		current = newNode;
		while (parent->color == 'R') { 	// Double Red
			if (parent == parent->parent->left) {
				// parent's sibling color check
				if (parent->parent->right->color == 'B') {
					//restructure
					if (current == parent->left) { //middle: parent
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
						current->color = 'B';
						parent->right = current->left;
						parent->parent->left = current->right;
						current->left = parent;
						current->right = parent->parent;
						parent->parent = current;
						parent->parent->parent = current;
						depth = depth - 2;
						break;
					}
				}
				else { // recolor
					parent->color = 'B';
					parent->parent->right->color = 'B'; //uncle
					parent->parent->color = 'R';
					current = parent->parent;
					parent = current->parent;
					if (parent == root)
						parent->color = 'B';
				}
			}
			else if (parent == parent->parent->right) {
				if (parent->parent->left->color == 'B') {
					//restructure
					if (current == parent->left) { // middle: newNode
						parent->parent->color = 'R';
						current->color = 'B';
						current->left = parent->parent;
						current->right = parent;
						parent->parent->right = current->left;
						parent->left = current->right;
						parent->parent = current;
						parent->parent->parent = current;
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
				else { // recolor
					parent->color = 'B';
					parent->parent->left->color = 'B'; //uncle
					parent->parent->color = 'R';
					current = parent->parent;
					parent = current->parent;
					if (parent == root)
						parent->color = 'B';
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
	int t, a, d, e, g;
	string b, c, f;
	char requirement;
	cin >> t;
	RBtree tree;

	while (t--) {
		cin >> requirement;
		switch (requirement) {
		case 'I':
			cin >> a >> b >> c >> d >> e >> f >> g;
			Node* newNode = new Node(a, b, c, d, e, f, g);
			tree.insert(newNode);
			break;
		case 'F':
			cin >> a;
			tree.find(k);
			break;
		case 'A':
			break;
		case 'E':
			break;
		}
	}
}