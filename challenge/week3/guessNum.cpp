#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	srand(time(NULL));				//rand()값을 현재 시간에 맞게 설정하는 함수

	int answer = rand() % 100;		//answer:정답, rand()값을 0~99까지로 제한하는 식
	int tries = 0;					//시도 횟수를 저장하는 변수

	int guess;						//입력값을 저장하는 변수
	do
	{
		cout << "정답을 추측하여 보시오:";
		cin >> guess;
		//입력값이 정답보다 높거나 낮으면 문장 출력
		if (answer < guess)								
			cout << "제시한 정수가 높습니다. " << endl;
		else if (answer > guess)
			cout << "제시한 정수가 낮습니다. " << endl;
		//입력값과 정답이 같으면 반복문을 종료
		else
			break;
		tries++;//입력값과 정답이 다르면 시도 횟수 1 증가
	} 
	while (answer != guess);		//입력값과 정답이 다르면 반복 실행


	cout << "축하합니다. 시도 횟수=" << tries << endl;
	return 0;
}

