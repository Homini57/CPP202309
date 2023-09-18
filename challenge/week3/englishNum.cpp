#include <iostream>

using namespace std;

int main()
{

	int number;
	cout << "숫자를 입력하시오:";
	cin >> number;//사용자에게서 숫자를 입력받아 number에 저장한다.
	if (number == 0)
		cout << "zero\n";//0을 입력했으면 "zero"를 출력한다.
	else if (number == 1)
		cout << "one\n";//1을 입력했으면 "one"을 출력한다.
	else
		cout << "many\n";//그 외의 값을 입력했으면 "many"를 출력한다.
	return 0;
}