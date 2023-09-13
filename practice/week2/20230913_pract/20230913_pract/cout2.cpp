#include <iostream>
#include <string>

using namespace std;

int main()
{
	//문자형, 정수형, 부동소수점형,
	//논리형, 문자열형 변수를 선언, 초기화합니다.
	char character = 'C';
	int integer = 100;
	double precision = 3.14159;
	bool is_true = true;
	string word = "Hello World";

	//변수들을 출력합니다.
	cout << "char : " << character << endl;
	cout << "int : " << integer << endl;
	cout << "double : " << precision << endl;
	cout << "bool : " << is_true << endl;
	cout << "string : " << word << endl;

	return 0;
}