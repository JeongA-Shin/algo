#include <iostream>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

//(아홉 개의 수 중 합이 100이 되는 일곱 개의 수를 찾으시오
//투 포인트 알고리즘 -> 두 개의 포인터로 제외될 2개의 수를 지정하고
// 나머지 7개의 합이 100이 되면 그게 해를 찾게 된 거임

//이 때 나는 투 포인터를 {0,1} {0,2} ......{0,8},{1,2}{1,3}....{1,8},....{7,8}  이렇게 지정해낼 거임
int arr[10];

//이걸 브루트 포스라고 하나?

int main() {
	fastio();

	int sum = 0;

	for (int i = 0; i < 9; i++) {
		int num;
		cin >> num;
		sum += num;
		arr[i] = num;
	}

	int outsiders = sum - 100;

	int spy1_index = 0;
	int spy2_index = 0;
	bool found = false;

	for (int i = 0; i < 8; i++) { //첫 번째 포인터
		for (int j = i+1; j < 9; j++) { // 두 번째 포인터
			int pt1 = arr[i];
			int pt2 = arr[j];

			if (pt1 + pt2 == outsiders) { //스파이 2명 찾음
				spy1_index = i;
				spy2_index = j;
				found = true;
				break;
			}
		}

		if (found) {
			break;
		}

	}

	for (int i = 0; i < 9; i++) {
		if ((i != spy1_index) && (i != spy2_index)) {
			cout << arr[i] << endl;
		}
	}


}