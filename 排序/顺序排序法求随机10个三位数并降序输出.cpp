#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int a[10],i,j,t;
	srand(time(0));
	for (i=0;i<10;i++)
	{
		a[i]=rand()%(999-100+1)+100;
	}
	printf("Before Sort:\n");
	for (i=0;i<10;i++)
		printf("%5d",a[i]);
	printf("\n");
	for (i=0;i<10-1;i++)
	     for (j=i+1;j<10;j++)
	     if (a[i]<a[j])
	     {
	     	t=a[i];
	     	a[i]=a[j];
	     	a[j]=t;
	     }
	printf("After Sort:\n");
	for (i=0;i<10;i++)
		printf("%5d",a[i]);
	printf("\n");
    return 0;
}

