#include <iostream>
#include <string>
using namespace std;
//문자열을 소문자로 변환하는 함수
string toLowerStr(string &str) {
	for (char& c:str) {
		 c= tolower(c); // c를 참조하는 이유 : str의 문자에 참조하여 대입하기 위해
						// 포인터를 쓰지 않아도 되는 이유 : 같은 기능, 차이점은 참조자는 변수, 포인터는 주소를 데이터로 하는 변수
	}
	return "";
}
//문자열을 대문자로 변환하는 함수
string toUpperStr(string &str) {
	for (char& c : str) {
		c = toupper(c);
	}
	return "";
}
//해밍 거리를 계산하는 함수
int calcHammingDist(string s1, string s2) {
	int count = 0;
	//string s1_low = toLowerStr(s1);
	//string s2_low = toLowerStr(s2);
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] != s2[i])
			count += 1;
	}
	return count;
}

int main() {
	
	string s1, s2;//입력받을 두 문자열
	int count = 0;//해밍 거리를 저장할 변수

	cout << "DNA1: ";
	cin >> s1;
	cout << "DNA2: ";
	cin >> s2;

	// 문자열 소문자화 =>대소문자 구분 X
	toLowerStr(s1);
	toLowerStr(s2);

	// 길이가 다른 두 문자열에 대하여 오류 출력
	if (s1.length() != s2.length())
		cout << "오류: 길이가 다름" << endl;

	//해밍 거리 계산, 출력
	else {
		count = calcHammingDist(s1, s2);
		cout << "해밍 거리는 " << count << endl;
	}
	return 0;
}
