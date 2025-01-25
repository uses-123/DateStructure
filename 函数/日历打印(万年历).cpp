#include <stdio.h>
#include <stdbool.h>

 //声明所有用到的函数
void printMonth(int, int);
void printMonthTitle(int, int);
void printMonthBody(int, int);
int getStartDay(int, int);
int getTotalNumberOfDays(int, int);
int getNumberOfDaysInMonth(int, int);
bool isLeapYear(int);

int main() {
    int year,month;
    printf("请输入一个年份(例如: 2001): ");
    scanf("%d",&year);
    printf("请输入一个月份(1-12的数字): ");
    scanf("%d",&month);
	while(month>12 || month<1){
		printf("月份错误,请重新输入:");
		scanf("%d",&month);
	}
    // 调用printMonth函数打印相应年份和月份的日历
    printMonth(year,month);
    return 0;
}
/** 打印相应年份和月份的日历 */
void printMonth(int year, int month) { 
    // 打印日历的开头
    printMonthTitle(year, month);
    // 打印日历内容
    printMonthBody(year, month);
}
/** 打印月份的开头*/
void printMonthTitle(int year, int month) {
    // 填写代码打印月份的开头
    printf("\t%d年%d月\n",year,month);
    printf("----------------------------\n");
	printf("  日  一  二  三  四  五  六\n");
}
/** 打印日历内容 */
void printMonthBody(int year, int month) {
	// 调用getStartDay函数获得每月第一天是星期几firthDayOfWeek
	int startDay = getStartDay(year,month);
	// 调用getNumberOfDaysInMonth函数获得某个月有days天
	int days = getNumberOfDaysInMonth(year,month);
	// 在当月的第一天前面加上若干空格
    switch(startDay){
    	case 7:break;
    	case 1:printf("    ");break;
    	case 2:printf("        ");break;
    	case 3:printf("            ");break;
    	case 4:printf("                ");break;
    	case 5:printf("                    ");break;
    	case 6:printf("                        ");break;
    }
    for (int i=1;i<=days;i++){
    	if (days%7 == 0)  {   //28天 
    		printf("%4d",i);
		switch(startDay){
			case 1:{
				if (i%7 == 6)
				  printf("\n");
				continue;
			}
			case 2:{
				if (i%7 == 5)
				  printf("\n");
				continue;
			}
			case 3:{
				if (i%7 == 4)
				  printf("\n");
				continue;
			}
			case 4:{
				if (i%7 == 3)
				  printf("\n");
				continue;
			}
			case 5:{
				if (i%7 == 2)
				  printf("\n");
				continue;
			}
			case 6:{
				if (i%7 == 1)
				  printf("\n");
				continue;
			}
			case 7:{
				if (i%7 == 0)
				  printf("\n");
				continue;
			}
		  }
		} 
        else if(days%7 == 1){ //29天 
        	printf("%4d",i);
        	switch(startDay){
			case 1:{
				if (i%7 == 6)
				  printf("\n");
				continue;
			}
			case 2:{
				if (i%7 == 5)
				  printf("\n");
				continue;
			}
			case 3:{
				if (i%7 == 4)
				  printf("\n");
				continue;
			}
			case 4:{
				if (i%7 == 3)
				  printf("\n");
				continue;
			}
			case 5:{
				if (i%7 == 2)
				  printf("\n");
				continue;
			}
			case 6:{
				if (i%7 == 1)
				  printf("\n");
				continue;
			}
			case 7:{
				if (i%7 == 0)
				  printf("\n");
				continue;
			}
		  }
        }
        else if(days%7 == 2){ //30天 
        	printf("%4d",i);
        	switch(startDay){
			case 1:{
				if (i%7 == 6)
				  printf("\n");
				continue;
			}
			case 2:{
				if (i%7 == 5)
				  printf("\n");
				continue;
			}
			case 3:{
				if (i%7 == 4)
				  printf("\n");
				continue;
			}
			case 4:{
				if (i%7 == 3)
				  printf("\n");
				continue;
			}
			case 5:{
				if (i%7 == 2)
				  printf("\n");
				continue;
			}
			case 6:{
				if (i%7 == 1)
				  printf("\n");
				continue;
			}
			case 7:{
				if (i%7 == 0)
				  printf("\n");
				continue;
			}
		  }
        }
        else if(days%7 == 3){ //31天 
        	printf("%4d",i);
            switch(startDay){
			  case 1:{
				if (i%7 == 6)
				  printf("\n");
				continue;
			  }
			  case 2:{
				if (i%7 == 5)
				  printf("\n");
				continue;
			  }
			  case 3:{
				if (i%7 == 4)
				  printf("\n");
				continue;
			  }
			  case 4:{
				if (i%7 == 3)
				  printf("\n");
				continue;
			  }
			  case 5:{
				if (i%7 == 2)
				  printf("\n");
				continue;
			  }
			  case 6:{
				if (i%7 == 1)
				  printf("\n");
				continue;
			  }
			  case 7:{
				if (i%7 == 0)
				  printf("\n");
				continue;
			  }
		   }
       }
   }
}

/** 获得某月第一天是星期几 */
int getStartDay(int year, int month) {  //测试通过 
    const int START_DAY_FOR_JAN_1_1800 = 3;
    // 获得从 1800年1月1日 至 year年month月1日之间的天数
    int totalNumber = getTotalNumberOfDays(year,month);
    // 返回year年month月1日是星期几
    switch (totalNumber%7){
    	case 0: return (START_DAY_FOR_JAN_1_1800)%7;break;  //3
    	case 1: return (START_DAY_FOR_JAN_1_1800+1)%7;break;  //4
		case 2: return (START_DAY_FOR_JAN_1_1800+2)%7;break;  //5
		case 3: return (START_DAY_FOR_JAN_1_1800+3)%7;break;  //6
		case 4: return (START_DAY_FOR_JAN_1_1800+4)%7+7;break;  //7
		case 5: return (START_DAY_FOR_JAN_1_1800+5)%7;break;  //1
		case 6: return (START_DAY_FOR_JAN_1_1800+6)%7;break;  //2
		default: return 0;break;
    }
}
/** 获得从 1800年1月1日 至 year年month月1日之间的天数 */
int getTotalNumberOfDays(int year, int month) {  //测试通过
    
    // 获得从 1800年1月1日 至  year年month月1日 之间的天数
    int TotalDay = 0;
    for (int i=1800;i<year;i++){
    	if (isLeapYear(i) == true)
    	  TotalDay += 366;
    	else
    	  TotalDay += 365;
    }
    // 计算输入年份的1月1日至输入月份的第一天之间的日期数
    for (int j=1;j<month;j++){
    	  TotalDay+=getNumberOfDaysInMonth(year,j);
    }
    return TotalDay; 
}
/** 获得每个月的天数 */
int getNumberOfDaysInMonth(int year, int month) {  //测试通过 
	if(isLeapYear(year)==true){
		switch (month) {
			case 1: return 31;break;
			case 2: return 29;break;
			case 3: return 31;break;
			case 4: return 30;break;
			case 5: return 31;break;
			case 6: return 30;break;
			case 7: return 31;break;
			case 8: return 31;break;
			case 9: return 30;break;
			case 10: return 31;break;
			case 11: return 30;break;
			case 12: return 31;break;
			default: return 0;break;
		}
	}
	else{
		switch (month){
			case 1: return 31;break;
			case 2: return 28;break;
			case 3: return 31;break;
			case 4: return 30;break;
			case 5: return 31;break;
			case 6: return 30;break;
			case 7: return 31;break;
			case 8: return 31;break;
			case 9: return 30;break;
			case 10: return 31;break;
			case 11: return 30;break;
			case 12: return 31;break;
			default: return 0;break;
		}
	}
}
/** 判断是否是闰年 */
bool isLeapYear(int year) {  //测试通过 
    //返回值是bool的函数,需要在前面添加库函数<stdbool.h>  
    return year%400 == 0 || year%4 == 0 && year%100 != 0; 
}
