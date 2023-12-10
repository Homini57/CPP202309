#include "user.h"

User::User(string name, int user_x, int user_y, int hp, int armor, int ad) {
	this->name = name;
	this->user_x = user_x;
	this->user_y = user_y;
	this->hp = hp;
	this->armor = armor;
	this->ad = ad;
}
// hp ������Ű�� �޼���
void User::IncreaseHP(int inc_hp) {
	hp += inc_hp;
}
// hp ���ҽ�Ű�� �޼���
void User::DecreaseHP(int dec_hp) {
	hp -= dec_hp;
}

// hp, ����, ���ݷ� ��ȯ�ϴ� �޼���
int User::GetHP() {
	return hp;
}
int User::GetArmor() {
	return armor;
}
int User::GetAd() {
	return ad;
}
// ���� ���� ����
void User::SetState(int armor, int ad) {
	this->armor = armor;
	this->ad = ad;
}
// ���� �̵�
void User::MoveUser(int movement_x, int movement_y) {
	user_x += movement_x;
	user_y += movement_y;
	hp -= 1;
}

// ���� �ǰ�
void User::GetDammaged(Monster monster) {
	hp -= monster.ad - armor;
}
// ����
void User::DoAttack(Monster& monster) {
	cout << "�����մϴ�" << endl;
	monster.DecreaseHP(ad);
}

// ������ Ŭ���� - ���� ���
Magician::Magician(string name, int user_x, int user_y, int hp, int armor, int ad) :
	User::User(name, user_x, user_y, hp, armor, ad) {}
void Magician::DoAttack(Monster& monster) {
	cout << "���� ���" << endl;
	monster.DecreaseHP(ad);
}

// ���� Ŭ���� - ���� ���
Warrior::Warrior(string name, int user_x, int user_y, int hp, int armor, int ad) :
	User::User(name, user_x, user_y, hp, armor, ad) {}
void Warrior::DoAttack(Monster& monster) {
	cout << "���� ���" << endl;
	monster.DecreaseHP(ad);
}