#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

vector<int> res[10];

vector<int> vec;

//따라서 분할 정복 기법으로 가면 쉬울 듯
   //완전 이진 트리라서
   /*즉 무슨 말이나면
   * 루트 노드를 중간에 방문하는 순회 방법이므로, 중간 값이 바로 루트 값일 것이다.
   이후엔 [처음~중간-1], [중간+1~끝]으로 범위를 나누고 각각의 범위에서 다시 중간 값을 찾는다.
   이와 같은 방식을 재귀 함수로 작성하여 실행
   */


//vector<vector<int>> graph;//연결 정보를 가지고 있게. 원래는 벡터"배열"로 하려고 했는데, 가능한 수가 너무 커서 그냥 벡터의 벡터로 감

//왼쪽 자식 -> 자기 자신 -> 오른쪽 자식
//preorder
/*
void preOrder(int startNode) {

    if (graph[startNode] != NULL) {

        preOrder(graph[startNode].at(0));
        cout << startNode << endl;
        preOrder(graph[startNode].at(1));
    }

}
*/


//분할정복방식 뼈대(노션 참고)를 활용해서 트리를 복구함
void makeTreeByDivide(int start, int end,int depth) { //파라미터의ㅣ depth는 현재 함수가 호출되었을 때==들어왔을 때,그 시점의 depth

    //cout << "( " << start<<" , " << end<<" , " << depth << " )" << endl;

    if (start <= end) {
        int middle = (start + end) / 2; 
        res[depth].push_back(vec.at(middle));
        //cout << "res[" << depth << "].push_back(" << middle << ")" << endl;
        makeTreeByDivide(start, middle - 1, depth+1);
        makeTreeByDivide(middle+1, end, depth+1);
    }
    else {
        return;
    }
 
}



int main() {
    fastio();

    int k;
    cin >> k;

    //트리 그대로 출력하라
    //완전 이진 트리임
  

    for (int i = 0; i < pow(2, k) - 1; i++) {
        int a;
        cin >> a;
        vec.push_back(a);
    }

    // 중간에 있는 애가 루트임
    int root_idx = vec.size() / 2;
    int root = vec.at(root_idx);
    //따라서 이거 기준 왼쪽에 있는 애들이 루트의 왼쪽 자식
    // 이거 기준 오른쪽에 있는 애들이 루트의 오른쪽 자식

    //따라서 분할 정복 기법으로 가면 쉬울 듯
    //완전 이진 트리라서
    /*즉 무슨 말이나면
    * 루트 노드를 중간에 방문하는 순회 방법이므로, 중간 값이 바로 루트 값일 것이다.
    이후엔 [처음~중간-1], [중간+1~끝]으로 범위를 나누고 각각의 범위에서 다시 중간 값을 찾는다.
    이와 같은 방식을 재귀 함수로 작성하여 실행
    */
       
    makeTreeByDivide(0, vec.size() - 1, 0);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i].at(j) << " ";
        }
        cout << endl;
    }


}