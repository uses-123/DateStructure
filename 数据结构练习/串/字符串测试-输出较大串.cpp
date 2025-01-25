#include<stdio.h>
#include<string.h>
char* Compare(char* str,char* ms){
    int len = strlen(str);
    if (len%2 == 0){
    	for (int k=0;k<len;k++){
    		if(str[k] >= str[k+len/2]){
		      for (int i=0;i<len/2;i++)
    		    ms[i] = str[i];
    		  break;
    	    }else{
    		  for (int i=0;i<len/2;i++)
    		    ms[i] = str[i+(len/2)];
    		  break;
    	    }
    	}
    		  
    }else{
    	for (int k=0;k<len;k++)	{
    		if(str[k] >= str[k+len/2]){
		      for (int i=0;i<len/2;i++)
    		    ms[i] = str[i];
    		  break;
    	    }else{
    		  for (int i=0;i<len/2+1;i++)
    		    ms[i] = str[i+(len/2)];
    		  break;
    	    }
    	}
    }
    return ms;
}
int main() {
    char str[20], majorSubstring[10];
    fgets(str, 20, stdin);  //stdin:标准输入流,通常是键盘。
    str[strlen(str) - 1] = '\0'; //去掉换行符
    Compare(str, majorSubstring);
    puts(majorSubstring);
    return 0;
}
/*
#include<stdio.h>
#include<string.h>
int main()
{
    char s[20],s1[10],s2[10];
    gets(s);
    strncpy(s1,s,strlen(s)/2);
    strcpy(s2,&s[strlen(s)/2]);
    if(strcmp(s1,s2)>0) 
        puts(s);
    else 
        puts(s2);
    return 0;
} 
*/

