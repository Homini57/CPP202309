#include <iostream>
#include <string>
using namespace std;

bool checkNumber(string randomNum, char& firstNum, char& secondNum, char& thirdNum);

int main() {
	string randomNum; // ����� �ϴ� 3�ڸ����� ���� ���� ����
	char firstNum; // ������ ù��° �ڸ���
	char secondNum; // ������ �ι�° �ڸ���
	char thirdNum; // ������ ����° �ڸ���

	while (1) {
		randomNum = to_string(rand() % 900 + 100); // ������ 3�ڸ��� ����
		bool same = false; // ��� ���� �ٸ� ��� true�� ���� ����

		// TODO 1: 3�ڸ� ������ �ڸ����� �����ϰ�, ��� ���� �ٸ��� üũ�ϴ� �ڵ��� �ۼ�
		same = checkNumber(randomNum, firstNum, secondNum, thirdNum);

		// ��� ���� �ٸ��� ���� �ڵ�� �Ѿ�� �ڵ�
		if (same == true) {
			break;
		}
	}
	
	int turn = 0; // �Է� �õ� Ƚ��
	while (1) {
		cout << turn + 1 << "��° �õ��Դϴ�. " << endl;
		string userNumber; // ����ڰ� �Է��� ���ڸ��� ���� ����
		char guessFirst; // ������ ������ ù��° �ڸ���
		char guessSecond; // ������ ������ �ι�° �ڸ���
		char guessThird; // ������ ������ ����° �ڸ���


		// ����ڿ��� ���ڸ� ���� �Է¹޴� �ڵ� ���
		while (1) {
			cout << "���ڸ� ���� �Է����ּ���: ";
			cin >> userNumber;

			bool same = false; // ��� ���� �ٸ� ��� true�� ���� ����
			// TODO 1: 3�ڸ� ������ �ڸ����� �����ϰ�, ��� ���� �ٸ��� üũ�ϴ� �ڵ��� �ۼ�

			if (userNumber.length() != 3) {
				cout << "�Էµ� ���ڰ� 3�ڸ� ���� �ƴմϴ�. �ٽ� �Է��ϼ���." << endl;
				continue;
			}

			same = checkNumber(userNumber, guessFirst, guessSecond, guessThird);

			if (same == false) {
				cout << "�Է��� ���ڿ� �ߺ��� ���ڰ� �ֽ��ϴ�. �ٽ� �Է��ϼ���." << endl;
				continue;
			}
			else break;
		}


		int strike = 0; // ��Ʈ����ũ ������ �����ϴ� ����
		int ball = 0; // �� ������ �����ϴ� ����

		// TODO 2: ����� ������ ������ �ڸ����� ���ڸ� ���ϸ� ��Ʈ�� �ֱ� ���� �ڵ��� �ۼ�

		if (firstNum == guessFirst) strike++;
		else if(firstNum == guessSecond || firstNum == guessThird) ball++;

		if (secondNum == guessSecond) strike++;
		else if (secondNum == guessFirst || secondNum == guessThird) ball++;

		if (thirdNum == guessThird) strike++;
		else if (thirdNum == guessFirst || thirdNum == guessSecond) ball++;
		

	

		

		if (strike == 0 && ball == 0) {
			cout << "�ƿ��Դϴ�." << endl;
		}
		else {
			cout << userNumber << "�� ��� : " << strike << " ��Ʈ����ũ, " << ball << "�� �Դϴ�." << endl;
		}

		

		if (strike == 3) {
			cout << "������ ������ϴ�. �����մϴ�.";
			break;
		}

		turn += 1;
	}

	return 0;
}

bool checkNumber(string randomNum, char& firstNum, char& secondNum, char& thirdNum) {
	bool same = true;
	firstNum = randomNum[0]; // ������ ù��° �ڸ���
	secondNum = randomNum[1]; // ������ �ι�° �ڸ���
	thirdNum = randomNum[2]; // ������ ����° �ڸ���
	if (firstNum == secondNum || secondNum == thirdNum || firstNum == thirdNum) same = false;

	return same;

}