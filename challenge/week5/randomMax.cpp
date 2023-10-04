#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	const int numCell = 10;
	int numList[numCell][numCell];			//10 X 10 �迭�� ����

	for (int i = 0; i < numCell; i++)		//�� �迭�� ������ ����
	{
		for (int j = 0; j < numCell; j++)
		{
			numList[i][j] = rand() % 999;
		}
	}

	cout << endl;

	int max = 0;							//�ִ밪�� �����ϱ� ���� ����
	int maxI;								//�ִ밪�� i�� �����ϱ� ���� ����
	int maxJ;								//�ִ밪�� j�� �����ϱ� ���� ����

	for (int i = 0; i < numCell; i++)		//�� �迭�� ���Ͽ� �ݺ�
	{
		int j = 0;							//���� j�� ���� ����
		for (auto value : numList[i])		//���� �迭�� ���� value�� ����
		{		
			if (value > max)				//�迭�� ���� max�� ��
			{
				max = value;				//value��  max���� ū���̸� �ش簪�� max�� �Է�
				maxI = i;					//�迭�� i�� ����
				maxJ = j;					//�迭�� j�� ����
			}
			j++;							//���� j�� ���� j�� ����
		}
	}

	cout << "���� ū ����" << max << "�̰�,";
	cout << "i�� j�� ����" << maxI << "," << maxJ << "�Դϴ�." << endl;
	cout << "���� ���: " << numList[maxI][maxJ] << endl;

	return 0;
}