#include <iostream>
using namespace std;

int main()
{
	int choice;

	cout << "1. 파일 저장" << endl;
	cout << "2. 저장 없이 닫기" << endl;
	cout << "3. 종료" << endl;
	cin >> choice;//사용자의 선택을 입력받는다.

	switch (choice)//사용자가 입력한 값에 따라 텍스트를 출력한다.
				   //switch 함수는 단순한 조건에서 사용하기 좋다.
	{
	case 1:
		cout << "파일 저장을 선택했습니다." << endl; //입력값이 1이면 파일 저장~을 출력한다.
		break;
	case 2:
		cout << " 파일 닫기를 선택했습니다." << endl;//입력값이 2이면 파일 닫기~를 출력한다.
		break;
	case 3:
		cout << "프로그램을 종료합니다." << endl;//입력값이 3이면 프로그램 종료~를 출력한다.
		break;
	default:
		cout << "잘못된 선택입니다." << endl;//그 외의 값을 입력하면 잘못된 선택~을 출력한다.
		break;
	}

	return 0;

}