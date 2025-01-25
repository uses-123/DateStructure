#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}Node,*LinkList;
void createList(LinkList &L){
    Node *s,*r;
    int len,num;
    scanf("%d",&len);
    L=(LinkList)malloc(sizeof(Node));
    L->next = NULL;
    r = L;
    for(int i=0;i<len;i++){
        s=(Node*)malloc(sizeof(Node));
        scanf("%d",&num);
        s->data = num;
        r->next = s;
        r = s;
    }
    r->next = NULL; 
}
int ListLength(LinkList L){
    Node *p;
    int len;
    p = L->next;
    len = 0;
    while(p!=NULL){
        p = p->next;
        len++;
    }
    return len;
}
void inversList (LinkList L){  //倒置链表 
	Node *p;
	int len = ListLength(L);
	int array[len];
	p=L->next;
	for (int i=0;i<len;i++){  //将链表元素存入数组array 
		array[i] = p->data;
		p=p->next;
		if (p==NULL) break;
	}
	Node *q;
	q=L->next;
	for (int j=len-1;j>=0;j--){  //更新链表的data域 
		q->data = array[j];
		q=q->next;
		if (q==NULL) break;
	} 
}
void printList(LinkList L){  //打印链表(最后一个数字不带空格)
    Node *p = L->next;
    while (p!=NULL){
        printf("%d",p->data);
        if (p->next!=NULL){
        	printf(" ");
        }
        p = p->next;
    }
    printf("\n");
}
int main(){
	LinkList L;
	createList(L);
	printf("len = %d\n",ListLength(L));
	inversList(L);
	printList(L);
	return 0;
}
