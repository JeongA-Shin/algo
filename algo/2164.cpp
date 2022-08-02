#include <iostream>
#include <queue>
using namespace std;

queue<int> que;

int main() {
	int n;
	cin >> n;

	for (int i = 1; i < n+1; i++) {
		que.push(i);
	}

	while (que.size() > 1) {
		que.pop(); //제일 위에 있는 카드를 바닥에 버린다.
		//제일 위에 있는 카드를 제일 아래에 있는 카드 밑으로 옮긴다.
		int element = que.front();
		que.pop();
		que.push(element);
		
	}

	cout << que.front() << endl;

}