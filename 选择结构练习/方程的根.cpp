#include<stdio.h>
#include<math.h>
int main()
{
	float a,b,c,m,n,x1,x2;
	scanf("%f%f%f",&a,&b,&c);
	m=(b*b)-(4*a*c);
	if(m<0) printf("�����޸�\n");
	else if(m==0) 
    {x1=x2=(-b)/(2.0*a);
    printf("���̵ĸ�Ϊ%.2f\n",x1);}
	     else {n=sqrt(1.0*m);
	     x1=(n-b)/(2.0*a);
	     x2=(-b-n)/(2.0*a);
	     printf("���̵ĸ�Ϊx1=%.2f,x2=%.2f\n",x1,x2); }
    return 0;
} 
