#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 20
int main()
{
	int a[N],i,j,t,k;
	srand(time(0));
	for(i=0;i<N;i++)
	{
		a[i]=rand();
	}
	for(i=1;i<N;i++)
	{
		for(j=0;j<i;j++)
		if (a[j]>a[i])
		break;
	    t=a[i];
	    for(k=i-1;k>=j;k--)
	    {
	    	a[k+1]=a[k];
	    }
	    a[j]=t;
	}
	for(i=0;i<N;i++)
	{
		printf("%5d  ",a[i]);
		if ((i+1)%5==0)
		printf("\n");
	}
	return 0;
} 
