#include <stdio.h>

struct date {
	int yun; //윤년이면 1, 아니라면 0을 넣어주세요.
	int year;
	int month;
	int day;
};

//윤년을 판별합니다. return이 1이면 윤년, 0이면 아닙니다.
int yuncheck(struct date d);


//잘못된 month 입력을 검사합니다. return이 1이면 정상, 0이면 오류입니다. 
int monthcheck(struct date d);

//잘못된 day 입력을 검사합니다. 윤년일 경우 year에 1, 아닐경우 0을 넣어주세요.
//return이 1이면 정상, 0이면 오류입니다.
int daycheck(struct date d);

//연,월,일을 입력받고 올바른지 검사합니다. 윤+m+d.c 파일의 yuncheck, monthcheck, daycheck함수와 같이 사용하세요.
struct date dateinput(void);


int main()
{
	struct date d;
	d = dateinput();
	printf("%d년 %d월 %d일\n", d.year, d.month, d.day);
	return 0;
}


int yuncheck(struct date d)
{

	int tf;
	if(d.year % 4 == 0 && d.year % 100 != 0 || d.year % 400 == 0)
	{
		tf = 1;
	}
	else
	{
		tf = 0;
	}
	return tf;
}


int monthcheck(struct date d)
{
	int mtf = 1;
	if(d.month < 1 || d.month > 12)
	{
		mtf = 0;
	}
	return mtf;
}


int daycheck(struct date d)
{
	int dtf = 1;
	if(d.day < 1 || (d.yun == 1 && d.month == 2 && d.day > 29) || (d.yun == 0 && d.month == 2 && d.day > 28) || (((d.month % 2 == 1 && d.month < 8) || (d.month % 2 == 0 && d.month >= 8)) && (d.day > 31)) || (((d.month % 2 == 1 && d.month >= 8) || (d.month % 2 == 0 && d.month < 8)) && (d.day > 30)))
	{
		dtf = 0;
	}
	return dtf;
}


struct date dateinput(void)
{
	struct date d;
	while(1)
	{
		d.yun = d.year = d.month = d.day = 0;
		printf("기준 날짜를 연.월.일 로 입력하세요. (예시 : 2019.8.25)\n입력 : ");
		scanf("%d.%d.%d", &d.year, &d.month, &d.day);
		getchar();
		if(d.month == 0 || d.day == 0)
		{
			printf("%d년\n", d.year);
			printf("잘못된 입력입니다. (자동으로 재실행이 안되면 엔터를 눌러주세요.)\n\n");
			while(getchar() != '\n'){}
			continue;
		}
		d.yun = yuncheck(d);
		if(monthcheck(d) == 0)
		{
			printf("월 입력이 잘못되었습니다.\n\n");
			continue;
		}
		if(daycheck(d) == 0)
		{
			printf("일 입력이 잘못되었습니다.\n\n");
			continue;
		}
		break;
	}
	return d;
}
