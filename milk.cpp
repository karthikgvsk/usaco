/*
ID: karthik24
TASK:  milk
LANG: C++
*/
// much memory and calc optimization can be done, but lazy

#include <iostream>
#include <fstream>
using namespace std;

long long t[5000], p[5000], a[5000];

void sort(long long M)
{
    long long i, j, temp;
    for(i = 0; i < M - 1; i++) {
        for(j = i + 1; j < M; j++) {
            if(p[i] > p[j]) {
                temp = t[i];
                t[i] = t[j];
                t[j] = temp;
                
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
                
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main()
{
    ifstream fin ("milk.in");
    ofstream fout ("milk.out");
    long long N, M, i, sum, price, item1, item2;
 
    fin >> N >> M;
    for(i = 0; i < M; i++)
    {
        fin >> p[i] >> a[i];
        t[i] = p[i] * a[i];
    }
    
    sort(M);
	
	for(i = 0; i < M; i++) {
		cout << p[i] << " " << a[i] << " " << t[i] << endl;
	}

    sum = 0;
	price = 0;
    for(i = 0; i < M; i++)
    {
        if(sum >= N) {
            break;
        }
		if(sum + a[i] > N) {
			//sum = N;
			price += (N - sum) * p[i];
			sum = N;
		} else {
			sum += a[i];
			price += t[i];
		}
        
    }
    
    fout << price << endl;
    cout << price << " " << sum << endl;
    
    return 0;
}
            
    
    
