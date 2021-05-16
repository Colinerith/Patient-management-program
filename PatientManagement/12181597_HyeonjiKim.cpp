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

vector<Node*> patients; // To make it easier to test for epidemic diseases

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
			patients.push_back(newNode);
			return;
		}
		int depth = 0;
		Node* parent = NULL;
		Node* current = root;
		while (current != NULL) { //searching position of newNode
			parent = current;
			if (newNode->num == parent->num) { //already exists
				cout << depth << " " << 0 << "\n";
				return;
			}
			else if (newNode->num < parent->num)
				current = current->left;
			else
				current = current->right;
			depth++;
		}
		patients.push_back(newNode);

		newNode->parent = parent;
		if (newNode->num < parent->num)
			parent->left = newNode;
		else
			parent->right = newNode;

		current = newNode;
		while (parent->color == 'R') { 	// Double Red
			if (parent == parent->parent->left) {
				// parent's sibling color check
				if (parent->parent->right == NULL || parent->parent->right->color == 'B') {
					//restructure
					if (current == parent->left) { //middle: parent
						if (parent->parent != root) {
							if (parent->parent == parent->parent->parent->left)
								parent->parent->parent->left = parent;
							else
								parent->parent->parent->right = parent;
						}

						parent->parent->color = 'R';
						parent->color = 'B';
						parent->parent->left = parent->right;
						parent->right = parent->parent;

						//
						if(parent->parent->left!=NULL)
							parent->parent->left->parent = parent->parent;
						

						Node* temp = parent->parent;
						parent->parent = parent->parent->parent;
						temp->parent = parent;
						//parent->parent->parent = parent;

						if (parent->parent == NULL)
							root = parent;

						//depth--;
						break;
					}
					else { // middle: newNode
						if (parent->parent != root) {
							if (parent->parent == parent->parent->parent->left)
								parent->parent->parent->left = current;
							else
								parent->parent->parent->right = current;
						}

						parent->parent->color = 'R';
						current->color = 'B';

						parent->right = current->left;
						parent->parent->left = current->right;

						//
						if (parent->parent->left != NULL)
							parent->parent->left->parent = parent->parent;
						if (parent->right != NULL)
							parent->right->parent = parent;

						current->left = parent;
						current->right = parent->parent;

						current->parent = parent->parent->parent;
						if (current->parent == NULL)
							root = current;

						parent->parent->parent = current;
						parent->parent = current;
						//depth = depth - 2;
						break;
					}
				}
				else { // recolor
					parent->color = 'B';
					parent->parent->right->color = 'B'; //uncle
					parent->parent->color = 'R';
					current = parent->parent;
					parent = current->parent;
					if (current == root) {
						current->color = 'B';
						cout << calcDepth(newNode->num)  << " " << 1;
						return;
					}
				}
			}
			else if (parent == parent->parent->right) {
				if (parent->parent->left == NULL || parent->parent->left->color == 'B') {
					//restructure
					if (current == parent->left) { // middle: newNode
						if (parent->parent != root) {
							if (parent->parent == parent->parent->parent->left)
								parent->parent->parent->left = current;
							else
								parent->parent->parent->right = current;
						}

						parent->parent->color = 'R';
						current->color = 'B';

						parent->parent->right = current->left;
						parent->left = current->right;

						//
						if(parent->parent->right!=NULL)
							parent->parent->right->parent = parent->parent;
						if(parent->left!=NULL)
							parent->left->parent = parent;

						current->left = parent->parent;
						current->right = parent;

						current->parent = parent->parent->parent;
						if (current->parent == NULL)
							root = current;

						parent->parent->parent = current;
						parent->parent = current;

						//depth = depth - 2;
						break;
					}
					else { // middle: parent
						if (parent->parent != root) {
							if (parent->parent == parent->parent->parent->left)
								parent->parent->parent->left = parent;
							else
								parent->parent->parent->right = parent;
						}

						parent->parent->color = 'R';
						parent->color = 'B';


						parent->parent->right = parent->left;
						parent->left = parent->parent;

						//
						if (parent->parent->right != NULL)
							parent->parent->right->parent = parent->parent;

						Node* temp = parent->parent;
						parent->parent = parent->parent->parent;
						temp->parent = parent;

						if (parent->parent == NULL)
							root = parent;

						//parent->parent = parent->parent->parent;
						//parent->parent->parent = parent;
						//depth--;
						break;
					}
				}
				else { // recolor
					parent->color = 'B';
					parent->parent->left->color = 'B'; //uncle
					parent->parent->color = 'R';
					current = parent->parent;
					parent = current->parent;
					if (current == root) {
						current->color = 'B';
						cout << calcDepth(newNode->num) << " " << 1;
						return;
					}
				}
			}
		}
		cout << calcDepth(newNode->num) << " " << 1 << "\n";
	}

	int calcDepth(int n) {
		int depth = 0;
		Node* parent = NULL;
		Node* current = root;
		while (current != NULL) { //searching position of newNode
			parent = current;
			if (n == parent->num) { //already exists
				return depth;
			}
			else if (n < parent->num)
				current = current->left;
			else
				current = current->right;
			depth++;
		}
	}

	void find(int k) {
		int depth = 0;
		Node* parent = NULL;
		Node* current = root;
		while (current != NULL) { //searching position of newNode
			parent = current;
			if (k == parent->num) { //exists
				cout << depth << " " << parent->name << " " << 
					parent->phoneNum << " " << 
					parent->address.first << " " << parent->address.second << "\n";
				return;
			}
			else if (k < parent->num)
				current = current->left;
			else
				current = current->right;
			depth++;
		}
		cout << "Not found\n";
	}
	void addition(int k, string di, int c) {
		int depth = 0;
		Node* parent = NULL;
		Node* current = root;
		while (current != NULL) { //searching position of newNode
			parent = current;
			if (k == parent->num) { //already exists
				//addition
				parent->records.push_back({ di, c });
				cout << depth << "\n";
				return;
			}
			else if (k < parent->num)
				current = current->left;
			else
				current = current->right;
			depth++;
		}
		cout << "Not found\n";
	}
	void epidemic(string di) {
		int t = 0;
		for (Node* n : patients) {
			if (n->records.back().first == di)
				t++;
		}
		cout << t << "\n";
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
		case 'I': {
			cin >> a >> b >> c >> d >> e >> f >> g;
			Node* newNode = new Node(a, b, c, d, e, f, g);
			tree.insert(newNode);
			break; }
		case 'F':
			cin >> a;
			tree.find(a);
			break;
		case 'A':
			cin >> a >> b >> d;
			tree.addition(a, b, d);
			break;
		case 'E':
			cin >> b;
			tree.epidemic(b);
			break;
		}
	}
}