#include <iostream>

using namespace std;

int main()
{
	int x = 1;
	//1�� ��µ� �� x�� 1�� �������ϴ�.
	cout << "x = " << x++ << endl;
	//2�� ��µ� �� xdp 1�� �������ϴ�.
	cout << "x = " << x++ << endl;
	//x�� 2�� ������ �� 3�� ��µ˴ϴ�.
	cout << "x = " << ++x << endl;
	cout << "x = " << x-- << endl;
	cout << "x = " << x-- << endl;
	cout << "x = " << --x << endl;

	return 0;
}