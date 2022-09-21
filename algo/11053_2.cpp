#include <iostream>
#include <algorithm>
#include <vector>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

//가장 긴 증가하는 부분 수열
int arr[1001];
int memo[1001] = { 1, };


int main() {
    fastio();

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        //수열을 입력
        cin >> arr[i];
    }


    for (int i = 0; i < n; i++) {
        int node = arr[i];//현재 카운트 기준 노드
        for (int j = 0; j < i; j++) {
            if (node > arr[j]) { //더 작은 애가 있다면
                memo[i] = max(memo[i], memo[j] + 1); // 그 더 작은애 길이 +1을 해줌    
            }
        }
    }


    /* 두 번째 삽질.
    * 이러면 당연히 기준 노드보다 작은 애들은 무조건 카운트가 되버림
    for (int i = 0; i < n; i++) {
        int node = arr[i];
        cout << "current: " << node << endl;
        int cnt = 1;

        for (int j = 0; j < i; j++) {
            if (arr[j] < node) {
                cout <<"j: "<<j<<" val: "<< arr[j] << "is counted" << endl;
                cnt++;
                cout <<"middle cnt: "<< cnt << endl;
            }
        }

        memo[i] = cnt;
        cout <<"memo cnt: "<< cnt << endl;


        cout << endl;
    }
    */

    // 1. 첫 번째 삽질
    //각각을 시작노드로 했을 때 수열의 길이를 memo에 저장함
    /*
    * 이렇게 풀었을 때의 문제점
    더 커진다고 무조건 잡으면 안 됩니다.
    1 100 2 3 4 5 6 7 이 경우에 100이 1보다 크다고 해서 덥석 잡아버리면 정답을 못 찾습니다.

*/
    /*
    for (int i = 0; i < n; i++) {
        vector<int> vec;
        int start_node = arr[i];
        vec.push_back(start_node);

        for (int j = i+1; j < n; j++) {
            int node = arr[j];
            if (node > vec.back()) {
                vec.push_back(node);
            }
         
        }

        memo[i] = vec.size();
        
    }
    */

    
}