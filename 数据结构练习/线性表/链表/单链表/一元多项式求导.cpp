/*
	输入格式:
	以指数递降方式输入多项式非零项系数和指数（绝对值均为不超过1000的整数）
	数字间以空格分隔。
	输出格式:
	以与输入相同的格式输出导数多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。
	输入样例:3 4 -5 2 6 1 -2 0 
	输出样例:12 3 -10 1 6 0
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h> 
typedef struct Node{  //单链表(相当于两个data) 
    int coef;  //系数 
    int exp;  //指数 
    struct Node *next;  //指针 
}Node,*List;
void addList(struct Node **head) {  //用头结点创建链表 
    struct Node* current = *head;
    int num;
    int count = 0;

    while (1) {
        count++;
        scanf("%d", &num);

        if (num > 1000 || num < -1000) {
            return; // 系数和指数绝对值均为不超过1000的整数
        }

        if (count % 2 == 1) {
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->coef = num;
            newNode->next = NULL;

            if (*head == NULL) {
                *head = newNode;
                current = *head;
            } else {
                current->next = newNode;
                current = newNode;
            }
        } else {
            current->exp = num;
        }

        if (num == 0) {
            break;
        }
    }
}
bool deleteNode(struct Node **head){  //利用头结点,删除指定数据域的结点 
	struct Node *temp;
	if((*head)->coef == 0){  //考虑删除头结点的情况 
		temp = *head;
		*head = (*head)->next;
		free(temp);
		return true;
	}
	else{
		struct Node *pre = *head;
		while(pre->next!=NULL){
			if(pre->next->coef == 0){
				temp = pre->next;
				pre->next = pre->next->next;
				free(temp);
				return true;
			}
			else{
				pre = pre->next;
			}
		}
		return false;
	} 
} 
void derivation(struct Node *head){
	struct Node* current = head;
	while (current!=NULL){
		current->coef = current->coef*current->exp;
	    current->exp = current->exp-1;  
		current = current->next;
	}
}
void printList(struct Node* head) {  //测试成功 
    struct Node* current = head;
    while (current != NULL) {
        printf("%d %d", current->coef,current->exp);
        if (current->next!=NULL)
            printf(" ");
        current = current->next;
    }
    printf("\n");
}
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
int main(){
	struct Node *head = NULL;
	addList(&head);
	derivation(head);
	//此时如果系数项为0,那么删除该结点 
	if(deleteNode(&head))
	  printf("删除成功!\n");
	else
	  printf("删除失败!\n");
	free(head);
	printList(head);
	freeList(head);  // 释放链表占用的内存
}
 /*  PTA  15/15
#include<stdio.h>
#include<stdlib.h>
 
typedef struct LNode{	 
	int num;			//系数 
	int exp;			//指数 
	LNode *Next;		//next指针 
}LNode,*LinkList;
 
void Init_List(LinkList &L){		//链表初始化 
	L=(LNode *)malloc(sizeof(LNode));
	L->Next=NULL; 
}
 
LNode *Derivation(int a,int b){		//利用求导法则生成结点 
	LNode *node=(LNode *)malloc(sizeof(LNode));
	node->num=a*b;
	node->exp=b-1;
	return node;
}
 
void TailInsert(LinkList &L,LNode *node){	//尾插法 
	LNode *p=L;
	while(p->Next != NULL){		//找到最后一个结点 
		p=p->Next;
	}
	node->Next=NULL;
	p->Next=node;
}
 
void PrintList(LinkList L,int f){	//输出链表,f==0为常数多项式输出0 0 
	if(f){
		int flag=0;
		L=L->Next;
		while(L){
			if(! flag){
				printf("%d %d",L->num,L->exp);
				flag=1;
			}
	
			else
				printf(" %d %d",L->num,L->exp);	
			L=L->Next;
		}		
	}
	else{
		printf("0 0");
	}
}
 
int main(){
	LinkList L;
	LNode *N;
	int a,b,flag=0;			//flag为标志位，判断该多项式是否为常数多项式 
	
	Init_List(L);
	while(scanf("%d %d",&a,&b)!=EOF){
		if(b!=0){			//b==0为常数 不参与链表的插入 
			flag=1;			 
			N=Derivation(a,b);
			TailInsert(L,N);			
		}
	}
	PrintList(L,flag);
	return 0;
}
*/
