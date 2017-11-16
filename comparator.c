#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "arraylist.h"
#include "path.h"
#include "date.h"


int compare(date d1,date d2){	
	
	if(d1.year > d2.year){
		return 1;
	}
	else if(d2.year > d1.year){
		return -1;
	}
	
	if(d1.month > d2.month){
		return 1;
	}
	else if(d2.month > d1.month){
		return -1;
	}
	
	if(d1.day > d2.day){
		return 1;
	}
	else if(d2.day > d1.day){
		return -1;
	}
	else{
		return 0;
	}
	
}

int difference_days(date oldest,date newest){
	int comp, days;
	struct tm start_date = {0};
	struct tm end_date = {0};
	time_t start_time, end_time;
	double seconds;
	
	comp = compare(oldest,newest);
	
	if(comp == 1){
		start_date.tm_year = oldest.year;
		start_date.tm_mon = oldest.month;
		start_date.tm_mday = oldest.day;
		start_date.tm_hour = 0;
		start_date.tm_min = 0;
		start_date.tm_sec = 0;
		
		end_date.tm_year = newest.year;
		end_date.tm_mon = newest.month;
		end_date.tm_mday = newest.day;
		end_date.tm_hour = 0;
		end_date.tm_min = 0;
		end_date.tm_sec = 0;
	}
	else{
		return 0;
	}
	
	start_time = mktime(&start_date);
	end_time = mktime(&end_date);

 	seconds = difftime(end_time, start_time);
 	
 	days = seconds / 86400; 
	
	return days;
}
