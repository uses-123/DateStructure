#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}Node,*LinkList; 
int createList(LinkList &L){  //β����� 
	Node *r,*s;
	L = new Node;
	L->next = NULL;
	r = L;
	int num;
	int len = 0;
	while (1){  //InitList��ʼ������ 
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
//�������ҵ�����K����㣬�ҵ�����1����������򷵻�0
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
    scanf("%d",&num);  //���������k,(������k��Ԫ��) 
    if (num > createList(L))  //����createList(L)�ķ���ֵ����������,ͬʱ�������� 
       printf("NULL");
	searchElem(L,num);
}
/*
	 searchElem()�ĵڶ��ַ��� 
*/
//void searchElem(LinkList L,int k){
//   Node *p=L->next,*q=L->next;//p����k����Ȼ���9-���ߣ���p��β��ʱ��q�պ�ָ������k��λ����
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
