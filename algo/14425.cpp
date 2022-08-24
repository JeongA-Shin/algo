#include <iostream>
#include <algorithm>
#include <set>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

set<string> stringSet;

int main() {
    fastio();

    // 여기에 구현

    int n, m;
    cin >> n >> m;

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        stringSet.insert(word);
    }

    for (int i = 0; i < m; i++) {
        string my_word;
        cin >> my_word;

        auto iter = stringSet.find(my_word);
        if (iter != stringSet.end()) { //존재한다면
            cnt++;
        }
    }

    cout << cnt << endl;
}