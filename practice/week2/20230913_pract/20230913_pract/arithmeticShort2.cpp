#include <iostream>

using namespace std;

int main()
{

	int two = 2;
	int eight = 8;
	int sum1 = 2;
	int sum2 = 8;
	// a *= b 는 a = a * b를 축약한 표현이다. 
	sum1 *= two;
	// a /= b 는 a = a / b를 축약한 표현이다
	sum2 /= eight;
	cout << "sum1 = " << sum1 << endl;
	cout << "sum2 = " << sum2 << endl;

	return 0;
}