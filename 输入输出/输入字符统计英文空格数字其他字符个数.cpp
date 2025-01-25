#include<stdio.h>
int main()
{
	int e = 0, b = 0, d = 0, o = 0;
	char c;
	while (c = getchar() != '\n')  //回车键结束输入，并且回车符不计入 
	{
		if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') e++;
		else if (c == ' ') b++;
		else if ((c >= '0') && (c <= '9')) d++;
		else o++;
	}
	printf("英文字母个数为%d，空格个数为%d，数字个数为%d，其他字符个数为%d", e, b, d, o);
	return 0;
}
