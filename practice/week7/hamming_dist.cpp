#include <iostream>
#include <string>
using namespace std;

int main() {
	
	string s1, s2;//입력받을 두 문자열
	int count = 0;//해밍 거리를 저장할 변수

	cout << "DNA1: ";
	cin >> s1;
	cout << "DNA2: ";
	cin >> s2;

	// 길이가 다른 두 문자열에 대하여 오류 출력
	if (s1.length() != s2.length())
		cout << "오류: 길이가 다름" << endl;
	//해밍 거리 계산, 출력
	else {
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] != s2[i])
				count += 1;
		}
		cout << "해밍 거리는 " << count << endl;
	}
	return 0;
}