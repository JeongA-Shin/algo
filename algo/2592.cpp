#include <iostream>
#include <map>
using namespace std;

map<int, int> m; //val, cnt

int main() {

	/*
	1. 삽입

	map[key]=value;

	map.insert(make_pair(key,value));

	위 2가지 방법으로 삽입 가능하다.

	key값은 정수가 아닌 문자열도 가능하다는 것이 map구조에서 가장 눈에 띄는 특징이다.

	map은 기본적으로 "key값 기준 오름차순"으로 정렬 된다. 
	*/

	int sum = 0;
	
	for (int i = 0; i < 10; i++) {
		int num;
		cin >> num;

		sum += num;

		//입력된 값이 이미 존재하는지 확인
		//만약 존재한다면 cnt에 ++1;
		//새롭게 추가된 값이라면 1을 입력
		if (m.find(num) != m.end()) { //찾음 - 기존에 있었음. 중복임
			//m[num] += 1; 이렇게 하면 간접 참조가 잘못되었습니다 라는 에러가 발생
			int new_val = m.at(num) + 1;
			m[num] = new_val;
		}
		else { //끝까지 가도 못 찾은 것 - 즉 이번에 새로 추가된 것
			m.insert({ num, 1 }); //자료형 선언시 < >는 pair라는 의미임. 따라서 insert할 때도 {}로 묶어서 한 번에 넣어야 함
			//중괄호 빼먹어서 계속 에러났었음
		}

	}

	int avg = sum / 10;
	//cout << "sum: " <<sum<< endl;
	//cout << "avg: " << avg << endl;

	int max_cnt = 0;

	int mode = 10;

	//map 출력
	for (auto iter : m) {
	
		if (max_cnt < iter.second) { // 최빈값 구하기
			max_cnt = iter.second;
			mode = iter.first;
		}

		//cout << iter.first << " : " << iter.second << endl;
	}

	cout << avg << endl << mode << endl;
	
}