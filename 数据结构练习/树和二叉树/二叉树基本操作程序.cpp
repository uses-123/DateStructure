#include<stdio.h>
#include <stdlib.h> 
#include <math.h>
  
typedef char ElemType;   //定义结点数据为字符型 
typedef int Status;       //定义函数类型为int型 
#define ERROR 0  
#define OK 1   

int leafNum=0;

typedef struct BiTNode{        //定义结构体  
	ElemType        data;     //结点数值  
	struct BiTNode   *lchild;  //左孩子指针  
	struct BiTNode   *rchild;  //右孩子指针    
}BiTNode, *BiTree; 

void Visit(ElemType e){
	printf("%c",e);
}
//用扩展先序遍历序列创建二叉树，如果是当前树根置为空，否则申请一个新节点
void CreatBiTree(BiTree &T) 
{   
	ElemType ch;   
	scanf("%c",&ch);    
	if(ch == '#')
		T = NULL; 
	else{      
		T= new BiTNode;  //申请一段关于该节点类型的存储空间  
		T->data=ch;                     //生成根结点     
		CreatBiTree(T->lchild);         //构造左子树      
		CreatBiTree(T->rchild);         //构造右子树  
	}   
}
//按先序次序(递归)访问二叉树
Status PreOrder(BiTree T)
{    
	if(T==NULL) 
		return ERROR;
	Visit(T->data);
	PreOrder(T->lchild);         //构造左子树      
	PreOrder(T->rchild);         //构造右子树
	return OK;  
}
//按中序次序(递归)访问二叉树
Status InOrder(BiTree T)
{  
	if (T == NULL)  return OK;
    InOrder(T->lchild);
    Visit(T->data);
    InOrder(T->rchild);
    return OK; 
}
//按后序次序(递归)访问二叉树 
Status PostOrder(BiTree T)
{  
	if (T == NULL)
        return OK;
    PostOrder(T->lchild);
    PostOrder(T->rchild);
    Visit(T->data);
    return OK;  
}
//按先序次序(递归)输出叶子结点
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
//统计叶子结点的个数
Status CountLeafNum(BiTree T)
{
	if (T == NULL)  return OK;
    if (T->lchild == NULL && T->rchild == NULL)
        leafNum++;
    CountLeafNum(T->lchild);
    CountLeafNum(T->rchild);
    return OK; 
}
//按后序次序(递归)输出度为2的结点
Status PostPrintNode(BiTree T)
{ 
	if (T == NULL)  return OK;
    PostPrintNode(T->lchild);
    PostPrintNode(T->rchild);
    if (T->lchild != NULL && T->rchild != NULL)
        Visit(T->data);
    return OK; 
}
//获取二叉树高度 
int PostTreeDepth(BiTree T)
{  
	if (T == NULL)  return 0;
    int left_depth = PostTreeDepth(T->lchild);  //左子树深度 
    int right_depth = PostTreeDepth(T->rchild);  //右子树深度 
    return (left_depth > right_depth ? left_depth : right_depth) + 1; 
}
/*
	输入样例: ABD##FE###CG#H##I##
*/
int main()
{
	BiTree T;
	int depth=0;  //二叉树的深度 
	printf("请输入二叉树结点\n");
	CreatBiTree(T);
	int mode=0;  //模式 
	printf("\n-------------------------欢迎使用二叉树基本操作程序-------------------\n");  
	printf("\n                                菜 单 选 择                         \n\n");   
	printf("      1.先序遍历二叉树                        2.中序遍历二叉树          \n");   
	printf("      3.后序遍历二叉树                        4.先序遍历输出叶子结点    \n");   
	printf("      5.输出叶子结点的个数                    6.后序遍历输出输出二度结点\n");   
	printf("      7.输出二叉树的深度                      8.退出                    \n");  
	printf("\n----------------------------------------------------------------------\n");  
	printf("请输入您的选择:");  
	
	scanf("%d",&mode);  
	while(mode<1 || mode>8){   
		printf("输入选择不明确，请重新输入:\n");   
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
		  case 8:exit(0);break;  //只有用户选择"退出"时,跳出循环 
		}
		printf("\n请输入您的选择:");
		scanf("%d",&mode);
	}
	return 0;	
}
