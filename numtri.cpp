/*
ID: karthik24
PROG: numtri
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int a[1000][1000];
int dp[1000][1000];
int main()
{
	int R, i, j;
	ifstream fin ("numtri.in");
	ofstream fout ("numtri.out");

	fin >> R;
	
	// input
	for (i = 0; i < R; i++) {
		for (j = 0; j <= i; j++) {
			fin >> a[i][j];
		}
	}

	// dp
	for (i = R - 1; i >= 0; i--) {
		for (j = 0; j <= i; j++) {
			if (i == R - 1) {
				dp[i][j] = a[i][j];
			} else {
				dp[i][j] = a[i][j] + max(dp[i+1][j], dp[i+1][j+1]);
			}
		}
	}

	fout << dp[0][0] << endl;
	
	return 0;
}
