#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;


// "최소의" 칸 수 == "격자"에서의 "최단 거리" == bfs

int arr[101][101]; //실제 미로
int visited[101][101]; //각 미로 노드 방문여부


int dist[101][101]; // 이동칸 기록용 2차원 배열 - 초딩 때 막 격자 한 칸당 1씩 누적해서 최소 거리 푸는 것처럼 그 때의 누적값 저장

int dx[4] = { -1, 1, 0, 0 };//상하좌우
int dy[4] = { 0,0,-1,1};//상하좌우

queue<pair<int, int> > que; // 방문해서 탐색할 좌표 저장용 queue


void bfs(int start_x, int start_y) { //파라미터는 시작 노드의 좌표
    visited[start_x][start_y] = 1; // 파라미터로 받은 시작 노드 방문
    que.push(make_pair(start_x, start_y)); //해당 노드 큐에 삽입 - 방문했으니까 탐색한다는 의미로

    // *** 격자 거리 문제에서 완전 핵심 *** //
    dist[start_x][start_y]++; // 해당 칸에 들어왔으니까 누적 거리를 +1

    //이제는 그냥 bfs랑 동일
    while (!que.empty()) {
        int top_x = que.front().first;
        int top_y = que.front().second;

        que.pop(); //제거
        //이제 제거된 노드에 상하좌우로 연결된 자식 노드들을 큐에 넣어줌 - 탐색 에정이므로
        for (int i = 0; i < 4; i++) {
            int new_x = top_x + dx[i];
            int new_y = top_y + dy[i];

            // 인접한 좌표가, 미로 내에 존재하는지, 방문한 적이 없는지, 이동이 가능한지 확인
            if ((0 <= new_x && new_x < 101) && (0 <= new_y && new_y < 101) && (visited[new_x][new_y] != 1) && (arr[new_x][new_y] == 1)) {
                visited[new_x][new_y] = 1;//큐에 등록되면 방문된 것으로 함
                que.push(make_pair(new_x, new_y)); //이제 큐에 등록

                 // *** 격자 거리 문제에서 완전 핵심. 누적 거리 업데이트 *** //
                dist[new_x][new_y] = dist[top_x][top_y] + 1;
            }
        }


    }
}


int main() {
    fastio();

    int n, m;
    cin >> n >> m; // n행 m열

    string str;


    for (int i = 0; i < n; ++i) {            // 미로 입력

        string row;                     // 행 입력
        cin >> row;

        for (int j = 0; j < m; ++j) {        // 행 별 좌표값 저장
            arr[i][j] = row[j] - '0';    // 행 별 좌표값들은 문자 형태이기 때문에, 숫자로 변환
        }
    }


    bfs(0, 0);//이제 주어진 배열을 bfs로 탐색해보기 
    //파라미터는 시작노드의 좌표

    cout << dist[n - 1][m - 1] << endl;

}