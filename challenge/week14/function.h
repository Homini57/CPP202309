#pragma once
#include <vector>
#include "user.h"
const int mapX = 5;		// ������ ĭ(��) ��
const int mapY = 5;		// ������ ��(��) ��

// ����� ���� �Լ�
//GenearteMonsters�Լ��� GenerateTargetMonster�Լ��� ���� �ʿ�
void GenerateMonsters(int map[][mapX], vector <Monster> monster_list);
void GenerateTargetMonster(int map[][mapX], User* user_now, vector <Monster> monster_list, int target_xy[2], Monster** target_monster);
bool MoveUser(int map[][mapX], const vector <User>& user_list, User* user_now, int input_type, int movement_x, int movement_y);
bool CheckXY(User& user, int movement_x, int movement_y);
void DisplayMap(int map[][mapX], const vector <User>& user_list);
bool CheckGoal(int map[][mapX], User& user);
void CheckEvent(int map[][mapX], User* user);
bool CheckUser(User& user);
