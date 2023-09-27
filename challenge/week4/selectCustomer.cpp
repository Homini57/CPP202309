#include <iostream>
#include <string>

using namespace std;

int main()
{
	const int maxPeople = 3;
	int i, j = 0;				// i : 반복문의 반복 횟수에 관한 변수
								//j : 특정 나이 이상인 사람 없으면 0, 있으면 1 이상, 0이면 문장 출력
	cout << "총 고객의 수를 입력하라: \n";
	// cin >> maxPeople;
	string names[maxPeople];	//고객 이름에 관한 배열
	int ages[maxPeople];		//고객 나이에 관한 배열
	for (i = 0; i < maxPeople; i++)						//다음 실행문을 maxPeople번 반복
	{
		cout << "사람 " << i+1 << "의 " << "이름: ";
		cin >> names[i];								//배열의 index는 0부터 시작, 1번째의 index = 0
		cout << "사람 " << i+1 << "의 " << "나이: ";
		cin >> ages[i];
	}


	int ageThreshold;
	cout << "특정 나이 이상인 사람을 찾으려면 나이를 입력하세요: ";
	cin >> ageThreshold;

	cout << ageThreshold << "세 이상인 고객들:\n";
	for (i = 0; i < maxPeople; i++)						//모든 고객에 대하여 다음 실행문(나이 검사) 반복
	{
		if (ages[i] >= ageThreshold)					//고객의 나이가 ageThreshold세 이상이면 문장 출력
		{
			cout << names[i] << " (" << ages[i] << "세)" << endl;
			j++;										//ageThreshold세 이상인 고객이 있으면 j가 1 이상
														//ageThreshold세 이상인 고객이 없으면 j = 0
		}
		
		
	}
	if(j == 0)											//ageThreshold세 이상인 고객이 없으면(j = 0이면)
	{
		cout << ageThreshold << "이상의 나이를 가진 고객이 없습니다.";		//고객이 없다는 문장 출력
	}


}