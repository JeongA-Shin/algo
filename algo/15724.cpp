#include <iostream>
#include <algorithm>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;


int memo[1025][1025];

int arr[1025][1025];

int main() {
    fastio();

    int n, m;
    cin >> n >> m;

    for (int i = 1; i < n + 1 ;i++) {
        for (int j = 1; j < m + 1; j++) {
            cin >> arr[i][j];

            //입력과 동시에 메모이제이션해주기
            memo[i][j] = arr[i][j] + memo[i][j - 1] + memo[i - 1][j] - memo[i - 1][j - 1];
        }
    }
    //이제 메모이제이션에서 필요한 부분만 (x1,y1,x2,y2) 추출해내기

    int tc;
    cin >> tc;

    for (int i = 0; i < tc; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
  
        cout << memo[x2][y2] - memo[x1 - 1][y2] - memo[x2][y1 - 1] + memo[x1 - 1][y1 - 1] << '\n';
    }

}
