#include <iostream>
using namespace std;

int main() 
{
	int vowel = 0;			//������ ������ �����ϴ� ����
	int consonant = 0;		//������ ������ �����ϴ� ����
	cout << "�����ڸ� �Է��ϰ� ctrl+z�� ġ����" << endl;

	char ch;				// �Է¹��� �����ڸ� �����ϴ� ����

	while (cin >> ch)
	{
		//����  ASCII�ڵ� : a,e,i,o,u = 97,101,105,111,117
		switch (ch)
		{
		case 97:			//���� 'a'�� �Է��ϸ� vowel 1+
			vowel++;
			break;
		case 101:			//���� 'e'�� �Է��ϸ� vowel 1+
			vowel++;
			break;
		case 105:			//���� 'i'�� �Է��ϸ� vowel 1+
			vowel++;
			break;
		case 111:			//���� 'o'�� �Է��ϸ� vowel 1+
			vowel ++;
			break;
		case 117:			//���� 'u'�� �Է��ϸ� vowel 1+
			vowel++;
			break;
		default:			//������ ������ �Է��ϸ� consonant 1+
			consonant++;
			break;
		}
	}

	cout << "����: " << vowel << endl;
	cout << "����: " << consonant << endl;
	return 0;

}