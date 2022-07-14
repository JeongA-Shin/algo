#include <iostream>
using namespace std;
//M과 N이 주어질 때 M이상 N이하의 자연수 중 소수인 것을 모두 골라 이들 소수의 합과 최솟값

//즉 소수들의 합과, 소수들 중 최솟값을 찾는 것

int sieve[10001];

int main() {

	for (int i = 0; i < 10001; i++) {
		sieve[i] = 1; //일단 1로 초기화
	}

	
	int m, n;
	cin >> m >> n; //M이상 N이하의 자연수


	//에라토스테네스의 체로 걸러서 남아있는 것들이 소수임
	for (int i = 2; i < 10001; i++) {
		if (sieve[i] == 0) { // 0인 애의 배수는 더 볼 필요 없음
			continue;
		}
		else {
			for (int j = i + i; j < 10001; j += i) {
				sieve[j] = 0; //해당 수의 배수들을 모두 탈락시킴
			}
		}
	}

	int sum = 0;
	bool min = true;
	int mini = -1;

	if (m == 1) {
		m += 1; //소수 문제에서 1은 고려하는 범위에서 아예 제외되어야 함. 
	}

	for (int i = m; i < n + 1; i++) {

		if (sieve[i] != 0) {
			if (min) {
				mini = i;
				min = false; //소수 중 최솟값을 찾았으면 false로
			}
			sum += i;
		}

	}

	

	if (min) { //여전히 true라면 체에 걸러진 소수가 없다는 뜻 
		cout<< mini << endl;
	}
	else {
		cout << sum << endl << mini << endl;
	}



}