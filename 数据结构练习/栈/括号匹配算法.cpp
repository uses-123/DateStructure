/*
	ʵ���������ŵ�ƥ���ж�
*/
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
struct Node {
    DataType      data;
    struct Node*  next;
};
typedef struct Node  *PNode;
typedef struct Node  *LinkStack;

LinkStack SetNullStack_Link()  //������ջ 
{
    LinkStack top = (LinkStack)malloc(sizeof(struct Node));
    if (top != NULL) top->next = NULL;
    else printf("Alloc failure");
    return top;  
}

int IsNullStack_link(LinkStack top) //�ж���ջ�Ƿ�Ϊ�� 
{
    if (top->next == NULL)
        return 1;  //�շ���1 
    else
        return 0;  //�ǿշ���0 
}

void Push_link(LinkStack top, DataType x)  //����ջ,��ջԪ��Ϊx 
{
    PNode p;
    p = (PNode)malloc(sizeof(struct Node));
    if (p == NULL)
        printf("Alloc failure");  //����ʧ�� 
    else
    {
        p->data = x;
        p->next = top->next;
        top->next = p;
    }
}
void Pop_link(LinkStack top)  //����ջ(�޷���ֵ)
{
    PNode p;
    if (top->next == NULL)
        printf("it is empty stack!");
    else
    {
        p = top->next;
        top->next = p->next;
        free(p);
    }
}
DataType Top_link(LinkStack top)  //��ջ��Ԫ�� 
{
    if (top->next == NULL)
    {
        printf("It is empty stack!");
        return 0;
    }
    else
        return top->next->data;
}

void BracketMatch(LinkStack top)  //����ƥ���㷨 
{
    int flag = 1;  //�����־���� 
    char ch, temp;
    scanf("%c", &ch);
    while (ch != '#')
    {
        switch (ch) {
        case '[':
        case '(':
            Push_link(top,ch);  //(���)
            break;  //(���)
        case ')':
            if (IsNullStack_link(top)==0&&Top_link(top)=='(')  //(���)�����ջ�ǿ�,��ջ��Ԫ��Ϊ������ 
                Pop_link(top);
            else
                flag = 0;
            break;
        case ']':
            if (IsNullStack_link(top)==0&&Top_link(top)=='[')  //(���)�����ջ�ǿ�,��ջ��Ԫ��Ϊ��������
                Pop_link(top);
            else
                flag = 0;
            break;
        }//swith
        scanf("%c", &ch);
    }//while

        if (!IsNullStack_link(top))  //(���)
            printf("no!");
        else
            printf("yes!");
}

int main()
{
    LinkStack mystack = NULL;
    mystack = SetNullStack_Link();
    BracketMatch(mystack);
    return 0;
}
