#include<stdio.h>
int fun(int x){
	int y;
	if (x>1)
	 y = fun(x-1)+2;
	else
	 y=2;
	 return y;
	 
}
m ain(){
	printf("%d\n",fun(3));
} 
