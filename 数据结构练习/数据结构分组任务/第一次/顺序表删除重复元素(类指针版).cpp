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
		if (L.data[p]!=L.data[q]){  //前后不相等则进行排序 
			if (q-p>1){
				L.data[p+1] = L.data[q];
				moveCount++;
			}
			p++;
		} 
		q++;
	}
	L.length = moveCount+1;  //修改L长度,moveCount只计算了移动元素,L.length = moveCount+1(首元素)
	
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
    printf("请输入数组长度:\n"); 
    scanf("%d", &number);
    printf("请输入数组的各个元素(顺序数组):\n"); 
    GetData(L, number);
    printf("\n数组元素总移动次数为%d\n",removeDuplicates(L)); 
    printf("删除后的数组为:\n"); 
    PrintList(L);
    printf("\n顺序表的长度是%d\n",L.length);
    return 0;
}
