#include <stdio.h>
#define N 14
int main()
{
    int i, j, n, temp;
    int a[N][N];
    int blank;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        a[i][0] = 1;
        a[i][i] = 1;
    }
    for (i = 2; i < n; i++)
    {
        for (j = 1; j < i; j++)
            a[i][j] = a[i-1][j-1] + a[i-1][j];
    }

    for (i = 0, blank = n - 1; i < n ; i++)
    {
    	for (int count = i;count != n-1;count++)
    		printf("   "); 
        for(j = 0; j <= i; j++)
            printf("%6d", a[i][j]);
        printf("\n");

    }
    
    return 0;
}
