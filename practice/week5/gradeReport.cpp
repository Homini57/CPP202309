#include <iostream>
#include <string>
using namespace std;

int main()
{
	const int STUDENT = 5;
	const int SUBJECT = 3;
	int scores[STUDENT][SUBJECT];
	string studentNames[STUDENT]						//학생의 이름 배열
		= { "영수", "영희", "철수", "미미", "쥬쥬" };
	string subjectNames[SUBJECT]						//과목명 배열
		= { "수학", "영어", "CPP" };
	for (int i = 0; i < STUDENT; i++)					//각 학생에 대하여 과목별 성적을 입력받음
	{
		cout << studentNames[i]
			<< "의 성적을 하나씩 입력하세요." << endl;
		for (int j = 0; j < SUBJECT; j++)
		{
			cout << subjectNames[j] << ":";				//각 과목에 대한 성적을 입력받아 scores에 넣음
			cin >> scores[i][j];
		}
	
	}
	
	for (int i = 0; i < STUDENT; i++)					//각 학생에 대한 평균점수를 산출
	{
		cout << studentNames[i] << "의 평균점수는 ";
		double sum = 0;
		double average = 0;
		for (int j = 0; j < SUBJECT; j++)
		{
			sum += scores[i][j];						//각 학생의 점수를 sum함수에 합산
		}
		average = sum / SUBJECT;						//총 합을 과목수로 나누어 평균점수 산출
		cout << average << "입니다" << endl;
	}
	return 0;
}