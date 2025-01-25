#include <stdio.h>
#define LISTSIZE 100
typedef int DataType;
typedef struct{
    DataType data[LISTSIZE];
    int length;
} SeqList;
int input(SeqList &L){
    int m;
    scanf("%d",&m);
    printf("��������������:"); 
    for (int i=0;i<m;i++)
        scanf("%d",&L.data[i]);
    return m;  //��������Ԫ�ظ��� 
}
void mergeList(SeqList LA,SeqList LB,SeqList &LC){
	int i=0,j=0,k=0;
	while (i<LA.length&&j<LB.length){
		if (LA.data[i]<=LB.data[j]){
			LC.data[k]=LA.data[i];
			i++,k++;
		}
		else{
			LC.data[k] = LB.data[j];
			j++,k++;
		}
    }
	while (i<LA.length){
			LC.data[k] = LA.data[i];
			i++;k++;
	}
	while (j<LB.length){
			LC.data[k] = LB.data[j];
			j++;k++;
	}
	LC.length = k;
	if (LC.length>LISTSIZE){
		printf("����Խ�磡");
		return; 
	}
} 
void OutPut(SeqList LC){
    for (int i=0;i<LC.length;i++)
        printf("%d ",LC.data[i]);
}
int main(){
    SeqList LA,LB,LC;
    printf("�������һ������Ԫ�ظ���:");
    LA.length = input(LA);
    printf("������ڶ�������Ԫ�ظ���:");
    LB.length = input(LB);
    mergeList (LA,LB,LC);
    OutPut(LC);
    return 0;
}
