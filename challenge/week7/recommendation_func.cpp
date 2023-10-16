#include <iostream>
#define NUM_USERS 3
#define NUM_ITEMS 3
using namespace std;

void initializePreferences(int preferences[NUM_USERS][NUM_ITEMS]);
void findRecommendedItems(const int preferences[NUM_USERS][NUM_ITEMS]);
int userPreferences[NUM_USERS][NUM_ITEMS];

int main() {
	// ��ȣ���� �ʱ�ȭ�ϰ� ����ڿ��� ��õ�� �׸� ã��
	initializePreferences(userPreferences);
	findRecommendedItems(userPreferences);

	return 0;
}

// ����� �� �� �׸� ���� ��ȣ���� �Է¹޾� 2���� �迭�� �����ϴ� �Լ�
void initializePreferences(int preferences[NUM_USERS][NUM_ITEMS]) {
	for (int i = 0; i < NUM_USERS; ++i) {
		cout << "�����" << (i + 1) << "�� ��ȣ���� �Է��ϼ��� (";
		cout << NUM_ITEMS << "���� �׸� ����): ";
		for (int j = 0; j < NUM_ITEMS; ++j) {
			cin >> userPreferences[i][j];
		}
	}
}

// �� ����ڿ� ���� ��õ �׸� ��� �� �׸��� ����ϴ� �Լ�
void findRecommendedItems(const int preferences[NUM_USERS][NUM_ITEMS]) {
	for (int i = 0; i < NUM_USERS; ++i) {
		int maxPreferenceIndex = 0;
		for (int j = 1; j < NUM_ITEMS; ++j) {
			if (userPreferences[i][j] > userPreferences[i][maxPreferenceIndex]) {
				maxPreferenceIndex = j;
			}
		}
		cout << "����� " << (i + 1) << "���� ��õ�ϴ� �׸�: ";
		cout << (maxPreferenceIndex + 1) << endl;
	}
}
