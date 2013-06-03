/*
ID: karthik24
LANG: C++
TASK: clocks
*/

#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;


//ofstream fout1 ("output.out");


int used[9], used1[9];
int m[9][5] = {{0, 1, 3, 4, -1}, {0, 1, 2, -1, -1}, {1, 2, 4, 5, -1}, 
					{0, 3, 6, -1, -1}, {1, 3, 4, 5, 7}, {2, 5, 8, -1, -1}, 
					{3, 4, 6, 7, -1}, {6, 7, 8, -1, -1}, {4, 5, 7, 8, -1}};

int minVal = pow(4, 9);

void move(int time[9], int index, int truth);

int calc(int time[9], int index)
{
	int i, j, k, val, prev;// timecopy[9];
	int minimum;

	// end criterion 1
	bool found = false;
	for(i = 0; i < 9; i++)
	{
		if(time[i] != 0)
		{
			found = true;
		}
	}
	if(!found)
	{
		return 0;
	}

	//end criterion 2
	else if(index >= 9)
	{
		return 1000000;
	}
	

	// using a copy of the time
	/*
	for(i = 0; i < 9; i++)
	{
		timecopy[i] = time[i];
	}
	*/
	

	for(i = 0; i <= 3; i++)
	{
		used[index] = i;
		
		for(j = 1; j <= i; j++)
		{
			move(time, index, true);
			//fout1 << "yes";
		}
		
		prev = 0;
		for(k = 0; k < index; k++) 
		{
			prev = prev + used[k];
		}
		val = prev + i + calc(time, index + 1);
		
		
		/*
		for(j = 0; j < 9; j++)
		{
			fout1 << used[j] << " ";
		}
		fout1 << val << endl;
		for(j = 0; j < 9; j++)
		{
			fout1 << time[j] << " ";
		}
		fout1 << endl << endl;
		*/

		if(minVal > val)
		{
			minVal = val;
			for(j = 0; j < 9; j++)
			{
				used1[j] = used[j];
			}
		}
		used[index] = 0;

		for(j = 1; j <= i; j++)
		{
			move(time, index, false);
			//fout1 << "no";
		}
	}
	
	//fout1 << endl << endl << endl;

	return minVal;
	
}

		

void move(int time[9], int index, int truth)
{
	int i;
	for(i = 0; i < 5; i++)
	{
		if(m[index][i] == -1)
		{
			break;
		}
		if(truth)
		{
			time[m[index][i]] = (time[m[index][i]] + 3) % 12;
		}
		else
		{
			time[m[index][i]] = (time[m[index][i]] - 3) % 12;
		}

	}
}

int main()
{
	
	ifstream fin ("clocks.in");
	ofstream fout ("clocks.out");

	int i, j, endIndex;
	int time[9];
	bool found;

	for(i = 0; i < 9; i++)
	{
		fin >> time[i];
		time[i] = time[i] % 12;
	}

	cout << endl;
	cout << "========" << endl;
	cout << calc(time, 0) << endl;
	cout << endl;
	
	/*
	move(time, 0, true);
	move(time, 0, true);
	move(time, 1, true);
	move(time, 1, true);
	move(time, 1, true);
	move(time, 3, true);
	move(time, 7, true);
	move(time, 7, true);
	move(time, 7, true);
	move(time, 8, true);
	*/
	
	/*
	move(time, 0, true);
	move(time, 0, true);
	move(time, 0, true);
	move(time, 1, true);
	move(time, 1, true);
	move(time, 3, true);
	move(time, 7, true);
	move(time, 7, true);
	move(time, 8, true);
	*/

	endIndex = 0;
	for(i = 0; i < 9; i++)
	{
		if(used1[i] != 0)
		{
			endIndex = i;
		}
	}

	for(i = 0; i < 9; i++)
	{
		cout << i << " " << used1[i] << endl;
		
		for(j = 1; j <= used1[i]; j++)
		{
			fout << (i + 1);
			
			if(i != endIndex || (i == endIndex && j != used1[i]))
			{
				fout << " ";
			}
		}
	}
	fout << endl;
	cout << endl;
	
	for(i = 0; i < 9; i++)
	{
		cout << time[i] << endl;
	}
	return 0;
}
