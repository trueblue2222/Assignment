#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

bool isNumber(const string& s) {
	return s[0] >= '0';
}

string getToken(istream& is) {
	string s;
	is >> s;
	return s;
}

int calcPostfix(istream& is) {
	stack<int> st;
	while (!is.eof()) {
		auto s = getToken(is);
		if (isNumber(s)) st.push(stoi(s));
		if (s[0] == '+') {
			if (st.size() < 2) throw string("missing operand");
			else {
				int right = st.top(); st.pop();
				int left = st.top(); st.pop();
				st.push(left + right);
			}
		}
		else if (s[0] == '-') {
			if (st.size() < 2) throw string("missing operand");
			else {
				int right = st.top(); st.pop();
				int left = st.top(); st.pop();
				st.push(left - right);
			}
		}
		else if (s[0] == '*') {
			if (st.size() < 2) throw string("missing operand");
			else {
				int right = st.top(); st.pop();
				int left = st.top(); st.pop();
				st.push(left * right);
			}
		}
	}
	if (st.empty()) throw string("wrong equation");
	if (st.size() > 1) throw string("missing operation");
	return st.top();
}


int main(void) {

	string line = ""; getline(cin, line);
	istringstream is(line);
	try {
		cout << calcPostfix(is) << endl;
	}
	catch (string e) {
		cout << e << endl;
	}
	return 0;

}
