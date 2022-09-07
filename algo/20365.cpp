#include <iostream>
#include <algorithm>
#include <vector>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

vector<char> vec;


int main() {
    fastio();

    int n;
    cin >> n;

    int cnt_b = 0;
    int cnt_r = 0;

    string str;
    cin >> str;

    for (int i = 0; i < n; i++) {
       
        // 페인트로 한번에 칠하기 때문에 연속된 색깔을 하나로 줄여서 배열에 입력
        //ex) BBRBBR 일때 BRBR - 한번에 칠하기 때문에 BBR은 곧 BR과 같음 - 어차피 색연필 바꾸는 횟수만 따지므로

        if (i == 0 || vec.back() != str[i]) { //바로 이전 것만 구분하면 되므로 그냥 벡터에 저장함
            vec.push_back(str[i]);
            if (str[i] == 'B') {
                cnt_b++;
            }
            else {
                cnt_r++;
            }
        }

    }

    /*
    
        6
        BRRRRB

        위 입출력의 경우 R의 연속된 경우는 1번(RRRR), B가 연속된 경우(B, B)2번 입니다. 
        따라서 둘 중 연속된 수가 적은 수인 R에다가 처음 B로 전부 칠했다고 가정한+1을 더하면 2가 나오게 되어 정답이 됩니다

    */
  

    int total = 1 + min(cnt_b, cnt_r);
    cout << total << endl;

}