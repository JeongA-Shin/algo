#include <iostream>
#include <algorithm>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;


int main() {
    fastio();

    // 여기에 구현

    int n; //거스름돈 액수
    cin >> n;

    int cnt = 0;

    int max_five_cnt = n / 5; // 해당 금액에서 일단 쓰일 수 있는 5원의 최대 개수 //현재 상태에서의 최적의 해답을 선택
    int two_cnt = 0;

    int flag = false;

    while (max_five_cnt>=0) {
        //적절성 검사//선택된 해가 문제의 조건을 만족하는지 검사
        int remain = n - (5 * max_five_cnt);  //남은 액수
       
        //해답 검사
        if (remain % 2 == 0) { //만약 바로 2원으로 나머지를 모두 낼 수 있다면 바로 정답
            two_cnt = remain / 2;
            cnt += max_five_cnt;
            cnt += two_cnt;
            flag = true;
            break;
        }
        else {//아니라면 다시 선택 절차로 넘어감
            max_five_cnt--;
        }
    }
    

    if (flag) {
        cout << cnt << endl;
    }
    else {
        cout << -1 << endl;
    }

}