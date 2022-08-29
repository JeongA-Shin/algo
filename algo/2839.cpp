#include <iostream>
#include <algorithm>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;


//dp로 나누어졌긴 한데, 그리디로도 풀 수 있을듯
//일단 dp로 풀자

//근데 이렇게 되버리니까 dp도 아니고 걍 그리디임,,,,
//걍 이 문제는 그리디로 처음부터 하는 게 더 적절했을 듯

int main() {



    /* 찐 dp로 푼 문제
    * 
    * int dp[5001];
    * 
    * 
    * dp[3] = 1;
	dp[5] = 1;

	for (int i = 3; i < 5001; i += 3) {
		dp[i] = dp[i - 3] + 1;
	}

	for (int i = 5; i < 5001; i += 5) {
		dp[i] = dp[i - 5] + 1;
	}

	for (int i = 3; i < 5001; i += 3) {
		for (int j = 5; i + j < 5001; j += 5) {
			dp[i + j] = dp[i] + dp[j];
		}
	}

    3의 배수와 5의 배수의 케이스를 채우면 되는데, 15의배수일 경우를 생각해야 한다. 
    15의 배수일 경우, 5의 배수일 때 최소의 숫자이므로, 5의 배수의 케이스를 3의 배수케이스보다 나중에 배열에 입력한다!!!! - 핵심 
    이후, 3과 5의 조합이 가능한 경우의 수를 배열에 입력하면 간단히 풀리는 문제이다.

	
	cout << dp[N];
출처: https://bluehyena.tistory.com/entry/백준-2839번-설탕-배달-C [Software Hyena:::티스토리]
    */

    fastio();

    // 3킬로그램 봉지와 5킬로그램 봉지만 있음

    int n;
    cin >> n; //찾는 kg

    int min = 10000;
    bool flag = false;

    for (int i = 0; i < 1700; i++) {
        for (int j = 0; j < 1700; j++) {
            int weight = 5 * i + 3 * j;
            if (weight == n) {
                flag = true;
                int temp = i + j;
                if (temp < min) {
                    min = temp;
                }
            }
        }
    }


    if (flag) {
        cout << min << endl;
    }
    else {
        cout << -1 << endl;
    }

    
}