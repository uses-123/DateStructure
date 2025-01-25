#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c;
	float p,s,m;
	printf("请输入三边长:\n");
	scanf("%d%d%d",&a,&b,&c);
	switch(((a+b)>c)&&((a+c)>b)&&((b+c)>a))
	{
		case 0:printf("bu neng\n");break;
		case 1:
		{
			p=(a+b+c)/2.0;
			m=p*(p-a)*(p-b)*(p-c);
			s=sqrt(1.0*m);
			printf("三角形的面积为%.2f",s);
		}break;	
	}
    return 0;
}
