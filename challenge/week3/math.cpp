#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	srand(time(NULL));					//rand()���� ���� �ð��� �°� �����ϴ� �Լ�
	int i=1;							//������ ���� Ƚ���� �����ϴ� ����
	int ans;							//�Է°�
	cout << "��� ������ �ڵ����� �����մϴ�. " << endl;

	while (i<=5)
	{
		int firstNum = rand() % 100;
		int secondNum = rand() % 100;

		cout << firstNum << "+" << secondNum << "=";// ���� ���� ���
		cin >> ans;
		if (firstNum + secondNum != ans)			//�Է°��� ��갪�� �ٸ��� "Ʋ�Ƚ��ϴ�." ���
			cout << "Ʋ�Ƚ��ϴ�." << endl;
													//�Է°��� ��갪�� ������ "�¾ҽ��ϴ�." ���
													//���� Ƚ�� 1 ����
		else
		{
			cout << "�¾ҽ��ϴ�." << endl;
			i++;
		}

	}
	return 0;

}