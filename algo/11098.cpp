#include <iostream>
#include <map>
using namespace std;

int main() {

	int n;
	cin >> n;


	//map<string, int> players;

	//처음엔 map에 선수 이름이랑 값을 넣어서 비교해보려고 했는데
	//생각해보니까 굳이 이럴 필요가 없음
	//그냥 평소 min, max 비교하듯이 입력 받는 순간에 비교해서 끝내버리면 됨


	for (int i = 0; i < n; i++) {
		int p;
		int max = 0;
		string res_name = "";

		cin >> p;

		for (int j = 0; j < p; j++) {
			int c; string name;
			cin >> c >> name;

			if (max < c) {
				max = c;
				res_name = name;
			}
		}

		cout << res_name << endl;
	}


	return 0;


}