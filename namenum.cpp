/*
ID: karthik24
LANG: C++
TASK: namenum
*/


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int asso(char ch) {
	if(ch == 'A' || ch == 'B' || ch == 'C') {
		return 2;
	} else if(ch == 'D' || ch == 'E' || ch == 'F') {
		return 3;
	} else if(ch == 'G' || ch == 'H' || ch == 'I') {
		return 4;
	} else if(ch == 'J' || ch == 'K' || ch == 'L') {
		return 5;
	} else if(ch == 'M' || ch == 'N' || ch == 'O') {
		return 6;
	} else if(ch == 'P' || ch == 'R' || ch == 'S') {
		return 7;
	} else if(ch == 'T' || ch == 'U' || ch == 'V') {
		return 8;
	} else if (ch == 'W' || ch == 'X' || ch == 'Y') {
		return 9;
	}
}

unsigned long long find(string s) {
	unsigned long long len = s.length();
	unsigned long long i, sum;
	sum = 0;
	for(i = 0; i < len; i++) {
		sum = 10 * sum + asso(s[i]);
	}
	return sum;
}

int main()
{
	ifstream fin ("namenum.in");
	ofstream fout ("namenum.out");
	ifstream din ("dict.txt");
	
	unsigned long long n, i, input;

	string names[5000];
	unsigned long long num[5000];
	n = 0;
	
	while(din.good())
	{
		din >> names[n];
		n++;
	}
	
	for(i = 0; i < n; i++) {
		num[i] = find(names[i]);
	}
	
	fin >> input;
	cout << input << endl;
	int count = 0;
	for(i = 0; i < n; i++) {
		if(num[i] == input) {
			fout << names[i] << endl;
			cout << names[i] << endl;
			count++;
		}
	}
	if(count == 0) {
		fout << "NONE" << endl;
		cout << "NONE" << endl;
	}

	return 0;
}
