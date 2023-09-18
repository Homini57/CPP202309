#include <iostream>//헤더 파일 불러오기

using namespace std;//이름 공간 생성

int main()
{
	int a, b, c, largest;

	cout << "3개의 정수를 입력하시오 : ";
	cin >> a >> b >> c; // 정수 3개를 입력받는다.

	if (a > b && a > c)//a 가 다른 두 수보다 크면 a가 largest에 저장된다.
		largest = a;
	else if (b > a && b > c)//b 가 다른 두 수보다 크면 b가 largest에 저장된다.
		largest = b;
	else
		largest = c;// 나머지 경우는 c가 가장 큰 경우이므로 c가 largest에 저장된다.
	cout << "가장 큰 정수는" << largest << endl; //largest를 출력받는다.
	return 0;


}