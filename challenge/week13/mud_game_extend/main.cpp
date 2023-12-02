

#include "user.h"
#include "function.h"


// 메인  함수
int main() {
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
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

	// 두명의 유저 생성
	Magician user1;
	Warrior user2;
	vector <User> user_list{user1,user2};

	// 1이면 user1, 2이면 user2의 턴( 나머지 + 1)
	int turn_number = 0;
	DisplayMap(map, user_list);

	// 게임 시작 
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프

		// 사용자의 입력을 저장할 변수
		string user_input = "";
		
		// 현재 유저를 받는 변수
		User* user_now = &user_list[turn_number % 2];
		//
		for (int i = 0; i < user_list.size(); i++) {
			cout << user_list[i].name << " 현재 Hp: " << user_list[i].GetHP() << endl;
		}
		cout << endl;
		
		//위치 입력시 실행문
		do {

			// 유저의 범위 1칸 내의 몬스터와 좌표 생성
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
				cout << "몬스터"<< target_monster->number << " 현재 Hp : " << target_monster->GetHP() << endl;
				cout << endl;
			}
			// 입력창 출력
			cout << "---------------------------------------------------" << endl;

			cout << user_now->name << " : 명령어를 입력하세요(";
			if (target_xy[0] != 0) {
				cout << "공격, ";
			}
			cout << "상, 하, 좌, 우, 지도, 종료) : ";
			cin >> user_input;
			cout << endl;
			// 몬스터 공격
			if (user_input == "공격") {
				// 유저와 몬스터가 서로 공격
				user_now->DoAttack(*target_monster);
				user_now->GetDammaged(*target_monster);
				// 몬스터가 죽으면 몬스터 소멸 후, 유저들이 버프 획득
				if (target_monster->GetHP() <= 0) {
					monster_list.erase(monster_list.begin() + target_monster->number);
					map[target_xy[1]][target_xy[0]] = 0;
					cout << "몬스터를 물리쳣습니다. 버프를 획득합니다." << endl << endl;
					for (int i = 0; i < user_list.size(); i++) {
						int user_armor = user_list[i].GetArmor();
						int user_ad = user_list[i].GetAd();
						user_list[i].SetState(user_armor + 1, user_ad + 1);
					}
				}
				DisplayMap(map, user_list);
				break;
			}
			// 위로 한 칸 올라가기
			else if (user_input == "상") {
				if (MoveUser(map, user_list, user_now, 0, 0, -1)) break;
				else continue;
			}
			// 아래로 한 칸 내려가기
			else if (user_input == "하") {
				if (MoveUser(map, user_list, user_now, 1, 0, 1)) break;
				else continue;
			}
			// 왼쪽으로 이동하기
			else if (user_input == "좌") {
				if (MoveUser(map, user_list, user_now, 2, -1, 0))break;
				else continue;
			}
			// 오른쪽으로 이동하기
			else if (user_input == "우") {
				if (MoveUser(map, user_list, user_now, 3, 1, 0))break;
				else continue;
			}
			// 지도 입력 시 실행문
			else if (user_input == "지도") {
				// 지도 출력 함수 호출
				DisplayMap(map, user_list);
				break;
			}
			// 종료 입력 시 실행문
			else if (user_input == "종료") {
				break;
			}
			// 잘못 입력 시 실행문
			else {
				cout << "잘못된 입력입니다." << endl;
				continue;
			}
			target_monster = NULL;
			delete target_monster;
		} while (true);

		// 종료 입력 시 실행문
		if (user_input == "종료") {
			cout << "종료합니다.";
			break;
			}

		// 목적지에 도달할 경우 종료
		bool finish = CheckGoal(map, *user_now);
		if (finish == true) {
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}
		// 특이사항(hp 변동) 발생 여부 체크, hp가 0이 되면 종료

		if (!CheckUser(*user_now)) {
			cout << "HP가 0 이하가 되었습니다.실패했습니다.\n게임을 종료합니다.";
			break;
		}
		
		turn_number++;
	}
	return 0;
}


