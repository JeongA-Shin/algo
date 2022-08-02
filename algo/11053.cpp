#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1001];
int dp[1001]; 
//vector<int> vec; //최대 길이의 부분 수열

//초반에 문제 자체를 잘못 이해했음;; -> 부분 수열의 시작점이 제일 첫 원소가 아닐 수도 있다!!!! 는 걸 까먹음
//https://bitwise.tistory.com/215 여기 설명보고 이해함

//현재의 자신 값을 기준으로 최대 부분 수열 길이를 dp에 저장하고 마지막에 max값을 꺼냄

//dp -> 이전의ㅣ 값을 저장한다!, 즉 해당 위치에서 중간 중간 값이 누적되는 문제?임. 


int main() {

	int size;
	cin >> size;


	for (int i = 0; i < size; i++) {
		int num;
		cin >> num;
		arr[i] = num;
		dp[i] = 1;//초기화
		//모든 원소들은 부분 수열의 첫 원소가 될 수 있음!
	}
	
	for (int i = 0; i < size; i++) {//i는 기준
		for (int j = 0; j <= i; j++) { //j는 과거의 값들
			if (arr[j] < arr[i]) { //이전의 값이 나보다 더 작으면
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	cout << *max_element(dp, dp + size);


	

}