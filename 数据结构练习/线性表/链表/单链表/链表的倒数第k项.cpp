#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}Node,*LinkList; 
int createList(LinkList &L){  //尾差法建表 
	Node *r,*s;
	L = new Node;
	L->next = NULL;
	r = L;
	int num;
	int len = 0;
	while (1){  //InitList初始化数组 
		scanf("%d",&num);
		if (num == -1||num<0) break;
		  else len++;
		s = new Node;
		s -> data = num;
		r -> next = s; 
		r = s;
	}
	r->next = NULL;
	return len;
}
//单链表找倒数第K个结点，找到返回1并输出，否则返回0
int searchElem(LinkList L,int num){
    Node *p = L->next;
    if (num>ListLength(L)||num<1){
    	 printf("NULL");
    	 return -1;
    }
    for (int i=1;i<num;i++){
        p = p->next;
    }
    return p->data;
}
int main(){
    LinkList L;
    int num;
    scanf("%d",&num);  //待查找序号k,(倒数第k个元素) 
    if (num > createList(L))  //利用createList(L)的返回值返回链表长度,同时创建链表 
       printf("NULL");
	searchElem(L,num);
}
/*
	 searchElem()的第二种方法 
*/
//void searchElem(LinkList L,int k){
//   Node *p=L->next,*q=L->next;//p先走k步，然后和9-起走，当p到尾部时，q刚好指到倒数k的位置上
//   int count=0;
//   while(p!=NULL){
//     if(count<k)
//      count++;
//     else
//   	  q=q->next;
//     p=p->next;
//   }
//     if(count<k)
//       return;
//     else{
//   	   printf("%d",q->data);
//     }
//}
