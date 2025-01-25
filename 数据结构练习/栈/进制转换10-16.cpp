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

SeqStack SetNullStack_Seq(int m)  //�����յ�˳��ջ 
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
        printf("out of space");  //�����ռ� 
        return NULL;
    }
}

int IsNullStack_seq(SeqStack sstack)  //�ж��Ƿ��ǿյ�˳��ջ 
{
    return(sstack->top == -1);  //����ջ��ָ��top�Ƿ�Ϊ-1 
}
void Push_seq(SeqStack sstack, int x) {  //���У�sstack��˳��ջ��x�Ǵ����Ƶ�Ԫ��
    if (sstack->top != sstack->MAX - 1) {  // �ж�ջ�Ƿ�����
        sstack->top = sstack->top + 1;  // �ȵ��� top
        sstack->elem[sstack->top] = x;  // ����Ԫ��
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
DataType Top_seq(SeqStack sstack)  //��ջ��Ԫ�� 
{
    if (IsNullStack_seq(sstack))  //�ж��Ƿ�ջ�� 
    {
        printf("it is empty");  //ջ�� 
        return 0;
    }
    else
        return sstack->elem[sstack->top];  //����ջ��Ԫ�� 
}
void Hexconversion(SeqStack sstack, int n)  //���У�sstack����Ҫ��ջ��n�Ǵ�ת����ʮ���Ƶ���
{
    int shang = n;
    int yushu;
    while(shang){
    	yushu = shang%16;
    	Push_seq(sstack,yushu);
    	shang = shang/16;  //�����̵�ֵ
    }
    while (!IsNullStack_seq(sstack)){  //ѭ����������ӡԪ��
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
    	Pop_seq(sstack);  //����ջ��Ԫ��
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
