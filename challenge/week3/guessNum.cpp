#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	srand(time(NULL));				//rand()���� ���� �ð��� �°� �����ϴ� �Լ�

	int answer = rand() % 100;		//answer:����, rand()���� 0~99������ �����ϴ� ��
	int tries = 0;					//�õ� Ƚ���� �����ϴ� ����

	int guess;						//�Է°��� �����ϴ� ����
	do
	{
		cout << "������ �����Ͽ� ���ÿ�:";
		cin >> guess;
		//�Է°��� ���亸�� ���ų� ������ ���� ���
		if (answer < guess)								
			cout << "������ ������ �����ϴ�. " << endl;
		else if (answer > guess)
			cout << "������ ������ �����ϴ�. " << endl;
		//�Է°��� ������ ������ �ݺ����� ����
		else
			break;
		tries++;//�Է°��� ������ �ٸ��� �õ� Ƚ�� 1 ����
	} 
	while (answer != guess);		//�Է°��� ������ �ٸ��� �ݺ� ����


	cout << "�����մϴ�. �õ� Ƚ��=" << tries << endl;
	return 0;
}

