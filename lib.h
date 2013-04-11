/*
 * lib.h
 *
 * Created on: 26.03.2013
 * Author: dev
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <fcntl.h>
#include <malloc.h>


extern int day_of_year(int year, int month, int day);

extern int month_day(int year, int yearday, int *pmonth, int *pday);


