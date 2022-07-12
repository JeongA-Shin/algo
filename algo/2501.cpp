#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//유클리드 호제법은 "최대" 공약수 , "최소" 공배수 구하기에서 쓰임
//여기서는 단순 약수 구하기

//1. 가장 간단한 약수 알고리즘
/*
* void factor(int a) {
	if (a <= 0) {
		return;
	}

	for (int i = 1; i <= a; i++) {
		if (a % i == 0) {
			cout << a << "의 약수 : " << i << endl;
		}
	}
}
* 
*/
 
//2. 1번보다 더욱 효율적인 알고리즘 -for문을 a / 2까지만 돌아도 됨, 왜냐면 모든 약수들은 절대 이 절반을 나눈 값보다 크지 않기 때문
//짝수인 24도 생각해보자. 24 / 2 는 12이며 24의 약수는 1, 2, 3, 4, 6, 12, 24 이다. 이 역시 24를 제외하면 모든 약수들은 절대 이 절반을 나눈 값보다 크지 않는다.
/*
* void factor(int a) {
	if (a <= 0) {
		return;
	}

	for (int i = 1; i <= a / 2; i++) { 
		if (a % i == 0) {
			cout << a << "의 약수 : " << i << endl;
		}
	}
    cout << a << "의 약수 : " << a << endl;
}
*/

//3. 더 효율적인 알고리즘 - i가 주어진 수의 제곱근이 될 때까지만 돌면 됨 (i<sqrt(a)) 
/*
void factor(int a) {
	if (a <= 0) {
		return;
	}

	for (int i = 1; i * i <= a; i++) {
	////i * i <= a 인 이유:  1 2 4처럶 제곱수인 경우 제곱근도 넣어주려고
		if (i * i == a) {
			cout << i << "는 " << a << "의 중복되는 제곱수 " << endl;
		}else if (a % i == 0) {
			cout << a << "의 약수 : " << i << ", "<< a / i << endl;
		}
	}
}
*/


vector<int> divisor;

int main() {

	int n, k;

	cin >> n >> k; //N의 약수들 중 K번째로 작은 수

	//N의 약수의 개수가 K개보다 적어서 K번째 약수가 존재하지 않을 경우에는 0을 출력


	for (int i = 1; i * i <= n; i++) { //위 중 3번째 - 제일 효율적인 알고리즘
		//i * i <= n 인 이유:  1 2 4처럶 제곱수인 경우 제곱근도 넣어주려고
		
		if (i * i == n) { //제곱근도 넣어주려고
			divisor.push_back(i);
		}
		else if (n % i == 0) {
			divisor.push_back(i);
			divisor.push_back(n/i);
		}

	}
	//! 1일 때 예외 처리 해줘야 함!!!
	if (n == 1) {
		divisor.push_back(1);
	}

	sort(divisor.begin(), divisor.end());


	if (divisor.size() <k) {
		cout << 0 << endl;
	}
	else {
		cout << divisor[k-1]<< endl;
	}

}