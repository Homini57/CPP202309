#include <iostream>

using namespace std;

int main()
{
	// ���� ��, ������ ������ ����
	int money = 0, price = 0;

	// ���� ��, ���� �Է�
	cin >> money >> price;

	// ���� ��, ����, ���� ���� ĵ�� ��, �ܵ� ���
	cout << "���� ������ �ִ� ��: " << money << endl;
	cout << " ĵ���� ����: " << price << endl;
	cout << "�ִ�� �� �� �ִ� ĵ�� = "<< money/price << endl;
	cout << "ĵ�� ���� �� ���� �� = " << money % price << endl;
	
	return 0;

}