#include <iostream>
using namespace std;

int main()
{
	int choice;

	cout << "1. ���� ����" << endl;
	cout << "2. ���� ���� �ݱ�" << endl;
	cout << "3. ����" << endl;
	cin >> choice;//������� ������ �Է¹޴´�.

	switch (choice)//����ڰ� �Է��� ���� ���� �ؽ�Ʈ�� ����Ѵ�.
				   //switch �Լ��� �ܼ��� ���ǿ��� ����ϱ� ����.
	{
	case 1:
		cout << "���� ������ �����߽��ϴ�." << endl; //�Է°��� 1�̸� ���� ����~�� ����Ѵ�.
		break;
	case 2:
		cout << " ���� �ݱ⸦ �����߽��ϴ�." << endl;//�Է°��� 2�̸� ���� �ݱ�~�� ����Ѵ�.
		break;
	case 3:
		cout << "���α׷��� �����մϴ�." << endl;//�Է°��� 3�̸� ���α׷� ����~�� ����Ѵ�.
		break;
	default:
		cout << "�߸��� �����Դϴ�." << endl;//�� ���� ���� �Է��ϸ� �߸��� ����~�� ����Ѵ�.
		break;
	}

	return 0;

}