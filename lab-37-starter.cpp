/****************************************************

COMSC 210 | Lab 37 | Skylar Robinson | IDE Used: Eclipse

****************************************************/

#include <iostream>
using namespace std;

int sum_ascii(string);

int main() {
    char a = 'A';
    cout << a << endl;
    cout << (int) a << endl;
    int b = 66;
    cout << b << endl;
    cout << (char) b << endl;
    
    string test = "Hello";
    cout << sum_ascii(test) << endl;

    return 0;
}

int sum_ascii(string s) {
	int sum = 0;
	for (int i = 0; i < s.size(); i++) {
		sum = sum + (int) s[i];
	}
	return sum;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
