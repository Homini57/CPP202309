#include "user.h"
// hp ������Ű�� �޼���
void User::DecreaseHP(int dec_hp) {
	hp -= dec_hp;
}
// hp ���ҽ�Ű�� �޼���
int User::GetHP() {
	return hp;
}