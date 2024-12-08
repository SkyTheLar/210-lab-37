/****************************************************

COMSC 210 | Lab 37 | Skylar Robinson | IDE Used: Eclipse

****************************************************/

#include <iostream>
#include <fstream>
#include <map>
#include <list>
using namespace std;

int gen_hash_index(string);

int main() {
    map<int, list<string>> hash_table;
    ifstream in;

    //open file
    in.open("lab-37-data.txt");
    if (!in) {
    	cout << "File error.\n";
    	return -1;
    }

    //add ascii values in file
    string temp;
    while (getline(in, temp)) {
    	int bucket = gen_hash_index(temp);
    	//see if bucket exists
    	auto it = hash_table.find(bucket);
    	if (it = hash_table.end()) { //bucket doesn't exist

    	}
    	else {

    	}
    }

    //close file
    in.close();

    //display first 100 entries

    return 0;
}

int gen_hash_index(string s) {
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
