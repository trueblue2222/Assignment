#include <iostream>
#include <sstream>
using namespace std;

struct Node {
	Node* parent;
	virtual int result() const = 0;
	virtual void print(ostream& os) const = 0;
	Node(Node* _parent = nullptr) : parent(_parent) {}
}; 

struct NumberNode : Node {
	int value;
	NumberNode(int v, Node* _parent) : value(v), Node(_parent) {}
	virtual int result() const override {
		return value;
	}
	virtual void print(ostream& os) const override {
		os << value;
	}
}; 

struct Operation : Node {
	Node* left = nullptr;
	Node* right = nullptr;
	Operation(Node* _parent) : Node(_parent) {}
}; 

struct Multiplication : Operation {
	virtual int result() const override {
		return left->result() * right->result();
	}
	virtual void print(ostream& os) const override {
		left->print(os); os << "*"; right->print(os);
	}
	Multiplication(Node* _parent) : Operation(_parent) {}
}; 

struct Subtraction : Operation {
	virtual int result() const override {
		return left->result() - right->result();
	}
	virtual void print(ostream& os) const override {
		if (dynamic_cast<Multiplication*>(parent) != nullptr) {
			os << "("; left->print(os); os << "-"; right->print(os); os << ")";
		}
		else {
			left->print(os); os << "-"; right->print(os);
		}
	}
	Subtraction(Node* _parent) : Operation(_parent) {}
}; 

struct Addition : Operation {
	virtual int result() const override {
		return left->result() + right->result();
	}
	virtual void print(ostream& os) const override {
		Subtraction* parentAsSub = dynamic_cast<Subtraction*>(parent);
		if (dynamic_cast<Multiplication*>(parent) != nullptr ||
			(parentAsSub != nullptr && parentAsSub->right == this)) {
			os << "("; left->print(os); os << "+"; right->print(os); os << ")";
		}
		else {
			left->print(os); os << "+"; right->print(os);
		}
	}
	Addition(Node* _parent) : Operation(_parent) {}
}; 

bool isNumber(const string& s) {
	return s[0] >= '0' && s[0] <= '9';
} 

string getToken(istream& is) {
	string s;
	is >> s;
	return s;
} 



Node* buildTree(istream& is, Node* _parent) {
	auto s = getToken(is); 

	if (isNumber(s)) {
		return new NumberNode(stoi(s), _parent);
	} 

	Operation* op = nullptr;

	if (s[0] == '+') {
		op = new Addition(_parent);
	} 

	else if (s[0] == '-') {
		op = new Subtraction(_parent);
	} 

	else if (s[0] == '*') {
		op = new Multiplication(_parent);
	} 

	if (op == nullptr) {
		cout << "Wrong token";
	} 

	op->left = buildTree(is, op);
	op->right = buildTree(is, op); 

	return op; 

}

int main(void) {

	Node* root = buildTree(cin, nullptr); 

	root->print(cout); cout << "=" << root->result(); 

	return 0;

}
