#include<stdio.h>
#include <stdlib.h> 
#include <math.h>

typedef char ElemType;   //����������Ϊ�ַ��� 
typedef int Status;       //���庯������Ϊint�� 
//����ṹ��  
typedef struct BiTNode{
	ElemType        data;     //�����ֵ  
	struct BiTNode   *lchild;  //����ָ��  
	struct BiTNode   *rchild;  //�Һ���ָ��    
}BiTNode, *BiTree; 

void Visit(ElemType e){
	printf("%c",e);
}
//����������������ǵ�ǰ������Ϊ�գ���������һ���½ڵ�
void CreatBiTree(BiTree &T) 
{   
	ElemType ch;   
	scanf("%c",&ch);    
	if(ch == '#')
		T = NULL; 
	else{      
		T= new BiTNode;  //����һ�ι��ڸýڵ����͵Ĵ洢�ռ�  
		T->data=ch;               //���ɸ����     
		CreatBiTree(T->lchild);   //����������      
		CreatBiTree(T->rchild);   //����������  
	}   
}
//0. ����������(�ݹ�)���Ҷ�ӽ��
void PrintLeafInR(BiTree T){
	if (T == NULL)  return;
    PrintLeafInR(T->rchild);
    if (T->lchild == NULL && T->rchild == NULL)
        Visit(T->data);
    PrintLeafInR(T->lchild); 
}
//1. ��������������������
void Change(BiTree T) {
    BiTree temp;
    // ������������
    temp = T->lchild;
    T->lchild = T->rchild;
    T->rchild = temp;
    // �ݹ齻����������
    if (T->lchild != NULL){
        Change(T->lchild);
    }
    if (T->rchild != NULL){
        Change(T->rchild);
    }
}
void PrintPreOrder(BiTree T)
{    
	if(T==NULL)  return;
	Visit(T->data);
	PrintPreOrder(T->lchild);         //����������      
	PrintPreOrder(T->rchild);         //����������  
}
//2. �������ǰk�����
int m = 0;
void PrePrintB(BiTree T, int k){
	if (T != NULL){ 
		if(m<k)  Visit(T->data);
		m++;
		PrePrintB(T->lchild,k);
		PrePrintB(T->rchild,k);
	}
}
//3.���������������һ�Ƚ��
void PrintOnePreR(BiTree T)  //����� 
{
	if (T == NULL)  return;
	PrintOnePreR(T->rchild);
	PrintOnePreR(T->lchild);
    if ((T->lchild != NULL && T->rchild == NULL)||(T->lchild == NULL && T->rchild != NULL))
        Visit(T->data);
}
//����ֵ����һ�Ƚ�����int CountOne(BiTree T)
int CountOne(BiTree T){
    if(!T) return 0;
    if ((!T->lchild&&T->rchild)||(T->lchild&&!T->rchild))
    return CountOne(T->lchild)+CountOne(T->rchild)+1;
    return CountOne(T->lchild)+CountOne(T->rchild);
}
/*
	��������: ABD##FE###CG#H##I##
*/
int main()
{
	BiTree T;
	printf("��������������\n");
	CreatBiTree(T);
	printf("\n----------------------------��ӭʹ�ö�����������������2---------------------\n");  
	printf("\n                                   �� �� ѡ ��                            \n\n");   
	printf("         0.�����������Ҷ�ӽ��               1.��������������������(�������)\n");   
	printf("         2.�������ǰk�����                  3.���������������һ�Ƚ��      \n");   
	printf("         4.����ֵ����һ�Ƚ�����                                             \n");
	printf("\n----------------------------------------------------------------------------\n");  
	printf("����������ѧ�ź���λ:");  
	int schoolDegree;
	scanf("%d",&schoolDegree);
	int mode = schoolDegree % 5;  //ѧ�ź���λ�� 5 ȡģ 
	switch(mode){
		case 0:PrintLeafInR(T);exit(0);break;
	    case 1:{
	    	Change(T);
	    	PrintPreOrder(T);
	    	exit(0);break;
	    }
		case 2:{
			int k;
			printf("\n��������Ҫ�������ǰ_�����:");
			scanf("%d",&k); 
			PrePrintB(T,k);
			exit(0);break;
		}
		case 3:PrintOnePreR(T);break;exit(0);break;
		case 4:{
			printf("һ�Ƚ��ĸ���Ϊ:%d",CountOne(T));
			exit(0);break;
		} 
	}
	return 0;	
}
