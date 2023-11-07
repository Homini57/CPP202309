#include <iostream>

using namespace std;

int main()
{
	// 가진 돈, 가격을 저장할 변수
	int money = 0, price = 0;

	// 가진 돈, 가격 입력
	cin >> money >> price;

	// 가진 돈, 가격, 구매 가능 캔디 수, 잔돈 출력
	cout << "현재 가지고 있는 돈: " << money << endl;
	cout << " 캔디의 가격: " << price << endl;
	cout << "최대로 살 수 있는 캔디 = "<< money/price << endl;
	cout << "캔디 구입 후 남은 돈 = " << money % price << endl;
	
	return 0;

}