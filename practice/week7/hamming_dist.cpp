#include <iostream>
#include <string>
using namespace std;

int main() {
	
	string s1, s2;//�Է¹��� �� ���ڿ�
	int count = 0;//�ع� �Ÿ��� ������ ����

	cout << "DNA1: ";
	cin >> s1;
	cout << "DNA2: ";
	cin >> s2;

	// ���̰� �ٸ� �� ���ڿ��� ���Ͽ� ���� ���
	if (s1.length() != s2.length())
		cout << "����: ���̰� �ٸ�" << endl;
	//�ع� �Ÿ� ���, ���
	else {
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] != s2[i])
				count += 1;
		}
		cout << "�ع� �Ÿ��� " << count << endl;
	}
	return 0;
}