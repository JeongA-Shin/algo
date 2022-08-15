#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

// bfs와 dfs와의 차이: dfs는 방문 대기줄에 넣어주는 게 아니라 바로 방문해버림. bfs는 자식레벨들을 방문 대기줄에 넣어줌

//dfs와 bfs 뼈대 문제
//노션의 dfs, bfs 공부 문서에 설명했던 것처럼  (그냥 간선이 딱 보기에 정말 많지 않으면 그냥 일단 인접 리스트 를 통해 구현하는 걸로 해버리자.)
// 인접 리스트 - 벡터배열로 구현하는 것이 편함 -로 구현
//그냥 단순 벡터가 아니라 벡터”배열”임)
vector<int> graph[1001];

//dfs,bfs 모두를 짜기 위해서는 해당 노드를 이미 방문했었는지를 알아야 함 - 그래야 백터 배열로 연결된 애들로 쭉 갈지 스탑할지 알 수 있음
bool check[1001];

//bfs로 탐색하기 위해서는 큐가 필요
queue<int> que;


void reset() {

    fill(check, check +1001, false);
}

void dfs(int curr_node) {
    check[curr_node] = true; // dfs 함수에 들어온 순간 방문 시작
    cout << curr_node << " "; //현재 어떤 노드에 방문했는지 확인용

    //현재 방문한 node에 딸려있는 자식들
    for (int i = 0; i < graph[curr_node].size(); i++) {
        int curr_child = graph[curr_node][i]; // curr_node의 i번째 자식

        //만약 이번 자식 노드를 아직 방문하지 않았다면 (방문 전 check를 통해 미리 확인)
        if (check[curr_child] == false) {
            //큐에 넣는 것 없이 바로 방문해줘야 함 == dfs에 들어가야 함 == 재귀호출 == 스택구조
            //BFS와의 차이
            dfs(curr_child);
        }//방문했다면 아무것도 없이 종료

    }

}

void bfs(int curr_node) {
    //제일 시작 노드만 해당됨
    que.push(curr_node);
    check[curr_node] = true; //dfs 경우와 똑같이 bfs에 들어왔다 == 방문함

    //제일 시작 노드 그 이후부터 끝까지
    while (!que.empty()) {
        int temp = que.front(); // 큐 제일 앞 노드
        cout << temp << " ";
        que.pop();

        //제일 앞 노드가 삭제되면서 그 노드의 자식레벨들을 모두 체크
        for (int i = 0; i < graph[temp].size(); i++) {
            // 자식을 아직 방문하지 않았다면 큐에 넣어줌 == 큐에 넣어줌 // dfs와의 차이. dfs는 큐에 넣어주는 과정이 없음
            if (check[graph[temp][i]] == false) {
                que.push(graph[temp][i]);
                check[graph[temp][i]] = true; //그리고 큐에 넣는다는 건 걍 방문 되었다는 거임
            }
        }
    }

}

int main() {
    fastio();

    // 여기에 구현

    int n, m,v;//정점의 개수, 간선의 개수, 탐색을 시작할 정점의 번호
   
    cin >> n >> m >> v;

    // 그래프 세팅
    for (int i = 0; i < m; i++) {
        int a, b; //간선이 연결하는 두 정점의 번호
        cin >> a >> b;
        //문제 조건에 따라 양방향임
        graph[a].push_back(b);
        graph[b].push_back(a);   
    }

    //일단 "벡터배열"을 노드 순서에 따라 정렬. [1,2,3,4,...] 이렇게 되게
    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    reset(); // 방문 내역 리셋


    //dfs 탐색 시작
    dfs(v);

    cout << endl;
    reset(); // 방문 내역 리셋

    //bfs 탐색 시작
    bfs(v);
   
}