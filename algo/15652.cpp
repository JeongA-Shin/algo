#include <iostream>
#include <algorithm>
#include <vector>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

//고른 자연수들로 만든 수열이 오름차순이어야 함

//백트래킹 - dfs로 풀어보자
//일반적인 dfs 풀이는 방문 후에 visited를 계속 true로 유지하지만
//백트래킹은 dfs로 재귀로 간 후에 복귀한 후 visited를 false로 해준다
//그리고 여기 같은 경우에는 방문 횟수도 계산해줘야 함

//현재 그래프는 그냥 graph[1] 1->2->3->....->n 이런 형태라고 생각
//vector<int> graph[9];
int arr[9] = { 0, }; // 
bool visited[9] = { 0, };
int n, m;

void dfs_backtracking(int start_node, int cnt) { // cnt 파라미터 : 현재까지 만들어진 수열의 길이이면서 동시에 해당 수열에서 추가될 요소의 인덱스
    
    if (cnt == m) { //종료 조건
        for (int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }
    
    for (int i = start_node; i < n+1; i++) {
        visited[i] = true;
        arr[cnt] = i;
        dfs_backtracking(i, cnt + 1); 
        visited[i] = false;
    }
}

int main() {
    fastio();
   
    cin >> n >> m;
    dfs_backtracking(1, 0);


}