#include<stdio.h>
void fun(int *a,int *b,int *c)
{ int *temp;
  temp=a;a=b;b=temp;
  *temp=*b;*b=*c;*c=*temp; }
 int main()
{ int a,b,c,*p1,*p2,*p3;
  a=5;b=7;c=3;
  p1=&a; p2=&b; p3=&c;
  fun(p1,p2,p3);
  printf("%d,%d,%d",a,b,c);
 }
