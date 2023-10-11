#include <iostream>
using namespace std;

int main() {
	
	const int numCell = 3;
	char board[numCell][numCell]{};// ���� ũ�� : 3 x 3
	int x, y;// x : �Է¹��� �� ��ǥ, y : �Է¹��� �� ��ǥ ���� ����
	// ������ �ʱ�ȭ
	for (x = 0; x < numCell; x++) {
		for (y = 0; y < numCell; y++) {
			board[x][y] = ' ';
		}
	}
	// ƽ���� �ڵ�
	
	int k = 0; // ���� �� �÷��̾� ������ ���� ����
	char currentUser = 'X'; // ���� �÷��̾� �� ����� �����ϱ� ���� ����
	while (true) {
		// 1. ���� �� �÷��̾� ���, �÷��̾� �� ��� ����
		switch (k % 2) {
		case 0:
			cout << k % 2 + 1 << "�� ����(X)�� �����Դϴ� -> ";
			currentUser = 'X';
			break;
		case 1:
			cout << k % 2 + 1 << "�� ����(O)�� �����Դϴ� -> ";
			currentUser = 'O';
			break;
		}

		// 2. ��ǥ �Է� �ޱ�
		cout << "(x, y) ��ǥ�� �Է��ϼ���: ";
		cin >> x >> y;

		//3. �Է¹��� ��ǥ ��ȿ�� �˻�
		if (x >= numCell || y >= numCell) {
			cout << x << ", " << y << ": ";
			cout << "x�� y �� �� �ϳ��� ĭ�� ����ϴ�." << endl;
			continue;
		}
		if (board[x][y] != ' ') {
			cout << x << ", " << y << ": �̹� ���� ���ֽ��ϴ�." << endl;
			continue;
		}

		// 4. �Է¹��� ��ǥ�� �� ����
		board[x][y] = currentUser;

		// 5. ������ ��Ȳ ���
		for (int i = 0; i < numCell; i++) {
			cout << "---|---|---" << endl;
			for (int j = 0; j < numCell; j++) {
				cout << " " << board[i][j];
				if (j == numCell - 1) {
					break;
				}
				cout << " |";
			}
			cout << endl;
		}
		cout << "---|---|---" << endl;

		// 6. ������ ���� �˻�
		bool win = false;
		for (int i = 0; i < numCell; i++) {
			for (int j = 0; j < numCell; j++) {
				if (board[i][j] == currentUser) {
					if (j == numCell - 1) {
						cout << "���ο� ��� ���� �������ϴ�!";
						win = true;
						break;
					}
				}
				else
					break;
			}
		}

		//7. ������ ���� �˻�
		for (int j = 0; j < numCell; j++) {
			for (int i = 0; i < numCell; i++) {
				if (board[i][j] == currentUser) {
					if (i == numCell - 1) {
						cout << "���ο� ��� ���� �������ϴ�!";
						win = true;
						break;
					}
				}
				else
					break;
			}
		}

		// 8. �밢��1 ���� �˻�
		for (int i = 0; i < numCell; i++) {
			if (board[i][i] == currentUser) {
				if (i == numCell - 1) {
					cout << "���� ������ ������ �Ʒ� �밢������ ��� ���� �������ϴ�!";
					win = true;
					break;
				}
			}
			else
				break;
		}

		// 9. �밢��2 ���� �˻�
		for (int i = 0; i < numCell; i++) {
			if (board[i][numCell - i - 1] == currentUser) {
				if (i == numCell - 1) {
					cout << "������ ������ ���� �Ʒ� �밢������ ��� ���� �������ϴ�!";
					win = true;
					break;
				}
			}
			else
				break;
		}

		if (win == true) {
			cout << k % 2 + 1 << "�� ����(" << currentUser << ")�� �¸��Դϴ�!" << endl;
			cout << "�����մϴ�" << endl;
			break;
		}

		k++;
		if (k >= 9) {
			cout << "��� ĭ�� �� á���ϴ�. �����մϴ�";
			break;
		}
		
	}
	return 0;

}
