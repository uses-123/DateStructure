#include<stdio.h>
int main()
{
	int e = 0, b = 0, d = 0, o = 0;
	char c;
	while (c = getchar() != '\n')  //�س����������룬���һس��������� 
	{
		if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') e++;
		else if (c == ' ') b++;
		else if ((c >= '0') && (c <= '9')) d++;
		else o++;
	}
	printf("Ӣ����ĸ����Ϊ%d���ո����Ϊ%d�����ָ���Ϊ%d�������ַ�����Ϊ%d", e, b, d, o);
	return 0;
}
