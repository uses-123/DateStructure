#include <stdio.h>
int main()
{
	float c,f;
	printf("请输入华氏度：");
	scanf("%f",&f);
	c=5*(f-32)/9.0;
	printf("对应的摄氏温度为:%.2f\n",c);
	return 0;
}     
