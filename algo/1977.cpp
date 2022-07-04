#include <iostream>
#include <vector>
using namespace std;

/*
* M과 N이 주어질 때 M이상 N이하의 자연수 중 완전제곱수인 것을 모두 골라 그 합을 구하고 
그 중 최솟값을 찾는 프로그램을 작성하시오. 
예를 들어 M=60, N=100인 경우 60이상 100이하의 자연수 중 
완전제곱수는 64, 81, 100 이렇게 총 3개가 있으므로 
그 합은 245가 되고 이 중 최솟값은 64가 된다.

*/

//동적 계획법으로 풀기
int arr[101][101];

vector<int> diagonal;

void init() {

	//완전 제곱수 - 특정 수의 자신의 배수
	//박스 a,b(에 담긴 수)가 있을 때 
	//만약 x = a*b 에서 만약 a=b인 케이스가 있다면 
	// x는 완전 제곱수임 여기서 "같다"에 착안해서 문자가 완전히 똑같은 i*i 식을 떠올렸어야 함

	for (int i = 0; i < 101; i++) {
		int num = i * i;
		arr[i][i] = num;
		diagonal.push_back(num);  //대각선에 당연히 제곱수가 들어감 (i*i)
	}
}

int main() {

	int m, n;

	cin >> m >> n;


	init();

	//cout << diagonal.size() << endl;

	bool IsThere = false;

	int sum = 0;
	int min = 0;

	for (int i = 0; i < diagonal.size(); i++) {
		//M이상 N이하의 수 중 완전 제곱수
		if (diagonal[i] >= m && diagonal[i] < n + 1) {
			if (IsThere == false) { //이번이 조건을 만족하는 제일 첫 수인지(최소인지)
				//cout << diagonal[i] << endl;
				min = diagonal[i];
			}
			IsThere = true;
			sum += diagonal[i];
		}
	}



	if (IsThere) { //M이상 N이하의 자연수 중 완전 제곱수가 있는 경우
		cout << sum << endl << min << endl;
	}
	else { //없는 경우
		cout << -1 << endl;
	}

	return 0;
}