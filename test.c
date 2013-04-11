#include "lib.h"
#include <assert.h>

int day,month,year,pmonth,pday;

void zero_all()
{
	day=0;
	month=0;
	year=0;
	pmonth=0;
	pday=0;
}

void test_day_of_year_ilegal_day()
{
	day=33;
	month=12;
	year=1990;
	int ans = day_of_year(year,month,day);
	assert(ans==-1);
	
}

void test_day_of_year_ilegal_year()
{
	day=4;
	month=12;
	year=-1990;
	int ans = day_of_year(year,month,day);
	assert(ans==-1);
	
}

void test_day_of_year_ilegal_month()
{
	day=4;
	month=-2;
	year=1990;
	int ans = day_of_year(year,month,day);
	assert(ans==-1);
	
}

void test_day_of_year_wrong_leap_year()
{
	day=29;
	month=2;
	year=1991;
	int ans = day_of_year(year,month,day);
	assert(ans==-1);
	
}

void test_day_of_year_correct_leap_year()
{
	day=29;
	month=2;
	year=2004;
	int ans = day_of_year(year,month,day);
	assert(ans==60);
	
}

void test_day_of_year_correct_values()
{
	day=22;
	month=1;
	year=1992;
	int ans = day_of_year(year,month,day);
	assert(ans==22);
	
}

void test_month_day_ilegal_year()
{
	year = -12;
	day = 34;
	int ans = month_day(year,day,&pmonth,&pday);
	assert(ans==-1);
		
}

void test_month_day_ilegal_day()
{
	year = 1912;
	day = 377;
	int ans = month_day(year,day,&pmonth,&pday);
	assert(ans==-1);
		
}

void test_month_day_incorrect_leap_year()
{
	year =1997;
	day = 366;
	int ans = month_day(year,day,&pmonth,&pday);
	assert(ans==-1);
		
}

void test_month_day_correct_leap_year()
{
	year = 2008;
	day = 366;
	int ans = month_day(year,day,&pmonth,&pday);
	assert(ans==0);
	assert(pmonth==12 && pday==31);
		
}

void test_month_day_correct_values()
{
	year=2004;
	day=90;
	int ans = month_day(year,day,&pmonth,&pday);
	assert(ans==0);
	assert(pmonth==3 && pday==30);
}

void run_day_of_year_tests()
{
	test_day_of_year_ilegal_day();
	test_day_of_year_ilegal_year();
	test_day_of_year_ilegal_month();
	test_day_of_year_wrong_leap_year();
	test_day_of_year_correct_leap_year();
	test_day_of_year_correct_values();
		
}

void run_month_day_tests()
{
	test_month_day_correct_values();
	test_month_day_correct_leap_year();
	test_month_day_incorrect_leap_year();
	test_month_day_ilegal_day();
	test_month_day_ilegal_year();
	
}

void run_all_tests()
{
	run_month_day_tests();
	run_day_of_year_tests();
	//accepted
}
int main() {
	run_all_tests();	
}
