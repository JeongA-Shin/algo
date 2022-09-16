#include <iostream>
#include <algorithm>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

long long arr[10001];

//처음 low값을 1로, high값을 랜선들 중 가장 긴 길이로 지정해줍니다.
//랜선 길이의 범위가 2^31-1이지만 mid값을 구할 때 랜선끼리의 덧셈 과정이 있어 int자료형의 범위를 넘을 수도 있기에 mid, high, low값은 long long으로 지정
int main() {
    fastio();

    int k, n;
    cin >> k >> n; //잘라서 총 n개 이상이 나와야 함

    for (int i = 0; i < k; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + k);

    long long low = 1;
    long long high = arr[k - 1];
    long long mid = (low + high) / 2;

    long long total = 0;
    long long ans = 0;

    while (low<=high) {

        total = 0;

        for (int i = 0; i < n; i++) {
            total += arr[i] / mid;
        }

        if (total >= n) { //mid를 늘려야 함
            low = mid + 1;
            ans = mid;
            mid = (low + high) / 2;
            
        }
        else {
            high = mid - 1;
            mid = (low + high) / 2;
        }
        

    }

    cout << ans << endl;


}