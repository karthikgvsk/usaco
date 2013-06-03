/*
ID: karthik24
LANG: C++
TASK: palsquare
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <sstream>
using namespace std;

bool palindrome(string s) {
	//cout << s << endl;
	int len = s.length();
	int i;
	bool found = true;
	for(i = 0; i < len / 2; i++) {
		if(s[i] != s[(len - 1) - i]) {
			found = false;
			break;
		}
	}
	return found;
}

string base(int num, int base) {
	string s = "";
	
	char a[] = 	{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 
				'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 
				'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 
				'U', 'V', 'W', 'X', 'Y', 'Z' 
				};
	while(num > 0) {
		s = a[num%base] + s; 
		num = num / base;
	}
	return s;
}

int main() 
{
	ifstream fin ("palsquare.in");
	ofstream fout ("palsquare.out");

	int B, N, i;
	string num1, num2;
	fin >> B;
	N = 300;
	for(i = 1; i <= N; i++) {
		num1 = base(i, B);
		num2 = base(i*i, B);
		//cout << num1 << " " << num2 << endl;
		if(palindrome(num2)) {
			fout << num1 << " " << num2 << endl;
			cout << num1 << " " << num2 << endl;
		}
	}

	return 0;
}
		

