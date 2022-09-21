#include <iostream>
#include <algorithm>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

int arr[1025][1025];
int memo[1025][1025];
int n, m;

/*
// 미리 격자 칸들의 합을 메모이제이션 해둠 - 된 거 확인함
void setMemo() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int k = 0; k < i+1; k++) {
                for (int s = 0; s < j+1; s++) {
                    sum += arr[k][s];
                }
            }
            memo[i][j] = sum;
        }
    }
}

int getPartSum(int x1, int y1, int x2, int y2) {
    int res = memo[x2][y2] - (memo[x1 - 1][y2]) - memo[x2][y1 - 1] + memo[x1 - 1][y1 - 1];
 

    return res;

}




void printMemo() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << memo[i][j] << " ";

        }
        cout << endl;
    }
}

int main() {
    fastio();

   
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
   }

    setMemo();
    printMemo();

    cout << endl << endl;
   

    for (int i = 0; i < m; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << getPartSum(x1-1, y1-1, x2-1, y2-1) << endl;

    }

}

*/


/*
int getPartSum(int x1, int y1, int x2, int y2) {
    int res = memo[x2][y2] - (memo[x1 - 1][y2]) - memo[x2][y1 - 1] + memo[x1 - 1][y1 - 1];


    return res;

}




void printMemo() {
    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < n+1; j++) {
            cout << memo[i][j] << " ";

        }
        cout << endl;
    }
}
*/


int main() {
    fastio();

    cin >> n >> m;

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            //위 풀이로 해보니까 범위가 i-1이 생기므로 그냥 애초에 i,j를 1부터 시작해버리는 게 속 편함
            cin >> arr[i][j];
            memo[i][j]= memo[i - 1][j] + memo[i][j - 1] - memo[i - 1][j - 1] + arr[i][j];
        }
    }


    //printMemo();
    //cout << endl << endl;

    for (int i = 0; i < m; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << memo[x2][y2] - (memo[x1 - 1][y2]) - memo[x2][y1 - 1] + memo[x1 - 1][y1 - 1] << '\n';

    }
}