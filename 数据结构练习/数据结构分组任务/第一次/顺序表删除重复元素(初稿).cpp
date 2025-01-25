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
int DelList(SeqList &L, int i) {  //返回值为数据在单次循环移动次数 
    int m;
    int moveNum = 0;
    if (i<1||i>L.length){
    	printf ("删除位置不合法!");
    	return 0;   //不执行,返回移动0次 
    }
    for (m=i;m<=L.length-1;m++){
    	L.data[m-1] = L.data[m];
    	moveNum++;
    }
    L.length--;
    return moveNum-1;
} 
int DeleteData(SeqList &L){  //返回数据总移动次数 
	int moveNumber = 0;
	int complete;
	for (int i=0;i<L.length-1;i++){  //定义比较变量 
	    complete = L.data[i]; 
	    for (int k=i+1;k<=L.length-1;k++){
	    	if (complete == L.data[k]){  //相等时执行删除操作  
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
    printf("请输入数组长度:\n"); 
    scanf("%d", &number);
    printf("请输入数组的各个元素(顺序数组):\n"); 
    GetData(L, number);
    printf("\n数组元素总移动次数为%d\n",DeleteData(L)); 
    printf("删除后的数组为:\n"); 
    PrintList(L);
    printf("\n顺序表的长度是%d\n",L.length);
    return 0;
}
