#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	srand(time(NULL));					//rand()값을 현재 시간에 맞게 설정하는 함수
	int i=1;							//정답을 맞힌 횟수를 저장하는 변수
	int ans;							//입력값
	cout << "산수 문제를 자동으로 출제합니다. " << endl;

	while (i<=5)
	{
		int firstNum = rand() % 100;
		int secondNum = rand() % 100;

		cout << firstNum << "+" << secondNum << "=";// 덧셈 식을 출력
		cin >> ans;
		if (firstNum + secondNum != ans)			//입력값이 계산값과 다르면 "틀렸습니다." 출력
			cout << "틀렸습니다." << endl;
													//입력값이 계산값과 같으면 "맞았습니다." 출력
													//맞은 횟수 1 증가
		else
		{
			cout << "맞았습니다." << endl;
			i++;
		}

	}
	return 0;

}