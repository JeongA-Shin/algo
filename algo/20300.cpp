#include <iostream>
#include <algorithm>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

long long arr[10001];


int main() {
    fastio();

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + (n)); //기본은 오름차순 //계속 틀렸던 이유 => 크기만큼 해줘야 하는데 인덱스로 착각하고 n-1로 해줘서 틀렸었음

  
    long long result = 0;

    //오름차순으로 정렬
    // 합 중에 최소 = 당연히 최대+최소여야 함
    // 그런데 중간 값들의 합이 그것보다 크면 그걸로 갱신해줘야 함
    //만약에 짝수라서 2개씩 묶을 수 있으면 max(젤 작은 거 + 젤 큰 거 , 차례대로 그 다음 제일 높은 거 + 젤 낮은 거 한 것들)
    // 그렇지 않다면 max(젤 큰 거,차례대로 그 다음 제일 높은 거 + 젤 낮은 거 한 것들)

    if (n % 2 == 0) { //짝수라면
        long long endSum = arr[0] + arr[n - 1];
        long long middleSum = 0;

        for (int i = 1; i < (n/2); i++) {
            middleSum = max(middleSum, arr[i] + arr[(n - 1) - i]);
        }

        result = max(middleSum, endSum);
    }
    else {
        long long maxEnd = arr[n - 1];
        long long middleSum2 = 0;

        for (int i = 0; i < ((n -1)/ 2); i++) {
            middleSum2 = max(middleSum2, arr[i] + arr[(n - 2) - i]);
        }


        result = max(maxEnd, middleSum2);
    }

    cout << result << '\n';

   
}