#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c;
	float p,s,m;
	printf("���������߳�:\n");
	scanf("%d%d%d",&a,&b,&c);
	switch(((a+b)>c)&&((a+c)>b)&&((b+c)>a))
	{
		case 0:printf("bu neng\n");break;
		case 1:
		{
			p=(a+b+c)/2.0;
			m=p*(p-a)*(p-b)*(p-c);
			s=sqrt(1.0*m);
			printf("�����ε����Ϊ%.2f",s);
		}break;	
	}
    return 0;
}
