#include <iostream>

using namespace std;

int main()
{
	//sizeof�Լ��� �Էµ� ���� ũ�⸦ ��ȯ�Ѵ�.
	//char�� ũ��� 1, int�� ũ��� 4, double�� ũ��� 8�̴�.
	cout << "char ũ�� : " << sizeof("p") << endl;
	cout << "int ũ�� : " << sizeof(10) << endl;
	cout << "double ũ�� : " << sizeof(10.8) << endl;

	return 0;
}