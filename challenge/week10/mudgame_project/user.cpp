#include "user.h"
// hp 증가시키는 메서드
void User::DecreaseHP(int dec_hp) {
	hp -= dec_hp;
}
// hp 감소시키는 메서드
int User::GetHP() {
	return hp;
}