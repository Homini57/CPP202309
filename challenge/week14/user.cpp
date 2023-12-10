#include "user.h"

User::User(string name, int user_x, int user_y, int hp, int armor, int ad) {
	this->name = name;
	this->user_x = user_x;
	this->user_y = user_y;
	this->hp = hp;
	this->armor = armor;
	this->ad = ad;
}
// hp 증가시키는 메서드
void User::IncreaseHP(int inc_hp) {
	hp += inc_hp;
}
// hp 감소시키는 메서드
void User::DecreaseHP(int dec_hp) {
	hp -= dec_hp;
}

// hp, 방어력, 공격력 반환하는 메서드
int User::GetHP() {
	return hp;
}
int User::GetArmor() {
	return armor;
}
int User::GetAd() {
	return ad;
}
// 유저 스탯 설정
void User::SetState(int armor, int ad) {
	this->armor = armor;
	this->ad = ad;
}
// 유저 이동
void User::MoveUser(int movement_x, int movement_y) {
	user_x += movement_x;
	user_y += movement_y;
	hp -= 1;
}

// 유저 피격
void User::GetDammaged(Monster monster) {
	hp -= monster.ad - armor;
}
// 공격
void User::DoAttack(Monster& monster) {
	cout << "공격합니다" << endl;
	monster.DecreaseHP(ad);
}

// 마법사 클래스 - 유저 상속
Magician::Magician(string name, int user_x, int user_y, int hp, int armor, int ad) :
	User::User(name, user_x, user_y, hp, armor, ad) {}
void Magician::DoAttack(Monster& monster) {
	cout << "마법 사용" << endl;
	monster.DecreaseHP(ad);
}

// 전사 클래스 - 유저 상속
Warrior::Warrior(string name, int user_x, int user_y, int hp, int armor, int ad) :
	User::User(name, user_x, user_y, hp, armor, ad) {}
void Warrior::DoAttack(Monster& monster) {
	cout << "베기 사용" << endl;
	monster.DecreaseHP(ad);
}