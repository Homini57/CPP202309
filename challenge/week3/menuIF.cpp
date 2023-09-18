#include <iostream>
using namespace std;

int main()
{
	int choice;

	cout << "1. 파일 저장" << endl;
	cout << "2. 저장 없이 닫기" << endl;
	cout << "3. 종료" << endl;
	cin >> choice;//사용자의 선택을 입력받는다.

	if(choice == 1)//입력값이 1이면 파일 저장~을 출력한다.
		cout << "파일 저장을 선택했습니다." << endl;
	else if(choice == 2)//입력값이 2이면 파일 닫기~를 출력한다.
		cout << " 파일 닫기를 선택했습니다." << endl;
	else if(choice == 3)//입력값이 3이면 프로그램 종료~를 출력한다.
		cout << "프로그램을 종료합니다." << endl;
	else//그외의 값을 입력하면 잘못된 선택~를 출력한다.
		cout << "잘못된 선택입니다." << endl;

	return 0;

}