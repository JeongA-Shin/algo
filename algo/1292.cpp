#include <iostream>
using namespace std;

int arr[1001];

int main() {

	//arr 초기화
	int num = 1;
	int index = 0;
	while (index < 1001) {
		//1을 한 번, 2를 두 번, 3을 세 번, 
		// 이런 식으로 1 2 2 3 3 3 4 4 4 4 5 .. 이러한 수열
		for (int i = 0; i < num; i++) {
			arr[index] = num;
			index++;
		}

		num++;
	}



	int begin, end;

	cin >> begin >> end;

	int sum = 0;

	for (int i = begin-1; i < end; i++) {
		sum += arr[i];
	}

	cout << sum << endl;

}