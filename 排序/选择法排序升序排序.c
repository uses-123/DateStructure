#include<stdio.h>
int main()
{
	void printArray (int array[],int length);
	int array[]={43,78,54,20,34,23};
	int i,j,temp,min;
	//������ѭ������i,��ѭ������j,�ݴ����temp
	int length = sizeof(array)/sizeof(int);
	printf("�������������:"); 
	printArray(array,length);
	for (i=0;i<length-1;i++){
		//����������,����length-1��ѡ�� ,ÿ���ҵ���С���� 
		min = i;
		for (j=i+1;j<length;j++){  //����������������һ����С��Ԫ�� 
			if (array[j] < array[min])
			min = j;
		}
		//��ǰ��С�����i���ǻ��� 
		if(min!=i){
			int temp = array[i];
			array[i] =  array[min];
			array[min] = temp;
		}
		printf("��%d��������:",i+1);
		printArray(array,length); 
	} 
}
void printArray(int array[],int length){
	int i;
	for (i=0;i<length;i++)
		printf("%d ",array[i]);
	printf("\n");
}
		

