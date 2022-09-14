#include <iostream>
#include <algorithm>
#include <string>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;


int main() {
    fastio();
    long long a, b; //혹시나 오버플로우 방지
    cin >> a >> b;


    int cnt = 0;
  
    bool flag = false;

    //나는 거꾸로 b에서 a 만들어버리면 될 듯

    while (b >= a) {

        if (b % 2 == 0) { //짝수면 
            b = b / 2;
            cnt++;
        }else { //홀수면
            string temp2 = to_string(b);
            long long length = temp2.length();

            if (temp2[length - 1] != '1') { //1로 끝나지 않는 홀수면 - 처음에 이 경우를 처리하는 걸 깜빡해서 틀림
                break;
            }

            string temp3 = "";
            for (int i = 0; i < length - 1; i++) {
                temp3 += temp2[i];
            }
            cnt++;
            b = stoi(temp3); //string to int
        }

        if (b == a) {
            cout << cnt + 1 << endl;
            flag = true;
            break;
        }
    }



    if (!flag) {
        cout << -1 << endl;
    }
    
}