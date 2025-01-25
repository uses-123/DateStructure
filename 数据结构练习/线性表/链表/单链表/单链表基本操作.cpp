#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}Node,*LinkList;
void CreateList(LinkList &L){
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
void ListInsert(LinkList &L,int k,int num){
    Node *p,*s;
    int j=0;
    p=L;
    while(p!=NULL&&j<k){
        p=p->next;
        j++;
    }
    s=new Node;
    s->data = num;
    s->next = p->next;
    p->next = s;
}
//void ListDelete(LinkList &L,int k){  
//    Node *p;
//    if(k==0)  return;
//    int j=1;
//    p = L;
//    while(p!=NULL&&j<k){
//        p = p->next;
//        j++;
//    }
//    if (p==NULL||p->next==NULL)  return;
//    else{
//        Node *q = p->next;
//        p->data = p->next->data;
//        p->next = q->next;
//        free(q);
//    }
//}
void ListDelete(LinkList &L, int k) {
    Node *p;
    if (k <= 0) return;
    int j = 1; // 从1开始计数
    p = L;
    while (p != NULL && j < k) {
        p = p->next;
        j++;
    }
    if (p == NULL || p->next == NULL) return;
    else if (p->next->next == NULL) { // 如果 p 的下一个节点是最后一个节点
        free(p->next);
        p->next = NULL;
    } else {
        Node *q = p->next;
        p->data = p->next->data;
        p->next = q->next;
        free(q);
    }
}
void printList(LinkList L){  //打印链表 
    Node *p = L->next;
    while (p!=NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
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
int main(){
    LinkList L;
    int sum,num1,num2,num3;
    CreateList(L);
    scanf("%d",&sum);
    
    int len=ListLength(L); 
    for (int i=0;i<sum;i++){
        scanf("%d",&num1);
        if(num1 == 0){
            scanf("%d %d",&num2,&num3);
            if (num2>len)  continue;
            ListInsert(L,num2,num3);
            len=ListLength(L);
        }
        else{
            scanf("%d",&num2);
            if (num2>len)  continue;
            ListDelete(L,num2);
            len=ListLength(L);
        }
    }
    printList(L);
    return 0;
}
//void InsertList(LinkList L, int i, DT x,int len) {
//    Node *pre, *s;
//    if (i < 0||i>len-1) {
////        printf("插入位置不合理！");
//        return;
//    }
//    else{
//    	pre = L;
//        s = new Node;
//        s->data = x;
//        s->next = pre->next;
//        pre->next = s;
//    }
//    
//}

//void CreateList(LinkList &H,int len){  //头插法建表 
//	Node *s;
//	H = new Node;
//	H->next = NULL;
//	int num;
//	for (int i=1;i<=len;i++){  //InitList初始化数组 
//		scanf("%d",&num);
//		s = new Node;
//		s -> data = num;
//		s -> next = H -> next;  //两个插入 
//		H -> next = s;
//	}
//}

//void CreateList(LinkList &L,int len){  //尾差法建表 
//	Node *r,*s;
//	L = new Node;
//	L->next = NULL;
//	r = L;
//	int num;
//	for (int i=1;i<=len;i++){  //InitList初始化数组 
//		scanf("%d",&num);
//		s = new Node;
//		s -> data = num;
//		r -> next = s; 
//		r = s;
//	}
//	r->next = NULL;
//}

//int ListLength(LinkList L){  求链表长度 
//	Node *p;
//	int len;
//	p = L->next;
//	len = 0;
//	while (p!=NULL){
//		p = p->next;
//		len++;
//	}
//	return len;
//}
//void printList(LinkList L){  //打印链表(最后一个数字不带空格)
//    Node *p = L->next;
//    while (p!=NULL){
//        printf("%d",p->data);
//        if (p->next!=NULL){
//        	printf(" ");
//        }
//        p = p->next;
//    }
//    printf("\n");
//}
//Node *LocateNode(list L,int coef,int exp){  //通过数据域查找结点,返回地址 
//	Node *p = L->next;
//	while (p!=NULL && p->coef!=coef && p->exp!=exp)
//	  p=p->next;
//	return p;  //若p==NULL,则查找失败,返回NULL;否则返回为key结点的地址 
//}
//void printList(struct Node* head) {
//    struct Node* current = head;
//    while (current != NULL) {
//        printf("(%d, %d) ", current->data1, current->data2);
//        current = current->next;
//    }
//    printf("\n");
//}
