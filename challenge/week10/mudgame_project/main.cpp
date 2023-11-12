#include "user.h"

const int mapX = 5;		// ������ ĭ(��) ��
const int mapY = 5;		// ������ ��(��) ��
User my_user;
// ����� ���� �Լ�

bool checkNmoveXY(int& user_x, int& user_y, int movement_x, int movement_y);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);
bool checkState(int map[][mapX], int user_x, int user_y);

// ����  �Լ�
int main() {
	// 0�� �� ����, 1�� ������, 2�� ��, 3�� ����, 4�� ������
	int map[mapY][mapX] = { {0, 1, 2, 0, 4},
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} };


	// ������ ��ġ�� ������ ����
	int user_x = 0; // ���� ��ȣ
	int user_y = 0; // ���� ��ȣ
	my_user.hp = 20;// ���� ���� ü��
	

	// ���� ���� 
	while (1) { // ����ڿ��� ��� �Է¹ޱ� ���� ���� ����

		// ������� �Է��� ������ ����
		string user_input = "";

		cout << "���� Hp: " << my_user.GetHP() << "��ɾ �Է��ϼ���(��, ��, ��, ��, ����, ����) : ";
		cin >> user_input;

		if (user_input == "��") {
			// ���� �� ĭ �ö󰡱�
			bool inMap = checkNmoveXY(user_x, user_y, 0, -1);
			if (inMap == true) {
				cout << "���� �� ĭ �ö󰩴ϴ�." << endl;
				displayMap(map, user_x, user_y);
			}
			else
				continue;
		}
		else if (user_input == "��") {
			// �Ʒ��� �� ĭ ��������
			bool inMap = checkNmoveXY(user_x, user_y, 0, 1);
			if (inMap == true) {
				cout << "���� �� ĭ �������ϴ�." << endl;
				displayMap(map, user_x, user_y);
			}
			else
				continue;
		}
		else if (user_input == "��") {
			// �������� �̵��ϱ�
			bool inMap = checkNmoveXY(user_x, user_y, -1, 0);
			if (inMap == true) {
				cout << "�������� �̵��մϴ�." << endl;
				displayMap(map, user_x, user_y);
			}
			else
				continue;
		}
		else if (user_input == "��") {
			// ���������� �̵��ϱ�
			bool inMap = checkNmoveXY(user_x, user_y, 1, 0);
			if (inMap == true) {
				cout << "���������� �̵��մϴ�." << endl;
				displayMap(map, user_x, user_y);
			}
			else
				continue;
		}
		else if (user_input == "����") {
			// ���� ��� �Լ� ȣ��
			displayMap(map, user_x, user_y);
		}
		else if (user_input == "����") {
			cout << "�����մϴ�.";
			break;
		}
		else {
			cout << "�߸��� �Է��Դϴ�." << endl;
			continue;
		}

		// �������� ������ ��� ����
		bool finish = checkGoal(map, user_x, user_y);
		if (finish == true) {
			cout << "�������� �����߽��ϴ�! �����մϴ�!" << endl;
			cout << "������ �����մϴ�." << endl;
			break;
		}
		// Ư�̻���(hp ����) �߻� ���� üũ, hp�� 0�� �Ǹ� ����
		if (checkState(map, user_x, user_y) == false) {
			break;
		}
	}
	return 0;
}


// ������ ����� ��ġ ����ϴ� �Լ�
void displayMap(int map[][mapX], int user_x, int user_y) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == user_y && j == user_x) {
				cout << " USER |"; // �� �� 1ĭ ����
			}
			else {
				int posState = map[i][j];
				switch (posState) {
				case 0:
					cout << "      |"; // 6ĭ ����
					break;
				case 1:
					cout << "������|";
					break;
				case 2:
					cout << "  ��  |"; // �� �� 2ĭ ����
					break;
				case 3:
					cout << " ���� |"; // �� �� 1ĭ ����
					break;
				case 4:
					cout << "������|";
					break;
				}
			}
		}
		cout << endl;
		cout << " -------------------------------- " << endl;
	}
}

// �̵��Ϸ��� ���� ��ȿ�� ��ǥ���� üũ�ϴ� �Լ�
bool checkNmoveXY(int& user_x, int& user_y, int movement_x, int movement_y) {
	bool checkFlag = false;
	user_x += movement_x;
	user_y += movement_y;
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
		checkFlag = true;
		my_user.DecreaseHP(1);
	}
	else {
		cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�.\n" << endl;
		user_x -= movement_x;
		user_y -= movement_y;
	}

	return checkFlag;
}
// ������ ��ġ�� ���������� üũ�ϴ� �Լ�
bool checkGoal(int map[][mapX], int user_x, int user_y) {
	// ������ �����ϸ�
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}

bool checkState(int map[][mapX], int user_x, int user_y) {
	if (map[user_y][user_x] == 1) {
		cout << "�������� �ֽ��ϴ�.\n" << endl;
	}
	else if (map[user_y][user_x] == 2) {
		cout << "���� �ֽ��ϴ�. HP�� 2 �پ��ϴ�.\n" << endl;
		my_user.DecreaseHP(2);
	}
	else if (map[user_y][user_x] == 3) {
		cout << "������ �ֽ��ϴ�. HP�� 2 �þ�ϴ�.\n" << endl;
		my_user.hp += 2;
	}

	if (my_user.GetHP() <= 0) {
		cout << "HP�� 0 ���ϰ� �Ǿ����ϴ�.�����߽��ϴ�.\n������ �����մϴ�.";
		return false;
	}
	return true;
}