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

LinkStack SetNullStack_Link()  //��������ջ 
{
    LinkStack top = (LinkStack)malloc(sizeof(struct Node));
    if (top != NULL) 
	  top->next = NULL;
    else 
	  printf("Alloc failure");  //����(�ڴ�)ʧ�� 
    return top;  
}

int IsNullStack_link(LinkStack top)  //�ж��Ƿ����ջ 
{
    if (top->next == NULL)
        return 1;  //��ջ����1 
    else
        return 0;  //�ǿշ���0 
}

void Push_link(LinkStack top, DataType x) //����ջ,��ջԪ��Ϊx 
{
    PNode p;
    p = (PNode)malloc(sizeof(struct Node));
    if (p == NULL)
        printf("Alloc failure");  //����(�ڴ�)ʧ�� 
    else
    {
        p->data = x;
        p->next = top->next;
        top->next = p;
    }
}
void Pop_link(LinkStack top)  //����ջ 
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
DataType Top_link(LinkStack top)  //����ջջ��Ԫ�� 
{
    if (top->next == NULL)
    {
        printf("It is empty stack!");
        return 0;
    }
    else
        return top->next->data;
}

LinkQueue  SetNullQueue_Link()  //���������� 
{
    LinkQueue lqueue;  //lqueue��һ��ָ�������е�ָ��
    lqueue = (LinkQueue)malloc(sizeof(struct Queue));
    if (lqueue != NULL)
    {
        lqueue->f = NULL;  //ָ��������а�������ָ�� f �� r
        lqueue->r = NULL;  //�ֱ�ָ����е�ͷ����β��
    }
    else
        printf("Alloc failure! \n");  //����ʧ�� 
    return  lqueue;  //���ؽ�� 
}

int IsNullQueue_link(LinkQueue lqueue)  //�ж��Ƿ��ǿ����� 
{
    return (lqueue->f == NULL); //���ؽ���front�Ƿ�Ϊ�� 
}

void EnQueue_link(LinkQueue lqueue, DataType x)  //������,����Ԫ��Ϊx 
{
    PNode  p;
    p = (PNode)malloc(sizeof(struct Node));
    if (p == NULL)
        printf("Alloc failure!");  //����ʧ�� 
    else {  //��㲻Ϊ�� 
        p->data = x;
        p->next = NULL;
        if (lqueue->f == NULL) 
        {
            lqueue->f = p;  //lqueue���Ķ���ָ��fָ��p��� 
            lqueue->r = p;  //lqueue���Ķ�βָ��rָ��p��� 
        }
        else
        {
            lqueue->r->next = p;  //����ǰ����β���ڵ�� next ָ��ָ���½ڵ� p
            lqueue->r = p;  //���������� lqueue ��βָ�� r��ʹ��ָ���²���Ľڵ� p
        }
    }
}
void DeQueue_link(LinkQueue lqueue)  //������ 
{
    struct Node  * p;
    if (lqueue->f == NULL)
        printf("It is empty queue!\n ");  //�ն���,��Ϊ���ӵ�ͷ���Ϊ�� 
    else
    {
        p = lqueue->f;
        lqueue->f = lqueue->f->next;  //���µ�ǰ���ӵ��ײ�Ԫ�� 
        free(p);
    }
}
DataType  FrontQueue_link(LinkQueue lqueue)  //�����Ԫ�� 
{
    if (lqueue->f == NULL)
    {
        printf("It is empty queue!\n");
        return 0;  //����Ϊ�� 
    }
    else
        return (lqueue->f->data);  //���ض���Ԫ�ص�ֵ 
}

int main()
{
    DataType ch;
    int flag;
    LinkStack stack_pal = SetNullStack_Link();  //����һ����Ϊ stack_pal �Ŀ���ջ 
    LinkQueue queue_pal = SetNullQueue_Link();  //����һ����Ϊ queue_pal �Ŀ����� 
    ch = getchar();
    while (ch != '#')
    {
        Push_link(stack_pal, ch);  //���ݴ�����ջ 
        EnQueue_link(queue_pal, ch);  //���ݴ������� 
        ch = getchar();
    }
    flag = 1;  //��־����,����Ϊ���� 
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
        printf("this is palindromic");  //�ǻ��� 
    else
        printf("this is NOT palindromic");
    return 0;
}
