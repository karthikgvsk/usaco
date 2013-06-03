/*

ID: karthik24

PROG: milk2

LANG: C++

*/

#include <fstream>
#include <iostream>
using namespace std;

long long start[5000], end[5000];

void sort(long long n) 
{
	long long i, j, temp;
	for(i = 0; i < n-1; i++) {
		for(j = i+1; j < n; j++) {
			if(start[i] > start[j]) {
				temp = start[j];
				start[j] = start[i];
				start[i] = temp;

				temp = end[j];
				end[j] = end[i];
				end[i] = temp;
			}
		}
	}
}

long long max(long long a, long long b) {
	return (a > b) ? a : b;
}

int main()
{
	ofstream fout ("milk2.out");
	ifstream fin ("milk2.in");

	long long N, i, j, use, idle, s, e, maxUse, maxIdle, prev;
	//long long start[5000], end[5000];

	fin >> N;
	for(i = 0; i < N; i++) {
		fin >> start[i] >> end[i];
	}

	sort(N);

	for(i = 0; i < N; i++) {
		cout << start[i] << " " << end[i] << endl;
	}

	if(N == 1) {
		fout << end[0] - start[0] << " " << 0 << endl;
		cout << end[0] - start[0] << " " << 0 << endl;
	}
	else {
	use = 0;
	idle = 0;
	maxUse = 0;
	maxIdle = 0;
	prev = 0;
	cout << "++++++++++++++++" << endl;
	/*
	for(i = 0; i < (N -1); i++) {
		s = start[i + 1];
		e = max(end[i], prev);
		prev = e;
		cout << s << " " << e << endl;
		if(s <= e) {
			cout << use << endl;
			use = use + start[i+1] - start[i];
			idle = 0;
		} else {
			use = use + end[i] - start[i];
			if(maxUse < use) {
				maxUse = use;
			}
			use = 0;
			idle = start[i+1] - end[i];
			if(maxIdle < idle) {
				maxIdle = idle;
			}
		}
	}
	*/
	i = 0;
	s = start[i];
	e = end[i];
	while(i <= (N - 1)) 
	{
		cout << "+++" << endl;
		if(start[i] <= e) {
			cout << e << endl;
			e = max(e, end[i]);
			idle = 0;
			if(i == (N-1)) {
				use = e - s;
				if(maxUse < use) {
					maxUse = use;
				}
				break;
			}
		}else{
			use = e - s;
			cout << use << " " << i << endl;
			if(maxUse < use) {
				maxUse = use;
			}
			s = start[i];
			idle = s - e;
			cout << idle << endl;
			if(maxIdle < idle) {
				maxIdle = idle;
			}
			e = end[i];
		}
		i = i + 1;

	}
	cout << "++++++++++++++++++" << endl;
	fout << maxUse << " " << maxIdle << endl;
	cout << maxUse << " " << maxIdle << endl;
	return 0;
	}
}
			
