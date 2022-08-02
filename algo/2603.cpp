#include <iostream>

using namespace std;

// 이 풀이가 훨씬 덜 헷갈림
// 각 사분면의 첫 칸을 기준으로 사분면 탐색

/*
int n;
int paper[128][128];
int blue, white;

void solve(int y, int x, int size)
{
	int check = paper[y][x];

	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			//현재 사분면 각 칸을 모두 비교해줌- 한 칸이라도 기준 색이 아니면 check =2;

			if (check == 0 && paper[i][j] == 1) //하나의 색이 아니면
			{
				check = 2;
			}
			else if (check == 1 && paper[i][j] == 0) // //하나의 색이 아니면
			{
				check = 2;
			}

			// 만약 하나의 색이 아니면 나누어짐
			if (check == 2)
			{
				solve(y, x, size / 2);
				solve(y, x + size / 2, size / 2);
				solve(y + size / 2, x, size / 2);
				solve(y + size / 2, x + size / 2, size / 2);
				return;
			}
		}
	}


	if (check == 0)
		white++;
	else
		blue++;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> paper[i][j];

	solve(0, 0, n);
	cout << white << '\n';
	cout << blue << '\n';
	return 0;
}
*/



int arr[128][128];

//흰색은 0, 파란색은 1
int white = 0;
int blue = 0;

//각 꼭짓점들이 되는 (행 열) : 1-1, 1-2, 2-1, 2-2 순
// //원래는 
// 1 :  (0,0), (0,n/2),
//      (n/2,0),(n/2, n/2)
// 
// 2:   (0,n/2) (0,n)
//      (n/2,n/2),(n/2,n)
// 
// 3:   (n/2,0),(n/2,n/2)
//      (n,0),(n,n/2)
// 
// 4:   (n/2,n/2),(n/2,n)
//       (n,n/2),(n,n)


bool is_square(int, int, int, int);

int cnt = 0;

void get_cnt(int row_start, int row_end, int col_start, int col_end) {

	if (is_square(row_start, row_end, col_start,col_end)) { //하나의 색으로 이루어진 정사각형이면
		if (arr[row_start][col_start] == 0) white++;
		else blue++;
		return;
	}
	else {
		get_cnt(row_start,(row_start+row_end) / 2, col_start, (col_start+col_end)/2);
		get_cnt(row_start, (row_start+row_end) / 2, (col_start+col_end)/2, col_end);
		get_cnt((row_start+row_end) / 2, row_end, col_start, (col_start+col_end)/2);
		get_cnt((row_start + row_end) / 2, row_end, (col_start + col_end) / 2, col_end);
	}

	return;
}


//하나의 색으로만 이루어진 것인지 확인
bool is_square(int row_start, int row_end, int col_start, int col_end) {

	int val = arr[row_start][col_start];

	bool is_square = true;

	for (int i = row_start; i < row_end; i++) {
		for (int j = col_start; j < col_end; j++) {
			if (val != arr[i][j]) { //다른 색이 섞여 있다면
				is_square = false;
				return false;
			}
		}

		//if (!is_square) break;
	}

	return true;

}

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	get_cnt(0, n, 0, n);
	

	cout << white << endl;
	cout << blue << endl;

}


