#include <iostream>
#include <algorithm>
#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include <hash_map> //곧 없어진다는 에러가 떠서 그거랑 똑같은 unordered map으로 대체
#include <vector>
#include <string>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
/*
시간초과를 잘 통과해야하는 문제이다.

그러기 위해서는 해시맵을 사용해야하며 문제를 보면 번호를 주면 포켓몬 이름을 포켓몬 이름을 주면 도감 번호를 답해야한다.
하지만 해시맵은 Key, value가 있고 key값으로 value를 찾는건 빠르지만(포켓몬 이름(key)을 주었을 때 도감 번호(value)를 찾는) 
value(도감번호)로 key(포켓몬 이름) 값을 찾으려면 iter를 이용해서 하나하나 같은지 체크하면서 구해주어야 하므로 시간이 오래걸린다.
그래서 이 부분은 해시맵에서 해결하는 것이 아니라 배열에 포켓몬 이름을 저장해주어
도감 번호를 배열에 넣기만해도 답을 구할 수 있도록 구현하였다.

 hash라는 자료구조는 정렬이 필요 없으며 빠른 검색을 원할 때 사용합니다.

즉 시간초과를 통과하기 위해서 "이름을 key로" 해주는 해시맵 하나, 그냥 일반 배열 하나(혹은 벡터)로 해서
만약 이름이 주어지면 해시맵에서 key를 통해 찾고, 그냥 문제 번호로 주어지면 일반배열에서(혹은 벡터에서) 이름을 찾는다.

즉 해시맵은 키 값이 이름인 거고, 일반배열은 키 값이 번호인 거임
*/

hash_map<string, int> hashmap;
vector<string> vec;

int main() {
    fastio();

    int n, m;//포켓몬의 개수, 문제의 개수
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        hashmap.insert(hash_map<string, int>::value_type(name, i + 1));
        vec.push_back(name);
    }

    for (int i = 0; i < m; i++) {
       
        string key;
        cin >> key;

        //숫자가 들어왔다면 - 숫자가 키인 배열 (혹은 벡터)에서 찾음
        if (((key[0] - '0') > 0) && ((key[0] - '0') < 10)) {
            int idx = stoi(key);
            cout << vec.at(idx - 1) << endl;
        }
        else { // 글자가 들어왔다면 글자가 키인 hashmap에서 찾음
           cout<< hashmap.find(key)->second<<endl;
        }
    }


}