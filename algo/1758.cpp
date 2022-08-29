#include <iostream>
#include <algorithm>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;


long long arr[100001];

// 원래 주려고 생각했던 돈 - (받은 등수 - 1) 

bool cmp(int a, int b) {
    return a > b;
}
//참이면 a먼저 나옴

int main() {
    fastio();

    long long n;//사람의 총 수
    cin >> n;


    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 이러면 걍 원래 주려고 생각했던 돈이 큰 사람이 앞에 가면 되지 않나..?

    sort(arr, arr + n, cmp);

    long long sum = 0;

    for (long long i = 0; i < n; i++) {
        if ((arr[i] - (i)) > 0) {
            sum += arr[i] - (i);
        }
    }

    cout <<sum << endl;


}