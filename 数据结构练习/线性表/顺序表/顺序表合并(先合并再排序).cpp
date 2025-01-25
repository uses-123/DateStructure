#include <stdio.h>
#define LISTSIZE 100
typedef int DataType;
typedef struct {
    DataType data[LISTSIZE];
    int length;
} SeqList;
void input(SeqList &LA, SeqList &LB) {
	int m, n;
	printf("�������һ������Ԫ�ظ���:"); 
	scanf("%d", &m);
	printf("��������������:"); 
	for (int i = 0; i < m; i++)
	    scanf("%d", &LA.data[i]);
	LA.length = m;
	printf("������ڶ�������Ԫ�ظ���:");
	scanf("%d", &n);
	printf("��������������:"); 
	for (int j = 0; j < n; j++)
	    scanf("%d", &LB.data[j]);
	LB.length = n;
}
void UniteList(SeqList LA,SeqList LB,SeqList &LC){
	for (int i=0;i<LA.length;i++)
	  LC.data[i] = LA.data[i];
	for (int j = 0; j < LB.length; j++)
      LC.data[LA.length + j] = LB.data[j];
	LC.length = LA.length+LB.length;
}
void ListSort(SeqList &LC) {
	for (int i = 0; i < LC.length - 1; i++) {
        for (int j = 0; j < LC.length - i - 1; j++) {
            if (LC.data[j] > LC.data[j + 1]) {
                int temp = LC.data[j];
                LC.data[j] = LC.data[j + 1];
                LC.data[j + 1] = temp;
            }
        }
    }
}
void OutPut(SeqList LC) {
    for (int i = 0; i < LC.length-1; i++) {
        printf("%d ", LC.data[i]);
    }
//    �������д���,ͬʱ forѭ����Ҫ�ĳ� i< LC.length
//    if (i != LC.length - 1)
//            printf(" ");
//    }
    printf("%d", LC.data[LC.length-1]);
}
int main() {
    SeqList LA;
    SeqList LB;
    SeqList LC;
    input(LA, LB);
    UniteList(LA,LB,LC);
    ListSort(LC);
    OutPut(LC);
    return 0;
}
