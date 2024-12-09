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
    	if (it == hash_table.end()) { //bucket doesn't exist
    		//make list and insert new pair
    		list<string> tList = {temp};
    		hash_table.insert(make_pair(bucket, tList));
    	}
    	else { //bucket does exist
    		//start with current list, add new value
    		list<string> tList = hash_table.at(bucket);
    		tList.push_front(temp);
    		// add new list to hash table
    		hash_table[bucket] = tList;
    	}
    }

    //close file
    in.close();

    //display first 100 entries
    auto it = hash_table.begin();
    for (int i = 0; i < 100; i++) {
    	cout << "Bucket: " << it->first << endl;
    	cout << "Key(s):\n";
    	for (string s : it->second) {
    		cout << "\t" << s << "\n";
    	}
    	cout << "\n";
    	it++;
    }

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
