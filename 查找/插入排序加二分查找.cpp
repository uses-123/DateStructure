#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 20
int main()
{
	int a[N],i,j,k,x;
	srand(time(0));
	for(i=0;i<N;i++)
	{
		a[i]=rand()%(999-100+1)+100;
	}
	for(i=1;i<N;i++)
	{
		k=a[i];
		j=i-1;
		while ((a[j]>k)&&(j>=0))
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=k;
	}
	for(i=0;i<N;i++)
	{
		printf("%5d",a[i]);
		if ((i+1)%5==0)
		printf("\n");
	}
	scanf("%d",&x);
	int mid,low=0,high=N-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if (a[mid]==x)
		{
			printf("%d的下标为%d\n",x,mid);
			break;
		}
		else if(a[mid]>x)
			high=mid-1;
		else
			low=mid+1;
	}
	if (a[mid]!=x) printf("-1\n");
	return 0;
} 
