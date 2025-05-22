#include <iostream>
#include <sstream>
using namespace std;

/* Node 하위 NumberNode(숫자 노드), Operation(연산자 노드), Operation 하위 덧셈, 뺄셈, 곱셈 연산자 */

struct Node {
	Node* parent;
	virtual int result() const = 0;
	virtual ostream& print(ostream& os) const = 0;
	Node(Node* _parent = nullptr) : parent(_parent) {}
}; /* 모든 Node instance들은 result 함수를 통해 각각의 결과를 반환하도록 함 */

struct NumberNode : Node {
	int value;
	NumberNode(int v, Node* _parent) : value(v), Node(_parent) {}
	virtual int result() const override {
		return value;
	}
	virtual ostream& print(ostream& os) const override {
		os << value;
	}
}; /* value를 constructor를 통해 assign하고 result 함수 사용 시 value 반환*/

struct Operation : Node {
	Node* left = nullptr;
	Node* right = nullptr;
	Operation(Node* _parent) : Node(_parent) {}
}; /* 연산자는 무조건 두 개의 자식 노드를 가져야 하므로, 상위 Operation 을 통해 모든 Operation들이 이 속성을 가지도록 함 */

struct Addition : Operation {
	virtual int result() const override {
		return left->result() + right->result();
	}
	virtual ostream& print(ostream& os) const override {
		
	}
	Addition(Node* _parent) : Operation(_parent) {}
}; /* 덧셈 */

struct Subtraction : Operation {
	virtual int result() const override {
		return left->result() - right->result();
	}
	virtual ostream& print(ostream& os) const override {
		if (dynamic_cast<Multiplication*>(parent) != nullptr) {
			os << "("; left->print(os); os << "-"; right->print(os); os << ")";
		}
		else
			left->print(os); os << "-"; right->print(os);
	}
	Subtraction(Node* _parent) : Operation(_parent) {}
}; /* 뺄셈 */

struct Multiplication : Operation {
	virtual int result() const override {
		return left->result() * right->result();
	}
	virtual ostream& print(ostream& os) const override{
		left->print(os); os << "*"; right->print(os);
	}
	Multiplication(Node* _parent) : Operation(_parent) {}
}; /* 곱셈 */

bool isNumber(const string& s) {
	return s[0] >= '0' && s[0] <= '9';
} /* 문자 형태로 0부터 9 사이의 정수인지 아닌지 판단. 추후 s는 stoi 함수를 통해 numberNode에 정수로 대입 */

string getToken(istream& is) {
	string s;
	is >> s;
	return s;
} /* inputstream 자체를 매개변수로 받아 s에서 prefix notation 입력 후 반환. recursion 과정에서 문자가 하나씩 순서대로 반환되며 노드 만들어짐 */


/* Tree 구현 */
Node* buildTree(istream& is, Node* _parent) {
	auto s = getToken(is); /* getToken()을 사용하여 문자열의 문자 하나씩 순서대로 입력 받기 */

	if (isNumber(s)) {
		return new NumberNode(stoi(s), _parent);
	} /* 입력 받은 문자가 0부터 9 사이의 정수 문자이면 정수로 convert하여 NumberNode를 반환*/

	Operation* op = nullptr;

	if (s[0] == '+') {
		op = new Addition(_parent);
	} /* 입력 받은 문자가 +이면 덧셈 노드 만들고 op에 assign */

	else if (s[0] == '-') {
		op = new Subtraction(_parent);
	} /* 입력 받은 문자가 -이면 뺄셈 노드 만들고 op에 assign */

	else if (s[0] == '*') {
		op = new Multiplication(_parent);
	} /* 입력 받은 문자가 *이면 곱셈 노드 만들고 op에 assign */

	if (op == nullptr) {
		cout << "Wrong token";
	} /* 이외의 연산자나 문자가 올 경우 잘못된 입력이라고 출력 */

	op->left = buildTree(is, op);
	op->right = buildTree(is, op); /* 연산자 노드의 경우 op가 nullptr가 아니므로, recursion을 통해 두 개의 자식 노드 만들어주기*/

	return op; /* 최종적으로는 root 노드가 main 함수에 반환됨 */

}

int main(void) {

	Node* root = buildTree(cin, root); /* 입력한 문자열을 pre-order traversal대로 tree 생성 후 root 노드 저장 */

	cout << root->result() << endl; /* root 노드부터 leaf 노드까지 traverse하며 result 계산함. 최종적으로는 root 노드에 모든 계산 결과가 모이게 됨. */

	return 0;

}