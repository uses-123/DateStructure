#include <stdio.h>
#include <ctype.h>

char* StrRTrim(char *str);

int main()
{
    char a[1024];
    gets(a);
    StrRTrim(a);
    puts(a);
    return 0;
}
/*
	˵�����������ַ��� str ��β��һ�����հ��ַ�ȫ��ɾȥ(ǰ��ĺ��м�Ŀհ��ַ�����)������ֵΪ str��
    ��ʾ���հ��ַ������ո�(SP)��ˮƽ�Ʊ�(HT)����ֱ�Ʊ�(VT)���س�(CR)������(LF)����ҳ(FF)�ȡ�
	������ isspace �������жϿհ��ַ���
*/

/* ���ύ�Ĵ��뽫��Ƕ������ */
char* StrRTrim(char *str) {
	int len = 0;
    //����Դ������ 
    while (str[len] != '\0') {   //��ȡ�ַ����ĳ���
        len++;
    } 
    int tag = len - 1;        //��ʼ�� tag Ϊ�ַ���ĩβ����

    // ���ַ���ĩβ��ǰ���ң�ֱ���ҵ���һ���ǿհ��ַ�
    while (tag >= 0 && isspace(str[tag])) {
        tag--;
    }

    // �ڵ�һ���ǿհ��ַ��ĺ�������ַ��������� null
    str[tag + 1] = '\0';

    return str;
}

