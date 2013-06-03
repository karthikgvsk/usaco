/*
ID: karthik24
TASK:  barn1
LANG: C++
*/

#include <iostream>
#include <fstream>
using namespace std;

int a[200], change[200], max[50];

void sortChange(int C)
{
	int i, j, temp;
	for(i = 0; i < C - 1; i++) {
		for(j = i + 1; j < C; j++) {
			if(change[j] > change[i]) {
				temp = change[j];
				change[j] = change[i];
				change[i] = temp;
			}
		}
	}
}

void sortValue(int C)
{
	int i, j, temp;
	for(i = 0; i < C - 1; i++) {
		for(j = i + 1; j < C; j++) {
			if(a[i] > a[j]) {
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}
}

int min(int a, int b) 
{
	return (a < b) ? a : b;
}

int main()
{
	ifstream fin ("barn1.in");
	ofstream fout ("barn1.out");
	int M, S, C, i, j, k, gap, s, e, gapMax, index, sum;
	//int a[200], change[200], max[50];
	fin >> M >> S >> C;
	for(i = 0; i < C; i++) {
		fin >> a[i];
	}
	sortValue(C);
	for(i = 0; i < C; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	
	for(i = 0; i < C - 1; i++) {
		change[i] = a[i + 1] - a[i];
	}
	
	sortChange(C);

	for(i = 0; i < C - 1; i++) {
		cout << change[i] << " ";
	}
	cout << endl;

	sum = 0;
	for(i = 0; i < min(M - 1, C - 1); i++) {
		cout << change[i] << endl;
		sum += change[i];
	}
	
	
	cout << a[C - 1] << " " << a[0] << " " << sum << endl;
	cout << (a[C - 1] - a[0] + 1) - sum + min(M - 1, C - 1)<< endl;
	fout << (a[C - 1] - a[0] + 1) - sum + min(M - 1, C - 1)<< endl;
	return 0;
}
