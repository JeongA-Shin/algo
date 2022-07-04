#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

vector<tuple<string,int, int, int>> vec; //2쌍이라면 pair, 3쌍이상이라면 튜플

//배열이 아닌 벡터를 쓰는 이유
// 2차원 배열을 정렬하기 위해서는 vector 컨테이너에 pair를 통해서 2차원 배열을 만들 수 있다.

bool cmp(tuple<string,int, int, int>& v1, tuple<string,int, int, int>& v2) {
	
	// year를 기준으로 오름차순 정렬하는데, year가 같으면 month를 기준으로, month가 같으면 day를 기준으로
	if (get<3>(v1) != get<3>(v2)) { //연도가 다르면
		return get<3>(v1) > get<3>(v2);
	}
	else { //연도가 같고
		if (get<2>(v1) != get<2>(v2)) {//달이 다르면
			return get<2>(v1) > get<2>(v2);
		}
		else {//달까지 같으면
			return get<1>(v1) > get<1>(v2); //날을 기준으로
		}
	}

	//모두 큰 것이 우선되는 것이므로 결론적으로 연소자부터 나오게 됨
}

int main() {


	int n;
	cin >> n;

	//일단 정보들을 모두 저장

	for (int i = 0; i < n; i++) {
		string name; int dd,mm, yyyy;

		cin >> name >> dd >> mm >> yyyy;

		vec.push_back(make_tuple(name,dd, mm, yyyy));
	}

	//그리고 후보들끼리 비교
	//하나 하나 하기에는 너무 코드가 복잡해짐, if지옥..
	// 모든 정보가 저장된 벡터를 통채로 정렬을 시켜버리자
	//그냥 sort로 해버리면 첫 번째 원소를 기준으로 정렬되므로 cmp 함수를 통해 커스텀 해줘야 한다,
	sort(vec.begin(), vec.end(),cmp);
	//cout << endl;
	
	/*
	for (int i = 0; i < vec.size(); i++) {
		cout << get<0>(vec[i]) << ":" << get<1>(vec[i]) << ":" << get<2>(vec[i])<< ":" << get<3>(vec[i]) << "\n";
	}
	*/


	cout << get<0>(vec[0]) << endl << get<0>(vec[vec.size() - 1]) << endl;



}