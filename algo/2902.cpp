#include <iostream>
#include <string>
using namespace std;

int main() {

	string name;

	cin >> name;

	string result;
	result+= name[0];

	for (int i = 1; i < name.length(); i++) {
		if (name[i] == '-') {
			result += name[i + 1];
		}
	}

	cout << result << endl;

}