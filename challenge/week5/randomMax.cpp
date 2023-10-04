#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	const int numCell = 10;
	int numList[numCell][numCell];			//10 X 10 배열을 생성

	for (int i = 0; i < numCell; i++)		//각 배열에 난수를 저장
	{
		for (int j = 0; j < numCell; j++)
		{
			numList[i][j] = rand() % 999;
		}
	}

	cout << endl;

	int max = 0;							//최대값을 저장하기 위한 변수
	int maxI;								//최대값의 i를 저장하기 위한 변수
	int maxJ;								//최대값의 j를 저장하기 위한 변수

	for (int i = 0; i < numCell; i++)		//각 배열에 대하여 반복
	{
		int j = 0;							//현재 j의 값을 선언
		for (auto value : numList[i])		//현재 배열의 값을 value에 저장
		{		
			if (value > max)				//배열의 값과 max를 비교
			{
				max = value;				//value가  max보다 큰값이면 해당값을 max에 입력
				maxI = i;					//배열의 i를 저장
				maxJ = j;					//배열의 j를 저장
			}
			j++;							//현재 j를 다음 j로 수정
		}
	}

	cout << "가장 큰 값은" << max << "이고,";
	cout << "i와 j는 각각" << maxI << "," << maxJ << "입니다." << endl;
	cout << "검증 결과: " << numList[maxI][maxJ] << endl;

	return 0;
}