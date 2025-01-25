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
      //空树结点数为0
      return 0;
    else if(T->lchild!=NULL && T->rchild!=NULL)  //左右孩子均不为空
             //递归求左右子树上度为2结点个数之和,再加上自身
             return 1+Degree2Count(T->lchild)+Degree2Count(T->rchild);
    //只有一个孩子则返回求左右子树上度为2结点个数之和
    return Degree2Count(T->lchild)+Degree2Count(T->rchild);
}
/*
	输入样例: ABM##D##CX##Y## 输出样例：3 
*/
int main()
{
    BiTree T = CreateBiTree();
    printf("%d\n", Degree2Count(T));
    return 0;
}
