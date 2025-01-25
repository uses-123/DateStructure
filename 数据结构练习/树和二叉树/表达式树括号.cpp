//ÓÃÏßË÷¶þ²æÊ÷Ð´ 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct TNode* Position;
typedef Position BinTree;
struct TNode {
    char Data;
    BinTree Left;
    BinTree Right;
};
BinTree CreatBinTree(BinTree BT) {
    char val;
    scanf("%c", &val);
    if (val == '#') {
        BT = NULL;
        return BT;
    }
    BT = (BinTree)malloc(sizeof(struct TNode));
    BT->Left = BT->Right = NULL;
    BT->Data = val;
    BT->Left = CreatBinTree(BT->Left);
    BT->Right = CreatBinTree(BT->Right);
    return BT;
}
void Add_RightBracket(BinTree* BT) {
    if (!*BT) {
        *BT = (BinTree)malloc(sizeof(struct TNode));
        (*BT)->Left = (*BT)->Right = NULL;
        (*BT)->Data = ')';
        return;
    }
    Add_RightBracket(&(*BT)->Right);
}
void Add_LeftBracket(BinTree* BT) {
    if (!*BT) {
        *BT = (BinTree)malloc(sizeof(struct TNode));
        (*BT)->Left = (*BT)->Right = NULL;
        (*BT)->Data = '(';
        return;
    }
    Add_LeftBracket(&(*BT)->Left);
}
void PreorderTraversal(BinTree* BT) {
    if (!(*BT))return;
    if ((*BT)->Data == '*' || (*BT)->Data == '/') {
        if ((*BT)->Left->Data == '-' || (*BT)->Left->Data == '+') {
            Add_LeftBracket(&(*BT)->Left);
            Add_RightBracket(&(*BT)->Left);
        }
        if ((*BT)->Right->Data == '-' || (*BT)->Right->Data == '+'||
            (*BT)->Right->Data == '*'||(*BT)->Right->Data == '/') {
            Add_LeftBracket(&(*BT)->Right);
            Add_RightBracket(&(*BT)->Right);
        }
    }
    else if ((*BT)->Data == '+' || (*BT)->Data == '-') {
        if ((*BT)->Right->Data == '+' || (*BT)->Right->Data == '-') {
            Add_LeftBracket(&(*BT)->Right);
            Add_RightBracket(&(*BT)->Right);
        }
    }
 
    PreorderTraversal(&(*BT)->Left);
    PreorderTraversal(&(*BT)->Right);
}
void InorderTraversal(BinTree BT)
{
    if (BT) {
        InorderTraversal(BT->Left);
        printf("%c", BT->Data);
        InorderTraversal(BT->Right);
    }
}
int main()
{
    BinTree BT = NULL;
    BT = CreatBinTree(BT);
    PreorderTraversal(&BT);
    InorderTraversal(BT);
    system("pause");
    return 0;
}
