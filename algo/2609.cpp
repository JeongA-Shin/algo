#include <iostream>
using namespace std;


int gcd(int a, int b) {
	//a가 더 큰 수가 들어옴
	if (a % b == 0) { //끝나는 조건
		return b;
	}
	else {
		//즉, 유클리드 호제법으로 풀기 위해서
		//기존의 나누는 수가 나누어지는 수로, 기존의 나머지가 나누는 수가 된다
		//gcd(b,a%b);
		return gcd(b, a % b);
	}

}


int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

int main() {
	//두 개의 자연수를 입력받아 최대 공약수와 최소 공배수를 출력하는 프로그램을 작성하시오.
	//최대공약수, 최소공배수 ==> 유클리드 호제법
	//a*b = (a와 b의 최대공약수) * (a와 b의 최소공배수)

	int n, m;

	cin >> n >> m;

	int gcd_val, lcm_val;

	if (n >= m) {
		gcd_val = gcd(n, m);
		lcm_val = lcm(n, m);
	}
	else {
		gcd_val = gcd(m, n);
		lcm_val = lcm(m, n);
	}


	cout << gcd_val << endl << lcm_val << endl;
	

}