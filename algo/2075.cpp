#include <iostream>
#include <algorithm>
#include <queue>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;


// pq(사실상 힙)도 정렬의 일종임
int main() {
    fastio();

    // 여기에 구현
    priority_queue<int> pq; //디폴트는 큰 게 우선순위. 즉 max heap이 디폴트

   
    int n;
    cin >> n;

    //단, 아래와 같이 n*n 모두 받아 실행하면 메모리 초과 뜬다. ㅠㅠ
    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;

            pq.push(a);
        }
    }
    */
    //총 n + 1개만 남도록 입력 개수가 n 초과되면
    // pop() 한 이후에 입력받은 수를 넣는다.
    // 즉 최소한 n번째 큰 수이므로 처음부터 제일 큰 수가 들어왔다는 가장 적게 pop할 수 있는 상황 가정

   
    for (int i = 0, tmp; i < n * n; i++) {
        cin >> tmp;
        //즉 pq에는 다 담을 필요 없이 늘 상위 n+1개만 남아있도록!!
        if (pq.size() > n) {
            pq.pop(); //기존의 제일 상위가 떨어져 나감 - 여기서 n개 남음
        }
        pq.push(tmp); //+1개
    }

    //N번째 큰 수 찾아서 출력
    pq.pop();
    cout << pq.top();


}