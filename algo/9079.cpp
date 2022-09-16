#include <iostream>
#include <algorithm>
#include <vector>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

// bfs와 같은 형식으로 큐를 활용해서 각 경우의 수 저장하는 경우 : https://khu98.tistory.com/228

char arr[3][3];
vector<int> vec;
int cnt = 0;

//행을 바꾸는 함수
void changeRow(int row) {
    for (int i = 0; i < 3; i++) {
        arr[row][i] = (arr[row][i] == 'H') ? 'T' : 'H';
    }
}

//열을 바꾸는 함수
void changeCol(int col) {
    for (int i = 0; i < 3; i++) {
        arr[i][col] = (arr[i][col] == 'H') ? 'T' : 'H';
    }
}

//대각선을 바꾸는 함수
void changeDiagonal(int dir) {
    for (int i = 0; i < 3; i++) {
        if (dir == 0) {
            arr[i][i] = (arr[i][i] == 'H') ? 'T' : 'H';
        }
        else {
            arr[i][2-i]= (arr[i][2-i] == 'H') ? 'T' : 'H';
        }
    }
}

//만약 전체가 같은 모양이면 바꾼 횟수를 벡터에 저장하기 - 그리고 여기서 최솟값이 정답임
void judge() {
    char letter = arr[0][0];
    bool flag = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] != letter) {
                flag = false;
                break;
            }
        }

        if (!flag) break;
    }

    if (flag) {
        vec.push_back(cnt);
    }
    
}


void makeBoard() {

}

int main() {
    fastio();

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {

        //각 테스트 케이스 당 해당되는 arr 세팅
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                cin >> arr[j][k];
            }
        }



    }
}