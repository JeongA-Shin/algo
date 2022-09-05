#include <iostream>
#include <algorithm>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;


int arr[1000][1000];


int main() {
    fastio();

    int n;
    cin >> n;

    int findNum;
    cin >> findNum;

    int cnt = 1;

    arr[(n / 2) +1][(n / 2)+1] = 1;

    int row = (n / 2) + 1;
    int col = (n / 2) + 1;

    int number= 2;

    int resRow = 0;
    int resCol = 0;

   
    if (findNum == 1) {
        resRow = row;
        resCol = col;
    }

    while (cnt < n) {
        if (cnt % 2 == 1) {
            for (int i = 0; i < cnt; i++) {
                //up
                col -= 1;
                if (number == findNum) {
                    resRow = row;
                    resCol = col;
                }
                arr[col][row] = number;
                number++;
            }
            for (int i = 0; i < cnt; i++) {
                //right
                row += 1;
                if (number == findNum) {
                    resRow = row;
                    resCol = col;
                }
                arr[col][row] = number;
                number++;
            }
            cnt++;
        }
        else {
            for (int i = 0; i < cnt; i++) {
                //down
                col += 1;
                if (number == findNum) {
                    resRow = row;
                    resCol = col;
                }
                arr[col][row] = number;
                number++;
            }

            for (int i = 0; i < cnt; i++) {
                //left
                row -= 1;
                if (number == findNum) {
                    resRow = row;
                    resCol = col;
                }
                arr[col][row]= number;
                number++;
            }
            cnt++;
        }
    }


    for (int i = 0; i < n-1; i++) {
        col -= 1;
        if (number == findNum) {
            resRow = row;
            resCol = col;
        }
        arr[col ][row] = number;
        number++;
    }

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << resCol << " " << resRow << endl;

}