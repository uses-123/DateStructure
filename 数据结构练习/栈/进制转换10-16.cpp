#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
struct SeqStackNode
{
    int MAX;         
    int top;        
    DataType *elem; 
};
typedef struct SeqStackNode *SeqStack;

SeqStack SetNullStack_Seq(int m)  //创建空的顺序栈 
{
    SeqStack sstack = (SeqStack)malloc(sizeof(struct SeqStackNode));
    if (sstack != NULL) {
        sstack->elem = (int*)malloc(sizeof(int)*m);
        if (sstack->elem != NULL) {
            sstack->MAX = m;
            sstack->top = -1;
            return(sstack);
        }
        else {
            free(sstack);
            return NULL;
        }
    }
    else {
        printf("out of space");  //超出空间 
        return NULL;
    }
}

int IsNullStack_seq(SeqStack sstack)  //判断是否是空的顺序栈 
{
    return(sstack->top == -1);  //返回栈的指针top是否为-1 
}
void Push_seq(SeqStack sstack, int x) {  //其中，sstack是顺序栈，x是待进制的元素
    if (sstack->top != sstack->MAX - 1) {  // 判断栈是否已满
        sstack->top = sstack->top + 1;  // 先递增 top
        sstack->elem[sstack->top] = x;  // 存入元素
    }
	else {
        printf("overflow!\n");
        return;
    }
}
void Pop_seq(SeqStack sstack)
{
    if (IsNullStack_seq(sstack)) 
        printf("Underflow!\n");
    else
        sstack->top = sstack->top - 1;
}
DataType Top_seq(SeqStack sstack)  //求栈顶元素 
{
    if (IsNullStack_seq(sstack))  //判断是否栈空 
    {
        printf("it is empty");  //栈空 
        return 0;
    }
    else
        return sstack->elem[sstack->top];  //返回栈顶元素 
}
void Hexconversion(SeqStack sstack, int n)  //其中，sstack是需要的栈，n是待转换的十进制的数
{
    int shang = n;
    int yushu;
    while(shang){
    	yushu = shang%16;
    	Push_seq(sstack,yushu);
    	shang = shang/16;  //更新商的值
    }
    while (!IsNullStack_seq(sstack)){  //循环弹出并打印元素
    	int a = Top_seq(sstack);
    	switch(a){
    		case 0:printf("0");break;
    		case 1:printf("1");break;
    		case 2:printf("2");break;
    		case 3:printf("3");break;
    		case 4:printf("4");break;
    		case 5:printf("5");break;
    		case 6:printf("6");break;
    		case 7:printf("7");break;
    		case 8:printf("8");break;
    		case 9:printf("9");break;
    		case 10:printf("A");break;
    		case 11:printf("B");break;
    		case 12:printf("C");break;
    		case 13:printf("D");break;
    		case 14:printf("E");break;
    		case 15:printf("F");break;
    	}
    	Pop_seq(sstack);  //弹出栈顶元素
    }
}  
int main()
{
    SeqStack mystack = NULL;
    int n;
    mystack = SetNullStack_Seq(4);
    scanf("%d", &n);
    Hexconversion(mystack, n);
    return 0;
}
