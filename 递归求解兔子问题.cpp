/*
	递归求解兔子问题
	一般而言，兔子在出生两个月后，就有繁殖能力，一对兔子每个月能生出一对小兔子来.
	假设开始有一对刚出生的兔子且所有兔子都不死，那么一年以后可以繁殖多少对兔子？
    程序分析:利用递归的方法解题。递归分为回推和递推两个阶段。例如，要想知道第12个月兔子的对数,
	         需知道第10，11个月兔子的对数，依次类推，推到第1，2个月兔子的对数，再往回推.
    要求输入几个月的整数值，输入前有提示。
    输出相应的兔子对的数量。
    输入月数小于等于0时输出num=0;
    输入月数为1或者2时输出num=1;
	输入格式:
    12
    输出格式:
    请输入几个月整数值:12
    num=144
*/

#include <stdio.h>
int main () {
    int N, i, a = 1, b = 0, c = 0;
    printf("请输入几个月整数值:");
	scanf("%d", &N);
    if (N > 0){
    	for (i = 1; i < N-1; i++) {
        a = a+b;
        b = c;
        c = a;
        }
        printf("\nnum=%d", a+b+c);  
    }
    else{
    	printf("\nnum=0");
    }
    return 0;
}
////法二 
//#include<stdio.h>
//size_t Rabbit(int count)
//{
//	if (count == 1 || count == 2)
//	{
//		return 1;
//	}
//	return Rabbit(count - 1) + Rabbit(count - 2);
//}int main()
//{
//	int count;
//    printf("请输入几个月整数值:");
//    scanf("%d",&count);
//    if (count <= 0){
//        printf("\nnum=0");
//    }else{
//        size_t res = Rabbit(count);
//	    printf("\nnum=%d",res);
//    }
//	return 0;
//}
