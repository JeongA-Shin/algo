#include <iostream>
#include <algorithm>
using namespace std;

int arr[5];

int main() {

	int t;
	cin >> t;


	for (int i = 0; i < t; i++) {

		for (int j = 0; j < 5; j++) {
			int score;
			cin >> score;

			arr[j] = score;
		}

		sort(arr, arr + 5); // 오름차순

		int max, min;
		max = arr[3];
		min = arr[1];
	

		int diff = max - min;

		if (diff >= 4) {
			cout << "KIN" << endl;
		}
		else {
			int score = arr[1] + arr[2] + arr[3];
			cout << score << endl;
		}

	}
}