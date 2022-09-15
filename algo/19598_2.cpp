#include <iostream>
#include <algorithm>
#include <vector>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;


//https://cocoon1787.tistory.com/534
vector<pair<long long, int>> vec; // 시작 시간, 끝나는 시간, 삭제 여부


int main() {
    fastio();

    int cnt = 0; //"현재 시간 기준으로" 사용하고 있는 회의실 개수

    //댑악..엄청 쉽게 풀리는 문제였음 ㅠ
    int n;
    cin >> n; //총 회의실 개수

    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        //벡터에는 {시작시간, 1}와 {종료시간, -1}으로 넣음
        vec.push_back({ s,1 });
        vec.push_back({ e,-1 });
    }


    /*
    5
    5 15
    0 40
    15 30
    5 15
    10 20*/

    sort(vec.begin(), vec.end());

    //정렬된 후 - 즉 완전 시간순대로 끝남.타임라인대로 정렬됨
    //즉 해당 시간에 시작이면 +1 끝나면 퇴출이므로 -1
    /*
    * {0, 1}
      {5, 1}
      {5, 1}
      {10, 1}
      {15, -1}
      {15, -1}
      {15, 1}
      {20, -1}
      {30, -1}
      {40, -1}
    */

    int ans = 0;

    for (int i = 0; i < vec.size(); i++) {
        cnt += vec[i].second;
        ans = max(ans, cnt);
    }
   
    cout << ans << endl;
}