#include <iostream>
#include <algorithm>
#include <vector>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

//그리디 - 모든 로프를 사용해야 할 필요는 없으며, 임의로 몇 개의 로프를 골라서 사용해도 되므로
// 최댓값부터 적용해봄
//그리고 해 탐색 및 선택을 여러번 해보는 쪽으로!


long long arr[100001];

bool cmp(int a, int b) {
    return a > b; // 뭐든지 오른쪽 항을 기준으로 생각. 지금 오른쪽 항이 더 작은 거니까 내림차순임
}

int main() {
    fastio();

    // 여기에 구현

    //로프들을 이용하여 들어올릴 수 있는 물체의 최대 중량을 구해내는

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

   // sort(vec.begin(), vec.end()); //디폴트는 오름차순

    sort(arr,arr+n,cmp); //내림차순
    // 모두 고르게 w/k 만큼의 중량
    //즉,따라서 병렬로 연결되어 있는 어떤 로프의 최대 중량을 초과할 수는 없다!!!!!!!!!!
    //다시 말해서, "가장 적은 수치의 최대 중량"이 각 로프들에 걸릴 수 있는 최대 하중이 되는 것

     //즉, 110, 70, 40, 35, 20, 5 이렇게 있다면
    // 110 하나의 로프만 있으면 110*1 따라서 최대 중량은 110
    //100 과 70 이렇게 두 개의 로프면 70*2 따라서 최대 중량은 140

    long long  max = 0;

    for (long long i = 0; i < n; i++) {
        long long temp = arr[i] * (long long)(i + 1);
        if (max < temp) {
            max = temp;
        }
    }

    cout << max << endl;
    


}