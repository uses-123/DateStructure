#include<stdio.h>
#include <stdlib.h> 
#include <math.h>
  
typedef char ElemType;   //����������Ϊ�ַ��� 
typedef int Status;       //���庯������Ϊint�� 
#define ERROR 0  
#define OK 1   

int leafNum=0;

typedef struct BiTNode{        //����ṹ��  
	ElemType        data;     //�����ֵ  
	struct BiTNode   *lchild;  //����ָ��  
	struct BiTNode   *rchild;  //�Һ���ָ��    
}BiTNode, *BiTree; 

void Visit(ElemType e){
	printf("%c",e);
}
//����չ����������д���������������ǵ�ǰ������Ϊ�գ���������һ���½ڵ�
void CreatBiTree(BiTree &T) 
{   
	ElemType ch;   
	scanf("%c",&ch);    
	if(ch == '#')
		T = NULL; 
	else{      
		T= new BiTNode;  //����һ�ι��ڸýڵ����͵Ĵ洢�ռ�  
		T->data=ch;                     //���ɸ����     
		CreatBiTree(T->lchild);         //����������      
		CreatBiTree(T->rchild);         //����������  
	}   
}
//���������(�ݹ�)���ʶ�����
Status PreOrder(BiTree T)
{    
	if(T==NULL) 
		return ERROR;
	Visit(T->data);
	PreOrder(T->lchild);         //����������      
	PreOrder(T->rchild);         //����������
	return OK;  
}
//���������(�ݹ�)���ʶ�����
Status InOrder(BiTree T)
{  
	if (T == NULL)  return OK;
    InOrder(T->lchild);
    Visit(T->data);
    InOrder(T->rchild);
    return OK; 
}
//���������(�ݹ�)���ʶ����� 
Status PostOrder(BiTree T)
{  
	if (T == NULL)
        return OK;
    PostOrder(T->lchild);
    PostOrder(T->rchild);
    Visit(T->data);
    return OK;  
}
//���������(�ݹ�)���Ҷ�ӽ��
Status PrePrintLeaf(BiTree T)
{
	if (T == NULL)
        return OK;
    if (T->lchild == NULL && T->rchild == NULL)
        Visit(T->data);
    PrePrintLeaf(T->lchild);
    PrePrintLeaf(T->rchild);
    return OK; 
}
//ͳ��Ҷ�ӽ��ĸ���
Status CountLeafNum(BiTree T)
{
	if (T == NULL)  return OK;
    if (T->lchild == NULL && T->rchild == NULL)
        leafNum++;
    CountLeafNum(T->lchild);
    CountLeafNum(T->rchild);
    return OK; 
}
//���������(�ݹ�)�����Ϊ2�Ľ��
Status PostPrintNode(BiTree T)
{ 
	if (T == NULL)  return OK;
    PostPrintNode(T->lchild);
    PostPrintNode(T->rchild);
    if (T->lchild != NULL && T->rchild != NULL)
        Visit(T->data);
    return OK; 
}
//��ȡ�������߶� 
int PostTreeDepth(BiTree T)
{  
	if (T == NULL)  return 0;
    int left_depth = PostTreeDepth(T->lchild);  //��������� 
    int right_depth = PostTreeDepth(T->rchild);  //��������� 
    return (left_depth > right_depth ? left_depth : right_depth) + 1; 
}
/*
	��������: ABD##FE###CG#H##I##
*/
int main()
{
	BiTree T;
	int depth=0;  //����������� 
	printf("��������������\n");
	CreatBiTree(T);
	int mode=0;  //ģʽ 
	printf("\n-------------------------��ӭʹ�ö�����������������-------------------\n");  
	printf("\n                                �� �� ѡ ��                         \n\n");   
	printf("      1.�������������                        2.�������������          \n");   
	printf("      3.�������������                        4.����������Ҷ�ӽ��    \n");   
	printf("      5.���Ҷ�ӽ��ĸ���                    6.����������������Ƚ��\n");   
	printf("      7.��������������                      8.�˳�                    \n");  
	printf("\n----------------------------------------------------------------------\n");  
	printf("����������ѡ��:");  
	
	scanf("%d",&mode);  
	while(mode<1 || mode>8){   
		printf("����ѡ����ȷ������������:\n");   
		scanf("%d",&mode);  
	}  
	while(mode){
		switch(mode){
		  case 1:PreOrder(T);break;
		  case 2:InOrder(T);break;
		  case 3:PostOrder(T);break;
		  case 4:PrePrintLeaf(T);break;
		  case 5:CountLeafNum(T);printf("%d",leafNum);break;
		  case 6:PostPrintNode(T);break;
		  case 7:depth=PostTreeDepth(T);printf("%d",depth);break;
		  case 8:exit(0);break;  //ֻ���û�ѡ��"�˳�"ʱ,����ѭ�� 
		}
		printf("\n����������ѡ��:");
		scanf("%d",&mode);
	}
	return 0;	
}
