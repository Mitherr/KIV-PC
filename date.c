/*
    DFS

    Module date.c
    This module contains a set of functions that assueres a maintance of dates used in a programme.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "date.h"


/* ____________________________________________________________________________

   date *create_date(int year,int month,int day)
    
    Creates a new struct date that containst 3 integers:
    -year
    -month
    -day
    passed by arguments year,month,day
    returns:
    struct date if succeed
    NULL if fails
   ____________________________________________________________________________
*/

date *create_date(int year,int month,int day){
	date *temp = NULL;
	
	temp = (date *) malloc(sizeof(date));
	if(temp == NULL){
		printf("Out of memory (date)\n");
		return NULL;
	}
	
	temp->year = year;
	temp->month = month;
	temp->day = day;
	
	return temp;
}

/* ____________________________________________________________________________

   date *create_date_from_str(char *date_s)
    
    Creates a new struct date from char pointer passed by an arguments date_s
	argument should be in format("yyyy-mm-dd").

    returns:
    struct date if succeed
    NULL if fails
   ____________________________________________________________________________
*/

date *create_date_from_str(char *date_s){
	date *date_n = NULL;
	int i;
	int year_i = 0;
	int month_i = 0;
	int day_i = 0;
	
	char *year = NULL , *month = NULL , *day = NULL ;
	
	if(date_s == NULL) return NULL;
	
	year = (char *) malloc(sizeof(char)*5);
	if(year == NULL){
		printf("Out of memory (date->year)\n");
		return NULL;
	}
	
	for(i=0;i<4;i++){
		year[i] = date_s[i];
	}
	year[4] = '\0';
	
	
		
	month = (char *) malloc(sizeof(char)*3);
	if(month == NULL){
		printf("Out of memory (date->month)\n");
		free(year);
		return NULL;
	}
	
	for(i=0;i<2;i++){
		month[i] = date_s[i+5];
	}
	month[2] = '\0';
	
	day = (char *) malloc(sizeof(char)*3);
	if(month == NULL){
		printf("Out of memory (date->day)\n");
		free(year);
		free(month);
		return NULL;
	}
	
	for(i=0;i<2;i++){
		day[i] = date_s[i+8];
	}
	day[2] = '\0';
	
	year_i = atoi(year);
	month_i = atoi(month);
	day_i = atoi(day);
	
	if(year_i != 0 && month_i != 0 && day_i != 0){
	date_n = create_date(year_i,month_i,day_i);
	}
	
	free(year);
	free(month);
	free(day);
	
	return date_n;
}

/* ____________________________________________________________________________

  	int compare(date *d1,date *d2)
    
    Compares dates struct passed by arguments d1,d2

    returns:
    1 if d2 is older
    0 if dates are equal
    -1 if date 1 is older
   ____________________________________________________________________________
*/

int compare(date *d1,date *d2){	
	if(d1 == NULL || d2 == NULL) return 0;
	
	if(d1->year > d2->year){
		return 1;
	}
	else if(d2->year > d1->year){
		return -1;
	}
	
	if(d1->month > d2->month){
		return 1;
	}
	else if(d2->month > d1->month){
		return -1;
	}
	
	if(d1->day > d2->day){
		return 1;
	}
	else if(d2->day > d1->day){
		return -1;
	}
	else{
		return 0;
	}
	
}

/* ____________________________________________________________________________

  	int difference_days(date *oldest,date *newest)
    
    Returns difference of two dates in days. Function uses difftime from <time.h>

    returns:
    positive integer if d2 is older
    0 if dates are equal
    negative integer if date 2 is older
   ____________________________________________________________________________
*/

int difference_days(date *oldest,date *newest){
	int comp, days;
	struct tm start_date = {0};
	struct tm end_date = {0};
	time_t start_time, end_time;
	double seconds;
	
	if(oldest == NULL || newest == NULL) return;
	
	if(oldest == newest) return 0;
	
	
	start_date.tm_year = oldest->year - 1900;
	start_date.tm_mon = oldest->month - 1;
	start_date.tm_mday = oldest->day;
	
	end_date.tm_year = newest->year - 1900;
	end_date.tm_mon = newest->month - 1;
	end_date.tm_mday = newest->day;
	
	start_time = mktime(&start_date);
	if(start_time == -1){
		printf("Cannot create time_t from newst_date\n");
		return 0;
	}
	
	end_time = mktime(&end_date);
	if(start_time == -1){
		printf("Cannot create time_t from oldest_date\n");
		return 0;
	}

 	seconds = difftime(end_time, start_time);
 	
 	days = seconds / 86400; 
	
	return days;
}

/* ____________________________________________________________________________

  	void print_date(date *d)
    
    Prints date passed by an argument d in format "yyyy-mm-dd";
   ____________________________________________________________________________
*/

void print_date(date *d){
	
	if(d->month < 9 && d->day < 9){
		printf("%i-0%i-0%i",d->year,d->month,d->day);
	}
	else if(d->month < 9){
		printf("%i-0%i-%i",d->year,d->month,d->day);
	}
	else if(d->day < 9){
		printf("%i-%i-0%i",d->year,d->month,d->day);
	}
	else{
		printf("%i-%i-%i",d->year,d->month,d->day);	
	}
}

/* ____________________________________________________________________________

  	void dispose_date(date **d)
    
    Dispose memory occupied by a date passed by an argument d
   ____________________________________________________________________________
*/

void dispose_date(date **d){
	free(*d);
}

