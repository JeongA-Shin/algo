#include <iostream>
#include <algorithm>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;



long long gcd(int a, int b)
{
	int mod = a % b; //나눈 나머지

	while (mod > 0)
	{
		a = b;
		b = mod;
		mod = a % b; //그리고 두 번째는 첫 항으로, 두 번째 항은 갱신된 나머지로
	}

	return b; 
}

int main() {
    fastio();

    // 여기에 구현
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		long long a, b;
		cin >> a >> b;
		long long max = gcd(a, b);
		long long min = (a * b) / max;
		cout << min << endl;
	}
}