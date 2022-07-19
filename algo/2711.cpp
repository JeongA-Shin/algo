#include <iostream>
using namespace std;


int main() {
	int num;
	cin >> num;//테스트 케이스 개수

	for (int i = 0; i < num; i++) {
		int index;
		string word;

		cin >> index >> word;
		 
		////반례: 제일 마지막 글자가 오타인 경우
		if (index == word.size()) {
			word[index - 1] = word[index];
		}

		//실제 인덱스는 index -1
		//반례: 제일 마지막 글자가 오타인 경우를 생각하지 못해서 틀렸음 
		for (int i = index-1; i < word.size(); i++) { //4가 입력되면 4번째 글자가 삭제됨
			word[i] = word[i + 1];
		}

		cout << word << endl;

	}

}


/*
* 
* #include <iostream>
#include <string>
using namespace std;
int main() {
    int T,index;
    string w;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> index >> w;
        for (int i = 0; i < w.size(); i++)
        {
            if (i != index - 1)
                cout << w[i];
        }
        cout << '\n';
    }
}

*/