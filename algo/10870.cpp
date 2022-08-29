#include <iostream>
#include <algorithm>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

//dp

int fibo[22]; //메모이제이션


int makeFibo(int n) {

    if (n == 0) {
        return 0;
    }

    if (fibo[n] != 0) {
        return fibo[n]; //기존의 메모이제이션에 있는 값이라면 다시 재귀로 함수를 호출할 필요가 없는 거임!
    }
    
    fibo[n] = makeFibo(n - 1) + makeFibo(n - 2);
    return fibo[n];
}


int main() {
    fastio();

    // 여기에 구현
    int n;
    cin >> n;

    fibo[0] = 0;
    fibo[1] = 1;

    cout << makeFibo(n) << endl;

}