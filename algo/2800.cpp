#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

//dfs+ 백트래킹 == dfs로 진행하면서 해당 노드를 넣을지 말지 결정

//각 괄호쌍이 dfs의 대상임
//즉 vector<pair<int, int>> bracket;의 각 노드들을 dfs로 방문한 것. 왼쪽 노드는 오른쪽 노드의 부모처럼 생각하면 됨

// 각 괄호쌍을 방문했다 == 그 괄호쌍을 삭제한다

vector<bool> isSelected;// 전체 노드별 방문 여부

vector<pair<int, int>> bracket; // { 열림 괄호 인덱스, 닫힘 괄호 인덱스} 이렇게 저장됨, 각 괄호쌍들의 인덱스 정보 저장
vector<bool> isVisited(10, false);// 괄호"쌍"별 방문 여부 //위 braceket에 담겨져 있는 각 괄호쌍별(즉 각 pair별) 방문 여부 //문제 조건상 최대 괄호쌍== pair의 개수는 10개임

set<string> result;// 사전 순 정렬 및 중복 제거를 위함

string str;

//reference
//https://m42-orion.tistory.com/54


void dfs(int idx, int cnt) { //idx는 검색 시작 노드의 인덱스, cnt는 "이미" 선택된 == 제거된 괄호의 쌍 개수

    cout << "this dfs: " << idx << " " << cnt << endl;

    if (cnt >= 1) { //방문된 괄호의 쌍이 1개 이상이라면 이제 그 방문된 괄호들을 뺀 식을 알아야 함
        string s = "";
        for (int i = 0; i < str.length(); i++) {
            if (isSelected[i]) continue; // 방문된 괄호는 제외하고 식을 만듦
            s += str[i];
        }
        //그리고 그 생성된 식은 집합인 result에 추가
        if (!result.count(s)) {
            cout << "this s: "<<s << endl;
            result.insert(s);
        }
    }



    //시작노드를 바꾸어주는 것. 현재 루트노드는 (3,5) 인데 루트 노드 없이 (0,6)만 포함하는 경우도 있으므로
    for (int i = idx; i < bracket.size(); i++) {
        //이번 괄호쌍을 아직 방문했다면 패스
        if (isVisited[i]) {
            cout << "already visited this pair:" << i << endl;
            continue;
        }

        //아직 이번 괄호쌍을 아직 방문하지 않았다면 
        cout << "now visited this pair:" << i << endl;
        isVisited[i] = true; //이번 괄호"쌍"방문 여부 true
        // 전체노드 레벨에서 이번에 방문한 괄호쌍의 각 열림, 닫힘 괄호 노드들도 방문했다고 업데이트
        cout << "now visited this index for braceket :" << bracket[i].first<<" , "<< bracket[i].second << endl;
        isSelected[bracket[i].first] = true;
        isSelected[bracket[i].second] = true;

        cout << "---start-----" << endl;
        dfs(i + 1, cnt + 1); // 이제 연결된 자식 노드 방문
        cout << "----this dsf comeback: "<<idx<<" "<<cnt<<"----" << endl;

        cout << "now make unvisited this pair:" << i << endl;
        isVisited[i] = false; 
        cout << "now make unvisited this index for braceket :" << bracket[i].first << " , " << bracket[i].second << endl;
        isSelected[bracket[i].first] = false;
        isSelected[bracket[i].second] = false;


    }

}

int main() {
    fastio();

    // 여기에 구현

    //올바른 괄호쌍을 제거해서 나올 수 있는 "식"의 모든 케이스를 "사전식으로" 출력
    
    //사전식으로 출력해야 함 == set을 활용해야 함
    // 왜냐면 C++에서 Set은 사전정렬이므로!
    //그리고 모든 조합(케이스)를 찾는다 ==  백트래킹(DFS) 활용

  
    cin >> str;

    isSelected.assign(str.length(), false);


    //bracket 정보 획득
    stack<int> stk;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') { // 스택에 열린 괄호의 인덱스를 나오는 순서대로 쌓음
            stk.push(i);
        }
        else if (str[i] == ')') { //만약 닫힌 괄호를 만났다면 현재 stack의 top을(현재 제일 마지막에 나온 열린 괄호의 인덱스) pop하고 이 닫힌 괄호의 인덱스와 페어를 만들어서 bracket에 저장
            int open_idx = stk.top();
            stk.pop();
            bracket.emplace_back(make_pair(open_idx, i)); //emplace_back 과 push_back 비슷
        }
    }

    dfs(0, 0);


    for (auto iter = result.begin(); iter != result.end(); iter++) {
        cout << *iter << '\n';
    }



}