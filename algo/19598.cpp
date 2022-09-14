#include <iostream>
#include <algorithm>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

pair<pair<int, int>,bool> arr[100001]; // 시작 시간, 끝나는 시간, 삭제 여부

bool cmp(pair<pair<int, int>,int>& p1, pair<pair<int, int>,int>& p2) {
    if (p1.first.first == p2.first.first) return p1.first.second < p2.first.second;
    return p1.first.first < p2.first.first;
}

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

    /*
    for (int i = 0; i < n; i++) {
       cout<< arr[i].first.first<<" "<< arr[i].first.second;
       cout << endl;
    }
    */

    //첫 번째 생각
    //일단 처음 시작하는 애는 일단 무조건 회의실 하나 차지함
    //두 번째 애는 처음 애 시작보다 늦고 끝나기 전에 시작하면 cnt++, 아니라면 cnt는 그대로
    //세 번째는 첫 번째랑 두 번째 애 모두 비교 - 첫 번째랑 두 번째 애 중에 끝난 거 있으면(== 모두 현재 start보다 end가 작다면) cnt 그대로, 아니라면 cnt++
    //네 번째 애는 첫 번째, 두 번째, 세번 째애 모두 비교

    //일단 최대는 주어진 회의실 개수( min(n,cnt)) 이렇게 하면 될 듯

    

    //그리디답게 하나씩 생각해봄
    //일단 첫번째는 무조건 하나 할당
    cnt = 1;
    // 두 번째는 조건에 따라 할당( 만약 앞에 거 중에 자기보다 빨리 끝난 게 있다면 그 자리를 자기가 차지, 아니면 할당)
    // 세 번째는 만약 앞에 거 중에 자기보다 빨리 끝난 게 있다면 그 자리를 자기가 차지, 아니면 할당
    //네 번째도 마찬가지로  자기보다 빨리 끝난 게 있다면 그 자리를 자기가 차지, 아니면 할당
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) { //j가 이전의 애들
            if (arr[i].first.first >= arr[j].first.second && !arr[j].second) { //아직 방 안 뺀 애들 중에! 이미 끝난 애가 있으면 - 한참전에 빠진 애는 이미 빠졌으므로 비교 필요 없을 것 같음
                cout << "updated" << endl;
                cout << "cnt: " << cnt << endl;
                cout << "i: "<<arr[i].first.first << " " << arr[i].first.second << endl;
                cout<<"j:"<< arr[j].first.first << " " << arr[j].first.second << endl;
                arr[j].second = true; // 해당 방 퇴출 여부 업뎃
            }
            else {
                cout << "cnt++" << endl;
                cout << "cnt: " << cnt << endl;
                cnt++;
            }
        }
    }

    cout << cnt << endl;

    /*
    for (int i = 0; i < n; i++) {
        cout<< arr[i].first <<" "<<arr[i].second;
        cout << endl;
    }*/
}