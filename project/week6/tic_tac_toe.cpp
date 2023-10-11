#include <iostream>
using namespace std;

int main() {
	
	const int numCell = 3;
	char board[numCell][numCell]{};// 보드 크기 : 3 x 3
	int x, y;// x : 입력받은 행 좌표, y : 입력받은 열 좌표 저장 변수
	// 보드판 초기화
	for (x = 0; x < numCell; x++) {
		for (y = 0; y < numCell; y++) {
			board[x][y] = ' ';
		}
	}
	// 틱택토 코드
	
	int k = 0; // 현재 턴 플레이어 구분을 위한 변수
	char currentUser = 'X'; // 현재 플레이어 돌 모양을 저장하기 위한 변수
	while (true) {
		// 1. 현재 턴 플레이어 출력, 플레이어 돌 모양 저장
		switch (k % 2) {
		case 0:
			cout << k % 2 + 1 << "번 유저(X)의 차례입니다 -> ";
			currentUser = 'X';
			break;
		case 1:
			cout << k % 2 + 1 << "번 유저(O)의 차례입니다 -> ";
			currentUser = 'O';
			break;
		}

		// 2. 좌표 입력 받기
		cout << "(x, y) 좌표를 입력하세요: ";
		cin >> x >> y;

		//3. 입력받은 좌표 유효성 검사
		if (x >= numCell || y >= numCell) {
			cout << x << ", " << y << ": ";
			cout << "x와 y 둘 중 하나가 칸을 벗어납니다." << endl;
			continue;
		}
		if (board[x][y] != ' ') {
			cout << x << ", " << y << ": 이미 돌이 차있습니다." << endl;
			continue;
		}

		// 4. 입력받은 좌표에 돌 놓기
		board[x][y] = currentUser;

		// 5. 보드판 현황 출력
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

		// 6. 가로줄 빙고 검사
		bool win = false;
		for (int i = 0; i < numCell; i++) {
			for (int j = 0; j < numCell; j++) {
				if (board[i][j] == currentUser) {
					if (j == numCell - 1) {
						cout << "가로에 모두 돌이 놓였습니다!";
						win = true;
						break;
					}
				}
				else
					break;
			}
		}

		//7. 세로줄 빙고 검사
		for (int j = 0; j < numCell; j++) {
			for (int i = 0; i < numCell; i++) {
				if (board[i][j] == currentUser) {
					if (i == numCell - 1) {
						cout << "세로에 모두 돌이 놓였습니다!";
						win = true;
						break;
					}
				}
				else
					break;
			}
		}

		// 8. 대각선1 빙고 검사
		for (int i = 0; i < numCell; i++) {
			if (board[i][i] == currentUser) {
				if (i == numCell - 1) {
					cout << "왼쪽 위에서 오른쪽 아래 대각선으로 모두 돌이 놓였습니다!";
					win = true;
					break;
				}
			}
			else
				break;
		}

		// 9. 대각선2 빙고 검사
		for (int i = 0; i < numCell; i++) {
			if (board[i][numCell - i - 1] == currentUser) {
				if (i == numCell - 1) {
					cout << "오른쪽 위에서 왼쪽 아래 대각선으로 모두 돌이 놓였습니다!";
					win = true;
					break;
				}
			}
			else
				break;
		}

		if (win == true) {
			cout << k % 2 + 1 << "번 유저(" << currentUser << ")의 승리입니다!" << endl;
			cout << "종료합니다" << endl;
			break;
		}

		k++;
		if (k >= 9) {
			cout << "모든 칸이 다 찼습니다. 종료합니다";
			break;
		}
		
	}
	return 0;

}
