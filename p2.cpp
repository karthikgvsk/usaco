/*
ID : karthikgvsk
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int prod(char c[]) {
	int i = 0;
	int prod = 1;
	for(i = 0; i < 6; i++) {
		if(c[i] == '\0') {
			break;
		}
		prod = prod * (c[i] - 'A' + 1);
	}
	return prod;
}

int main() 
{
	ofstream fout ("ride.out");
	ifstream fin ("ride.in");
	char a[7], b[7];
	fin >> a >> b;	
	int valA, valB;
	valA = prod(a);
	valB = prod(b);
	if((valA % 47) == (valB % 47)) {
		fout << "GO" << endl;
	}
	else {
		fout << "STAY" << endl;
	}
	
	return 0;
}
