#include<stdio.h>
#include<stdlib.h>

typedef char DataType;
struct Node {
    DataType      data;
    struct Node*  next;
};
typedef struct Node  *PNode;
typedef struct Node  *LinkStack;
struct Queue
{
    PNode        f;
    PNode        r;
};
typedef struct Queue *LinkQueue;

LinkStack SetNullStack_Link()  //创建空链栈 
{
    LinkStack top = (LinkStack)malloc(sizeof(struct Node));
    if (top != NULL) 
	  top->next = NULL;
    else 
	  printf("Alloc failure");  //分配(内存)失败 
    return top;  
}

int IsNullStack_link(LinkStack top)  //判断是否空链栈 
{
    if (top->next == NULL)
        return 1;  //空栈返回1 
    else
        return 0;  //非空返回0 
}

void Push_link(LinkStack top, DataType x) //入链栈,入栈元素为x 
{
    PNode p;
    p = (PNode)malloc(sizeof(struct Node));
    if (p == NULL)
        printf("Alloc failure");  //分配(内存)失败 
    else
    {
        p->data = x;
        p->next = top->next;
        top->next = p;
    }
}
void Pop_link(LinkStack top)  //出链栈 
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
DataType Top_link(LinkStack top)  //求链栈栈顶元素 
{
    if (top->next == NULL)
    {
        printf("It is empty stack!");
        return 0;
    }
    else
        return top->next->data;
}

LinkQueue  SetNullQueue_Link()  //创建空链队 
{
    LinkQueue lqueue;  //lqueue是一个指向链队列的指针
    lqueue = (LinkQueue)malloc(sizeof(struct Queue));
    if (lqueue != NULL)
    {
        lqueue->f = NULL;  //指向的链队列包含两个指针 f 和 r
        lqueue->r = NULL;  //分别指向队列的头部和尾部
    }
    else
        printf("Alloc failure! \n");  //分配失败 
    return  lqueue;  //返回结点 
}

int IsNullQueue_link(LinkQueue lqueue)  //判断是否是空链队 
{
    return (lqueue->f == NULL); //返回结点的front是否为空 
}

void EnQueue_link(LinkQueue lqueue, DataType x)  //入链队,进队元素为x 
{
    PNode  p;
    p = (PNode)malloc(sizeof(struct Node));
    if (p == NULL)
        printf("Alloc failure!");  //分配失败 
    else {  //结点不为空 
        p->data = x;
        p->next = NULL;
        if (lqueue->f == NULL) 
        {
            lqueue->f = p;  //lqueue结点的队首指针f指向p结点 
            lqueue->r = p;  //lqueue结点的队尾指针r指向p结点 
        }
        else
        {
            lqueue->r->next = p;  //将当前队列尾部节点的 next 指针指向新节点 p
            lqueue->r = p;  //更新链队列 lqueue 的尾指针 r，使其指向新插入的节点 p
        }
    }
}
void DeQueue_link(LinkQueue lqueue)  //出链队 
{
    struct Node  * p;
    if (lqueue->f == NULL)
        printf("It is empty queue!\n ");  //空队列,因为链队的头结点为空 
    else
    {
        p = lqueue->f;
        lqueue->f = lqueue->f->next;  //更新当前链队的首部元素 
        free(p);
    }
}
DataType  FrontQueue_link(LinkQueue lqueue)  //求队首元素 
{
    if (lqueue->f == NULL)
    {
        printf("It is empty queue!\n");
        return 0;  //链队为空 
    }
    else
        return (lqueue->f->data);  //返回队首元素的值 
}

int main()
{
    DataType ch;
    int flag;
    LinkStack stack_pal = SetNullStack_Link();  //建立一个名为 stack_pal 的空链栈 
    LinkQueue queue_pal = SetNullQueue_Link();  //建立一个名为 queue_pal 的空链队 
    ch = getchar();
    while (ch != '#')
    {
        Push_link(stack_pal, ch);  //数据存入链栈 
        EnQueue_link(queue_pal, ch);  //数据存入链队 
        ch = getchar();
    }
    flag = 1;  //标志变量,假设为回文 
    while (IsNullStack_link(stack_pal)==0&&IsNullQueue_link(queue_pal)==0)
    {
        if (Top_link(stack_pal)!=FrontQueue_link(queue_pal))
        {
            flag = 0;
            break;
        }
        else 
        {
        Pop_link(stack_pal);
        DeQueue_link(queue_pal);
        }
    }
    if (flag == 1)
        printf("this is palindromic");  //是回文 
    else
        printf("this is NOT palindromic");
    return 0;
}
