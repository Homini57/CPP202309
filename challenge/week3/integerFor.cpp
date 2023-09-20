#include <iostream>
using namespace std;

int main()
{
	int userInput;		//입력받은 정수를 저장할 변수

	cout << "정수를 10번 입력하세요 (0을 입력하면 종료):";
	int i;				//입력 횟수 관련 변수
	for(i=0;i<10;i++)	//입력 횟수 10번으로 설정
	{
		cin >> userInput;

		if (userInput == 0)				//0을 입력하면 반복문을 종료
		{
			break;
		}

		cout << "입력값: " << userInput << "횟수 :" << i<< endl; //입력값과 횟수를 출력

	}
	return 0;

}