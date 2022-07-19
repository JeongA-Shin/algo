#include <iostream>
#include <set>
using namespace std;

set<int> s;

int main() {

	//집합은 중복을 허용하지 않는다
	for (int i = 0; i < 10; i++) {
		int num;
		cin >> num;
		int remainder = num % 42;

		s.insert(remainder);

	}

	/*
	set<int>::iterator iter;
	for (iter = s.begin(); iter != s.end(); iter++) {
		cout << *iter << endl;
	}
	*/

	cout << s.size() << endl;
}