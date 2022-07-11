#include <iostream>
using namespace std;

//틀린 이유:  내가 아직 약하다고 생각했던 int 등 자료형의 범위...
/*
피보나치 수의 90번째 수의 값은 무려 2, 880, 067, 194, 370, 816, 120나 됩니다. 
int 자료형이 저장할 수 있는 가장 큰 수인 2, 147, 483, 647에 비하면 너무 큰 수입니다. 
그렇기 때문에 작성하신 코드에서는 오버플로우, 즉 저장할 수 있는 수의 범위를 초과해 의도했던 것과 다른 수가 저장됩니다.
이를 해결하기 위해서는 더 큰 수를 저장할 수 있는 long long 자료형을 사용하시면 되겠습니다.
문제가 해결되기를 바랍니다
*/


long long fibo_arr[91];


//이렇게 하니까 시간초과 뜸 - 동적 계획법 가나여?
//재귀함수로 해서 시간 초과 뜨면 그냥 동적 계획법으로 바로 가라는 의미임
/*
int fibo(int num) {


//이게 헷갈렸는데, 피보나치 함수 특징 및 정의상 입력받는 파라미터 자체가 몇 번째임을 나타낼 수 밖에 없음
//0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597
//이렇게 했을 때 아래의 함수에 3을 넣으면 1이 나오는 것임
//3번째는 2이니까
//문제 조건상 0은 0번째 순서임


	int res;

	if (num == 0) {
		return 0;
	}
	else if (num == 1) {
		return 1;
	}
	else {
		res=fibo(num-1) + fibo(num - 2);
	}

	return res;

}*/

/*
int fibo(int order) {

	return fibo_arr[order];

}
*/

int main() {

	fibo_arr[0] = 0;
	fibo_arr[1] = 1;


	long long n;
	cin >> n;

	for (int i = 2; i < n + 1; i++) {
		fibo_arr[i] = fibo_arr[i - 1] + fibo_arr[i - 2];
		//이렇게 과정을 기록 - 동적계획법
	}


	cout << fibo_arr[n] << endl;

	return 0;
	
}