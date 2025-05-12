#include <iostream>
#include <sstream>
using namespace std;

/* Node 밑에 NumberNode와 Operation, Operation 밑에 더하기, 빼기, 곱하기 */

struct Node {
	virtual int result() const = 0;
};

struct NumberNode : Node {
	int value;
	NumberNode(int v) : value(v) {}
	virtual int result() const override {
		return value;
	}
};

struct Operation : Node {
	Node* left = nullptr;
	Node* right = nullptr;
};

struct Addition : Operation {
	virtual int result() const override {
		return left->result() + right->result();
	}
};

struct Subtration : Operation {
	virtual int result() const override {
		return left->result() - right->result();
	}
};

struct Multiplication : Operation {
	virtual int result() const override {
		return left->result() * right->result();
	}
};

/* 입력받은 값이 숫자인지 연산자인지 판단하는 함수 : IsNumber, getToken */

bool isNumber(const string& s) {
	return s[0] >= '0' && s[0] <= '9';
}

string getToken(istream& is) {
	string s;
	is >> s;
	return s;
}



Node* buildTree(istream& is) {
	auto s = getToken(is);

	if (isNumber(s)) {
		return new NumberNode(stoi(s));
	}

	Operation* op = nullptr;

	if (s[0] == '+') {
		op = new Addition();
	}

	else if (s[0] == '-') {
		op = new Subtration();
	}

	else if (s[0] == '*') {
		op = new Multiplication();
	}

	if (op == nullptr) {
		cout << "Wrong token";
	}

	op->left = buildTree(is);
	op->right = buildTree(is);

	return op;

}

int main(void) {

	Node* root = buildTree(cin);
	
	cout << root->result() << endl;

	return 0;
	
}