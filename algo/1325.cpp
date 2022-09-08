#include <iostream>
#include <algorithm>
#include <vector>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

//a가 b를 신뢰한다 = b를 해킹하면 a까지 줄줄이 해킹할 수 있음 == b가 부모, a 가 자식으로 해서
//연결된 자식이 가장 많은 부모 == 한 번에 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터 이렇게 해석

//각 부모 노드별로 dfs 탐색을 해서 가진 자식수들을 저장하고 비교

//자식 수 저장 벡터
vector<pair<int, int>> children;
int cnt = 0;

//dfs에서 필요한 것
//1. 방문 여부 배열
int visited[10001];
//2. 연결 그래프
vector<int> graph[10001];


bool cmp(pair<int, int>& p1, pair<int, int>& p2) {
    // true 이면!! sort함수는 왼쪽항이 오른쪽보다 먼저

    if (p1.second == p2.second) return p1.first < p2.first;
    else return p1.second > p2.second;
}

void reset() {
    cnt = 0;
    fill(visited, visited + 10001, 0);
}

void dfs(int startNode) { //파라미터는 탐색을 시작할 시작노드
    
    visited[startNode] = 1; //방문 기록 업뎃
    cnt++; 
    
    for (int i = 0; i < graph[startNode].size(); i++) {
        if (visited[graph[startNode][i]] != 1) { //아직 해당 자식을 방문하지 않았다면
            dfs(graph[startNode][i]);
        }
    }
}

int main() {
    fastio();

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int child, parent;
        cin >> child >> parent;

        graph[parent].push_back(child);
    }


    for (int i = 1; i < n+1; i++) {
        dfs(i);
        children.push_back(make_pair(i, cnt));
        reset(); //새로운 시작 노드 될 때마다 방문 기록 같은 거 모두 초기화해줘야 함
    }

    // 한 번에 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터의 번호를 오름차순으로 출력
    // 자식 수를 저장하고 있는 children 벡터를 자식 순으로 정렬ㅍ- 같으면 오름차순
    sort(children.begin(), children.end(), cmp);

    int max = 0;
    for (int i = 0; i < children.size(); i++) {
        if (max <= children[i].second) {
            max = children[i].second;
            cout << children[i].first << " ";
        }
        else break;
    }

}