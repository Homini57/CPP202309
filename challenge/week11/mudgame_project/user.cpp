#include "user.h"
// hp ������Ű�� �޼���
void User::IncreaseHP(int inc_hp) {
	hp += inc_hp;
}
// hp ���ҽ�Ű�� �޼���
void User::DecreaseHP(int dec_hp) {
	hp -= dec_hp;
}
// hp ��ȯ�ϴ� �޼���
int User::GetHP() {
	return hp;
}