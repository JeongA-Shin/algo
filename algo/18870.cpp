#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//아직 좌표 압축이 먼지 잘은 모르겠지만
//값들을 크기 순으로 세운 후 - 오름차순으로 해당 값의 그 순위를 알려주면 되는 거 같음

vector<int> order; //값들의 순위를 보여줌
vector<int> vals; //입력 값을 순서대로

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		vals.push_back(val);
		order.push_back(val);
	}

	//중복값 없애기 - 순위대로 값들 정렬하기
	sort(order.begin(), order.end()); //디폴트는 오름차순
	order.erase(unique(order.begin(), order.end()), order.end());

	/*
	vector<int>::iterator iter;

	for (iter = order.begin(); iter != order.end(); iter++) {
		cout << *iter << " ";
	}
	*/

	//이미 order 인덱스 내에 값이 있는 것은 확실하므로 굳이
	//find 말고 그냥 lower_bound로 찾아주기로 했음

	for (int i = 0; i < vals.size(); i++) {
		cout << lower_bound(order.begin(), order.end(), vals[i]) - order.begin() << " ";
	}

}