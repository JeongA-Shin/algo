#include <iostream>
#include <algorithm>
#include <string>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

//GREEDY

bool flag = true;
string word;

void greedyJudge(string result) {

    if (result.length() <= 0)return;

    int max_a_count = result.length() / 4; //일단 최적 == 들어갈 수 있는 A의 최대 개수
    int remain_length = result.length() - 4 * max_a_count; //남은 나머지

    if (remain_length % 2 == 0) {
        for (int i = 0; i < max_a_count; i++) {
            word += "AAAA";
        }
        if (remain_length != 0) {
            word += "BB";
        }

    }
    else {
        flag = false;
        return;
    }
}


int main() {

    string board;
    cin >> board;


    int cur_position = 0; // 구분에서 시작되는 포지션
    int position; //구분에서 끝나는 포지션//구분자의 인덱스
    string separator = ".";

    if (board[0] == '.') {
        for (int i = 0; i < board.length(); i++) {
            if (board[i] == '.') {
                word += ".";
                cur_position++;
            }
            else {
                break;
            }
        }

    }

    bool visited = false;
    while ((position = board.find(separator, cur_position)) != string::npos) { //중간에 찾았다면
        int len = position - cur_position;//현재꺼 - 이전 기준길이를 빼면 해당 문자열의 길이
        string result = board.substr(cur_position, len);
        visited = true;
        greedyJudge(result);

        //cout << ".";
        word += ".";
        cur_position = position + 1;//다음 것부터 찾음
    }


    if (visited && flag == false) {
        cout << -1 << endl;
    }
    else {
        string result = board.substr(cur_position); //나머지 끝까지
        greedyJudge(result);

        if (flag == false) {
            cout << -1 << endl;
        }
        else {
            cout << word << endl;
        }
    }
}
