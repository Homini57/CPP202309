#pragma once
#include <iostream>
#include <string>
using namespace std;
// ���� hp�� ���� Ŭ����
class User {
public:
	int hp;
	void DecreaseHP(int dec_hp);//hp ���ҽ�Ű�� �޼���
	int GetHP();//hp ��ȯ�ϴ� �޼���
};
