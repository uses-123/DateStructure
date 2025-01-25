#include<stdio.h>
int main()
{
	void printArray (int array[],int length);
	int array[]={43,78,54,20,34,23};
	int i,j,temp,min;
	//定义外循环变量i,内循环变量j,暂存变量temp
	int length = sizeof(array)/sizeof(int);
	printf("待排序的数组是:"); 
	printArray(array,length);
	for (i=0;i<length-1;i++){
		//对数组排序,进行length-1轮选择 ,每次找到最小的数 
		min = i;
		for (j=i+1;j<length;j++){  //从无序数列中挑出一个最小的元素 
			if (array[j] < array[min])
			min = j;
		}
		//当前最小数与第i个记互换 
		if(min!=i){
			int temp = array[i];
			array[i] =  array[min];
			array[min] = temp;
		}
		printf("第%d轮排序结果:",i+1);
		printArray(array,length); 
	} 
}
void printArray(int array[],int length){
	int i;
	for (i=0;i<length;i++)
		printf("%d ",array[i]);
	printf("\n");
}
		

