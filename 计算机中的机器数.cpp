#include<stdio.h>
int main(){
	unsigned short usi = 65535;  //usi: 1111 1111 1111 1111
	short si = usi;  //si: 1,111 1111 1111 1111
	printf("si = %d\n",si);  //si��ԭ��: 1,000 0000 0000 0001 (-1) 
	printf("usi = %d\n",usi);  //�޷�����usi: 65536
	
    short a = -32767;  //a(ԭ��): 1,111 1111 1111 1111 a(����): 1,000 0000 0000 0001
	unsigned short b = a;  //b: 1000 0000 0000 0001
	printf("b = %d\n",b);  //b: 1000 0000 0000 0001 (32768+1 = 32769)
	printf("a = %d\n",a);  //a: 1,111 1111 1111 1111 (-32767)
}
