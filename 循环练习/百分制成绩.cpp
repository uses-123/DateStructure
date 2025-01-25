/*
	方法一 
*/
#include<stdio.h>
int main()
{
	int score;
	printf("请输入一个百分制分数:\n");
	scanf("%d",&score);
    switch(score<=59)
    {
    	case 1:printf("F\n");break;
    	case 0:switch(score<70)
    	{
    		case 1:printf("E\n");break;
    		case 0:switch(score<80)
    		{
    			case 1:printf("D\n");break;
    		    case 0:switch(score<90)
    		    {
    		    	case 1:printf("C\n");break;
    		        case 0:switch(score<100)
    		        {
    		        	case 1:printf("B\n");break;
    		        	case 0:printf("A\n");break;
    		        }
    		    }
    		}
    	}
    }
    return 0;
}
/*
   方法二 
*/
//#include<stdio.h>
//int main()
//{
//	int score;
//	char ch;
//	printf("请输入一个百分制成绩:\n");
//	scanf("%d",&score);
//	if(score<=59) ch='F';
//	else if(score<70) ch='E';
//	     else if(score<80) ch='D';
//	          else if(score<90) ch='C';
//	               else if(score<100) ch='B';
//	                    else ch='A';
//	switch(ch)
//	{
//		case 'A':printf("A\n");break;
//		case 'B':printf("B\n");break;
//		case 'C':printf("C\n");break;
//		case 'D':printf("D\n");break;
//		case 'E':printf("E\n");break;
//		case 'F':printf("F\n");break;
//	}
//	return 0;
//}
