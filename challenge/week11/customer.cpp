#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int maxPeople; // �� �� ���� �Է¹��� ����
	int i, is_age = 0; // Ư�� ���� �̻� ���� �ִ��� Ȯ���ϴ� ����

	string name; int age;
	
	cout << "�� ���� ���� �Է��϶�: ";
	cin >> maxPeople;
	vector<string> names;	    //�� �̸��� ���� ���� �迭
	vector<int> ages;           //�� ���̿� ���� ���� �迭
	for (i = 0; i < maxPeople; i++) {						
		cout << "��� " << i + 1 << "�� " << "�̸�: ";
		cin >> name;
		names.push_back(name);
		cout << "��� " << i + 1 << "�� " << "����: ";
		cin >> age;
		ages.push_back(age);
	}

	int ageThreshold;
	cout << "Ư�� ���� �̻��� ����� ã������ ���̸� �Է��ϼ���: ";
	cin >> ageThreshold;

	cout << ageThreshold << "�� �̻��� ����:\n";
	// ���̰� ageThreshold �̻��� �� ���
	for (i = 0; i < names.size(); i++)
	{
		
		if (ages[i] >= ageThreshold)
		{
			cout << names[i] << " (" << ages[i] << "��)" << endl;
			is_age++;										// ���̰� ageThreshold �̻��� ���� �ִٸ� is_age >= 1
		}

	}
	if (is_age == 0)											//ageThreshold�� �̻��� ���� ������(is_age == 0)
	{
		cout << ageThreshold << "�̻��� ���̸� ���� ���� �����ϴ�.";		//���� ���ٴ� ���� ���
	}


}