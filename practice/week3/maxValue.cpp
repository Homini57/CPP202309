#include <iostream>//��� ���� �ҷ�����

using namespace std;//�̸� ���� ����

int main()
{
	int a, b, c, largest;

	cout << "3���� ������ �Է��Ͻÿ� : ";
	cin >> a >> b >> c; // ���� 3���� �Է¹޴´�.

	if (a > b && a > c)//a �� �ٸ� �� ������ ũ�� a�� largest�� ����ȴ�.
		largest = a;
	else if (b > a && b > c)//b �� �ٸ� �� ������ ũ�� b�� largest�� ����ȴ�.
		largest = b;
	else
		largest = c;// ������ ���� c�� ���� ū ����̹Ƿ� c�� largest�� ����ȴ�.
	cout << "���� ū ������" << largest << endl; //largest�� ��¹޴´�.
	return 0;


}