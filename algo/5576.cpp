#include <iostream>
#include <algorithm>
using namespace std;

//참가한 10 명 중 득점이 높은 사람에서 3 명의 점수를 합산하여 대학의 득점으로

int wscores[11];
int kscores[11];

int main() {

	for (int i = 0; i < 10; i++) {
		int score;
		cin >> score;
		wscores[i] = score;
	}

	sort(wscores, wscores + 11); //오름차순, 따라서 제일 첫 칸(인덱스 0)은 0

	int w_max = wscores[10] + wscores[9] + wscores[8];

	for (int i = 0; i < 10; i++) {
		int score2;
		cin >> score2;
		kscores[i] = score2;
	}

	sort(kscores, kscores + 11);

	int k_max = kscores[10] + kscores[9] + kscores[8];

	cout << w_max << " " << k_max << endl;
}