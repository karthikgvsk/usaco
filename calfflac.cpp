/*
ID: karthik24
PROG: calfflac
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

char a[20000];
int index[20000];
bool palindrome(int j, int i)
{
	int k;
	for(k = j; k <= i; k++)
	{
		if(a[k] != a[i + j - k])
		{
			return false;
		}
	}
	return true;
}

bool alphabet(char ch) 
{
	if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
	{
		return true;
	} 
	else 
	{
		return false;
	}

}

int main()
{
	char a1[20000];
	ifstream fin ("calfflac.in");
	ofstream fout ("calfflac.out");
	int n1, n2, i, max, j, k1, k2, palLen, index1, index2, prevIndex, count1, count2;
	bool cont1, cont2;
	n1 = n2 = 0;
	string s;
	while(fin.good())
	{
		getline(fin, s);
		cout << a1[n1] << " " << (int) a1[n1] << endl;
		cout << s << endl;
		for(i = 0; i < s.length(); i++)
		{
			a1[n1] = s[i];
			if(alphabet(a1[n1]))
			{	
				//cout << (int) a1[n1] << " ";
				a[n2] = tolower(a1[n1]);
				index[n2] = n1;
				n2++;
			}
			n1++;
		}
		a1[n1] = '\n';
		n1++;
	}
	
	
	for(i = 0; i < n1; i++) 
	{
		cout << a1[i];
	}
	cout << endl;
	for(i = 0; i < n2; i++) 
	{
		cout << a[i];
	}
	cout << endl;
	
	max = 0;
	//largest palindrome ending with a[i]
	//brute force algo
	/*	
	bool found = false;
	for(i = 1; i < n2; i++)
	{
		for(j = 0; j < i; j++)
		{
			if(palindrome(j, i))
			{
				palLen = i - j + 1;
				break;
			}
		}
		if(max < palLen)
		{
			max = palLen;
			index1 = j;
			index2 = i;
			if(max >= 2000)
			{
				found = true;
				break;
			}
		}
		if(found)
		{
			break;
		}
	}
	*/
	//dyn prog algo
	//n2 is for formatted array, a 
	//array becoming too big for this
	/*	
	max = 0;
	bool truth[20000][20000];
	
	for(i = 0; i < 100; i++)
	{
		for(j = 0; j < 100; j++)
		{
			truth[i][j] = false;
		}
	}
	
	for(i = 0; i < n2; i++)
	{
		truth[i][i] = true;
	}
	for(i = 0; i < n2 - 1; i++)
	{
		if(a[i] == a[i+1])
		{
			truth[i][i+1] = true;
		}
	}
	//cout << "n2" << n2 << endl;
	for(i = 0; i < n2; i++)
	{
		for(j = i + 2; j < n2; j++)
		{
			for(k = i; k < j; k++)
			{
				cout << a[k];
			}
			cout << endl;
			if((a[i] == a[j]) && truth[i+1][j-1] == true)
			{
				truth[i][j] = true;
				if(max < j - i + 1)
				{
					max = j - i + 1;
					index1 = i;
					index2 = j;
				}
			}
			else
			{
				truth[i][j] = false;
			}
		}
	}
	*/
	
	//greedy approach - from hints
	for(i = 0; i < n2; i++)
	{
		
		// first loop (odd palindrome case)
		cont1 = true;
		count1 = 1;
		for(k1 = 1; k1 <= 2000; k1++)
		{
			if(i - k1 < 0 || i + k1 >= n2)
			{
				break;
			}
			if(cont1 && a[i-k1] == a[i+k1])
			{
				count1+=2;
			}
			else
			{
				cont1 = false;
				break;
			}
		}

		// second loop (even palindrome case)
		cont2 = true;
		count2 = 0;
		for(k2 = 0; k2 <= 2000; k2++)
		{
			if(i - k2 < 0 || i + k2 + 1 >= n2)
			{
				break;
			}
			if(cont2 && a[i - k2] == a[i + k2 + 1])
			{
				count2+=2;
			}
			else
			{
				cont2 = false;
				break;
			}
		}

		if(count1 > count2)
		{
			if(max < count1)
			{
				max = count1;
				index1 = i - k1 + 1;
				index2 = i + k1 - 1;
			}
		}
		else
		{
			if(max < count2)
			{
				max = count2;
				index1 = i - k2 + 1;
				index2 = i + k2;
			}
		}
	}


	
	cout << max << endl;
	fout << max << endl;
	i = 0;
	
	for(k1 = index[index1]; k1 <= index[index2]; k1++)
	{
		
		/*
		if(i == 80)
		{
			cout << endl;
			fout << endl;
			i = 0;
		}
		*/
		if(a1[k1] != '\n')
		{
			cout << a1[k1];
			fout << a1[k1];
		}
		
		else
		{
			cout << endl;
			fout << endl;
		}
		i++;
	}
	
	cout << endl;
	fout << endl;

	return 0;
}

