#include <iostream>//��� ���� �ҷ�����

using namespace std;//�̸� ���� ����

int main()
{
	int a, b, c, lowest;

	cout << "3���� ������ �Է��Ͻÿ� : ";
	cin >> a >> b >> c; // ���� 3���� �Է¹޴´�.

	if (a < b && a < c)//a �� �ٸ� �� ������ ������ a�� lowest�� ����ȴ�.
		lowest = a;
	else if (b < a && b < c)//b �� �ٸ� �� ������ ������ b�� lowest�� ����ȴ�.
		lowest = b;
	else
		lowest = c;// ������ ���� c�� ���� ���� ����̹Ƿ� c�� lowest�� ����ȴ�.
	cout << "���� ���� ������" << lowest << endl; //lowest�� ��¹޴´�.
	return 0;

}