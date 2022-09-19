#include <iostream>
#include <cstring>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

//https://hello70825.tistory.com/281

long long arr[5001];
long long memo[5001]; 
//즉 memo의 인덱스가 출발 노드라고 했을 때, 가장 오른쪽으로 갔을 때의 최솟값을 memo에 저장해놓음
//가장 왼쪽 돌에서 출발하여 가장 오른쪽에 있는 돌로 건너갈 수 있는 힘의 최댓값 중 최솟값
//가장 왼쪽 돌에서 출발하여 가장 오른쪽에 있는 돌로 건너갈 수 있는 모든 경우 중 돌을 한번 건너갈 때마다 쓸 수 있는 힘의 최댓값(k) 중 최솟값을 


//cur->next로 가는 비용을 구할 때 cur->i로 가는 비용, i->next로 가는 비용중 더 큰 값을 취하고, 이렇게 취한 값중 가장 작은 값을 구한다.

int n; //입력 받는 총 돌의 개수


long long getDistanceFrom(int start_node_idx) {

    if (start_node_idx == n-1) return 0; //인덱스이므로 n-1이면 마지막 돌임. 즉 더 갈 곳이 없으므로 0 반환

    long long& distance = memo[start_node_idx]; //& 안 해주면 시간 초과 남
    if (distance != -1) return distance; //만약 값이 있는 상태라면 걔를 리턴

    //아직 해당 칸에 값이 들어오지 않았다면
    distance = 1e10;  // long long 에서의 최댓값을 줌
    for (int i = start_node_idx + 1; i < n; i++) {
        distance = min(distance, max(getDistanceFrom(i), (i - start_node_idx) * (1 + abs(arr[start_node_idx] - arr[i]))));
    }

    return distance;

}

int main() {
    fastio();

    memset(memo, -1, sizeof(memo));//-1로 메모이제이션 초기화
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << getDistanceFrom(0) << endl;

    return 0;

}