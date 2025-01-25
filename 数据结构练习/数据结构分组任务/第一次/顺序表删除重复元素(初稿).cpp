#include <stdio.h>
#define LISTSIZE 100
#include<time.h> 
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
int DelList(SeqList &L, int i) {  //����ֵΪ�����ڵ���ѭ���ƶ����� 
    int m;
    int moveNum = 0;
    if (i<1||i>L.length){
    	printf ("ɾ��λ�ò��Ϸ�!");
    	return 0;   //��ִ��,�����ƶ�0�� 
    }
    for (m=i;m<=L.length-1;m++){
    	L.data[m-1] = L.data[m];
    	moveNum++;
    }
    L.length--;
    return moveNum-1;
} 
int DeleteData(SeqList &L){  //�����������ƶ����� 
	int moveNumber = 0;
	int complete;
	for (int i=0;i<L.length-1;i++){  //����Ƚϱ��� 
	    complete = L.data[i]; 
	    for (int k=i+1;k<=L.length-1;k++){
	    	if (complete == L.data[k]){  //���ʱִ��ɾ������  
			  moveNumber += DelList(L,k);
			  complete = L.data[k];
		    }
		    else{
			  complete = L.data[i+1];
		    }
	    }	
    }
    return moveNumber;
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
    printf("\n����Ԫ�����ƶ�����Ϊ%d\n",DeleteData(L)); 
    printf("ɾ���������Ϊ:\n"); 
    PrintList(L);
    printf("\n˳���ĳ�����%d\n",L.length);
    return 0;
}
