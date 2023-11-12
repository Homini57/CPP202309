#include "user.h"

const int mapX = 5;		// 지도의 칸(열) 수
const int mapY = 5;		// 지도의 줄(행) 수
User my_user;
// 사용자 정의 함수

bool checkNmoveXY(int& user_x, int& user_y, int movement_x, int movement_y);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);
bool checkState(int map[][mapX], int user_x, int user_y);

// 메인  함수
int main() {
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	int map[mapY][mapX] = { {0, 1, 2, 0, 4},
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} };


	// 유저의 위치를 저장할 변수
	int user_x = 0; // 가로 번호
	int user_y = 0; // 세로 번호
	my_user.hp = 20;// 말의 현재 체력
	

	// 게임 시작 
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프

		// 사용자의 입력을 저장할 변수
		string user_input = "";

		cout << "현재 Hp: " << my_user.GetHP() << "명령어를 입력하세요(상, 하, 좌, 우, 지도, 종료) : ";
		cin >> user_input;

		if (user_input == "상") {
			// 위로 한 칸 올라가기
			bool inMap = checkNmoveXY(user_x, user_y, 0, -1);
			if (inMap == true) {
				cout << "위로 한 칸 올라갑니다." << endl;
				displayMap(map, user_x, user_y);
			}
			else
				continue;
		}
		else if (user_input == "하") {
			// 아래로 한 칸 내려가기
			bool inMap = checkNmoveXY(user_x, user_y, 0, 1);
			if (inMap == true) {
				cout << "위로 한 칸 내려갑니다." << endl;
				displayMap(map, user_x, user_y);
			}
			else
				continue;
		}
		else if (user_input == "좌") {
			// 왼쪽으로 이동하기
			bool inMap = checkNmoveXY(user_x, user_y, -1, 0);
			if (inMap == true) {
				cout << "왼쪽으로 이동합니다." << endl;
				displayMap(map, user_x, user_y);
			}
			else
				continue;
		}
		else if (user_input == "우") {
			// 오른쪽으로 이동하기
			bool inMap = checkNmoveXY(user_x, user_y, 1, 0);
			if (inMap == true) {
				cout << "오른쪽으로 이동합니다." << endl;
				displayMap(map, user_x, user_y);
			}
			else
				continue;
		}
		else if (user_input == "지도") {
			// 지도 출력 함수 호출
			displayMap(map, user_x, user_y);
		}
		else if (user_input == "종료") {
			cout << "종료합니다.";
			break;
		}
		else {
			cout << "잘못된 입력입니다." << endl;
			continue;
		}

		// 목적지에 도달할 경우 종료
		bool finish = checkGoal(map, user_x, user_y);
		if (finish == true) {
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}
		// 특이사항(hp 변동) 발생 여부 체크, hp가 0이 되면 종료
		if (checkState(map, user_x, user_y) == false) {
			break;
		}
	}
	return 0;
}


// 지도와 사용자 위치 출력하는 함수
void displayMap(int map[][mapX], int user_x, int user_y) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == user_y && j == user_x) {
				cout << " USER |"; // 양 옆 1칸 공백
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
		cout << " -------------------------------- " << endl;
	}
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool checkNmoveXY(int& user_x, int& user_y, int movement_x, int movement_y) {
	bool checkFlag = false;
	user_x += movement_x;
	user_y += movement_y;
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
		checkFlag = true;
		my_user.DecreaseHP(1);
	}
	else {
		cout << "맵을 벗어났습니다. 다시 돌아갑니다.\n" << endl;
		user_x -= movement_x;
		user_y -= movement_y;
	}

	return checkFlag;
}
// 유저의 위치가 목적지인지 체크하는 함수
bool checkGoal(int map[][mapX], int user_x, int user_y) {
	// 목적지 도착하면
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}

bool checkState(int map[][mapX], int user_x, int user_y) {
	if (map[user_y][user_x] == 1) {
		cout << "아이템이 있습니다.\n" << endl;
	}
	else if (map[user_y][user_x] == 2) {
		cout << "적이 있습니다. HP가 2 줄어듭니다.\n" << endl;
		my_user.DecreaseHP(2);
	}
	else if (map[user_y][user_x] == 3) {
		cout << "포션이 있습니다. HP가 2 늘어납니다.\n" << endl;
		my_user.hp += 2;
	}

	if (my_user.GetHP() <= 0) {
		cout << "HP가 0 이하가 되었습니다.실패했습니다.\n게임을 종료합니다.";
		return false;
	}
	return true;
}