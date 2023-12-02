#include <random>
#include <time.h>
#include "monster.h"

// 몬스터 클래스
Monster::Monster(int number, int user_x, int user_y, int hp, int ad) {
	this->number = number;
	this->monster_x = user_x;
	this->monster_y = user_y;
	this->hp = hp;
	this->ad = ad;
}
// hp 반환
int Monster::GetHP() {
	return hp;
}
// 몬스터의 스탯을 랜덤으로 설정
void Monster::SetRandomState() {
	srand((unsigned int)time(NULL));
	hp = rand() % 10 + 3;
	ad = rand() % 5 + 2;
}
// 몬스터 체력 감소
void Monster::DecreaseHP(int dec_hp) {
	hp -= dec_hp;
}