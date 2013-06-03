/*
ID: karthik24
LANG: C++
TASK: dualpal
*/


//array can be used to change base but lazy to change
#include <iostream>
#include <fstream>
using namespace std;

unsigned long long base(unsigned long long i,unsigned long long j) 
{
	unsigned long long b = 0;
	unsigned long long count = 1;
	while(i > 0) {
		b = b + (count) * (i%j);
		//cout << b << " " << (count) << endl;
		i = i / j;
		count *= 10;
	}
	return b;
}

bool palindrome(long long num)
{
	long long a[100];
	long long n = 0;
	long long i;

	while(num > 0) {
		a[n] = num % 10;
		n++;
		num = num / 10;
	}
	
	//bool found = true;
	for(i = 0; i < (n + 1) / 2; i++)
	{
		if(a[i] != a[n - 1 - i]) {
			return false;
		}
	}
	return true;
}


int main()
{
	
	ifstream fin ("dualpal.in");
	ofstream fout ("dualpal.out");
	long long N, S;
	long long count, num, j, palCount;
	fin >> N >> S;
	cout << N << " " << S << endl;
	long long i = S + 1;
	count = 0;
	bool found = false;
	while(count < N) {
		palCount = 0;
		for(j = 2; j < 11; j++) {
			num =  base(i, j);
			//cout << num << endl;
			if(palindrome(num)) {
				cout << i << " " << num << " " << j <<  endl;
				palCount++;
			}
			if(palCount >= 2) {
				fout << i << endl;
				cout << i << endl;
				count++;
				break;
				found = true;
			}
			if(found)
			{
				break;
			}

		}

		i = i + 1;
	}
	cout << count << endl;
	cout << "+++++++++++" << endl;
	for(j = 2; j < 11; j++) {
		num = base(11253, j);
		cout << num << " " << j << " " << palindrome(num) << endl;
	}

	cout << "=========" << endl;
	cout << base(11253, 2);

	return 0;
}


	
