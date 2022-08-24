#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;


//map을 활용해 볼까, 이름이 key, 등장횟수가 value
//거기다 map은 사전순 배열, 거기다 중복도 허용하지 않음
int main() {
    fastio();
     
    map<string, float> dict; //map은 key와 value가 이미 pair임. 따라서 map<pair<string, int>> dict하면 오류남
    string str;

    //키의 존재 여부 확인은 find로도 가능
    //dict.find(str) != dict.end()

    int total = 0;

    while (getline(cin,str)) { // 윈도우에서 ctrl + z 할 때가지 줄로 입력 받음
        total += 1;
        //만약 키가 이미 있다면
        if (dict.count(str)){
            //int val = dict.at(str) + 1; //횟수 증가
            dict[str] += 1;//횟수 증가
        }
        else {//없다면
            dict.insert({ str,1 });
        }
    }

  

    //소수점 자리 수 설정하기
    cout << fixed; ////소수점 자릿수 고정
    cout.precision(4);

    for (auto iter = dict.begin(); iter != dict.end(); iter++) {
        float res = (iter->second / total) * 100;
        cout << iter->first << " " << res << '\n';
   }
    
}