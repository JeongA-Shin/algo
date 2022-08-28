#include <iostream>
#include <algorithm>
#include <string.h>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

int arr[200001];
int cnt[100001] = { 0, };

void reset() {

    memset(cnt, 0, sizeof(cnt));
    return;
}

int main() {
    fastio();

    int n, k;
    cin >> n >> k; //같은 원소 k개 이하여야 함

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int pt1 = 0;
    int pt2 = 1;

    int max_length = 0;

    cnt[arr[pt1]]++;
    cnt[arr[pt2]]++;
   
    while (pt2 != n) {

        if (cnt[arr[pt2]] > k) { //이번에 넣으면 기준 초과됨, pt1 다시 설정
            int originpt1 = pt1;
            bool flag = false;
            while (arr[pt1] != arr[pt2]) { 
                cnt[arr[pt1]]--;
                pt1++;
            }

            cnt[arr[pt1]]--;
            pt1++;

            if (pt2 == pt1) {
                pt2++;
                cnt[arr[pt2]]++;
            }

            if (max_length < (pt2 - pt1)) {
                max_length = pt2 - pt1;
            }
        }
        else { //일반적인 경우엔 그냥 끝의 pt2만 늘리면서 확인

            if (max_length < (pt2 - pt1)) { //현재 길이 먼저
                max_length = pt2 - pt1;
            }

            pt2++;
            cnt[arr[pt2]]++;
        }
    }

  
    cout << max_length+1 << '\n';
}