
#include<cstring>
#include<iostream>
using namespace std; 

typedef struct
{    
    int weight;
    int parent,lchild,rchild;
}HTNode,*HuffmanTree;
typedef char **HuffmanCode;

void Select(HuffmanTree HT,int len,int &s1,int &s2)
{
    int i,min1=32767,min2=32767;
    for(i=1;i<=len;i++)
    {
        if(HT[i].weight<min1&&HT[i].parent==0)
        {
            s2=s1;
            min2=min1;
            min1=HT[i].weight;
            s1=i;
        }
        else if(HT[i].weight<min2&&HT[i].parent==0)
        {    min2=HT[i].weight;
            s2=i;
        }
    }
}

void CreatHuffmanTree(HuffmanTree &HT,int n)
{
    int m,s1,s2,i;
    if(n<=1) return;
    m=2*n-1;
    HT=new HTNode[m+1];
    for(i=1;i<=m;++i)              
       { HT[i].parent=0;  HT[i].lchild=0;  HT[i].rchild=0; }
    for(i=1;i<=n;++i)        
        cin >> HT[i].weight;
    for(i=n+1;i<=m;++i) 
    {      
        Select(HT,i-1,s1,s2);
        HT[s1].parent=i;     
        HT[s2].parent=i;   
        HT[i].lchild=s1;   
        HT[i].rchild=s2;                            
        HT[i].weight=HT[s1].weight+HT[s2].weight; 
    }                                            
}    

void print(HuffmanTree HT,int n)
{
    for(int i=1;i<=2*n-1;i++)
        cout << HT[i].weight << " " << HT[i].parent << " " << HT[i].lchild  << " " << HT[i].rchild << endl;
}

int main()
{
    HuffmanTree HT;
    int n;
    cin >> n;
    CreatHuffmanTree(HT,n);
    print(HT,n);
    return 0;
}
/*
	输入样例：
	  第一行输入一个数n(1<n<100)，表示叶子节点的个数，
	接下去输入n个整数(小于1000），表示每个节点表示的字符和权值   5 1 5 2 7 10
	输出样例：
      输出2*n-1行，每行输出哈夫曼节点的权值、父节点编号、左右孩子节点编号。
    1 6 0 0
    5 7 0 0
    2 6 0 0
    7 8 0 0
    10 9 0 0
    3 7 1 3
    8 8 6 2
    15 9 4 7
    25 0 5 8
*/
