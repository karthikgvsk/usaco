/*

ID: karthik24

PROG: transform

LANG: C++

*/

#include <fstream>
#include <iostream>
using namespace std;

char a[10][10], b[10][10];

int calc(int n) {
	int i, j;
	bool flag = true;
	// trans #1;
	
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			if(a[i][j] != b[j][(n - 1) - i]) {
				flag = false;
				break;
			}
		}
		if(!flag) {
			break;
		}
	}

	if(flag) {
		return 1;
	}

	// trans #2
	flag = true;
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			if(a[i][j] != b[(n - 1) - i][(n - 1) - j]) {
				flag = false;
				break;
			}
		}
		if(!flag) {
			break;
		}
	}
	if(flag) {
		return 2;
	}

	// trans #3
	flag = true;
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			
			if(a[i][j] != b[(n - 1) - j][i]) {
				flag = false;
			}
		}
		if(!flag) {
			break;
		}
	}
	if(flag) {
		return 3;
	}

	// trans #4
	flag = true;
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			if(a[i][j] != b[i][(n-1) - j]) {
				flag = false;
				break;
			}
		}
		if(!flag) {
			break;
		}
	}
	if(flag) {
		return 4;
	}

	// trans #5
	/*
	flag = true; 
	int ele1 = 0;
	int ele2 = (n - 1) - 0;
	int opr = 0;
	if(a[0][0] == b[ele2][(n - 1) - ele1]) {
		opr = 1;
	} else if(a[0][0] == b[n - 1 - ele1][n - 1 - ele2]) {
		opr = 2;
	} else if(a[0][0] == b[n - 1 - ele2][ele1]) {
		opr = 3;
	} else {
		flag = false;
	}
	*/
	int j1;
	flag = true;
	bool flag1, flag2, flag3;
	flag1 = true;
	flag2 = true;
	flag3 = true;

	if(flag) {
		//cout << opr << endl;
		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) {
				j1 = (n - 1) - j;
				if(a[i][j] != b[j1][n - 1 - i]) {
					flag1 = false;
					break;
				}
			}
			if(!flag1) {
				break;
			}
		}
		if(flag1) {
			return 5;
		}

		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) {
				j1 = (n - 1) - j;
				if(a[i][j] != b[n - 1 - i][n - 1 - j1]) {
					flag2 = false;
					break;
				}
			}
			if(!flag2) {
				break;
			}
		}
		if(flag2) {
			return 5;
		}

		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) {
				j1 = n - 1 - j;
				if(a[i][j] != b[n - 1 - j1][n - 1 - i]) {
					flag3 = false;
					break;
				}
			}
			if(!flag3) {
				break;
			}
		}
		if(flag3) {
			return 5;
		}
	}

	// trans #6
	flag = true;
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			if(a[i][j] != b[i][j]) {
				flag = false;
				break;
			}
		}
		if(!flag) {
			break;
		}
	}
	if(flag) {
		return 6;
	}

	return 7;
}
			

int main()
{
	ifstream fin ("transform.in");
	ofstream fout ("transform.out");

	int n, i, j, num;
	fin >> n;
	
	// initial array
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			fin >> a[i][j];
		}
	}
	// transformed array
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			fin >> b[i][j];
		}
	}

	num = calc(n);

	fout << num << endl;
	cout << num << endl;

	return 0;
}
