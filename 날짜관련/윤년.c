#include <stdio.h>

struct date {
	int yun;
	int year;
	int month;
	int day;
};

/*
* 윤년은 4년마다 한 번. 하지만 100년 단위일 때는 윤년에 해당하지 않음
* 400년 단위일 따는 어떤 상황이어도 윤년으로 설정
*/
//윤년을 판별합니다. tf가 1이면 윤년, 0이면 윤년이 아닙니다.
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
