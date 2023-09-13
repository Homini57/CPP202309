#include <iostream>

using namespace std;

int main()
{
	//sizeof함수는 입력된 값의 크기를 반환한다.
	//char의 크기는 1, int의 크기는 4, double의 크기는 8이다.
	cout << "char 크기 : " << sizeof("p") << endl;
	cout << "int 크기 : " << sizeof(10) << endl;
	cout << "double 크기 : " << sizeof(10.8) << endl;

	return 0;
}