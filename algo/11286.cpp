#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

//힙 문제
//priority_queue는 
//이미 내부적으로 make_heap 을 통해 구현
//따라서 heap 문제가 나오면 pq로 푼다고 생각하자 - pq가 곧 max_heap인 것이므로


//bool 오름차순 내림차순: 오른쪽 항 기준. 어떤 경우에 오른쪽항이 우선인지
struct cmp {
	//자신의 부모 노드와 크기를 비교하면서 조건(여기선 내림차순임!)에 따라 swap
	bool operator()(pair<int,int>&a, pair<int,int> &b) {
		if (a.first == b.first) return a.second > b.second; //절댓값 같은 경우 원래 실제 값이 더 작은 것부터
		else return a.first > b.first; // 절댓값도 작은 것부터
	}

};

int main() {

	fastio();
	
	priority_queue<pair<int, int>,vector<pair<int,int>>,cmp> pq;  //절댓값, 실제 값
	// 디폴트는 큰 수부터 우선순위
	// 따라서 작은 수부터 나오게 하려면 -를 해줘야 함!! 아니면 비교 연산자로 위에처럼 따로 처리
	//근데 우리는 만약 첫 번째 int가 같다면 두 번째로 비교해줘야 함
	//즉 임의로 크기를 비교해줘야 하므로 구조체 cmp를 해줌

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;

		if (x != 0) {
			pq.push(make_pair(abs(x), x));
		}
		else {
			if (pq.size() != 0) {
				cout<<pq.top().second << '\n';
				pq.pop();
			}
			else {
				cout<< 0 << '\n';
			}
		}
	}

}