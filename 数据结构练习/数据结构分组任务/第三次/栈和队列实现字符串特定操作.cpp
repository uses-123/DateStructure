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
int pushStack(SeqStack &S,char x){  //入栈操作 
	if(S.top == STACKSIZE-1)
	  return 0;
	else{
		S.top++;
		S.data[S.top] = x;
		return 1;
	}
}
int popStack(SeqStack &S,char &x){  //出栈操作 
	if(S.top == -1)
	  return 0;
	else{
		x = S.data[S.top];
		S.top--;
		printf("%c",x);  //在函数内部输出栈顶元素
		return 1;
	}
}
int InQueue(CirQueue &Q,char x){  //入队操作 
	if ((Q.rear+1)%QUEUESIZE == Q.front){
		exit(0);
		return 0;
	}else{
		Q.data[Q.rear] = x;
	    Q.rear = (Q.rear+1)%QUEUESIZE;
	   return 1;
	}
}
int DelQueue(CirQueue &Q,char x){  //出队操作 
	if (Q.front == Q.rear){
		exit(0);
		return 0;
	}else{
		x = Q.data[Q.front];
	    Q.front = (Q.front+1)%QUEUESIZE;
	    printf("%c",x);  //在函数内部输出队首元素
	    return 1;
	}
}
int main(){
	SeqStack S;
	S.top = -1;  //初始化栈 
	CirQueue Q;
	Q.front = 0;  //初始化队列 
	Q.rear = 0;
	//创建字符数组,记录字符串 
	char ch;
	int count = 0,count1 = 0,count2 = 0;
	for (int i=0;i<N;i++){  //将输入字符分别放入队列和栈 
		ch = getchar();
		if(ch == '\n')  break;
		if (count%2 == 1) { //奇数次序从小到大排列<队列:先进先出> 
		   pushStack(S,ch);
		   count1++;
	    }
		else { //偶数次序从大到小排列<栈:后进先出> 
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
