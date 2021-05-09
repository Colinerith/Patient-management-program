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
	Node left; // left child
	Node right; // right child

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
	}
};

class RBtree {
public:
	Node root;
	RBtree() {
		this->root = NULL;
	}

	void insert(Node newNode) {

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