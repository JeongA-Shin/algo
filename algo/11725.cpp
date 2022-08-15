#include <iostream>
#include <algorithm>
#include <vector>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

//dfs로 풂 - 노션에 공부해놓은 것처럼 그냥 웬만하면 행렬이 아니라 인접 그래프로
vector<int> graph[100001];

//dfs, bfs 모두 방문 여부를 확인할 수 있어야 함
bool check[100001];


int parents[100001]; //인덱스는 자식, 해당 칸에 들어있는 실제 값은 그 부모 - 문제에서 원하는 것

void reset() {

    fill(check, check + 100001, false);
}


void dfs(int curr_node) {
    check[curr_node] = true; //dfs함수에 들어옴 == 방문

    //이제 딸린 자식들을 확인해봄
    for (int i = 0; i < graph[curr_node].size(); i++) {
        int curr_child = graph[curr_node][i];
        if (check[curr_child] == false) { //이번 자식을 방문한 적이 없으면 - 즉 벡터로 딸린 애들 중에 아직 방문한 적 없는 애들만 자식임
            //방문해버림
            parents[curr_child] = curr_node; // 그리고 부모 정보 획득
            dfs(curr_child);
        }
    }

}

int main() {
    fastio();

    // 여기에 구현

    int n;
    cin >> n; //노드의 개수

    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }


    //일단 "벡터배열"을 노드 순서에 따라 정렬. [1,2,3,4,...] 이렇게 되게
    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    reset(); //방문기록 초기화

    dfs(1);

    for (int i = 2; i < n+1; i++) {
        cout << parents[i] <<'\n';
    }
    
}