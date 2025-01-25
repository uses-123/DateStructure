#include<stdio.h>
#include<stdlib.h>
#define STACKSIZE 10
#define QUEUESIZE 10
#define N 15
typedef struct{
	char data[STACKSIZE];
	int top;
}SeqStack;
typedef struct{
	char data[QUEUESIZE];
	int front;
	int rear;
}CirQueue;
int pushStack(SeqStack &S,char x){  //��ջ���� 
	if(S.top == STACKSIZE-1)
	  return 0;
	else{
		S.top++;
		S.data[S.top] = x;
		return 1;
	}
}
int popStack(SeqStack &S,char &x){  //��ջ���� 
	if(S.top == -1)
	  return 0;
	else{
		x = S.data[S.top];
		S.top--;
		printf("%c",x);  //�ں����ڲ����ջ��Ԫ��
		return 1;
	}
}
int InQueue(CirQueue &Q,char x){  //��Ӳ��� 
	if ((Q.rear+1)%QUEUESIZE == Q.front){
		exit(0);
		return 0;
	}else{
		Q.data[Q.rear] = x;
	    Q.rear = (Q.rear+1)%QUEUESIZE;
	   return 1;
	}
}
int DelQueue(CirQueue &Q,char x){  //���Ӳ��� 
	if (Q.front == Q.rear){
		exit(0);
		return 0;
	}else{
		x = Q.data[Q.front];
	    Q.front = (Q.front+1)%QUEUESIZE;
	    printf("%c",x);  //�ں����ڲ��������Ԫ��
	    return 1;
	}
}
int main(){
	SeqStack S;
	S.top = -1;  //��ʼ��ջ 
	CirQueue Q;
	Q.front = 0;  //��ʼ������ 
	Q.rear = 0;
	//�����ַ�����,��¼�ַ��� 
	char ch;
	int count = 0,count1 = 0,count2 = 0;
	for (int i=0;i<N;i++){  //�������ַ��ֱ������к�ջ 
		ch = getchar();
		if(ch == '\n')  break;
		if (count%2 == 1) { //���������С��������<����:�Ƚ��ȳ�> 
		   pushStack(S,ch);
		   count1++;
	    }
		else { //ż������Ӵ�С����<ջ:����ȳ�> 
		   InQueue(Q,ch);
		   count2++;
	    }
	    count++;
	}
	char x;
	for (int i=0;i<count1;i++){
		DelQueue(Q,x);
	}
	for (int i=0;i<count2;i++){
		popStack(S,x);
	}
	return 0;	
}
