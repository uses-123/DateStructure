#include <stdio.h>

char* StrMid(char *dst, const char *src, int idx, int len);

int main()
{
    char a[128], b[128];
    int s, n;
    gets(a);
    scanf("%d%d", &s, &n);
    StrMid(b, a, s, n);
    puts(b);
    return 0;
}
//dst是目标串(b)，src是源串(a)，idx为下标(s)，len是长度(n) 
char* StrMid(char *dst, const char *src, int idx, int len)
{
    int size = 0;
    //计算源串长度 
    while (src[size] != '\0') {
        size++;
    }

    if (idx < 0 || idx >= size) {
        dst[0] ='\0'; //目的串为空串
        return dst;
    }

    if (len < 0) {  //若 len 值不正确，则修正为 0
        len = 0; 
    } else if (idx + len > size) {  //若 len 值超出范围，则自动修正
        len = size-idx; 
    }

    for (int i = 0; i < len; i++) {  //根据要求给目的串dst赋值 
        dst[i] = src[idx+i];
    }
    dst[len] = '\0'; //添加字符串结尾标志
    return dst;
}
/*
	说明：函数取源串 src 下标 idx 处开始的 len 个字符，保存到目的串 dst 中， 
	函数值为 dst。若 len 值不正确，则自动修正。若 idx 值不正确，则目的串为空串。 
	abcd
    1 2
    bc
    
    abcd
    1 5
	bcd
	
    abcd
    -5 2
    
*/


