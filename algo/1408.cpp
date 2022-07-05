#include <iostream>
#include <string>
using namespace std;

int main() {

	string now;
	string start;

	cin >> now >> start;

	//1. 임무 시작 시간이 현재보다 큼 == 현재 날을 넘김
	//    따라서 남은 시간 == 임무 시작 시간(== 현재 날의 데드라인) - 현재 시간

	//2. 임무 시작 시간이 현재보다 작음 == 현재 아직 날을 넘기지 않음
	//   따라서 남은 시간 == 24시간 - (현재 시간 - 임무 시작 시간)

	// 연산시에는 단위를 맞춰줘야 함. (일반적으로 가장 작은 단위) == 초로 맞춰주자(변환이 제일 간단함)
	int now_hour = ((now[0]-'0') * 10) + (now[1]-'0'); //13 string to int
	int now_min = ((now[3] - '0') * 10) + (now[4] - '0');//52
	int now_sec = ((now[6] - '0') * 10) + (now[7] - '0');//30

	int now_to_sec = now_hour * 3600 + now_min * 60 + now_sec;
	
	int start_hour = ((start[0] - '0') * 10) + (start[1] - '0'); //string to int
	int start_min = ((start[3] - '0') * 10) + (start[4] - '0');//
	int start_sec = ((start[6] - '0') * 10) + (start[7] - '0');//

	int start_to_sec = start_hour * 3600 + start_min * 60 + start_sec;


	//현재를 초로 변환, 시작 시간도 초로 변환한 후에 두 개를 뺸 것의 절댓값을 구함
	int res_sec;


	if (start_to_sec >= now_to_sec) {
		res_sec = start_to_sec - now_to_sec;
	}
	else {
		res_sec = 24 * 3600 - (now_to_sec - start_to_sec);
	}
	

	int res_hour = res_sec / 3600;

	int res_min = (res_sec % 3600) / 60;

	res_sec = res_sec - res_hour*3600 - res_min*60;

	string resHour;
	string resMin;
	string resSec;

	if (res_hour>=10) {
		resHour =to_string(res_hour);
	}
	else {
		resHour = "0" + to_string(res_hour);
	}

	if (res_min >= 10) {
		resMin = to_string(res_min);
	}
	else {
		resMin = "0" + to_string(res_min);
	}

	if (res_sec >= 10) {
		resSec = to_string(res_sec);
	}
	else {
		resSec = "0" + to_string(res_sec);
	}

	cout << resHour << ":" << resMin << ":" << resSec << endl;

	return 0;


}