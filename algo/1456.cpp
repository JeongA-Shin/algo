#include <iostream>
#include <algorithm>
#include <cmath>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
long long a, b;

int arr[10000001]; //0으로 초기화됨 . 0 이면 소수, 1이면 소수가 아님, 일반 수
/*
 if (i <= b / k) 와 if (k*i <= b)는 의미적으로 같아보입니다.

하지만, k*i 는 자료형의 범위를 넘어갈 수 있는 반면
b/k는 자료형의 범위를 넘어가는 경우가 없기 때문에 차이가 생깁니다(k가 커질수록 계산 결과가 줄어들기만 하므로).
*/


int main() {
    fastio();

    //소수문제는 에라토스테네스의 체
    //b의 루트까지 돌아서 일단 그 사이의 소수가 몇 개 있는지 보면 될 듯

    cin >> a >> b;

    int val = sqrt(b);

  
    //에라토스테네스의 체
    for (int i = 2; i<= val; i++) {
        for (int j = i + i; j < val; j += i) {
            arr[j] = 1; //소수가 아님
        }
    }

    int cnt = 0;

    for (long long i = 2; i <= val; i++) {
        if (arr[i] == 0 ) { //소수면
            long long temp = i; //거의 소수만 봐야 함
            while (temp<=b) {
                if (temp >= a) {
                    cout << temp << endl;
                    cnt++;
                }
                temp = temp * i;
            }
            cout << endl;
        }
       
    }

    cout << cnt << endl;

    //그리고 그 소수를 제곱을 언제까지할 수 있는지 확인

}