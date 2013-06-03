/*
ID : karthikgvsk
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ifstream fin ("beads.in");
	ofstream fout ("beads.out");
	// variabls for collecting values
	int n;
	string necklace;
	//collecting the values
	fin >> n;
	fin >> necklace;
	//iterator over necklace
	int i = 0;
	int max = 0;

	for(i = 0; i < n; i++) {
		//broke the necklace before the ith index
		int j, count; // indexer 
		//front portion of the necklace
		count = 0;
		j = i % n;
		bool found = false;
		bool condition;
		do{
			//increase the counter
			count++;
			int k;
			char temp1, temp2;
			//condition checking
			j = j % n;
			k = (j + 1) % n;
			temp1 = necklace[j];
			temp2 = necklace[k];
			if (temp2 == 'w') {
				temp2 = temp1;
			}

			condition = (temp1 == temp2);
			//increment for while loop
			j++;
		}while(count <= n && condition);
		cout << count << endl;
		//backside of necklace
		if(count < n) {
			j = (i - 1) % n;
			found = false;
			do {
				count++;
				int k;

				j = j % n;
				k = (j - 1) % n;
				
				char temp1, temp2;
				temp1 = necklace[j];
				temp2 = necklace[k];
				if (temp2 == 'w') {
					temp2 = temp1;
				}

				condition = (temp1 == temp2);
				//increment for while loop
				j--;
			}while(condition);	
		}
		cout << count << endl << "-------" << endl;
		if(max <= count) {
			max = count;
		}
	}
	fout << max - 1 << endl;
	cout << max - 1<< endl;

	return 0;
}
