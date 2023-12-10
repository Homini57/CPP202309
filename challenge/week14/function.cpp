#include "function.h"

// 사용자 정의 함수

// 맵에 존재하는 몬스터들 생성, 리스트화, 수정 필요
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
// 공격 목표 몬스터 생성, 수정 필요
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
		cout << "몬스터" << (*target_monster)->number + 1 << " 현재 Hp : " << (*target_monster)->GetHP() << endl;
		cout << endl;
	}
}

//0. 체크 1. 위치 이동 2. 적 공격 가능하다면 공격 선택 3. 적이 유저 공격 4. 지도 출력
bool MoveUser(int map[][mapX], const vector <User>& user_list, User* user_now, int input_type, int movement_x, int movement_y) {
	bool return_value = true;
	// 이동 메시지
	string move_message[4] = { "위로 한 칸 올라갑니다." , "아래로 한 칸 내려갑니다.", "왼쪽으로 이동합니다.", "오른쪽으로 이동합니다." };
	// 이동시 유저가 맵에서 벗어나는지 확인
	bool inMap = CheckXY(*user_now, movement_x, movement_y);

	try {
		if (inMap == true) {
			// 이동 메시지 출력
			cout << move_message[input_type] << endl;
			// 유저 이동
			user_now->MoveUser(movement_x, movement_y);
			// 맵 출력
			DisplayMap(map, user_list);
			// 이벤트 실행, 출력 
			CheckEvent(map, user_now);
			//SelectAttack();
		}
		else {
			throw false;
		}
	}
	// 예외 처리
	catch (bool return_valu) {
		cout << "맵을 벗어났습니다. 다시 돌아갑니다.\n" << endl;
		return return_value;
	}

	return return_value;

}


// 지도와 사용자 위치 출력하는 함수
void DisplayMap(int map[][mapX],const vector <User>& user_list) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == user_list[0].user_y && j == user_list[0].user_x && i == user_list[1].user_y && j == user_list[1].user_x) {
				cout << "마, 전" << "|"; // 양 옆 1칸 공백
			}
			else if (i == user_list[0].user_y && j == user_list[0].user_x) {
				cout << user_list[0].name << "|"; // 양 옆 1칸 공백
			}
			else if (i == user_list[1].user_y && j == user_list[1].user_x) {
				cout << user_list[1].name << "|"; // 양 옆 1칸 공백
			}
			else {
				int posState = map[i][j];
				switch (posState) {
				case 0:
					cout << "      |"; // 6칸 공백
					break;
				case 1:
					cout << "아이템|";
					break;
				case 2:
					cout << "  적  |"; // 양 옆 2칸 공백
					break;
				case 3:
					cout << " 포션 |"; // 양 옆 1칸 공백
					break;
				case 4:
					cout << "목적지|";
					break;
				}
			}
		}
		cout << endl;
		cout << " ---------------------------------- " << endl;
	}
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
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

// 유저의 위치가 목적지인지 체크하는 함수
bool CheckGoal(int map[][mapX], User& user) {
	// 목적지 도착하면
	if (map[user.user_y][user.user_x] == 4) {
		return true;
	}
	return false;
}
// 이벤트 실행, 출력
void CheckEvent(int map[][mapX], User* user) {
	int user_x = user->user_x;
	int user_y = user->user_y;
	if (map[user_y][user_x] == 1) {
		cout << "아이템이 있습니다.\n" << endl;
	}
	else if (map[user_y][user_x] == 2) {
		cout << "적이 있습니다. HP가 2 줄어듭니다.\n" << endl;
		user->DecreaseHP(2);
	}
	else if (map[user_y][user_x] == 3) {
		cout << "포션이 있습니다. HP가 2 늘어납니다.\n" << endl;
		user->IncreaseHP(2);
	}
}
// 유저 hp가 0이하가 되었는지 체크
bool CheckUser(User& user) {
	bool is_live = true;
	int user_HP = user.GetHP();
	if (user_HP <= 0) {
		is_live = false;
	}

	return is_live;
}