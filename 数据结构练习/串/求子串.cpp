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
//dst��Ŀ�괮(b)��src��Դ��(a)��idxΪ�±�(s)��len�ǳ���(n) 
char* StrMid(char *dst, const char *src, int idx, int len)
{
    int size = 0;
    //����Դ������ 
    while (src[size] != '\0') {
        size++;
    }

    if (idx < 0 || idx >= size) {
        dst[0] ='\0'; //Ŀ�Ĵ�Ϊ�մ�
        return dst;
    }

    if (len < 0) {  //�� len ֵ����ȷ��������Ϊ 0
        len = 0; 
    } else if (idx + len > size) {  //�� len ֵ������Χ�����Զ�����
        len = size-idx; 
    }

    for (int i = 0; i < len; i++) {  //����Ҫ���Ŀ�Ĵ�dst��ֵ 
        dst[i] = src[idx+i];
    }
    dst[len] = '\0'; //����ַ�����β��־
    return dst;
}
/*
	˵��������ȡԴ�� src �±� idx ����ʼ�� len ���ַ������浽Ŀ�Ĵ� dst �У� 
	����ֵΪ dst���� len ֵ����ȷ�����Զ��������� idx ֵ����ȷ����Ŀ�Ĵ�Ϊ�մ��� 
	abcd
    1 2
    bc
    
    abcd
    1 5
	bcd
	
    abcd
    -5 2
    
*/


