#include <stdio.h>
#include<math.h>
int main()
{
	int a,b,c;
	float m,n,x1,x2;
	scanf("%d%d%d",&a,&b,&c);
	m=(b*b)-(4*a*c);
	n=sqrt(1.0*m);
	x1=(m-b)/(2*a);
	x2=(-b-m)/(2*a);
	printf("x1=%.2f,x2=%.2f",x1,x2);
	return 0;
}     