#include <stdio.h>
int main(){
	void printArray (int array[],int length);
	void insertSort (int array[],int length);
	int array[]  = {12,33,34,56,77,99,25,11, 101};
//	int array[]  = {1,2,5,7,9,24,56,45,67,58};
	int i,j,temp; 
	//������ѭ������i,��ѭ������j,�ݴ����temp
	int length = sizeof(array)/sizeof(int);
	printf("�������������:"); 
	printArray(array,length);
	insertSort(array,length);
	printf("������������:");
	for (int i=0;i<length;i++)
	  printf("%d ",array[i]); 
	return 0; 
} 
void printArray(int array[],int length){
	int i;
	for (i=0;i<length;i++)
		printf("%d ",array[i]);
	printf("\n");
}
void insertSort(int array[],int n){
	int j;
	for (int i=2;i<=n;i++){
		array[0] = array[i];
		j = i-1;
		while (array[0] < array[j]){
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = array[0];
	}
}
