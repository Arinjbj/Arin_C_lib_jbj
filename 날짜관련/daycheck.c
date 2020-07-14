#include <stdio.h>

struct date {
	int yun; //윤년이면 1, 아니라면 0을 넣어주세요.
	int year;
	int month;
	int day;
};

//잘못된 day 입력을 검사합니다. return이 0이면 오류, 1이면 정상입니다.
int daycheck(struct date d)
{
	int dtf = 1;
	if(d.day < 1 || (d.yun == 1 && d.month == 2 && d.day > 29) || (d.yun == 0 && d.month == 2 && d.day > 28) || (((d.month % 2 == 1 && d.month < 8) || (d.month % 2 == 0 && d.month >= 8)) && (d.day > 31)) || (((d.month % 2 == 1 && d.month >= 8) || (d.month % 2 == 0 && d.month < 8)) && (d.day > 30)))
	{
		dtf = 0;
	}
	return dtf;
}


int main()
{
	struct date d;
	d.yun = d.year = d.day = 0;
	while(1)
	{
		scanf("%d.%d", &d.month, &d.day);
		printf("%d.%d  %d", d.month, d.day, daycheck(d));
		if(daycheck(d) == 0)
		{
			printf("잘못된 입력입니다.\n");
		}
		else
		{
			break;
		}
	}
	return 0;
}
