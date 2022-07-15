#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

//열 개의 자연수가 주어질 때 
// 이들의 평균과 최빈값을 구하는 프로그램을 작성하시오.

map<int, int> m; //val, cnt

int main() {

	/*
	1. 삽입

	map[key]=value;

	map.insert(make_pair(key,value));

	위 2가지 방법으로 삽입 가능하다.

	key값은 정수가 아닌 문자열도 가능하다는 것이 map구조에서 가장 눈에 띄는 특징이다.

	map은 기본적으로 key값 기준 오름차순으로 정렬 된다. 
	*/

	
	for (int i = 0; i < 10; i++) {
		int num;
		cin >> num;

		//입력된 값이 이미 존재하는지 확인
		//만약 존재한다면 cnt에 ++1;
		//새롭게 추가된 값이라면 1을 입력
		if (m.find(num) != m.end()) { //찾음 - 기존에 있었음. 중복임
			m[num] += 1;
		}
		else { //끝까지 가도 못 찾은 것 - 즉 이번에 새로 추가된 것
			m.insert(num, 1);
		}

	}


	//map 출력
	for (auto iter : m) {
		cout << iter.first << " " << iter.second << endl;
	}




	
}