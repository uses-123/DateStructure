#include<stdio.h>
int main()
{
	int i,j,m,n;
	for (i=1;i<=99;i++)
	{
		m=i*i;
		j=i;
		if ((j<10)&&(j==(m%10)))
		printf("%d %d\n",j,m);
	    else if (j==(m%100))
	    printf("%d %d\n",j,m);
	}
        return 0;
}
