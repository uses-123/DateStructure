#include<stdio.h>
#define row 3
#define column 4
int main(){
	int k,array[row][column],max,flag,t,p;
	for (int i=0;i<row;i++){
		for (int j=0;j<column;j++){
			if (j!=column-1)
			  scanf("%d ",&array[i][j]);
			else
			  scanf("%d",&array[i][j]);
		}
	}
	int i,j;
	for(i=0;i<row;i++)
	{
		max=array[i][0];
		for(j=0;j<column;j++){
			if(array[i][j]>=max){
				max=array[i][j];
				t=i;
				p=j;
			}
		}
		flag=1;
		for(k=0;k<row;k++){  
			if(array[k][p]<max){
				flag=0;
			}
		}
		if(flag==1){
			printf("鞍点是%d,位于%d行%d列\n",max,t,p);
			return 0;
		}
	}
	printf("不存在鞍点\n");
	return 0;
}
