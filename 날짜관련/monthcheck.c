#include <stdio.h>

struct date {
	int yun;
	int year;
	int month;
	int day;
};

//잘못된 month 입력을 검사합니다. mtf가 1이면 정상, 0이면 오류입니다. 
int monthcheck(struct date d)
{
	int mtf = 1;
	if(d.month < 1 || d.month > 12)
	{
		mtf = 0;
	}
	return mtf;
}

int main()
{
	struct date d;
	while(1)
	{
		scanf("%d", &d.month);
		if(monthcheck(d) == 0)
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
