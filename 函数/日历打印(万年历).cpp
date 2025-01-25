#include <stdio.h>
#include <stdbool.h>

 //���������õ��ĺ���
void printMonth(int, int);
void printMonthTitle(int, int);
void printMonthBody(int, int);
int getStartDay(int, int);
int getTotalNumberOfDays(int, int);
int getNumberOfDaysInMonth(int, int);
bool isLeapYear(int);

int main() {
    int year,month;
    printf("������һ�����(����: 2001): ");
    scanf("%d",&year);
    printf("������һ���·�(1-12������): ");
    scanf("%d",&month);
	while(month>12 || month<1){
		printf("�·ݴ���,����������:");
		scanf("%d",&month);
	}
    // ����printMonth������ӡ��Ӧ��ݺ��·ݵ�����
    printMonth(year,month);
    return 0;
}
/** ��ӡ��Ӧ��ݺ��·ݵ����� */
void printMonth(int year, int month) { 
    // ��ӡ�����Ŀ�ͷ
    printMonthTitle(year, month);
    // ��ӡ��������
    printMonthBody(year, month);
}
/** ��ӡ�·ݵĿ�ͷ*/
void printMonthTitle(int year, int month) {
    // ��д�����ӡ�·ݵĿ�ͷ
    printf("\t%d��%d��\n",year,month);
    printf("----------------------------\n");
	printf("  ��  һ  ��  ��  ��  ��  ��\n");
}
/** ��ӡ�������� */
void printMonthBody(int year, int month) {
	// ����getStartDay�������ÿ�µ�һ�������ڼ�firthDayOfWeek
	int startDay = getStartDay(year,month);
	// ����getNumberOfDaysInMonth�������ĳ������days��
	int days = getNumberOfDaysInMonth(year,month);
	// �ڵ��µĵ�һ��ǰ��������ɿո�
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
    	if (days%7 == 0)  {   //28�� 
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
        else if(days%7 == 1){ //29�� 
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
        else if(days%7 == 2){ //30�� 
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
        else if(days%7 == 3){ //31�� 
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

/** ���ĳ�µ�һ�������ڼ� */
int getStartDay(int year, int month) {  //����ͨ�� 
    const int START_DAY_FOR_JAN_1_1800 = 3;
    // ��ô� 1800��1��1�� �� year��month��1��֮�������
    int totalNumber = getTotalNumberOfDays(year,month);
    // ����year��month��1�������ڼ�
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
/** ��ô� 1800��1��1�� �� year��month��1��֮������� */
int getTotalNumberOfDays(int year, int month) {  //����ͨ��
    
    // ��ô� 1800��1��1�� ��  year��month��1�� ֮�������
    int TotalDay = 0;
    for (int i=1800;i<year;i++){
    	if (isLeapYear(i) == true)
    	  TotalDay += 366;
    	else
    	  TotalDay += 365;
    }
    // ����������ݵ�1��1���������·ݵĵ�һ��֮���������
    for (int j=1;j<month;j++){
    	  TotalDay+=getNumberOfDaysInMonth(year,j);
    }
    return TotalDay; 
}
/** ���ÿ���µ����� */
int getNumberOfDaysInMonth(int year, int month) {  //����ͨ�� 
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
/** �ж��Ƿ������� */
bool isLeapYear(int year) {  //����ͨ�� 
    //����ֵ��bool�ĺ���,��Ҫ��ǰ����ӿ⺯��<stdbool.h>  
    return year%400 == 0 || year%4 == 0 && year%100 != 0; 
}
