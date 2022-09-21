#include <iostream>
#include <algorithm>
#include <memory.h>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

int arr[201];
int memo[201];//최대 증가 수열 길이 1로 초기화

// 번호 순서대로 배치하기 위해 옮겨지는 아이의 최소 수를 구하는 프로그램
// 최대 증가 수열 길이 구하는 것임


int main() {
    fastio();

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int max_val = 0;

    for (int i = 0; i < n; i++) {
        memo[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                memo[i] = max(memo[i], memo[j] + 1);
            }
        }

        max_val = max(max_val, memo[i]);
    }

    cout << n - max_val << endl;
    
}