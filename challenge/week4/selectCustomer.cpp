#include <iostream>
#include <string>

using namespace std;

int main()
{
	const int maxPeople = 3;
	int i, j = 0;				// i : �ݺ����� �ݺ� Ƚ���� ���� ����
								//j : Ư�� ���� �̻��� ��� ������ 0, ������ 1 �̻�, 0�̸� ���� ���
	cout << "�� ���� ���� �Է��϶�: \n";
	// cin >> maxPeople;
	string names[maxPeople];	//�� �̸��� ���� �迭
	int ages[maxPeople];		//�� ���̿� ���� �迭
	for (i = 0; i < maxPeople; i++)						//���� ���๮�� maxPeople�� �ݺ�
	{
		cout << "��� " << i+1 << "�� " << "�̸�: ";
		cin >> names[i];								//�迭�� index�� 0���� ����, 1��°�� index = 0
		cout << "��� " << i+1 << "�� " << "����: ";
		cin >> ages[i];
	}


	int ageThreshold;
	cout << "Ư�� ���� �̻��� ����� ã������ ���̸� �Է��ϼ���: ";
	cin >> ageThreshold;

	cout << ageThreshold << "�� �̻��� ����:\n";
	for (i = 0; i < maxPeople; i++)						//��� ���� ���Ͽ� ���� ���๮(���� �˻�) �ݺ�
	{
		if (ages[i] >= ageThreshold)					//���� ���̰� ageThreshold�� �̻��̸� ���� ���
		{
			cout << names[i] << " (" << ages[i] << "��)" << endl;
			j++;										//ageThreshold�� �̻��� ���� ������ j�� 1 �̻�
														//ageThreshold�� �̻��� ���� ������ j = 0
		}
		
		
	}
	if(j == 0)											//ageThreshold�� �̻��� ���� ������(j = 0�̸�)
	{
		cout << ageThreshold << "�̻��� ���̸� ���� ���� �����ϴ�.";		//���� ���ٴ� ���� ���
	}


}