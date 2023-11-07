#include <iostream>

using namespace std;

int main()
{
	//화씨 온도를 저장할 변수
	int f = 0;
	//화씨 온도 입력
	cin >> f;

	// 섭씨온도 계산, 출력
	cout << "화씨온도: " << f << endl;
	cout << "섭씨온도 = " << (5.0 / 9.0) * (f - 32) << endl;

	return 0;

}