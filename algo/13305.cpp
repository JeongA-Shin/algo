#include <iostream>
#include <algorithm>
#include <vector>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

#define MAX 1000000000 // 10억

long long dist[100001];
long long price[100001];
long long N, sum;
long long greedy;

//이거 너무 어렵게 생각함...ㅠ
//그냥 말 그대로 어차피 처음부터 최소를 알 수 없음! 왜냐면 아예 처음부터 기름이 없으므로
//따라서 그냥 각 지점 지점마다 가격이 지금보다 싸면 바꾸고, 아니면 그냥 기존 가격으로 진행되는 식으로 하면 됨

int main()
{
	cin >> N;

	for (int i = 1; i <= N - 1; i++)
		cin >> dist[i];

	for (int i = 1; i <= N; i++)
		cin >> price[i];

	greedy = MAX;

	for (int i = 1; i <= N - 1; i++)
	{
		if (price[i] < greedy)
			greedy = price[i];
		sum += greedy * dist[i];
	}

	cout << sum;

}