#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

//힙 문제
//priority_queue는 
//이미 내부적으로 make_heap 을 통해 구현
//따라서 heap 문제가 나오면 pq로 푼다고 생각하자 - pq가 곧 max_heap인 것이므로
int main() {
	
	priority_queue<pair<int, int>,cmp> pq;  //절댓값, 실제 값
	// 디폴트는 큰 수부터 우선순위
	// 따라서 작은 수부터 나오게 하려면 -를 해줘야 함
	//근데 우리는 만약 첫 번째 int가 같다면 두 번째로 비교해줘야 함
	//즉 임의로 크기를 비교해줘야 하므로 구조체 cmp를 해줌


}