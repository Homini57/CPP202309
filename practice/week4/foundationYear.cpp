#include <iostream>

using namespace std;

int main()
{
	const int kArraySize = 3;

	int founding[kArraySize];							//�迭 ���� : type �迭�̸�[�迭ũ��]
	founding[0] = 918;
	founding[1] = 1302;
	founding[2] = 1948;

	cout << "��� �Ǳ� ���� : " << founding[0] << endl;	//�迭[index]�� �迭�� ���� ��ȯ�Ѵ�.
	cout << "���� �Ǳ� ���� : " << founding[1] << endl;
	cout << "�ѱ� �Ǳ� ���� : " << founding[2] << endl;

	return 0;

}