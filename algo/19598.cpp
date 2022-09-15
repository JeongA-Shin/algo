/*
* 시간 초과 뜸
* 
#include <iostream>
#include <algorithm>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

pair<pair<long long, long long>,bool> arr[100001]; // 시작 시간, 끝나는 시간, 삭제 여부

int main() {
    fastio();

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i].first.first >> arr[i].first.second;
        arr[i].second = false; 
    }

    sort(arr, arr + n);

    int cnt = 0;

    //그리디답게 하나씩 생각해봄
    //일단 첫번째는 무조건 하나 할당
    cnt = 1;
    // 두 번째는 조건에 따라 할당( 만약 앞에 거 중에 자기보다 빨리 끝난 게 있다면 그 자리를 자기가 차지, 아니면 할당)
    // 세 번째는 만약 앞에 거 중에 자기보다 빨리 끝난 게 있다면 그 자리를 자기가 차지, 아니면 할당
    //네 번째도 마찬가지로  자기보다 빨리 끝난 게 있다면 그 자리를 자기가 차지, 아니면 할당
    for (int i = 1; i < n; i++) {
        bool flag = false;
        for (int j = 0; j < i; j++) { //j가 이전의 애들
            if (arr[i].first.first >= arr[j].first.second && !arr[j].second) { //아직 방 안 뺀 애들 중에! 이미 끝난 애가 있으면 - 한참전에 빠진 애는 이미 빠졌으므로 비교 필요 없을 것 같음
                arr[j].second = true; // 해당 방 퇴출 여부 업뎃
                flag = true; //퇴출될 방 생김
                break;
            }
        }

        if (!flag) {
            cnt++;
        }
    }

    cout << cnt << '\n';
}

*/