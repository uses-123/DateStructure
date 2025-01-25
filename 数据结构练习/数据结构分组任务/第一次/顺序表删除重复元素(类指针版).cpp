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
int removeDuplicates(SeqList &L){
	if (L.length == 0)
	  return 0;
	int p=0;
	int q=1;
	int moveCount = 0; 
	while (q<L.length){
		if (L.data[p]!=L.data[q]){  //ǰ�������������� 
			if (q-p>1){
				L.data[p+1] = L.data[q];
				moveCount++;
			}
			p++;
		} 
		q++;
	}
	L.length = moveCount+1;  //�޸�L����,moveCountֻ�������ƶ�Ԫ��,L.length = moveCount+1(��Ԫ��)
	
	return moveCount; 
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
    int number;
    printf("���������鳤��:\n"); 
    scanf("%d", &number);
    printf("����������ĸ���Ԫ��(˳������):\n"); 
    GetData(L, number);
    printf("\n����Ԫ�����ƶ�����Ϊ%d\n",removeDuplicates(L)); 
    printf("ɾ���������Ϊ:\n"); 
    PrintList(L);
    printf("\n˳���ĳ�����%d\n",L.length);
    return 0;
}
