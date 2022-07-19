#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map<int, int> m;

int num[10];

// !! map은 디폴트가 "key" 오름차순으로 정렬됨!

int main() {

	for (int i = 0; i < 8; i++) {
		int score;
		cin >> score;

		m.insert({ score, i+1 }); // 점수,문제 번호

	}


	map<int, int>::iterator iter = m.end();
	int sum = 0;

	int cnt = 5;
	while (cnt > 0) {
		iter--;
		sum += iter->first;
		//cout << iter->second << endl;
		num[cnt] = iter->second;
		cnt--;
	}

	sort(num, num + 10);

	cout << sum << endl;
	for (int i = 5; i < 10; i++) {
		cout << num[i] << " ";
	}
	cout << endl;
}