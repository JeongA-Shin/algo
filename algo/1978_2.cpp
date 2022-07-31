#include <iostream>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

//1978-소수 찾기 복습

int arr[1001]; //0이면 아직 살아남은 거고 1이면 지워진 걸로 가자
//초기화를 0으로 했으니까

int main() {
	fastio();

	//100 이하의 소수들을 구한 후 주어진 값들이 그 소수들에 해당되는지 파악한다
	// - 에라토스테네스의 체 활용해버리기

	//에라토스테네스의 체 만들기
	// 
	//소수의 판단에서 1은 들어가지 않으므로 2부터 시작
	for (int i = 2; i < 1001; i++) {
		if (arr[i] == 1) { //이미 지워졌으면
			continue;
		}
		else {//아직 살아남았다면 해당 수의 배수들을 모두 지워버리기
			for (int j = i + i; j < 1001; j+=i) {
				arr[j] = 1;
			}
		}
	}

	int cnt = 0;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;


		if (num!=1 && arr[num] == 0) { //1은 소수의 판단에서 아예 배제해야 함!!
			cnt++;
		}
	}

	cout << cnt << endl;

}