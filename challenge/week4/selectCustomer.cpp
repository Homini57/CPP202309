#include <iostream>
#include <string>

using namespace std;

int main()
{
	const int maxPeople = 3;
	int i, j = 0;
	cout << "�� ���� ���� �Է��϶�: \n";
	// cin >> maxPeople;
	string names[maxPeople];
	int ages[maxPeople];
	for (i = 0; i < maxPeople; i++)
	{
		cout << "��� " << i+1 << "�� " << "�̸�: ";
		cin >> names[i];
		cout << "��� " << i+1 << "�� " << "����: ";
		cin >> ages[i];
	}


	int ageThreshold;
	cout << "Ư�� ���� �̻��� ����� ã������ ���̸� �Է��ϼ���: ";
	cin >> ageThreshold;

	cout << ageThreshold << "�� �̻��� ����:\n";
	for (i = 0; i < maxPeople; i++)
	{
		if (ages[i] >= ageThreshold)
		{
			cout << names[i] << " (" << ages[i] << "��)" << endl;
			j++;
		}
		
		
	}
	if(j == 0)
	{
		cout << ageThreshold << "�̻��� ���̸� ���� ���� �����ϴ�.";
	}


}