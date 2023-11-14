#pragma once
#include <iostream>
#include <string>
using namespace std;
// 유저 hp에 대한 클래스
class User {
public:
	int hp;
	void DecreaseHP(int dec_hp);//hp 감소시키는 메서드
	int GetHP();//hp 반환하는 메서드
};
