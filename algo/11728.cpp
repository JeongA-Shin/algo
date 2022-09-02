#include <iostream>
#include <algorithm>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

int arr_a[1000001];
int arr_b[1000001];

//정렬되어있는 두 배열 A와 B가 주어진다. 
// 두 배열을 합친 다음 정렬해서 출력하는 프로그램

int main() {
    fastio();

    int n, m;// 배열 A의 크기, 배열 B의 크기
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr_a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> arr_b[i];
    }

    int pt_a = 0;
    int pt_b = 0;

    bool flag = true;

    while (flag) {
        if (pt_a < n && pt_b< m) {

            int smaller = min(arr_a[pt_a], arr_b[pt_b]);

            if (smaller == arr_a[pt_a]) pt_a++;
            else pt_b++;

            cout << smaller << " ";
        }
        else {
            break;
        }
    }

    for (int i = pt_a; i < n; i++) {
        cout << arr_a[i] << " ";
    }

    for (int i = pt_b; i < m; i++) {
        cout << arr_b[i] << " ";
    }

}