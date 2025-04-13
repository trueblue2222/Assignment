#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
	long id;
	string name;
	int midScore;
	int finalScore;

	Student(long _id, string _name, int _midScore, int _finalScore)
		: id(_id), name(_name), midScore(_midScore), finalScore(_finalScore) {}

	float totalScore() const {
		return (midScore + finalScore) / 2;
	}

	friend ostream& operator << (ostream& os, const Student& s) {
		os << "[" << s.id << ", " << s.name << ", " << s.totalScore() << "]";
		return os;
	}
};

void print(const vector<Student>& v) {
	for (const auto& s : v) {
		cout << s << " ";
	}
	cout << endl;

}

int main(void) {
	vector<Student> students;
	bool termination = false;
	while (!termination) {
		int operationCode = 0;
		cout << "Enter operation code : ";
		cin >> operationCode;

		switch (operationCode) {
		case 1: {

			long id = 0;
			string name = "";
			int score1 = 0, score2 = 0;
			cout << "Enter student`s information : ";
			cin >> id >> name >> score1 >> score2;

			auto it = find_if(students.begin(), students.end(),
				[id](const auto& a) {return a.id == id;});

			if (it != students.end()) {
				cout << "The student already exists." << endl;
				break;
			}

			students.emplace_back(id, name, score1, score2);

		} break;

		case 2: {

			long id = 0;
			cout << "Enter student`s id : ";
			cin >> id;

			auto it = find_if(students.begin(), students.end(),
				[id](const auto& a) {return a.id == id;});

			if (it != students.end()) {
				students.erase(it);
			}

			else {
				cout << "No such student." << endl;
			}

		} break;

		case 3: {
			long id = 0;
			int score1 = 0;

			cout << "Enter student`s id & midterm exam score : ";
			cin >> id >> score1;

			auto it = find_if(students.begin(), students.end(),
				[id](const auto& a) {return a.id == id;});

			if (it != students.end()) {
				it->midScore = score1;
			}

			else {
				cout << "No such student." << endl;
			}

		} break;

		case 4: {
			long id = 0;
			int score2 = 0;
			cout << "Enter student`s id & final exam score : ";
			cin >> id >> score2;

			auto it = find_if(students.begin(), students.end(),
				[id](const auto& a) {return a.id == id;});

			if (it != students.end()) {
				it->finalScore = score2;
			}

			else {
				cout << "No such student." << endl;
			}
		} break;

		case 5: {

			sort(students.begin(), students.end(), [] (const auto& a, const auto& b) {return a.id < b.id;});

		} break;

		case 6: {

			sort(students.begin(), students.end(), [](const auto& a, const auto& b) {return a.totalScore() > b.totalScore();});

		} break;

		case 7: {

			string name = "";
			cout << "Enter student`s name : ";
			cin >> name;

			for (const auto& v : students) {
				if (v.name == name)
					cout << v.id << " ";
			}

			cout << endl;


		} break;

		case 8: {

			termination = true;

		} break;

		default: {

			cout << "Wrong code.";

		}
		
		}

		

		


		print(students);


	}
}

