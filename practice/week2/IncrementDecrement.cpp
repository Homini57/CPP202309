#include <iostream>

using namespace std;

int main()
{
	int x = 1;
	//1�� ��µ� �� x�� 1�� �������ϴ�.
	cout << "x = " << x++ << endl;
	//2�� ��µ� �� x�� 1�� �������ϴ�.
	cout << "x = " << x++ << endl;
	//x�� 1�� ������ �� 4�� ��µ˴ϴ�.
	cout << "x = " << ++x << endl;
	//4�� ��µ� �� x�� 1�� ������.
	cout << "x = " << x-- << endl;
	//3�� ��µ� �� x�� 1�� ������.
	cout << "x = " << x-- << endl;
	//x�� 1�� ���� �� 1�� ��µȴ�.
	cout << "x = " << --x << endl;

	return 0;
}