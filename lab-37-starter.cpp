/****************************************************

COMSC 210 | Lab 37 | Skylar Robinson | IDE Used: Eclipse

****************************************************/

#include <iostream>
#include <fstream>
using namespace std;

int sum_ascii(string);

int main() {
    int sum = 0;
    string temp;
    ifstream in;

    //open file
    in.open("lab-37-data.txt");
    if (!in) {
    	cout << "File error.\n";
    	return -1;
    }

    //add ascii values in file
    while (getline(in, temp)) {
    	sum = sum + sum_ascii(temp);
    }

    //close file
    in.close();

    cout << "Sum of ascii values: " << sum << endl;

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
