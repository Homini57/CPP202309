

#include "user.h"
#include "function.h"


// ����  �Լ�
int main() {
	// 0�� �� ����, 1�� ������, 2�� ��, 3�� ����, 4�� ������
	int map[mapY][mapX] = { {0, 1, 2, 0, 4},
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} };
	vector<Monster> monster_list;
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

	// �θ��� ���� ����
	Magician user1;
	Warrior user2;
	vector <User> user_list{user1,user2};

	// 1�̸� user1, 2�̸� user2�� ��( ������ + 1)
	int turn_number = 0;
	DisplayMap(map, user_list);

	// ���� ���� 
	while (1) { // ����ڿ��� ��� �Է¹ޱ� ���� ���� ����

		// ������� �Է��� ������ ����
		string user_input = "";
		
		// ���� ������ �޴� ����
		User* user_now = &user_list[turn_number % 2];
		//
		for (int i = 0; i < user_list.size(); i++) {
			cout << user_list[i].name << " ���� Hp: " << user_list[i].GetHP() << endl;
		}
		cout << endl;
		
		//��ġ �Է½� ���๮
		do {

			// ������ ���� 1ĭ ���� ���Ϳ� ��ǥ ����
			int target_xy[2]{ 0, -0 };
			Monster* target_monster = new Monster;

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
						target_monster = &monster;
					}
				}
				cout << "����"<< target_monster->number << " ���� Hp : " << target_monster->GetHP() << endl;
				cout << endl;
			}
			// �Է�â ���
			cout << "---------------------------------------------------" << endl;

			cout << user_now->name << " : ��ɾ �Է��ϼ���(";
			if (target_xy[0] != 0) {
				cout << "����, ";
			}
			cout << "��, ��, ��, ��, ����, ����) : ";
			cin >> user_input;
			cout << endl;
			// ���� ����
			if (user_input == "����") {
				// ������ ���Ͱ� ���� ����
				user_now->DoAttack(*target_monster);
				user_now->GetDammaged(*target_monster);
				// ���Ͱ� ������ ���� �Ҹ� ��, �������� ���� ȹ��
				if (target_monster->GetHP() <= 0) {
					monster_list.erase(monster_list.begin() + target_monster->number);
					map[target_xy[1]][target_xy[0]] = 0;
					cout << "���͸� ���������ϴ�. ������ ȹ���մϴ�." << endl << endl;
					for (int i = 0; i < user_list.size(); i++) {
						int user_armor = user_list[i].GetArmor();
						int user_ad = user_list[i].GetAd();
						user_list[i].SetState(user_armor + 1, user_ad + 1);
					}
				}
				DisplayMap(map, user_list);
				break;
			}
			// ���� �� ĭ �ö󰡱�
			else if (user_input == "��") {
				if (MoveUser(map, user_list, user_now, 0, 0, -1)) break;
				else continue;
			}
			// �Ʒ��� �� ĭ ��������
			else if (user_input == "��") {
				if (MoveUser(map, user_list, user_now, 1, 0, 1)) break;
				else continue;
			}
			// �������� �̵��ϱ�
			else if (user_input == "��") {
				if (MoveUser(map, user_list, user_now, 2, -1, 0))break;
				else continue;
			}
			// ���������� �̵��ϱ�
			else if (user_input == "��") {
				if (MoveUser(map, user_list, user_now, 3, 1, 0))break;
				else continue;
			}
			// ���� �Է� �� ���๮
			else if (user_input == "����") {
				// ���� ��� �Լ� ȣ��
				DisplayMap(map, user_list);
				break;
			}
			// ���� �Է� �� ���๮
			else if (user_input == "����") {
				break;
			}
			// �߸� �Է� �� ���๮
			else {
				cout << "�߸��� �Է��Դϴ�." << endl;
				continue;
			}
			target_monster = NULL;
			delete target_monster;
		} while (true);

		// ���� �Է� �� ���๮
		if (user_input == "����") {
			cout << "�����մϴ�.";
			break;
			}

		// �������� ������ ��� ����
		bool finish = CheckGoal(map, *user_now);
		if (finish == true) {
			cout << "�������� �����߽��ϴ�! �����մϴ�!" << endl;
			cout << "������ �����մϴ�." << endl;
			break;
		}
		// Ư�̻���(hp ����) �߻� ���� üũ, hp�� 0�� �Ǹ� ����

		if (!CheckUser(*user_now)) {
			cout << "HP�� 0 ���ϰ� �Ǿ����ϴ�.�����߽��ϴ�.\n������ �����մϴ�.";
			break;
		}
		
		turn_number++;
	}
	return 0;
}


