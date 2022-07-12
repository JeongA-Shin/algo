#include <iostream>
using namespace std;

long long fibo_dp[46]; //dp활용해서 피보나치 수열 구하기

/*
long long fibo(long long num) { //num은 순서

	long long res;

	if (num == 1) {
		return 1;
	}
	else if (num == 0) {
		return 0;
	}
	else {
		res = fibo(num - 1) + fibo(num - 2);
		//즉 피보나치 수열에서 num-1번째 수와 num-2번째 수를 더하겠다는 의미
	}

	return res;
}
*/

int main() {

	fibo_dp[0] = 0;
	fibo_dp[1] = 1;

	long long n;

	cin >> n;


	//동적 계획법 - 계산 및 연산 및 필요한 결과를 저장하면서 꺼내 쓰는 것
	for (int i=2; i < n+1; i++) {
		fibo_dp[i] = fibo_dp[i - 1] + fibo_dp[i - 2];
	}

	cout << fibo_dp[n] << endl;

	//cout << fibo(n) << endl;

}