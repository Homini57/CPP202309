#include <iostream>

using namespace std;

int main()
{

	int two = 2;
	int eight = 8;
	int sum1 = 2;
	int sum2 = 8;
	// a *= b �� a = a * b�� ����� ǥ���̴�. 
	sum1 *= two;
	// a /= b �� a = a / b�� ����� ǥ���̴�
	sum2 /= eight;
	cout << "sum1 = " << sum1 << endl;
	cout << "sum2 = " << sum2 << endl;

	return 0;
}