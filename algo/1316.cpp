#include <iostream>
#include <vector>
#include <algorithm>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

//즉 같은 단어가 떨어져서 또 나타나면 그룹 단어가 아님

/*
if(find(v.begin(), v.end(), 0) == v.end()) { // vector내에 0이 존재하지 않음
		cout << "not exist\n";
	}

	if(find(v.begin(), v.end(), 6) != v.end()) { // vector내에 6이 존재함
		cout << find(v.begin(), v.end(), 6) - v.begin(); // index 확인
	}
*/


int main() {
	fastio();
	int n;
	cin >> n;

	int cnt = 0;

	for (int i = 0; i < n; i++) {

		bool is_group_word = true;

		vector<char> vec; //현재 단어에 어떤 그룹들이 있는지

		string word;
		cin >> word;

		vec.push_back(word[0]);

		for (int j = 1; j < word.size(); j++) {
			if (word[j] != vec.back()) { //바로 앞 글자와 다른 글자. 즉 다른 그룹의 등장. 그리고 이 그룹이 이전에 존재했는지 판단
				if (find(vec.begin(), vec.end(), word[j]) == vec.end()) {//완전히 새로운 그룹이라면 vec에 추가
					vec.push_back(word[j]);
				}
				else {//이미 이전에 있었다면 이 단어는 그룹 단어가 아님
					is_group_word = false;
					break;
				}
			}
		}

		if (is_group_word) {
			cnt++;
		}

	}

	cout << cnt << endl;
}