#include <stdio.h>
#include <stdlib.h>
#define bool char
#define true 1
#define false 0
#define MaxSize 1000
 
typedef int ElemType;
//定义栈的结构
typedef struct SqStack
{
    ElemType data[MaxSize];
    int top;
} SqStack;
//栈的初始化
bool InitStack(SqStack* S)
{
    S->top = -1;
    return true;
}
//栈判空
bool Empty(SqStack S)
{
    if(S.top == -1)
        return true;
    else
        return false;
}
//压栈
bool Push(SqStack* S, ElemType e)
{
    //判断栈满的情况
    if(S->top == MaxSize-1)
        return false;
    S->data[++S->top] = e;
    return true;
}
//出栈
bool Pop(SqStack* S, ElemType* e)
{
    if(S->top == -1)
        return false;
    *e = S->data[S->top--];
    return true;
}
//遍历测试用
bool Print(SqStack S)
{
    for(int i = 0; i < S.top+1; i++)
        printf("%d ",S.data[i]);
    return true;
}
int main()
{
    //定义和初始化栈
    SqStack S1, S2;
    InitStack(&S1);
    InitStack(&S2);
    int answer;
    //输入字符串
    char str[1000];
    gets(str);
    char c = str[0];
    int i = 0;
    for(i = 0; str[i] != '\0'; i++)
    {
        c = str[i];
        int x, t;
        //printf("%d ",c);
        //如果是数字，压入栈中
        if(str[i] <= '9' && str[i] >= '0')
        {
            t = 0;
            while(str[i] <= '9' && str[i] >= '0')
            {
                x = str[i]-48;
                t = t*10 + x;
                i++;
            }
            Push(&S1, t);
            i--;
        }
        //如果是空格，跳过
        else if(c == ' ')
            continue;
        //如果是运算符，进行计算操作
        else if(c == '+' || c == '-' || c == '*')
        {
            int m, p;
            Pop(&S1, &m);
            Pop(&S1, &p);
            if(c == '+')
                answer = p+m;
            else if(c == '-')
                answer = p-m;
            else if(c == '*')
                answer = p*m;
            Push(&S1, answer);
        }
 
    }
    printf("%d", answer);
    return 0;
}
