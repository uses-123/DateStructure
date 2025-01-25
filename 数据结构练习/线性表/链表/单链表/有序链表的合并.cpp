#include <stdio.h>
#include <stdlib.h>
typedef int DT;
typedef struct Node{
    DT data;
    struct Node *next;
}Node,*LinkList;
int isEmpty(LinkList L){
    return L->next == NULL;
}
void MergeList(LinkList LA,LinkList LB,LinkList &LC){
    Node *pa,*pb,*pc;
    pa=LA->next;
    pb=LB->next;
    LC=LA;
    pc=LC;
    while (pa!=NULL&&pb!=NULL){
        if(pa->data<=pb->data){
            pc->next=pa;
            pc=pa;
            pa=pa->next;
        }else{
            pc->next=pb;
            pc=pb;
            pb=pb->next;
        }
    }
    if(pa)
        pc->next=pa;
    else
        pc->next=pb;
}
void CreateList(LinkList &L){  //尾插法
    Node *s,*r;
    L = (LinkList)malloc(sizeof(Node));
    L->next=NULL;
    r=L;
    int num;
    int i;
    while (1){  //死循环,有break时跳出循环
        scanf("%d",&num);
        if (num == -1) break;
        s=(Node*)malloc(sizeof(Node));
        s->data = num;
        r->next = s;
        r = s;
    }
    r->next = NULL;
    //int length = i+1;
}
void printList(LinkList L){
    Node *p = L->next;
    while(p!=NULL){
        printf("%d",p->data);
        if (p->next!=NULL)
            printf(" ");
        p=p->next;
    }
    printf("\n");
}
int main(){
    LinkList LA,LB,LC;
    CreateList(LA);
    CreateList(LB);
    MergeList(LA,LB,LC);
    if (isEmpty(LC))
        printf("NULL");
    else
        printList(LC);
    return 0;
}
