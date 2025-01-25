#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

BiTree CreateBiTree(){
    char ch;
    BiTree T;
    scanf("%c",&ch);   
    if(ch=='#')  T=NULL;
    else{
        T=(BiTree)malloc(sizeof(BiTNode));
        T->data=ch;                     
        T->lchild=CreateBiTree();   
        T->rchild=CreateBiTree();   
    }
    return T;
}
int Degree2Count (BiTree T)
{
    if(T==NULL) 
      //���������Ϊ0
      return 0;
    else if(T->lchild!=NULL && T->rchild!=NULL)  //���Һ��Ӿ���Ϊ��
             //�ݹ������������϶�Ϊ2������֮��,�ټ�������
             return 1+Degree2Count(T->lchild)+Degree2Count(T->rchild);
    //ֻ��һ�������򷵻������������϶�Ϊ2������֮��
    return Degree2Count(T->lchild)+Degree2Count(T->rchild);
}
/*
	��������: ABM##D##CX##Y## ���������3 
*/
int main()
{
    BiTree T = CreateBiTree();
    printf("%d\n", Degree2Count(T));
    return 0;
}
