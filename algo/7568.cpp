#include <iostream>
#include <algorithm>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

//덩치는 (x, y)로 표시 - 몸무게, 키
//만일 자신보다 더 큰 덩치의 사람이 k명이라면 그 사람의 덩치 등수는 k+1이 된다

pair<int, int> bulks[51];

bool cmp(pair<int, int> p1, pair<int, int> p2) {
	return p1.first > p2.first && p1.second > p2.second;
}

int main() {
	fastio();

	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		pair<int, int> bulk = make_pair(x, y);
		bulks[i] = bulk;

	}



	for (int i = 0; i < n; i++) {
		//bulks[i];// 순위 결정하고 싶은 애
		int order = 0; ////순위 결정하고 싶은 애보다 큰 애들 숫자
		for (int j = 0; j < n; j++) {
			if (j != i) {
				if (bulks[j].first > bulks[i].first && bulks[j].second > bulks[i].second) {
					order++; 
				}
			}
		}


		cout<< order+1<< endl;
		//cout << "( " << bulks[i].first << " ," << bulks[i].second << " )" << endl;
	}


}