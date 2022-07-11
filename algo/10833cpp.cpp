#include <iostream>
using namespace std;

int main() {

	int remainder = 0;

	int school_cnt;

	cin >> school_cnt;


	for (int i = 0; i < school_cnt; i++) {
		int students, apples;

		cin >> students >> apples;

		remainder +=apples % students;
	}

	cout << remainder << endl;

	return 0;

}