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
	说明：函数将字符串 str 结尾的一连串空白字符全部删去(前面的和中间的空白字符保留)，函数值为 str。
    提示：空白字符包括空格(SP)、水平制表(HT)、垂直制表(VT)、回车(CR)、换行(LF)、换页(FF)等。
	可利用 isspace 函数来判断空白字符。
*/

/* 你提交的代码将被嵌在这里 */
char* StrRTrim(char *str) {
	int len = 0;
    //计算源串长度 
    while (str[len] != '\0') {   //获取字符串的长度
        len++;
    } 
    int tag = len - 1;        //初始化 tag 为字符串末尾索引

    // 从字符串末尾向前查找，直到找到第一个非空白字符
    while (tag >= 0 && isspace(str[tag])) {
        tag--;
    }

    // 在第一个非空白字符的后面添加字符串结束符 null
    str[tag + 1] = '\0';

    return str;
}

