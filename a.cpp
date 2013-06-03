/*
ID: karthik24
LANG: C++
TASK: ariprog
*/

#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

// to check if val is a sum of two perfect squares
int main()
{
    int val;
    val = 48;
    if(sqrt(val) == (int)sqrt(val))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    
    return 0;
}
