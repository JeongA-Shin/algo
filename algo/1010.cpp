#include <iostream>
#include <algorithm>
#include <map>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

//다리끼리는 서로 겹쳐질 수 없다
//따라서 순서는 어차피 정해져 있으므로 동쪽 다리 중 서쪽 다리 개수만큼만 선택하는 수가 경우의ㅣ 수가 되는 것일 듯
//즉 조합을 구현해내는 것 
/*
int combination(int n, int r)
{
    if(n == r || r == 0)
        return 1;
    else
        return combination(n - 1, r - 1) + combination(n - 1, r);
}
*/

//근데 얘도 피보나치처럼 중복되는 것이 많음 - dp(메모이제이션) 활용하기

map<pair<int, int>,int> memo; //combination의 n, r

int combination(int n, int r){

    //1.메모이제이션에 이미 해당 값이 있다면 그대로 반환
    //2. 아니라면 계산(점화식 재귀 등)을 통해 값을 메모이제이션에 저장해두고 반환

    if (memo.count(make_pair(n, r))!=0) { //이미 값이 저장되어 있었다면
        return memo[make_pair(n, r)];
    }

    if (n == r || r == 0) {
        memo[make_pair(n, r)] = 1;
        return memo[make_pair(n, r)];
    }

    memo[make_pair(n, r)] = combination(n - 1, r - 1) + combination(n - 1, r);
    return memo[make_pair(n, r)];
}


int main() {
    fastio();

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m; //서쪽 사이트, 동쪽 사이트
        cin >> n >> m;
        cout << combination(m, n) << endl;
    }

}