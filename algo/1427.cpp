#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/* 정렬시
* 1.배열의 경우
* sort(arr, arr + 10);
* 
* 2.벡터의 경우
* sort(v.begin(), v.end());
*/


vector<int> vec;


bool cmp(int a, int b) {
	return a > b; //내림차순 큰 게 앞으로. > 순으로
	//return a < b; //올림차순, 작은 게 앞으로. < 순으로 // 1234
}

int main() {


	string num;
	cin >> num;

	for (int i = 0; i < num.size(); i++) {
		//cout << num[i] - '0' << endl;
		vec.push_back(num[i] - '0');
	}


	sort(vec.begin(), vec.end(),cmp);
	vector<int>:: iterator iter;
	for (iter = vec.begin(); iter != vec.end(); iter++) {
		cout << *iter;
	}
	
	cout << endl;

}