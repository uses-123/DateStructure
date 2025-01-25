#include<stdio.h>
#include <stdlib.h> 
#include <math.h>

typedef char ElemType;   //定义结点数据为字符型 
typedef int Status;       //定义函数类型为int型 
//定义结构体  
typedef struct BiTNode{
	ElemType        data;     //结点数值  
	struct BiTNode   *lchild;  //左孩子指针  
	struct BiTNode   *rchild;  //右孩子指针    
}BiTNode, *BiTree; 

void Visit(ElemType e){
	printf("%c",e);
}
//创建二叉树，如果是当前树根置为空，否则申请一个新节点
void CreatBiTree(BiTree &T) 
{   
	ElemType ch;   
	scanf("%c",&ch);    
	if(ch == '#')
		T = NULL; 
	else{      
		T= new BiTNode;  //申请一段关于该节点类型的存储空间  
		T->data=ch;               //生成根结点     
		CreatBiTree(T->lchild);   //构造左子树      
		CreatBiTree(T->rchild);   //构造右子树  
	}   
}
//0. 按中序逆序(递归)输出叶子结点
void PrintLeafInR(BiTree T){
	if (T == NULL)  return;
    PrintLeafInR(T->rchild);
    if (T->lchild == NULL && T->rchild == NULL)
        Visit(T->data);
    PrintLeafInR(T->lchild); 
}
//1. 交换二叉树的左右子树
void Change(BiTree T) {
    BiTree temp;
    // 交换左右子树
    temp = T->lchild;
    T->lchild = T->rchild;
    T->rchild = temp;
    // 递归交换左右子树
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
	PrintPreOrder(T->lchild);         //访问左子树      
	PrintPreOrder(T->rchild);         //访问右子树  
}
//2. 先序输出前k个结点
int m = 0;
void PrePrintB(BiTree T, int k){
	if (T != NULL){ 
		if(m<k)  Visit(T->data);
		m++;
		PrePrintB(T->lchild,k);
		PrePrintB(T->rchild,k);
	}
}
//3.先序逆序输出所有一度结点
void PrintOnePreR(BiTree T)  //右左根 
{
	if (T == NULL)  return;
	PrintOnePreR(T->rchild);
	PrintOnePreR(T->lchild);
    if ((T->lchild != NULL && T->rchild == NULL)||(T->lchild == NULL && T->rchild != NULL))
        Visit(T->data);
}
//返回值返回一度结点个数int CountOne(BiTree T)
int CountOne(BiTree T){
    if(!T) return 0;
    if ((!T->lchild&&T->rchild)||(T->lchild&&!T->rchild))
    return CountOne(T->lchild)+CountOne(T->rchild)+1;
    return CountOne(T->lchild)+CountOne(T->rchild);
}
/*
	输入样例: ABD##FE###CG#H##I##
*/
int main()
{
	BiTree T;
	printf("请输入二叉树结点\n");
	CreatBiTree(T);
	printf("\n----------------------------欢迎使用二叉树基本操作程序2---------------------\n");  
	printf("\n                                   菜 单 选 择                            \n\n");   
	printf("         0.中序逆序输出叶子结点               1.交换二叉树的左右子树(先序输出)\n");   
	printf("         2.先序输出前k个结点                  3.先序逆序输出所有一度结点      \n");   
	printf("         4.返回值返回一度结点个数                                             \n");
	printf("\n----------------------------------------------------------------------------\n");  
	printf("请输入您的学号后三位:");  
	int schoolDegree;
	scanf("%d",&schoolDegree);
	int mode = schoolDegree % 5;  //学号后三位对 5 取模 
	switch(mode){
		case 0:PrintLeafInR(T);exit(0);break;
	    case 1:{
	    	Change(T);
	    	PrintPreOrder(T);
	    	exit(0);break;
	    }
		case 2:{
			int k;
			printf("\n请输入需要先序输出前_个结点:");
			scanf("%d",&k); 
			PrePrintB(T,k);
			exit(0);break;
		}
		case 3:PrintOnePreR(T);break;exit(0);break;
		case 4:{
			printf("一度结点的个数为:%d",CountOne(T));
			exit(0);break;
		} 
	}
	return 0;	
}
