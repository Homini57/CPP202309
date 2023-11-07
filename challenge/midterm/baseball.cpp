#include <iostream>
#include <string>
using namespace std;

bool checkNumber(string randomNum, char& firstNum, char& secondNum, char& thirdNum);

int main() {
	string randomNum; // 맞춰야 하는 3자리수의 숫자 저장 변수
	char firstNum; // 정답의 첫번째 자리수
	char secondNum; // 정답의 두번째 자리수
	char thirdNum; // 정답의 세번째 자리수

	while (1) {
		randomNum = to_string(rand() % 900 + 100); // 랜덤한 3자리수 생성
		bool same = false; // 모든 수가 다를 경우 true를 갖는 변수

		// TODO 1: 3자리 숫자의 자릿수를 추출하고, 모든 수가 다른지 체크하는 코드블록 작성
		same = checkNumber(randomNum, firstNum, secondNum, thirdNum);

		// 모든 수가 다르면 다음 코드로 넘어가는 코드
		if (same == true) {
			break;
		}
	}
	
	int turn = 0; // 입력 시도 횟수
	while (1) {
		cout << turn + 1 << "번째 시도입니다. " << endl;
		string userNumber; // 사용자가 입력한 세자리수 저장 변수
		char guessFirst; // 추측한 숫자의 첫번째 자리수
		char guessSecond; // 추측한 숫자의 두번째 자리수
		char guessThird; // 추측한 숫자의 세번째 자리수


		// 사용자에게 세자리 수를 입력받는 코드 블록
		while (1) {
			cout << "세자리 수를 입력해주세요: ";
			cin >> userNumber;

			bool same = false; // 모든 수가 다를 경우 true를 갖는 변수
			// TODO 1: 3자리 숫자의 자릿수를 추출하고, 모든 수가 다른지 체크하는 코드블록 작성

			if (userNumber.length() != 3) {
				cout << "입력된 숫자가 3자리 수가 아닙니다. 다시 입력하세요." << endl;
				continue;
			}

			same = checkNumber(userNumber, guessFirst, guessSecond, guessThird);

			if (same == false) {
				cout << "입력한 숫자에 중복된 숫자가 있습니다. 다시 입력하세요." << endl;
				continue;
			}
			else break;
		}


		int strike = 0; // 스트라이크 갯수를 저장하는 변수
		int ball = 0; // 볼 갯수를 저장하는 변수

		// TODO 2: 정답과 추측한 숫자의 자릿수와 숫자를 비교하며 힌트를 주기 위한 코드블록 작성

		if (firstNum == guessFirst) strike++;
		else if(firstNum == guessSecond || firstNum == guessThird) ball++;

		if (secondNum == guessSecond) strike++;
		else if (secondNum == guessFirst || secondNum == guessThird) ball++;

		if (thirdNum == guessThird) strike++;
		else if (thirdNum == guessFirst || thirdNum == guessSecond) ball++;
		

	

		

		if (strike == 0 && ball == 0) {
			cout << "아웃입니다." << endl;
		}
		else {
			cout << userNumber << "의 결과 : " << strike << " 스트라이크, " << ball << "볼 입니다." << endl;
		}

		

		if (strike == 3) {
			cout << "정답을 맞췄습니다. 축하합니다.";
			break;
		}

		turn += 1;
	}

	return 0;
}

bool checkNumber(string randomNum, char& firstNum, char& secondNum, char& thirdNum) {
	bool same = true;
	firstNum = randomNum[0]; // 정답의 첫번째 자리수
	secondNum = randomNum[1]; // 정답의 두번째 자리수
	thirdNum = randomNum[2]; // 정답의 세번째 자리수
	if (firstNum == secondNum || secondNum == thirdNum || firstNum == thirdNum) same = false;

	return same;

}