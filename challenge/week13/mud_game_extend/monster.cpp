#include <random>
#include <time.h>
#include "monster.h"

// ���� Ŭ����
Monster::Monster(int number, int user_x, int user_y, int hp, int ad) {
	this->number = number;
	this->monster_x = user_x;
	this->monster_y = user_y;
	this->hp = hp;
	this->ad = ad;
}
// hp ��ȯ
int Monster::GetHP() {
	return hp;
}
// ������ ������ �������� ����
void Monster::SetRandomState() {
	srand((unsigned int)time(NULL));
	hp = rand() % 10 + 3;
	ad = rand() % 5 + 2;
}
// ���� ü�� ����
void Monster::DecreaseHP(int dec_hp) {
	hp -= dec_hp;
}