#include <iostream>

using namespace std;

int main()
{
	const int kArraySize = 3;

	int founding[kArraySize];							//배열 선언 : type 배열이름[배열크기]
	founding[0] = 918;
	founding[1] = 1302;
	founding[2] = 1948;

	cout << "고려 건국 연도 : " << founding[0] << endl;	//배열[index]는 배열의 값을 반환한다.
	cout << "조선 건국 연도 : " << founding[1] << endl;
	cout << "한국 건국 연도 : " << founding[2] << endl;

	return 0;

}