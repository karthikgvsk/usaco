/*
ID: karthik24
PROG: crypt1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdbool.h>
#include <stdio.h>
using namespace std;

int a[10];
int times[10000];

bool satisfies(int val, int N);

void sorted(int N)
{
	int i, j, temp;
	for(i = 0; i < N; i++)
	{
		for(j = i + 1; j < N; j++)
		{
			if(a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

int numDigits(int val)
{
	int count = 0;
	if(val < 10)
	{
		return 1;
	}
	while(val >= 10)
	{
		count++;
		val /= 10;
	}

	return count + 1;
}


bool satisfies(int val, int N)
{
	int i, rem, count, num, val1;
	bool found;
	//cout << "++++" << endl;
	//cout << val << endl;
	count = 0;
	val1 = val;
	while(val > 0)
	{
		found = false;
		rem = val % 10;
		//cout << rem << endl;
		for(i = 0; i < N; i++)
		{
			if(a[i] == rem)
			{
				found = true;
			}
		}
		if(!found)
		{
			return false;
		}
		val /= 10;
	}
	
	times[val1]++;
	return true;
}


int main()
{
	
	ifstream fin ("crypt1.in");
	ofstream fout ("crypt1.out");
	//ofstream fout1 ("debug.out");

	int N, i, j, k, num, in, count, num1, num2;
	int n[1000];
	bool pass;

	fin >> N;
	for(i = 0; i < N; i++)
	{
		fin >> a[i];
		cout << a[i] << endl;
	}
	
	sorted(N);
	
	
	in = 0;
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			for(k = 0; k < N; k++)
			{
				num = 100*a[i] + 10*a[j] + a[k];
				//cout << num << endl;
				n[in] = num;
				in++;
				
			}
		}
	}
	
	/*
	count = 0;
	for(i = 0; i < in; i++)
	{
		for(j = i; j < in; j++)
		{
			if(satisfies(10*n[i] + n[j], N))
			{
				cout << n[i] << " " << n[j] << " " << 10*n[i] + n[j] << endl;
				count++;
			}
		}
	}
	*/

	
	count = 0;
	for(i = 0; i < in; i++)
	{
		for(j = 0; j < N; j++)
		{
			for(k = 0; k < N; k++)
			{
				num1 = n[i] * a[j];
				num2 = n[i] * a[k];

				if(numDigits(num1) == 3 && numDigits(num2) == 3)
				{
						//cout << n[i] << " " << a[j] << " " << a[k] << " " << num1 << " " << num2 << " " << num << " ";

					if(satisfies(num1, N) && satisfies(num2, N))
					{
						num = n[i] * (10 * a[j] + a[k]);
						if(satisfies(num, N) && numDigits(num) == 4)
						{
							//cout << n[i] << " " << a[j] << " " << a[k] << " " << num1 << " " << num2 << " " << num << endl;
							//fout1 << n[i] << " " << a[j] << " " << a[k] << " " << num1 << " " << num2 << " " << num << endl;
							//if(times[num] == 1)
							//{
								cout << n[i] << " " << a[k] << " " << a[j] << " " << num2 << " " << num1 << " " << num << endl;
								//fout1 << n[i] << " " << a[k] << " " << a[j] << " " << num2 << " " << num1 << " " << num << endl;

								//cout << num << endl;
								//fout1 << num << endl;
								count++;
							//}
							pass = true;
						}
					}
				}
				
			}
		}
	}
	


	/*
	count = 0;
	for(i = 100; i <= 999; i++)
	{
		for(j = 10; j <= 99; j++)
		{
			if(satisfies(i, N) && satisfies(j, N))
			{
				num1 = i*(j%10);
				num2 = i*(j/10);
				cout << num1 << " " << num2 << " ";
				if(satisfies(num1, N) && satisfies(num2, N) && numDigits(num1) == 3 && numDigits(num2) == 3)
				{
					cout << "pass ";
					if(satisfies(i*j, N) && numDigits(i*j) == 4)
					{
						cout << i * j;
						fout1 << i << " " << (j % 10) << " " << j / 10 << " " << num1 << " " << num2 << " " << i*j << endl;
						count++;
					}
				}
				cout << endl;
			}
		}
	}
	*/	
	fout << count << endl;
	cout << count << endl;
	//cout << numDigits(124321);
	return 0;
}

