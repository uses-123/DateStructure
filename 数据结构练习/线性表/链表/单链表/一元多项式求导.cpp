/*
	�����ʽ:
	��ָ���ݽ���ʽ�������ʽ������ϵ����ָ��������ֵ��Ϊ������1000��������
	���ּ��Կո�ָ���
	�����ʽ:
	����������ͬ�ĸ�ʽ�����������ʽ�������ϵ����ָ�������ּ��Կո�ָ�������β�����ж���ո�
	��������:3 4 -5 2 6 1 -2 0 
	�������:12 3 -10 1 6 0
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h> 
typedef struct Node{  //������(�൱������data) 
    int coef;  //ϵ�� 
    int exp;  //ָ�� 
    struct Node *next;  //ָ�� 
}Node,*List;
void addList(struct Node **head) {  //��ͷ��㴴������ 
    struct Node* current = *head;
    int num;
    int count = 0;

    while (1) {
        count++;
        scanf("%d", &num);

        if (num > 1000 || num < -1000) {
            return; // ϵ����ָ������ֵ��Ϊ������1000������
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
bool deleteNode(struct Node **head){  //����ͷ���,ɾ��ָ��������Ľ�� 
	struct Node *temp;
	if((*head)->coef == 0){  //����ɾ��ͷ������� 
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
void printList(struct Node* head) {  //���Գɹ� 
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
	//��ʱ���ϵ����Ϊ0,��ôɾ���ý�� 
	if(deleteNode(&head))
	  printf("ɾ���ɹ�!\n");
	else
	  printf("ɾ��ʧ��!\n");
	free(head);
	printList(head);
	freeList(head);  // �ͷ�����ռ�õ��ڴ�
}
 /*  PTA  15/15
#include<stdio.h>
#include<stdlib.h>
 
typedef struct LNode{	 
	int num;			//ϵ�� 
	int exp;			//ָ�� 
	LNode *Next;		//nextָ�� 
}LNode,*LinkList;
 
void Init_List(LinkList &L){		//�����ʼ�� 
	L=(LNode *)malloc(sizeof(LNode));
	L->Next=NULL; 
}
 
LNode *Derivation(int a,int b){		//�����󵼷������ɽ�� 
	LNode *node=(LNode *)malloc(sizeof(LNode));
	node->num=a*b;
	node->exp=b-1;
	return node;
}
 
void TailInsert(LinkList &L,LNode *node){	//β�巨 
	LNode *p=L;
	while(p->Next != NULL){		//�ҵ����һ����� 
		p=p->Next;
	}
	node->Next=NULL;
	p->Next=node;
}
 
void PrintList(LinkList L,int f){	//�������,f==0Ϊ��������ʽ���0 0 
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
	int a,b,flag=0;			//flagΪ��־λ���жϸö���ʽ�Ƿ�Ϊ��������ʽ 
	
	Init_List(L);
	while(scanf("%d %d",&a,&b)!=EOF){
		if(b!=0){			//b==0Ϊ���� ����������Ĳ��� 
			flag=1;			 
			N=Derivation(a,b);
			TailInsert(L,N);			
		}
	}
	PrintList(L,flag);
	return 0;
}
*/
