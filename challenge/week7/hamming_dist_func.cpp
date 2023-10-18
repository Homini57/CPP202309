#include <iostream>
#include <string>
using namespace std;
string toLowerStr(string str) {
	for (char& c:str) {
		 c= tolower(c);
	}
	return 0;
}
string toUpperStr(string str) {
	for (char& c : str) {
		c = toupper(c);
	}
	return 0;
}

int calcHammingDist(string s1, string s2) {
	int count = 0;
	toLowerStr(s1);
	toLowerStr(s2);
	printf("%s", s1);
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] != s2[i])
			count += 1;
	}
	return count;
}

int main() {
	string s1, s2;
	int count = 0;

	cout << "DNA1: ";
	cin >> s1;
	cout << "DNA2: ";
	cin >> s2;


	if (s1.length() != s2.length())
		cout << "오류: 길이가 다름" << endl;
	else {
		count = calcHammingDist(s1, s2);
		cout << "해밍 거리는 " << count << endl;
	}
	return 0;
}
