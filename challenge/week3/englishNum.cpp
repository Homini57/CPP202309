#include <iostream>

using namespace std;

int main()
{

	int number;
	cout << "���ڸ� �Է��Ͻÿ�:";
	cin >> number;//����ڿ��Լ� ���ڸ� �Է¹޾� number�� �����Ѵ�.
	if (number == 0)
		cout << "zero\n";//0�� �Է������� "zero"�� ����Ѵ�.
	else if (number == 1)
		cout << "one\n";//1�� �Է������� "one"�� ����Ѵ�.
	else
		cout << "many\n";//�� ���� ���� �Է������� "many"�� ����Ѵ�.
	return 0;
}