/*
ID : karthikgvsk
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void findFreq(int year, bool leap, int freq[], int n, int initial) {
	int thirteenthJan = ((13 - 1) % 7 + initial) % 7;
	cout << thirteenthJan << endl;
	freq[thirteenthJan]++;
	int array[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (leap) {
		array[1] = 29;
	}
	int i, sum;
	sum = 0;
	for(i = 0; i < 11; i++) {
		sum = sum + array[i];
		sum %= 7;
		int newThirteenth = (sum + thirteenthJan) % 7;
		freq[newThirteenth]++;
	}
}


int main() {
	//input and output file streams
	ifstream fin ("friday.in");
	ofstream fout ("friday.out");

	//input receiver (num of years)
	int n;
	fin >> n;
	//storing the frequencies
	int freq[] = {0, 0, 0, 0, 0, 0, 0};
	bool leap = false;
	
	int year;
	int initial = 1;
	int prev = 0;
	for(year = 1900; year <= 1900 + n - 1; year++) {
		cout << year << " " << leap;
		if (leap) {
			initial = (prev + 2) % 7;
			prev = initial;
		}else {
			initial = (prev + 1) % 7;
			prev = initial;
		}

		cout << initial << " " << prev << endl;
		
		if ((year % 100 != 0 && year % 4 == 0) || (year % 100 == 0 && year % 400 == 0)) {
			leap = true;
		}else {
			leap = false;
		}

		findFreq(year, leap, freq, n, initial);

	}
	int i;
	fout << freq[6] << " ";
	cout << freq[6] << " ";
	for(i = 0; i < 6; i++) {
		if (i < 5){
			fout << freq[i] << " ";
		}else {
			fout << freq[i] << endl;
		}
		cout << freq[i] << " ";
	}

}
