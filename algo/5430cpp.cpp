#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

//큐 활용해보자
queue<int> que;
stack<int> stk;

//이렇게 큐랑 스택 왔다갔다하면서 해버리면 시간 초과가 남.
//상수 시간 안에 작업들을 해결 해야 함

//(Deque)
//그래서 필요한 게 덱... 덱의 존재도 몰랐움,, 반성..

//!! 덱은 큐+ 스택이라서 앞과 뒤 양 사이드에서 입출력이 가능함!!
//dq.push_front(x) : dq의 첫 번째 원소에 'x' 추가
//dq.push_back(x) : dq의 마지막 원소에 'x' 추가
//dq.pop_front() : dq의 첫 번째 원소 삭제
//dq.pop_back() : dq의 마지막 원소 삭제

//아래 코드 수정 방향 = 큐가 아니라 덱을 선언하여 저장
// 정방향과 역방향을 나타내는 flag를 두어
// R이면 그냥 단순히 !!!flag의 값을 바꾸어주고, 
//D 를 실행해야 할 때 
//flag가 참이면- 정방향이면 맨 앞의 원소를 제거
//flag가 거짓이면- 역방향이면 맨 뒤의 원소를 제거

// 그리고 이렇게 쭉 가다가(주어진 r,d 모두 수행 한 후)
//출력한 시점이 되었을 때,
//현재 flag가 정방향(참)이면 덱의 앞에서부터 출력
//현재 flag가 역방향(거짓)이면 덱의 뒤에서부터 출력



void rmethod(queue<int>& que) {
    
    while (que.size() != 0) {
        int front = que.front();
        stk.push(front);
        que.pop();
    }

   
    while (stk.size() != 0) {
        int top = stk.top();
        que.push(top);
        stk.pop();
    }
}


void dmethod(queue<int>& que) {

    if (que.size() == 0) {
        cout << "error" << '\n';
        return;
    }

    que.pop();
}


void print(queue<int>& que) {

    cout << "[";
    while (que.size() != 0) {
        int front = que.front();
        if (que.size() == 1) cout << front;
        else  cout << front << ",";
        que.pop();
    }
    cout << "]" << endl;
}

//0 1 2 3 4 5


int main() {
    fastio();

    // 여기에 구현

    //r은 배열의 수의 순서를 뒤집는 함수 - 큐나 스택으로 해버리면 쉬울 듯
    //d는 첫번째 수를 버리는 함수 - 현재 배열이 비었는데 이러면 에러남

    int t; //총 테스트케이스 개수
    string p; //RDD
    int n; //배열 안 원소의 개수
    string arr;

    cin >> t;

    for (int i = 0; i < t; i++) {

        cin >> p; //rdd
        cin >> n; //배열 안 원소의 개수
        cin >> arr;// [x1, ..., xn] 과 같은 형태로 배열에 들어있는 정수

        //배열을 그대로 큐로 만들기
        arr = arr.substr(1, arr.length() - 2); //시작 시점과 길이 ////좌우 [,]는 빼기
        //그리고 , 기준으로 구분 - 왜냐면 두 자리, 세자리일수도 있으니까

        //cout << "arr:"<<arr << endl;//1,2,3,4
        string num;
        for (int j= 0; j < arr.length(); j++) {

            if (j != arr.length() - 1 && arr[j] != ',') {
                num += arr[j];
                continue;
            }
            else if (j == arr.length() - 1) {
                num += arr[j];//마지막까지
            }

            int element = stoi(num);
            que.push(element);
            num = "";//초기화
        }

        //r,d 함수 실행
        for (int j = 0; j < p.length(); j++) {
            if (p[j] == 'R') {
                rmethod(que);
            }
            else {
                dmethod(que);
            }
        }

        //결과 출력과 동시에 다음 케이스 들어가기전 clear해주기
        if (que.size() != 0) print(que);
    }


}