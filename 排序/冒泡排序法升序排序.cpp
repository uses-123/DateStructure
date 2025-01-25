#include <stdio.h>
int main(){
	void printArray (int array[],int length);
	int array[]  = {12,33,34,56,77,99,25,11, 101};
//	int array[]  = {1,2,5,7,9,24,56,45,67,58};
	int i,j,temp; 
	//定义外循环变量i,内循环变量j,暂存变量temp
	int length = sizeof(array)/sizeof(int);
	printf("待排序的数组是:"); 
	printArray(array,length);
	for (int i=0;i<length-1;i++){
		int flag = 0; 
		for (int j=0;j<length-i-1;j++){
			if (array[j]>array[j+1]){
				flag = 1;
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp; 
			}
		}
		//如果本轮没有交换,数据已经排好,可以提前退出循环 
		if (!flag)  break;
		
		printf("第%d轮排序结果:",i+1);
		printArray(array,length); 
	}
	return 0; 
} 
void printArray(int array[],int length){
	int i;
	for (i=0;i<length;i++)
		printf("%d ",array[i]);
	printf("\n");
}
