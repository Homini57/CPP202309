#include <iostream>

using namespace std;

int main()
{
	int x = 1;
	//1이 출력된 후 x에 1이 더해집니다.
	cout << "x = " << x++ << endl;
	//2가 출력된 후 x이 1이 더해집니다.
	cout << "x = " << x++ << endl;
	//x에 1이 더해진 후 4가 출력됩니다.
	cout << "x = " << ++x << endl;
	//4가 출력된 후 x에 1이 빼진다.
	cout << "x = " << x-- << endl;
	//3이 출력된 후 x에 1이 빼진다.
	cout << "x = " << x-- << endl;
	//x에 1이 빼진 후 1이 출력된다.
	cout << "x = " << --x << endl;

	return 0;
}