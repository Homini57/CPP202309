#include <iostream>
using namespace std;

int main()
{
	int choice;

	cout << "1. ���� ����" << endl;
	cout << "2. ���� ���� �ݱ�" << endl;
	cout << "3. ����" << endl;
	cin >> choice;//������� ������ �Է¹޴´�.

	if(choice == 1)//�Է°��� 1�̸� ���� ����~�� ����Ѵ�.
		cout << "���� ������ �����߽��ϴ�." << endl;
	else if(choice == 2)//�Է°��� 2�̸� ���� �ݱ�~�� ����Ѵ�.
		cout << " ���� �ݱ⸦ �����߽��ϴ�." << endl;
	else if(choice == 3)//�Է°��� 3�̸� ���α׷� ����~�� ����Ѵ�.
		cout << "���α׷��� �����մϴ�." << endl;
	else//�׿��� ���� �Է��ϸ� �߸��� ����~�� ����Ѵ�.
		cout << "�߸��� �����Դϴ�." << endl;

	return 0;

}