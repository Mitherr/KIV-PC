#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "date.h"

date *create_date(int year,int month,int day){
	date *temp = NULL;
	
	temp = (date *) malloc(sizeof(date));
	
	temp->year = year;
	temp->month = month;
	temp->day = day;
	
	return temp;
}

date *create_date_from_str(char *date_s){
	date *date_n = NULL;
	int i;
	
	char *year = NULL , *month = NULL , *day = NULL ;
	
	if(date_s == NULL) return;
	
	if(strlen(date_s) > 11 ) return;
	
	year = (char *) malloc(sizeof(char)*5);
	
	for(i=0;i<4;i++){
		year[i] = date_s[i];
	}
	year[4] = '\0';
	
	
		
	month = (char *) malloc(sizeof(char)*3);
	
	for(i=0;i<2;i++){
		month[i] = date_s[i+5];
	}
	month[2] = '\0';
	
	day = (char *) malloc(sizeof(char)*3);
	
	for(i=0;i<2;i++){
		day[i] = date_s[i+8];
	}
	day[2] = '\0';
	
	date_n = create_date(atoi(year),atoi(month),atoi(day));
	
	free(year);
	free(month);
	free(day);
	
	return date_n;
}

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

int difference_days(date *oldest,date *newest){
	int comp, days;
	struct tm start_date = {0};
	struct tm end_date = {0};
	time_t start_time, end_time;
	double seconds;
	
	if(oldest == newest) return 0;
	
	
	start_date.tm_year = oldest->year - 1900;
	start_date.tm_mon = oldest->month - 1;
	start_date.tm_mday = oldest->day;
	
	end_date.tm_year = newest->year - 1900;
	end_date.tm_mon = newest->month - 1;
	end_date.tm_mday = newest->day;
	
	start_time = mktime(&start_date);
	end_time = mktime(&end_date);

 	seconds = difftime(end_time, start_time);
 	
 	days = seconds / 86400; 
	
	return days;
}

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

void dispose_date(date **d){
	free(*d);
}

