#include <iostream>
using namespace std;

// ������ �����ϴ� �� �ʿ��� ���� ����

const int numCell = 3; // �������� ���� ���� ����
char board[numCell][numCell]{}; // �������� ��Ÿ���� 2���� �迭


bool isValid(int x, int y);
bool checkWin(int x, int y, int currentUser);

int main() {

	char currentUser = 'O'; // ���� ������ ���� �����ϱ� ���� ����
	int x, y = 0; // ����ڿ��� xy��ǥ���� �Է¹ޱ� ���� ����
	int k = 0; // ���� �������� üũ�ϱ� ���� ����

	for (int i = 0; i < numCell; i++) {
		for (int j = 0; j < numCell; j++) {
			board[i][j] = ' ';
		}
	}

	// ������ ���� �ݺ�
	while (true) {
		// 1. ���� �������� ���
		// TODO 1.1: 3�ο� �������� ����
		switch (k % 3) {
		case 0:
			currentUser = 'O';
			break;
		case 1:
			currentUser = 'X';
			break;
		case 2:
			currentUser = 'H';
			break;
		}
		cout << k % 3 + 1 << "�� ����(" << currentUser << ")�� �����Դϴ�. -> ";

		// 2. ��ǥ �Է� �ޱ�
		cout << "(x, y) ��ǥ�� �Է��ϼ���: ";
		int x, y;
		cin >> x >> y;

		// 3. �Է¹��� ��ǥ�� ��ȿ�� üũ
		// TODO FUNC 1: isValid �Լ� ���� �� ȣ��
		bool is_valid = isValid(x, y);
		if (is_valid == false) continue;



		// 4. �Է¹��� ��ǥ�� ���� ������ �� ����
		board[y][x] = currentUser;

		// 5. ���� ���� �� ���
		// TODO 1.2: numCell ���ڿ� ���� ������ ���
		for (int i = 0; i < numCell; i++) {
			cout << "---";
			for (int h = 0; h < numCell - 1; h++) {
				cout << "|---";
			}
			cout << endl;
			for (int j = 0; j < numCell; j++)
			{
				cout << board[i][j];
				if (j == numCell - 1) {
					break;
				}
				cout << "  |";
			}
			cout << endl;
		}
		cout << "---";
		for (int h = 0; h < numCell - 1; h++) {
			cout << "|---";
		}
		cout << endl;


		bool isWin = false; // �¸� ����
		// TODO FUNC2: 6.1���� 6.2���� checkWin �Լ� ���� �� ȣ��
		// TODO 1.3: numCell�� ���� �밢�� ���� üũ �ڵ�� Ȯ��

		isWin = checkWin(x, y, currentUser);
			

		// �¸��ڰ� �����Ǿ����� �ش� �÷��̾ ����ϰ� ������ �����Ѵ�.

		if (isWin == true) {
			cout << k % 3 + 1 << "�� ����(" << currentUser << ")�� �¸��Դϴ�!" << endl;
			cout << "�����մϴ�" << endl;
			break;
		}
		// 7. ��� ĭ �� á���� üũ�ϱ�
		int checked = 0;
		for (int i = 0; i < numCell; i++) {
			for (int j = 0; j < numCell; j++) {
				if (board[i][j] == ' ') {
					checked++;
				}
			}
		}
		if (checked == 0) {
			cout << "��� ĭ�� �� á���ϴ�.  �����մϴ�. " << endl;
			break;
		}

		k++;
	}
	return 0;
}


bool isValid(int x, int y) {

	bool isValid = true;
	// ��ǥ ������ �����
	if (x < 0 || numCell <= x || y < 0 || numCell <= y) {
		cout << x << "," << y << ": x�� y���� �ϳ��� ĭ�� ����ϴ�. " << endl;
		isValid = false;
		return isValid;
	}

	// ��ǥ������ �Է°��� �ߺ��ɶ�
	if (board[y][x] != ' ') {
		cout << x << "," << y << ": �̹� ���� ���ֽ��ϴ�. " << endl;
		isValid = false;
	}
	return isValid;
}


bool checkWin(int x, int y, int currentUser) {
	bool isWin = false;
	// 6.1. ����/���� �� üũ�ϱ�
	for (int i = 0; i < numCell; i++) {
		if (board[y][i] == currentUser) {
			if (i < numCell -1) continue;
			else {
				cout << "���ο� ��� ���� �������ϴ�!: ";
				isWin = true;
			}
		}
		else break;
	}

	for (int i = 0; i < numCell; i++) {
		if (board[i][x] == currentUser) {
			if (i < numCell - 1) continue;
			else {
				cout << "���ο� ��� ���� �������ϴ�!: ";
				isWin = true;
			}
		}
		else break;
	}
	// 6.2. �밢���� üũ�ϱ�
	for (int i = 0; i < numCell; i++) {
		if (board[i][i] == currentUser) {
			if (i < numCell - 1) continue;
			else {
				cout << "���� ������ ������ �Ʒ� �밢������ ��� ���� �������ϴ�!: ";
				isWin = true;
			}
		}
		else break;
	}

	for (int i = 0; i < numCell; i++) {
		if (board[i][numCell - 1 - i] == currentUser) {
			if (i < numCell - 1) continue;
			else {
				cout << "������ ������ ���� �Ʒ� �밢������ ��� ���� �������ϴ�!: ";
				isWin = true;
			}
		}
		else break;
	}

	
	return isWin;

}