#include <stdio.h>

struct date {
	int yun; //윤년이면 1, 아니라면 0을 넣어주세요.
	int year;
	int month;
	int day;
};

//1월 1일부터 month월 day일까지의 일 수를 세어줍니다. 윤년이면 yun에 1, 아니라면 0을 넣어주세요.
int dayfromtonewyear(struct date d)
{
	int count = 0, i;
	
	for(i = 1;i < d.month;i++)
	{
		if(i == 2 && d.yun == 1)
		{
			count += 29;
		}
		else if(i == 2)
		{
			count += 29;
		}
		else if((i % 2 == 1 && i < 8) || (i >= 8 && i % 2 == 0))
		{
			count += 31;
		}
		else
		{
			count += 30;
		}
		
	}
	count += d.day;
	return count;
}

