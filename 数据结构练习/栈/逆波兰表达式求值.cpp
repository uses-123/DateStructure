#include <stdio.h>
#include <stdlib.h>
#define bool char
#define true 1
#define false 0
#define MaxSize 1000
 
typedef int ElemType;
//����ջ�Ľṹ
typedef struct SqStack
{
    ElemType data[MaxSize];
    int top;
} SqStack;
//ջ�ĳ�ʼ��
bool InitStack(SqStack* S)
{
    S->top = -1;
    return true;
}
//ջ�п�
bool Empty(SqStack S)
{
    if(S.top == -1)
        return true;
    else
        return false;
}
//ѹջ
bool Push(SqStack* S, ElemType e)
{
    //�ж�ջ�������
    if(S->top == MaxSize-1)
        return false;
    S->data[++S->top] = e;
    return true;
}
//��ջ
bool Pop(SqStack* S, ElemType* e)
{
    if(S->top == -1)
        return false;
    *e = S->data[S->top--];
    return true;
}
//����������
bool Print(SqStack S)
{
    for(int i = 0; i < S.top+1; i++)
        printf("%d ",S.data[i]);
    return true;
}
int main()
{
    //����ͳ�ʼ��ջ
    SqStack S1, S2;
    InitStack(&S1);
    InitStack(&S2);
    int answer;
    //�����ַ���
    char str[1000];
    gets(str);
    char c = str[0];
    int i = 0;
    for(i = 0; str[i] != '\0'; i++)
    {
        c = str[i];
        int x, t;
        //printf("%d ",c);
        //��������֣�ѹ��ջ��
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
        //����ǿո�����
        else if(c == ' ')
            continue;
        //���������������м������
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
