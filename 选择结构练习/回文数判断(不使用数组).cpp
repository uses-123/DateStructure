#include <stdio.h>
//法一 
int main() {
    int symmetricalNum;  //对称数 
    int cmp=0,count = 1;
    int copysy;  //存储操作数 
    scanf("%d",&symmetricalNum);
    copysy = symmetricalNum;
    while(symmetricalNum/10){  //计算最大权值 
        symmetricalNum/=10;
        count*=10;
    }
    symmetricalNum = copysy;
    while(symmetricalNum/10){
        cmp += (symmetricalNum%10)*count;
        symmetricalNum/=10;
        count/=10;
        if (symmetricalNum<10)
            cmp += symmetricalNum*count;
    }
    if (cmp == copysy){
        printf("is huiwen");
    }else{
        printf("is not huiwen");
    }
    return 0;
}
/*
	法二:
	#include <stdio.h>

    int main() {
    int symmetricalNum,cmp=0,copysy;
    scanf("%d",&symmetricalNum);
    copysy = symmetricalNum;
    while(symmetricalNum) {
        cmp = cmp*10+symmetricalNum%10;
        symmetricalNum/=10;
    }
    if (cmp == copysy){
        printf("yes\n");
    }else{
        printf("no\n");
    }
    return 0;
} 
*/

