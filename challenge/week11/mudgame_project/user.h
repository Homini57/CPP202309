#pragma once
#include <iostream>
#include <string>
using namespace std;
// 유저 hp에 대한 클래스
class User {
private:
	int hp;
public:
	// hp 초기화
	User() {
		hp = 20;
	}
	void IncreaseHP(int inc_hp); //hp 증가시키는 메서드
	void DecreaseHP(int dec_hp); //hp 감소시키는 메서드
	int GetHP(); // hp를 반환하는 메서드
};
