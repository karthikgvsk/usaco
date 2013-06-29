/*
ID: karthik24
PROG: sprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int prime_list[10000];

/*
int gen_prime_list(int max) {
	prime_list[0] = 2;
	prime_list[1] = 3;
	
	int num_primes = 2;
	int index = num_primes - 1;
	
	int num, q;
	
	bool truth;
	
	for(num = 4; num <= max; num++) {
		
		truth = true;
		for(q = 0; q <= num_primes; q++) {
			
			if(num % prime_list[q] == 0) {
				truth = false;
				break;
			}

			if(prime_list[q] >= sqrt(num)) {
				break;
			}
		}
		
		if(truth) {
			num_primes++;
			index = num_primes - 1;
			prime_list[index] = num;
		}
	}

	return num_primes;
}
*/

bool is_prime(int n) {
	if(n == 0 || n == 1) return false;
	
	int p;

	for(p = 2; p <= sqrt(n); p++) {
		if(n % p == 0) return false;
	}

	return true;
}

int main()
{
	ifstream fin ("sprime.in");
	ofstream fout ("sprime.out");
	
	int num_digits, num_primes, i, num, temp, min, max;
	int primes_five_list[20];
	int last_digit[4] = {1, 3, 7, 9};
	int d1, d2, d3, num1, num2, num3, num4, count, index;
	
	bool truth;

	fin >> num_digits;
	
	if(num_digits <= 5) {
		min = pow(10, num_digits - 1);
		max = pow(10, num_digits);
		for(num = min; num < max; num++) {
			truth = true;
			temp = num;
			while((temp > 0) && truth){
				if(not is_prime(temp)) {
					truth = false;
					break;
				}
				temp = temp / 10;
			}
			if(truth) {
				fout << num << endl;
				cout << num << endl;
			}
		}
	} else {
		min = pow(10, 5 - 1);
		max = pow(10, 5);
		count = 0;
		for(num = min; num < max; num++) {
			truth = true;
			temp = num;
			while((temp > 0) && truth){
				if(not is_prime(temp)) {
					truth = false;
					break;
				}
				temp = temp / 10;
			}
			if(truth) {
				primes_five_list[count] = num;
				count++;
			}
		}
		
		// 6 digit number
		if(num_digits == 6) {
			for(index = 0; index < count; index++) {
				for(d1 = 0; d1 < 4; d1++) {
					num1 = primes_five_list[index]* 10 + last_digit[d1];
					if(is_prime(num1)) {
						fout << num1 << endl;
						cout << num1 << endl;
					}
				}
			}
		}
		
		// 7 digit number
		if(num_digits == 7) {
			for(index = 0; index < count; index++) {
				for(d1 = 0; d1 < 4; d1++) {
					for(d2 = 0; d2 < 4; d2++) {
						num1 = primes_five_list[index]*10 + last_digit[d1];
						num2 = num1*10 + last_digit[d2];
						if(is_prime(num1) && is_prime(num2)) {
							fout << num2 << endl;
							cout << num2 << endl;
						}
					}
				}
			}
		}

		// 8 digit number
		if(num_digits == 8) {
			for(index = 0; index < count; index++) {
				for(d1 = 0; d1 < 4; d1++) {
					for(d2 = 0; d2 < 4; d2++) {
						for(d3 = 0; d3 < 4; d3++) {
							num1 = primes_five_list[index]*10 + last_digit[d1];
							num2 = num1*10 + last_digit[d2];
							num3 = num2*10 + last_digit[d3];
							if(is_prime(num1) && is_prime(num2) && is_prime(num3)) {
								fout << num3 << endl;
								cout << num3 << endl;
							}
						}
					}
				}
			}
		}
	}
	
	return 0;
}
