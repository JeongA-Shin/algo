#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {

	string a, b;

	cin >> a >> b;

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	//string -> int
	int num_a = stoi(a);
	int num_b = stoi(b);

	int res = num_a > num_b ? num_a : num_b;

	cout << res << endl;
}