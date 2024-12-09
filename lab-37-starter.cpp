/****************************************************

COMSC 210 | Lab 38 | Skylar Robinson | IDE Used: Eclipse

****************************************************/

#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <algorithm>
using namespace std;

int gen_hash_index(string);
int menu();
void print100(map<int, list<string>>);
void searchKey(map<int, list<string>>);
void addKey(map<int, list<string>>&);
void delKey(map<int, list<string>>&);
void modKey(map<int, list<string>>&);

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

    int choice;
    while (choice != 6) {
    	choice = menu();
    	switch (choice) {
    	case 1: print100(hash_table); break;
    	case 2: searchKey(hash_table); break;
    	case 3: addKey(hash_table); break;
    	case 4: delKey(hash_table); break;
    	case 5: modKey(hash_table); break;
    	default: break;
    	}
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

int menu() {
	int choice;
	cout << "Hash Table Options:\n"
		 << "[1] Print the first 100 entries.\n"
		 << "[2] Search for a key.\n"
		 << "[3] Add a key.\n"
		 << "[4] Remove a key.\n"
		 << "[5] Modify a key.\n"
		 << "[6] Exit.\n"
		 << "Enter a choice by number-> ";
	cin >> choice;
	cin.ignore();
	return choice;
}

void print100(map<int, list<string>> t){
    //display first 100 entries
    auto it = t.begin();
    for (int i = 0; i < 100; i++) {
    	cout << "Bucket: " << it->first << endl;
    	cout << "Key(s):\n";
    	for (string s : it->second) {
    		cout << "\t" << s << "\n";
    	}
    	cout << "\n";
    	it++;
    }
}

void searchKey(map<int, list<string>> t) {
	string search;
	cout << "Enter a key to search for: ";
	getline(cin, search);
	int bucket = gen_hash_index(search);
	auto it = t.find(bucket);
	if (it == t.end()) {
		cout << "Key not found.\n";
		return;
	}
	else {
		auto lit = find(it->second.begin(), it->second.end(), search);
		if (lit == it->second.end()) {
			cout << "Key not found.\n";
			return;
		}
		else {
			cout << "Key found in hash table!\n";
		}
	}
}

void addKey(map<int, list<string>>& t) {
	string temp;
	cout << "Enter a key to add: ";
	getline(cin, temp);
	int bucket = gen_hash_index(temp);
	//see if bucket exists
	auto it = t.find(bucket);
	if (it == t.end()) { //bucket doesn't exist
		//make list and insert new pair
		list<string> tList = {temp};
		t.insert(make_pair(bucket, tList));
	}
	else { //bucket does exist
		//start with current list, add new value
		list<string> tList = t.at(bucket);
		tList.push_front(temp);
		// add new list to hash table
		t[bucket] = tList;
	}
	cout << "Key added!\n";
}
void delKey(map<int, list<string>>& t) {
	string toDel;
	cout << "Enter a key to delete: ";
	getline(cin, toDel);
	int bucket = gen_hash_index(toDel);
	auto it = t.find(bucket);
	if (it == t.end()) {
		cout << "Key not found.\n";
		return;
	}
	else {
		auto lit = find(it->second.begin(), it->second.end(), toDel);
		if (lit == it->second.end()) {
			cout << "Key not found.\n";
			return;
		}
		else {
			it->second.erase(lit);
			cout << "Key deleted!\n";
		}
	}
}

void modKey(map<int, list<string>>& t) {
	string toMod;
	cout << "Enter a key to modify: ";
	getline(cin, toMod);
	int bucket = gen_hash_index(toMod);
	auto it = t.find(bucket);
	if (it == t.end()) {
		cout << "Key not found.\n";
		return;
	}
	else {
		auto lit = find(it->second.begin(), it->second.end(), toMod);
		if (lit == it->second.end()) {
			cout << "Key not found.\n";
			return;
		}
		else {
			it->second.erase(lit);
			string temp;
			cout << "Enter modified key: ";
			getline(cin, temp);
	    	int tBuc = gen_hash_index(temp);
	    	//see if bucket exists
	    	auto it = t.find(tBuc);
	    	if (it == t.end()) { //bucket doesn't exist
	    		//make list and insert new pair
	    		list<string> tList = {temp};
	    		t.insert(make_pair(tBuc, tList));
	    	}
	    	else { //bucket does exist
	    		//start with current list, add new value
	    		list<string> tList = t.at(tBuc);
	    		tList.push_front(temp);
	    		// add new list to hash table
	    		t[tBuc] = tList;
	    	}
	    	cout << "Key modified!\n";
		}
	}
}
/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
