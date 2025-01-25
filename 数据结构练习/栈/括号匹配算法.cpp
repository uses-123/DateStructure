/*
	实现两种括号的匹配判断
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

LinkStack SetNullStack_Link()  //创建链栈 
{
    LinkStack top = (LinkStack)malloc(sizeof(struct Node));
    if (top != NULL) top->next = NULL;
    else printf("Alloc failure");
    return top;  
}

int IsNullStack_link(LinkStack top) //判断链栈是否为空 
{
    if (top->next == NULL)
        return 1;  //空返回1 
    else
        return 0;  //非空返回0 
}

void Push_link(LinkStack top, DataType x)  //进链栈,进栈元素为x 
{
    PNode p;
    p = (PNode)malloc(sizeof(struct Node));
    if (p == NULL)
        printf("Alloc failure");  //分配失败 
    else
    {
        p->data = x;
        p->next = top->next;
        top->next = p;
    }
}
void Pop_link(LinkStack top)  //出链栈(无返回值)
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
DataType Top_link(LinkStack top)  //求栈顶元素 
{
    if (top->next == NULL)
    {
        printf("It is empty stack!");
        return 0;
    }
    else
        return top->next->data;
}

void BracketMatch(LinkStack top)  //括号匹配算法 
{
    int flag = 1;  //定义标志变量 
    char ch, temp;
    scanf("%c", &ch);
    while (ch != '#')
    {
        switch (ch) {
        case '[':
        case '(':
            Push_link(top,ch);  //(填空)
            break;  //(填空)
        case ')':
            if (IsNullStack_link(top)==0&&Top_link(top)=='(')  //(填空)如果链栈非空,且栈顶元素为左括号 
                Pop_link(top);
            else
                flag = 0;
            break;
        case ']':
            if (IsNullStack_link(top)==0&&Top_link(top)=='[')  //(填空)如果链栈非空,且栈顶元素为左中括号
                Pop_link(top);
            else
                flag = 0;
            break;
        }//swith
        scanf("%c", &ch);
    }//while

        if (!IsNullStack_link(top))  //(填空)
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
