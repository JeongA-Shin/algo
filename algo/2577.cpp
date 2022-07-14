#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int cnt[11];

int main() {

	long long a, b, c;

	cin >> a >> b >> c;

	long long res = a * b * c;

	string mul_res = to_string(res);

	for (int i = 0; i < mul_res.size(); i++) {
		int index = mul_res[i] - '0'; //char to int
		cnt[index]++;
	}

	for (int i = 0; i < 10; i++) {
		cout << cnt[i] << endl;
	}



}