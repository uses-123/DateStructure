#include<iostream>
using namespace std;
typedef struct BiNode{                
    char data;
    struct BiNode *lchild,*rchild;
}BiTNode,*BiTree;

void CreateBiTree(BiTree &T){    
    char ch;
    cin >> ch;
    if(ch=='#')  T=NULL;            
    else{                            
        T=new BiTNode;
        T->data=ch;                
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

int NodeCount (BiTree T){
	if(T==NULL) return 0;
    if(T->lchild==NULL&&T->rchild!=NULL)
      return 1+NodeCount(T->rchild);
    if(T->lchild!=NULL&&T->rchild==NULL)
      return 1+NodeCount(T->lchild);
     else  return 0 + NodeCount(T->lchild) + NodeCount(T->rchild);
}
/*
	输入样例: AB#DF##G##C##
	输出样例: 1
*/
int main(){
    BiTree T;
    CreateBiTree(T);
    printf("%d", NodeCount(T));
    return 0;
}
