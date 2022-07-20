#include <iostream>
#include <algorithm>
using namespace std;

int arr[101];

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int stores;
		cin >> stores;


		for (int j = 0; j < stores; j++) {
			int distance;
			cin >> distance;
			arr[j] = distance;
		}

		sort(arr, arr + stores); //오름차순

		int res = (arr[stores - 1] - arr[0]) * 2;

		cout << res << endl;
	}

}