#include "function.h"

// ����� ���� �Լ�

// �ʿ� �����ϴ� ���͵� ����, ����Ʈȭ, ���� �ʿ�
void GenerateMonsters(int map[][mapX], vector <Monster> monster_list) {
	int monster_number = 0;
	for (int j = 0; j < mapY; j++) {
		for (int i = 0; i < mapX; i++) {
			if (map[j][i] == 2) {
				Monster monster(monster_number, i, j);
				monster.SetRandomState();
				monster_list.push_back(monster);
				monster_number++;
			}
		}
	}
}
// ���� ��ǥ ���� ����, ���� �ʿ�
void GenerateTargetMonster(int map[][mapX], User *user_now, vector <Monster> monster_list, int target_xy[2], Monster** target_monster) {
	for (int j = -1; j < 2; j++) {
		int target_y = user_now->user_y + j;
		for (int i = -1; i < 2; i++) {
			int target_x = user_now->user_x + i;
			if (map[target_y][target_x] == 2) {
				target_xy[0] = target_x;
				target_xy[1] = target_y;
			}
		}
	}
	if (target_xy[0] != 0) {
		for (Monster& monster : monster_list) {
			if (monster.monster_x == target_xy[0] && monster.monster_y == target_xy[1]) {
				*target_monster = &monster;
			}
		}
		cout << "����" << (*target_monster)->number + 1 << " ���� Hp : " << (*target_monster)->GetHP() << endl;
		cout << endl;
	}
}

//0. üũ 1. ��ġ �̵� 2. �� ���� �����ϴٸ� ���� ���� 3. ���� ���� ���� 4. ���� ���
bool MoveUser(int map[][mapX], const vector <User>& user_list, User* user_now, int input_type, int movement_x, int movement_y) {
	bool return_value = true;
	// �̵� �޽���
	string move_message[4] = { "���� �� ĭ �ö󰩴ϴ�." , "�Ʒ��� �� ĭ �������ϴ�.", "�������� �̵��մϴ�.", "���������� �̵��մϴ�." };
	// �̵��� ������ �ʿ��� ������� Ȯ��
	bool inMap = CheckXY(*user_now, movement_x, movement_y);

	try {
		if (inMap == true) {
			// �̵� �޽��� ���
			cout << move_message[input_type] << endl;
			// ���� �̵�
			user_now->MoveUser(movement_x, movement_y);
			// �� ���
			DisplayMap(map, user_list);
			// �̺�Ʈ ����, ��� 
			CheckEvent(map, user_now);
			//SelectAttack();
		}
		else {
			throw false;
		}
	}
	// ���� ó��
	catch (bool return_valu) {
		cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�.\n" << endl;
		return return_value;
	}

	return return_value;

}


// ������ ����� ��ġ ����ϴ� �Լ�
void DisplayMap(int map[][mapX],const vector <User>& user_list) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == user_list[0].user_y && j == user_list[0].user_x && i == user_list[1].user_y && j == user_list[1].user_x) {
				cout << "��, ��" << "|"; // �� �� 1ĭ ����
			}
			else if (i == user_list[0].user_y && j == user_list[0].user_x) {
				cout << user_list[0].name << "|"; // �� �� 1ĭ ����
			}
			else if (i == user_list[1].user_y && j == user_list[1].user_x) {
				cout << user_list[1].name << "|"; // �� �� 1ĭ ����
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
		cout << " ---------------------------------- " << endl;
	}
}

// �̵��Ϸ��� ���� ��ȿ�� ��ǥ���� üũ�ϴ� �Լ�
bool CheckXY(User& user, int movement_x, int movement_y) {
	bool checkFlag = true;
	int user_x = user.user_x;
	int user_y = user.user_y;
	user_x += movement_x;
	user_y += movement_y;
	if (user_x < 0 || mapX <= user_x || user_y < 0 || mapY <= user_y) {
		checkFlag = false;
	}
	return checkFlag;
}

// ������ ��ġ�� ���������� üũ�ϴ� �Լ�
bool CheckGoal(int map[][mapX], User& user) {
	// ������ �����ϸ�
	if (map[user.user_y][user.user_x] == 4) {
		return true;
	}
	return false;
}
// �̺�Ʈ ����, ���
void CheckEvent(int map[][mapX], User* user) {
	int user_x = user->user_x;
	int user_y = user->user_y;
	if (map[user_y][user_x] == 1) {
		cout << "�������� �ֽ��ϴ�.\n" << endl;
	}
	else if (map[user_y][user_x] == 2) {
		cout << "���� �ֽ��ϴ�. HP�� 2 �پ��ϴ�.\n" << endl;
		user->DecreaseHP(2);
	}
	else if (map[user_y][user_x] == 3) {
		cout << "������ �ֽ��ϴ�. HP�� 2 �þ�ϴ�.\n" << endl;
		user->IncreaseHP(2);
	}
}
// ���� hp�� 0���ϰ� �Ǿ����� üũ
bool CheckUser(User& user) {
	bool is_live = true;
	int user_HP = user.GetHP();
	if (user_HP <= 0) {
		is_live = false;
	}

	return is_live;
}