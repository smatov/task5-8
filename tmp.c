/*
 * tmp.c
 *
 *  Created on: 11.04.2013
 *      Author: dev
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <fcntl.h>


static char daytab[2][13] = { { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30,
		31 }, { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };
/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day) {
	int i, leap;
	if (year <= 0) {
		fprintf(stderr, "Year value is not legal\n");
		return -1;
	}
	if (month <= 0 || month > 12) {
		fprintf(stderr, "Month value is not legal\n");
		return -1;
	}
	if (day <= 0) {
		fprintf(stderr, "Year value is not legal\n");
		return -1;
	}

	leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	if (daytab[leap][month] < day) {
		fprintf(stderr, "There are less then %d days in month %d\n", day, month);
		return -1;
	}
	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}
/* month_day: set month, day from day of year */
int month_day(int year, int yearday, int *pmonth, int *pday) {
	int i, leap;
	if (year < 0) {
		fprintf(stderr, "Year value is not legal\n");
		return -1;
	}

	if (yearday <= 0 || yearday > 366) {
		fprintf(stderr, "Day value is not legal\n");
		return -1;
	}

	leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

	if (yearday == 366 && leap == 0) {
		fprintf(stderr,"Day value is not legal. Make sure that year is leap\n");
		return -1;
	}
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
	return 0;
}
#ifndef TEST
int main() {
	int day, month,year;
	scanf("%d %d %d", &day, &month, &year);
	int yearday = day_of_year(year,month,day);
	int checkmonth, checkday;
	month_day(year,yearday,&checkmonth, &checkday);
	printf("Day checking: %d %d\n",day,checkday);
	printf("Month checking: %d %d\n",month,checkmonth);
	return 0;
}
#endif

