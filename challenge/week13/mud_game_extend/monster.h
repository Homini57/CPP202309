#pragma once
#include <iostream>
#include <string>
using namespace std;
// 몬스터 클래스
class Monster {
	
	int hp;
	
public:
	int number;
	int monster_x;
	int monster_y;
	int ad;
	Monster(int number = 0 , int monster_x = 0, int monster_y = 0, int hp = 5, int ad = 3);
	int GetHP();
	void SetRandomState();
	void DecreaseHP(int dec_hp);

	
	// void DoAttack();
};
