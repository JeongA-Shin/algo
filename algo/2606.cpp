#include <iostream>
#include <algorithm>
#include <vector>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

vector<int> graph[101]; //행렬이 아니라 그래프 선택. bfs,dfs 뼈대 문제에 나와있음

//방문 여부는 dfs, bfs 모두 필요
bool check[101];

int cnt = 0;

void reset() {

    fill(check, check + 101, false);
}

void dfs(int curr_node) {
    check[curr_node] = true;//방문
    cnt++;

    for (int i = 0; i < graph[curr_node].size(); i++) {
        int curr_child = graph[curr_node][i];
        if (check[curr_child] == false) {
            dfs(curr_child);
        }
    }


}

int main() {
    fastio();

    // 여기에 구현

    int n,m;//컴퓨터의 수, 연결 정보의 수
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    reset();

    //일단 "벡터배열"을 노드 순서에 따라 정렬. [1,2,3,4,...] 이렇게 되게
    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(1);

    cout << cnt-1 << endl; //문제조건 상 첫 번째는 제외함
}