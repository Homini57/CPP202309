#include <iostream>
#include <string>
using namespace std;

const int mapX = 5;
const int mapY = 5;
int user_hp = 20;
// ����� ���� �Լ�
bool moveNcheckXY(int& user_x, int mapX, int& user_y, int mapY, int movement_x, int movement_y);
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

	// ���� ���� 
	while (1) { // ����ڿ��� ��� �Է¹ޱ� ���� ���� ����

		// ������� �Է��� ������ ����
		string user_input = "";
		
		cout << "���� Hp: "<<user_hp << "��ɾ �Է��ϼ���(��, ��, ��, ��, ����, ����) : ";
		cin >> user_input;

		if (user_input == "��") {
			// ���� �� ĭ �ö󰡱�
			bool inMap = moveNcheckXY(user_x, mapX, user_y, mapY, 0, -1);
			if (inMap == true) {
				cout << "���� �� ĭ �ö󰩴ϴ�." << endl;
				displayMap(map, user_x, user_y);
			}

		}
		else if (user_input == "��") {
			// TODO: �Ʒ��� �� ĭ ��������
			bool inMap = moveNcheckXY(user_x, mapX, user_y, mapY, 0, 1);
			if (inMap == true) {
				cout << "���� �� ĭ �������ϴ�." << endl;
				displayMap(map, user_x, user_y);
			}

		}
		else if (user_input == "��") {
			// TODO: �������� �̵��ϱ�
			bool inMap = moveNcheckXY(user_x, mapX, user_y, mapY, -1, 0);
			if (inMap == true) {
				cout << "�������� �̵��մϴ�." << endl;
				displayMap(map, user_x, user_y);
			}
		}
		else if (user_input == "��") {
			// TODO: ���������� �̵��ϱ�
			bool inMap = moveNcheckXY(user_x, mapX, user_y, mapY, 1, 0);
			if (inMap == true) {
				cout << "���������� �̵��մϴ�." << endl;
				displayMap(map, user_x, user_y);
			}
		}
		else if (user_input == "����") {
			// TODO: ���� �����ֱ� �Լ� ȣ��
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

		// �������� �����ߴ��� üũ
		bool finish = checkGoal(map, user_x, user_y);
		if (finish == true) {
			cout << "�������� �����߽��ϴ�! �����մϴ�!" << endl;
			cout << "������ �����մϴ�." << endl;
			break;
		}

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
bool moveNcheckXY(int& user_x, int mapX, int& user_y, int mapY, int movement_x, int movement_y) {
	bool checkFlag = false;
	user_x += movement_x;
	user_y += movement_y;
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
		checkFlag = true;
		user_hp -= 1;
	}
	else {
		cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
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
		cout << "�������� �ֽ��ϴ�." << endl;
	}
	else if (map[user_y][user_x] == 2) {
		cout << "���� �ֽ��ϴ�. HP�� 2 �پ��ϴ�." << endl;
		user_hp -= 2;
	}
	else if (map[user_y][user_x] == 3) {
		cout << "������ �ֽ��ϴ�. HP�� 2 �þ�ϴ�." << endl;
		user_hp += 2;
	}

	if (user_hp <= 0) {
		cout << "HP�� 0 ���ϰ� �Ǿ����ϴ�.�����߽��ϴ�.\n������ �����մϴ�.";
		return false;
	}
		return true;
}