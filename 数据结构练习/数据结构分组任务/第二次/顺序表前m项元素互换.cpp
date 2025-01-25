#include <stdio.h>
#include<stdlib.h>
#define LISTSIZE 100
typedef int DataType;
typedef struct{
    DataType data[LISTSIZE];
    int length;
} SeqList;
int input(SeqList &L){
    int m;
    printf("������˳������:");
    scanf("%d",&m);
    printf("������˳�������:"); 
    for (int i=0;i<m;i++)
        scanf("%d",&L.data[i]);
    return m;  //��������Ԫ�ظ��� 
}
void invert(SeqList &L,int i,int j){
	int newSize = j-i+1;
	int array [newSize];
	int count = i;
	for (int m=0;m<newSize;m++){
		array[m] = L.data[i++];
	} 
	for (int n=0;n<newSize;n++){
		L.data[count+n] = array[newSize-n-1]; 
	}
}
void exchange(SeqList &L,int m){  //m�����,0~m-1���±��һ��,m~L.length-1 
	invert(L,(m-1)+1,L.length-1);
	invert(L,0,m-1);
	invert(L,0,L.length-1);
}
void printList(SeqList L){
    for (int i=0;i<L.length;i++)
        printf("%d ",L.data[i]);
}
int main(){
	SeqList L;
	int m;
	L.length = input(L);
	printf("��������Ҫ����˳����ǰ__��Ԫ��:\n");
	scanf("%d",&m);
	exchange(L,m);
	printf("�������˳���:"); 
	printList(L);
}
//void invert(SeqList L,int i,int j){
//	int newSize = j-i+1;
//	int *array = NULL;
//	if(newSize>0){
//		array = (int*)realloc(array,newSize*sizeof(int));
//		if (array==NULL)  //�����ڴ����ʧ��ʱ����� 
//		  return;
//	}
//	int count = i;
//	for (int m=0;m<newSize;m++){
//		array[m] = L.data[i++];
//	} 
//	for (int n=0;n<newSize;n++){
//		L.data[count+n] = array[newSize-n-1]; 
//	}
//}
