#include <iostream>
using namespace std;

int main()
{
	int userInput;		//�Է¹��� ������ ������ ����

	cout << "������ 10�� �Է��ϼ��� (0�� �Է��ϸ� ����):";
	int i;				//�Է� Ƚ�� ���� ����
	for(i=0;i<10;i++)	//�Է� Ƚ�� 10������ ����
	{
		cin >> userInput;

		if (userInput == 0)				//0�� �Է��ϸ� �ݺ����� ����
		{
			break;
		}

		cout << "�Է°�: " << userInput << "Ƚ�� :" << i<< endl; //�Է°��� Ƚ���� ���

	}
	return 0;

}