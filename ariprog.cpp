/*
 ID: karthik24
 PROG: ariprog
 LANG: C++
 */
 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
 
using namespace std;
 
int main(int argc, char **argv) {
    int  i, j, n, m, sols = 0;
    bool bi[125001] = { 0 };
    memset(bi, 0, sizeof bi);
 
    freopen("ariprog.in", "r", stdin);
    freopen("ariprog.out", "w", stdout);
    scanf("%d %d", &n, &m);
 
    for (i = 0; i <= m; i++)
        for (j = i; j <= m; j++)
            bi[i * i + j * j] = true;
 
    for (int b = 1; b <= m * m; b++)
        for (int a = 0; a <= (2 * m * m - b * (n - 1)); a++) {
            for (i = 0; i < n && bi[a + i * b]; i++)
                ;
            if (i == n && ++sols)
                printf("%d %d\n", a, b);
        }
 
    if (!sols)
        puts("NONE");
 
    return 0;
}

