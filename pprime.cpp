/*
ID: karthik24
PROG: pprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
#define MAX_NUM 100000000
#define MAX_DIGITS 11

int is_prime(int n)
{
	int p;
	if(n == 0 || n == 1) return false;

	for(p = 2; p <= (int) sqrt(n); p++) {
		if(n % p == 0) return false;
	}

	return true;
}

int get_num_digits(int n)
{
	int count = 0;
	while(n >= 10) {
		count++;
		n = n / 10;
	}

	if(n == 10) {
		count = count + 2;
	} else {
		count = count + 1;
	}

	return count;
}


int main()
{
	ifstream fin ("pprime.in");
	ofstream fout ("pprime.out");
	
	int a, b, num_half_digits, da, db, num;
	int d1, d2, d3, d4, d5, d6, d7, d8, d9;
	int diglist[MAX_DIGITS];
	
	fin >> a >> b;	

	da = get_num_digits(a);
	db = get_num_digits(b);

	cout << da << " " << db << endl;

	// generating 1 digit palindromes
	if(da <= 1) {
		for(d1 = 5; d1 <= 9; d1++) {
			num = d1;
			if(num >= a && num <= b) {
				if(is_prime(num)) {
					fout << num << endl;
				}
				//cout << num << endl;
			}
		}
	}

	// generating 2 digit palindromes
	if(da <= 2 && db >= 2) {
		for(d1 = 1; d1 <= 9; d1++) {
			num = 10*d1 + d1;
			if(num >= a && num <= b) {
				if(is_prime(num)) {
					fout << num << endl;
				}
			}
		}
	}
	// generating 3 digit palindromes
	if(da <= 3 && db >= 3) {
		for(d1 = 1; d1 <= 9; d1++) {
			for(d2 = 0; d2 <= 9; d2++) {
				num = 100*d1 + 10*d2 + d1;
				if(num >= a && num <= b) {
					if(is_prime(num)) {
						fout << num << endl;
					}
				}
			}
		}
	}

	// generating 4 digit palindromes
	if(da <= 4 && db >= 4) {
		for(d1 = 1; d1 <= 9; d1++) {
			for(d2 = 0; d2 <= 9; d2++) {
				num = 1000*d1 + 100*d2 + 10*d2 + d1;
				if(num >= a && num <= b) {
					if(is_prime(num)) {
						fout << num << endl;
					}
				}
			}
		}
	}

	// generating 5 digit palindromes
	if(da <= 5 && db >= 5) {
		for(d1 = 1; d1 <= 9; d1++) {
			for(d2 = 0; d2 <= 9; d2++) {
				for(d3 = 0; d3 <= 9; d3++) {
					num = 10000*d1 + 1000*d2 + 100*d3 + 10*d2 + d1;
					if(num >= a && num <= b) {
						if(is_prime(num)) {
							fout << num << endl;
						}
					}
				}
			}
		}
	}

	// generating 6 digit palindromes
	if(da <= 6 && db >= 6) {
		for(d1 = 1; d1 <= 9; d1++) {
			for(d2 = 0; d2 <= 9; d2++) {
				for(d3 = 0; d3 <= 9; d3++) {
					num = 100000*d1 + 10000*d2 + 1000*d3 + 100*d3 + 10*d2 + d1;
					if(num >= a && num <= b) {
						if(is_prime(num)) {
							fout << num << endl;
						}
					}
				}
			}
		}
	}
	// generating 7 digit palindromes
	if(da <= 7 && db >= 7) {
		for(d1 = 1; d1 <= 9; d1++) {
			for(d2 = 0; d2 <= 9; d2++) {
				for(d3 = 0; d3 <= 9; d3++) {
					for(d4 = 0; d4 <= 9; d4++) {
						num = 1000000*d1 + 100000*d2 + 10000*d3 + 1000*d4 + 100*d3 + 10*d2 + d1;
						if(num >= a && num <= b) {
							if(is_prime(num)) {
								fout << num << endl;
							}
						}
					}
				}
			}
		}
	}

	// generating 8 digit palindromes
	if(da <= 8 && db >= 8) {
		for(d1 = 1; d1 <= 9; d1++) {
			for(d2 = 0; d2 <= 9; d2++) {
				for(d3 = 0; d3 <= 9; d3++) {
					for(d4 = 0; d4 <= 9; d4++) {
						num = 10000000*d1 + 1000000*d2 + 100000*d3 + 10000*d4 + 1000*d4 + 100*d3 + 10*d2 + d1;
						if(num >= a && num <= b) {
							if(is_prime(num)) {
								fout << num << endl;
							}
						}
					}
				}
			}
		}
	}

	// generating 9 digit palindromes
	if(da <= 9 && db >= 9) {
		for(d1 = 1; d1 <= 9; d1++) {
			for(d2 = 0; d2 <= 9; d2++) {
				for(d3 = 0; d3 <= 9; d3++) {
					for(d4 = 0; d4 <= 9; d4++) {
						for(d5 = 0; d5 <= 9; d5++) {
							num = 100000000*d1 + 10000000*d2 + 1000000*d3 + 100000*d4 + 10000*d5 + 1000*d4 + 100*d3 + 10*d2 + d1;
							if(num >= a && num <= b) {
								if(is_prime(num)) {
									fout << num << endl;
								}
							}
						}
					}
				}
			}
		}
	}

	return 0;
}
