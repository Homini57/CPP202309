#pragma once
#include <iostream>
#include <string>
using namespace std;
// ���� hp�� ���� Ŭ����
class User {
private:
	int hp;
public:
	// hp �ʱ�ȭ
	User() {
		hp = 20;
	}
	void IncreaseHP(int inc_hp); //hp ������Ű�� �޼���
	void DecreaseHP(int dec_hp); //hp ���ҽ�Ű�� �޼���
	int GetHP(); // hp�� ��ȯ�ϴ� �޼���
};
