#pragma once
#include <iostream>
#include <string>
#include "monster.h"
using namespace std;
// ���� hp�� ���� Ŭ����
class User {
protected:
	// ������ ü��, ����, ���ݷ�
	int hp;
	int armor;
	int ad;
public:
	// hp �ʱ�ȭ
	string name;
	// ������ ��ġ�� ������ ����
	int user_x; // ���� ��ȣ
	int user_y; // ���� ��ȣ
	
	User(string name = " ���� ", int user_x = 0, int user_y = 0, int hp = 20, int armor = 0, int ad = 0);
	void IncreaseHP(int inc_hp); //hp ������Ű�� �޼���
	void DecreaseHP(int dec_hp); //hp ���ҽ�Ű�� �޼���
	int GetHP(); // hp�� ��ȯ�ϴ� �޼���
	int GetArmor();
	int GetAd();
	void SetState(int armor, int ad);
	void MoveUser(int movement_x, int movement_y);
	void GetDammaged(Monster monster);
	virtual void DoAttack(Monster& monster);
};


class Magician : public User {
public:
	Magician(string name = "������", int user_x = 0, int user_y = 0, int hp = 20, int armor = 0, int ad = 5);
	void DoAttack(Monster& monster);
};


class Warrior : public User {
public:
	Warrior(string name = " ���� ", int user_x = 0, int user_y = 0, int hp = 20, int armor = 2, int ad = 3);
	void DoAttack(Monster& monster);
};