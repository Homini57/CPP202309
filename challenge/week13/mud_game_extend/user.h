#pragma once
#include <iostream>
#include <string>
#include "monster.h"
using namespace std;
// 유저 hp에 대한 클래스
class User {
protected:
	// 유저의 체력, 방어력, 공격력
	int hp;
	int armor;
	int ad;
public:
	// hp 초기화
	string name;
	// 유저의 위치를 저장할 변수
	int user_x; // 가로 번호
	int user_y; // 세로 번호
	
	User(string name = " 유저 ", int user_x = 0, int user_y = 0, int hp = 20, int armor = 0, int ad = 0);
	void IncreaseHP(int inc_hp); //hp 증가시키는 메서드
	void DecreaseHP(int dec_hp); //hp 감소시키는 메서드
	int GetHP(); // hp를 반환하는 메서드
	int GetArmor();
	int GetAd();
	void SetState(int armor, int ad);
	void MoveUser(int movement_x, int movement_y);
	void GetDammaged(Monster monster);
	virtual void DoAttack(Monster& monster);
};


class Magician : public User {
public:
	Magician(string name = "마법사", int user_x = 0, int user_y = 0, int hp = 20, int armor = 0, int ad = 5);
	void DoAttack(Monster& monster);
};


class Warrior : public User {
public:
	Warrior(string name = " 전사 ", int user_x = 0, int user_y = 0, int hp = 20, int armor = 2, int ad = 3);
	void DoAttack(Monster& monster);
};