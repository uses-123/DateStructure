#include <stdio.h>
#define LISTSIZE 100
typedef int DataType;
typedef struct {
    DataType data[LISTSIZE];
    int length;
} SeqList;
void GetData(SeqList &L, int number) {
    for (int i = 0; i < number; i++) {
        scanf("%d", &L.data[i]);
    }
    L.length = number;
}
void DelList(SeqList &L, int x, int y) {
    int i, k;
    for (i = 0, k = 0; i < L.length; i++) {
        if (L.data[i] < x || L.data[i] > y) {
            L.data[k++] = L.data[i];
        }
    }
    L.length = k;
}
void PrintList(SeqList L) {
    int i;
    for (i = 0; i < L.length - 1; i++) {
        printf("%d ", L.data[i]);
    }
    printf("%d", L.data[i]);
}

int main() {
    SeqList L;
    int number, start, end;
    printf("���������鳤��:\n"); 
    scanf("%d", &number);
    printf("����������ĸ���Ԫ��:\n"); 
    GetData(L, number);
    printf("��������Ҫɾ��Ԫ�ص�����ֵ:\n"); 
    scanf("%d %d", &start, &end);
    DelList(L, start, end);
    printf("ɾ���������Ϊ:\n"); 
    PrintList(L);
    return 0;
}
