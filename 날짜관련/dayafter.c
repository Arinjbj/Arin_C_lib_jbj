#include <stdio.h>

struct date {
	int yun; //윤년이면 1, 아니라면 0을 넣어주세요.
	int year;
	int month;
	int day;
};

//date에 after일만큼 더합니다.  //daycheck등으로 날짜 입력이 올바른지 검사 후 사용하세요.
struct date dayafter(struct date d, int after);


int main()
{
	struct date d;
	d.yun = 0;
	int after;
	scanf("%d.%d.%d", &d.year, &d.month, &d.day);
	scanf("%d", &after);
	dayafter(d, after);
	return 0;
}


 struct date dayafter(struct date d, int after)
 {
 	d.day += after;
 	while(d.day > 28)
 	{
 		if(d.yun == 1 && d.month == 2 && d.day > 29)
 		{
 			if(d.day <= 29) {break;}
 			d.day -= 29;
 			d.month++;
 		}
 		else if(d.yun == 0 && d.month == 2 && d.day > 28)
 		{
 			d.day -= 28;
 			d.month++;
 		}
 		else if(((d.month % 2 == 1 && d.month < 8) || (d.month % 2 == 0 && d.month >= 8)) && (d.day > 31))
 		{
 			if(d.day <= 31) {break;}
 			d.day -= 31;
 			d.month++;
 		}
 		else if(((d.month % 2 == 1 && d.month >= 8) || (d.month % 2 == 0 && d.month < 8)) && (d.day > 30))
 		{
 			if(d.day <= 30) {break;}
 			d.day -= 30;
 			d.month++;
 		}
 		
 		if(d.month > 12)
 		{
 			d.year++;
 			d.month -= 12;
 			d.yun = yuncheck(d.year);
 		}
 	}
 	return d;
 }
