#include <iostream>
#include <algorithm>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

long long diff[300001];
long long height[300001];

bool cmp(int a, int b) {
    return a > b; //정렬 조건 함수. 참이면 a부터 나오도록
}

int main() {
    fastio();


    long long n,k;
    cin >> n >> k; //총 수와 조의 수


    //잊지말자 그리디는 그냥 순간 순간만 생각하면 됨
    //그리디에서 중요한 것: 어떤 것을 생각할 것인지! 이 문제의 경우에는 옆 사람과의 키 차이임

    //티셔츠를 맞추는 비용은 조 내부에서 가장 키가 큰 사람과 작은 사람의 차이
    //옆사람과의 키 차이를 저장한 뒤, 그 키 차이에서 "큰" 순서대로 K개만큼 제외해준 다음 제외되지 않은 키 차이들을 전부 더한다면 이것이 조별로 드는 비용이 될 것이다


    //다시 말해,
    // K개의 조로 나눴을 때 ,"키 차이가 큰 애들일 수록 다른 조"여야 유리한 거임
    // 근데 여기서는 무조건 인접한 애들끼리만 조가 되어야 하는 것이므로, 결국 옆 사람과의 차이가 큰 애들 사이에 경계를 두는 것
    // 같은 조인데 키 차이가 제일 크면 진짜 최악이되는 것이므로
    
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    for (int i = 0; i < n-1; i++) {
        diff[i] = height[i + 1] - height[i];
    }

    sort(diff, diff + n-1,cmp); //키 차이 큰 애들 순대로 정렬

    long long sum = 0;
    for (int i = k-1; i < n-1; i++) {
        sum += diff[i];
    }

    cout << sum << endl;

}