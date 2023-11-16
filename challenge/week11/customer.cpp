#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int maxPeople; // 총 고객 수를 입력받을 변수
	int i, is_age = 0; // 특정 나이 이상 고객이 있는지 확인하는 변수

	string name; int age;
	
	cout << "총 고객의 수를 입력하라: ";
	cin >> maxPeople;
	vector<string> names;	    //고객 이름에 관한 동적 배열
	vector<int> ages;           //고객 나이에 관한 동적 배열
	for (i = 0; i < maxPeople; i++) {						
		cout << "사람 " << i + 1 << "의 " << "이름: ";
		cin >> name;
		names.push_back(name);
		cout << "사람 " << i + 1 << "의 " << "나이: ";
		cin >> age;
		ages.push_back(age);
	}

	int ageThreshold;
	cout << "특정 나이 이상인 사람을 찾으려면 나이를 입력하세요: ";
	cin >> ageThreshold;

	cout << ageThreshold << "세 이상인 고객들:\n";
	// 나이가 ageThreshold 이상인 고객 출력
	for (i = 0; i < names.size(); i++)
	{
		
		if (ages[i] >= ageThreshold)
		{
			cout << names[i] << " (" << ages[i] << "세)" << endl;
			is_age++;										// 나이가 ageThreshold 이상인 고객이 있다면 is_age >= 1
		}

	}
	if (is_age == 0)											//ageThreshold세 이상인 고객이 없으면(is_age == 0)
	{
		cout << ageThreshold << "이상의 나이를 가진 고객이 없습니다.";		//고객이 없다는 문장 출력
	}


}