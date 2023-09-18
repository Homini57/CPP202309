#include <iostream>//헤더 파일 불러오기

using namespace std;//이름 공간 생성

int main()
{
	int a, b, c, lowest;

	cout << "3개의 정수를 입력하시오 : ";
	cin >> a >> b >> c; // 정수 3개를 입력받는다.

	if (a < b && a < c)//a 가 다른 두 수보다 작으면 a가 lowest에 저장된다.
		lowest = a;
	else if (b < a && b < c)//b 가 다른 두 수보다 작으면 b가 lowest에 저장된다.
		lowest = b;
	else
		lowest = c;// 나머지 경우는 c가 가장 작은 경우이므로 c가 lowest에 저장된다.
	cout << "가장 작은 정수는" << lowest << endl; //lowest를 출력받는다.
	return 0;

}