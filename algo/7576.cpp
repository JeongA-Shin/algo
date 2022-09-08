#include <iostream>
#include <algorithm>
#include <queue>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;


//알게 된 점
//1. bfs, dfs 탐색시 꼭 시작 노드가 1,1일 필요가 없다,,,ㅠ
//2. 격자 배열 그래프 탐색은 사실상 격자 최단 거리 문제랑 똑같이 일단 접근 (+) (시간 == 거리)

//https://inseonyun.github.io/devlog/2022/04/05/boj-7576-tomato.html
//  기초 뼈대는 잘 만들었는데 ㅠ 마무리를 제대로 못 함 ㅠ
/*
토마토 맵 입력 시 1인 경우(익은 토마토인 경우) 해당 좌표를 큐에 넣는다.
BFS 함수 작성 시 다음 칸이 이동 가능하면 현재 자리 값에 + 1 한 값을 다음 칸에 대입한다.
이렇게 만들어진 토마토 맵을 다시 반복문을 이용해서 탐색한다. 
이때, 0이 하나라도 존재하면 -1을 출력하고 프로그램 종료, 아니라면 result 값과 맵의 각 값을 비교하며 최대로 큰 값을 대입한다.
*/

//얘도 사실 따지고 보면 격자 최단 거리 문제였음,,, 1인 칸에서 출발해서 끝까지 최소한의 날 == 최소 거리 이므로!!!

int n, m;

// 배열 내용을 그래프로 풀어보는 문제
//"최소" 날짜니까 bfs로 풀어보자

int dx[4] = {-1,1,0,0 }; //상 하 좌 우
int dy[4] = { 0,0,-1,1}; //상 하 좌 우

//배열 정보
int arr[1001][1001];
queue<pair<int, int>> que; //탐색 예정 줄을 담는 큐

int day = 0;

void bfs() {

    //탐색할 자식들 큐에 넣어주기
    while (!que.empty()) {

        int x = que.front().first;
        int y = que.front().second;

        que.pop();

        //인접 노드들(자식들) 검사
        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if (1 <= new_x && new_x <= n && 1 <= new_y && new_y <= m) {
                //지도를 벗어나지도 않고, 썩은 토마토가 아니라면
                if (arr[new_x][new_y] == 0) {
                    arr[new_x][new_y] = arr[x][y] + 1;
                    que.push(make_pair(new_x, new_y));
                }
            }
        }

    }

}

int main() {
    fastio();
    cin >> m >> n; //열, 행

    int start_x = 1;
    int start_y = 1;

    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < m+1; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                que.push(make_pair(i, j)); //1인 애들부터 검사해야 하므로 큐에 넣어줌
            }
        }
    }

    bfs();


    //첫 패착 - 시작 노드를 단순 1,1이 아니라 썩은 토마토가 있는 곳들에서 시작했어야 했음
    //bfs(1, 1);

     /* 날짜 계산 및 출력  */
    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < m+1; j++) {
            // 익지않은 토마토(0)가 존재할 경우
            
            if (arr[i][j] == 0) {
                cout << -1 << endl;
                return 0;
            }
            
            // 토마토는 다 익었는데, 얼마만에 익었는지?
            if (day < arr[i][j]) {
                day = arr[i][j];
            }
        }
    }
   
    cout << day - 1 << endl;

}