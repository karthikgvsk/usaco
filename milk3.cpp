/*
ID: karthik24
LANG: C++
TASK: milk3
*/

#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int maxLit[3];
int poss[22][22][22];
bool done[22][22][22];
bool cVal[22];

//ofstream fout1 ("output.out");


void calc(int a[3])
{
	int i, j, k, temp, temp1, temp2;
	done[a[0]][a[1]][a[2]] = true;
	for(i = 0; i < 3; i++)	
	{
		for(j = 0; j < 3; j++)
		{
			// pouring i into j
			if(j != i)
			{
				if(a[i] <= maxLit[j] - a[j])
				{

					temp = a[i];
					a[j] = a[j] + a[i];
					a[i] = 0;
					if(!done[a[0]][a[1]][a[2]])
					{
						calc(a);
					}
					done[a[0]][a[1]][a[2]] = true;
					a[j] = a[j] - temp;
					a[i] = temp;
				}
				else
				{
					temp = a[i];
					temp1 = maxLit[j] - a[j];
					temp2 = a[j];
					a[j] = maxLit[j];
					a[i] = a[i] - temp1;
					if(!done[a[0]][a[1]][a[2]])
					{
						calc(a);
					}

					a[j] = temp2;
					a[i] = temp;
				}
			}
		}
	}
	return;
}				

int main()
{
	int i, j, k, endVal;
	int a[3];
	ifstream fin ("milk3.in");
	ofstream fout ("milk3.out");

	fin >> maxLit[0] >> maxLit[1] >> maxLit[2];
	a[0] = 0;
	a[1] = 0;
	a[2] = maxLit[2];
	calc(a);
	
	for(i = 0; i <= 20; i++)
		for(j = 0; j <= 20; j++)
			for(k = 0; k <= 20; k++)
			{
				//fout1 << i << " " << j << " " << k << " " << done[i][j][k] << endl;
				if(i == 0 && done[i][j][k])
				{
					cVal[k] = true;
				}
			}

for(i = 0; i <= 20; i++)
{
	if(cVal[i])
	{
		endVal = i;
	}
}

for(i = 0; i <= 20; i++)
{
	if(cVal[i])
	{
		cout << i;
		fout << i;
		if(i < endVal)
		{
			cout << " ";
			fout << " ";
		}
	}
}
cout << endl;
fout << endl;

	return 0;
}
