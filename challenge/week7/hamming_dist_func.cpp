#include <iostream>
#include <string>
using namespace std;
//���ڿ��� �ҹ��ڷ� ��ȯ�ϴ� �Լ�
string toLowerStr(string &str) {
	for (char& c:str) {
		 c= tolower(c); // c�� �����ϴ� ���� : str�� ���ڿ� �����Ͽ� �����ϱ� ����
						// �����͸� ���� �ʾƵ� �Ǵ� ���� : ���� ���, �������� �����ڴ� ����, �����ʹ� �ּҸ� �����ͷ� �ϴ� ����
	}
	return "";
}
//���ڿ��� �빮�ڷ� ��ȯ�ϴ� �Լ�
string toUpperStr(string &str) {
	for (char& c : str) {
		c = toupper(c);
	}
	return "";
}
//�ع� �Ÿ��� ����ϴ� �Լ�
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
	
	string s1, s2;//�Է¹��� �� ���ڿ�
	int count = 0;//�ع� �Ÿ��� ������ ����

	cout << "DNA1: ";
	cin >> s1;
	cout << "DNA2: ";
	cin >> s2;

	// ���ڿ� �ҹ���ȭ =>��ҹ��� ���� X
	toLowerStr(s1);
	toLowerStr(s2);

	// ���̰� �ٸ� �� ���ڿ��� ���Ͽ� ���� ���
	if (s1.length() != s2.length())
		cout << "����: ���̰� �ٸ�" << endl;

	//�ع� �Ÿ� ���, ���
	else {
		count = calcHammingDist(s1, s2);
		cout << "�ع� �Ÿ��� " << count << endl;
	}
	return 0;
}
