#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

int n, l, r;
int arr[51][51];
int res = 0;

int dx[4] = { -1,1,0,0 };//상 하 좌 우
int dy[4] = { 0,0,-1,1 };

//bool flag2 = false;
bool isThere = false;

map<pair<int, int>, int> visited;
queue<pair<int, int>> que;

queue<pair<int, int>> unions;

void reset() {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[{i, j}] = 0;
        }
    }

    while (!que.empty()) {
        que.pop();
    }

    while (!unions.empty()) {
        unions.pop();
    }

}

//인접한 두 나라의 인구 차이가 L명 이상, R명 이하인 곳이 있는지 체크. 있다면 큐에 넣어줌 == 하나의 그래프가 생성되는 것
void makeUnion_bfs(int row, int col) {

    int total = 0; //이번 연합의 전체 인구 수

    visited[{row, col}] = 1;
    que.push({ row,col });
    total += arr[row][col];

    unions.push({ row,col }); //일단 자기 자신을 연합에 넣음

    while (!que.empty()) {
        pair<int, int> nowIdx = que.front();
        que.pop();

        for (int i = 0; i < 4; i++) {
            int new_x = nowIdx.first + dx[i];
            int new_y = nowIdx.second + dy[i];

            if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < n && visited[{new_x, new_y}] != 1) {
                if (abs(arr[nowIdx.first][nowIdx.second] - arr[new_x][new_y]) >= l && abs(arr[nowIdx.first][nowIdx.second] - arr[new_x][new_y]) <= r) {
                   
                    visited[{new_x, new_y}] = 1;
                    que.push({ new_x, new_y }); //인접한 애들 탐색할 큐에 넣어줌 == 연합인 애들
                    total += arr[new_x][new_y];
                    unions.push({ new_x,new_y });
                }
            }
        }

    }


    //연합된 게 없다면 끝남 == 자기 자신만 이번 연합에 속해있다면
    if (unions.size() == 1) {
        return;
    }
    else {
        isThere = true;
    }

    //연합을 이루고 있는 각 칸의 인구수는(연합의 인구수) / (연합을 이루고 있는 칸의 개수)
    int avg = total / unions.size();
    

    while (!unions.empty()) {

        int row = unions.front().first;
        int col = unions.front().second;

        unions.pop();

        arr[row][col] = avg;
    }

}


int main() {
    fastio();


    cin >> n >> l >> r; //두 나라의 인구 차이가 L명 이상, R명 이하

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }


    while (true) {

        isThere = false;

        //하룻동안 모든 노드들을 시작노드로 연합이 생기는지 확인
        //이중 포문 전체 한 번 도는 게 하루치임
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                reset();
                makeUnion_bfs(i, j); //연합이 하나라도 있으면 그 하루를 카운트
            }
        }

        if (isThere) res++; //연합이 하나라도 있으면 그 하루를 카운트
        else break; //어느 노드를 시작으로 해도 연합이 없다면 종료

    }
    

    cout << res << endl;
    /*
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    */

}