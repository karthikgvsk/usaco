/*
ID : karthikgvsk
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	// opening the basic file input and output stream
	ifstream fin ("gift1.in");
	ofstream fout ("gift1.out");
	// names, account values and number of people
	int acc[10];
	int np;
	string names[10];
	fin >> np;
	
	//loop for recording names
	int i;
	for(i = 0; i < np; i++){
		fin >> names[i];
		cout << names[i] << endl;;
	}

	//
	for(i = 0; i < np; i++) {
		acc[i] = 0;
	}
	
	//noting down the names and performing the deduction and addition operations
	while (fin.good()) {
		string name;
		string frndNames[10];
		fin >> name;
		//
		cout << name << endl;
		//
		int amt, numPeople;
		fin >> amt >> numPeople;
		//
		cout << amt << " " << numPeople << endl;
		//
		//noting down the names
		if (numPeople > 0) {
			for(i = 0; i < numPeople; i++) {
				fin >> frndNames[i];
				//
				cout << frndNames[i] << endl;
				//
			}
		}
		//adding amt to user value
		i = 0;
		if (amt > 0) {
		while (i < np) {
			if (names[i] == name) {
					
					acc[i] = acc[i] - amt + (amt % numPeople);
					//
					cout << acc[i] << endl;
					//
					break;
				}
				i++;
			}
		}
		//adding to friends' account values
		if ( numPeople > 0 ) {
			for(i = 0; i < numPeople; i++) {
				name = frndNames[i];
				int j = 0;
				while (j < np) {
					if (name == names[j]) {
						acc[j] = acc[j] + (amt / numPeople);
						//
						cout << acc[j] << endl;
						//
						break;
					}
					j++;
				}
			}
		}
	}

	//printing out the names and acc values
	for(i = 0; i < np; i++) {
		fout << names[i] << " " << acc[i] << endl;
		cout << names[i] << " " << acc[i] << endl;
	}

	return 0;

}

