#include <iostream>

using namespace std;

int main()
{
	//섭씨 온도를 저장할 변수
	int c = 0;
	// 섭씨 온도 입력
	cin >> c;
	// 화씨 온도 계산, 출력
	cout << "섭씨온도: " << c << endl;
	cout << "화씨온도 = " << (9.0 / 5.0 * c) + 32 << endl;

	return 0;

}