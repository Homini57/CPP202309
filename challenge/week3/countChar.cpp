#include <iostream>
using namespace std;

int main() 
{
	int vowel = 0;			//모음의 개수를 저장하는 변수
	int consonant = 0;		//자음의 개수를 저장하는 변수
	cout << "영문자를 입력하고 ctrl+z를 치세요" << endl;

	char ch;				// 입력받은 영문자를 저장하는 변수

	while (cin >> ch)
	{
		//모음  ASCII코드 : a,e,i,o,u = 97,101,105,111,117
		switch (ch)
		{
		case 97:			//모음 'a'를 입력하면 vowel 1+
			vowel++;
			break;
		case 101:			//모음 'e'를 입력하면 vowel 1+
			vowel++;
			break;
		case 105:			//모음 'i'를 입력하면 vowel 1+
			vowel++;
			break;
		case 111:			//모음 'o'를 입력하면 vowel 1+
			vowel ++;
			break;
		case 117:			//모음 'u'를 입력하면 vowel 1+
			vowel++;
			break;
		default:			//나머지 자음을 입력하면 consonant 1+
			consonant++;
			break;
		}
	}

	cout << "모음: " << vowel << endl;
	cout << "자음: " << consonant << endl;
	return 0;

}