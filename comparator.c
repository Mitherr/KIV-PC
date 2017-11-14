#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "arraylist.h"


int compare(array_node *a1,array_node *a2){
	int y1, y2, m1, m2, d1,d2;
	
	y1 = a1->year;
	y2 = a2->year;
	
	if(y1 > y2){
		return 1;
	}
	else if(y2 > y1){
		return -1;
	}
	
	m1 = a1->month;
	m2 = a2->month;
	
	if(m1 > m2){
		return 1;
	}
	else if(m2 > m1){
		return -1;
	}
	
	d1 = a1->day;
	d2 = a2->day;
	
	if(d1 > d2){
		return 1;
	}
	else if(d2 > d1){
		return -1;
	}
	else{
		return 0;
	}
	
	
}

int difference_days(array_node *a1,array_node *a2){
	int comp, days;
	struct tm start_date = {0};
	struct tm end_date = {0};
	time_t start_time, end_time;
	double seconds;
	
	comp = compare(a1,a2);
	
	printf("%i ",comp);
	
	if(comp == 1){
		start_date.tm_year = a2->year-1900;
		start_date.tm_mon = a2->month;
		start_date.tm_mday = a2->day;
		start_date.tm_hour = 0;
		start_date.tm_min = 0;
		start_date.tm_sec = 0;
		
		end_date.tm_year = a1->year-1900;
		end_date.tm_mon = a1->month;
		end_date.tm_mday = a1->day;
		end_date.tm_hour = 0;
		end_date.tm_min = 0;
		end_date.tm_sec = 0;
	}
	else if(comp == -1){
		start_date.tm_year = a1->year-1900;
		start_date.tm_mon = a1->month;
		start_date.tm_mday = a1->day;
		start_date.tm_hour = 0;
		start_date.tm_min = 0;
		start_date.tm_sec = 0;
		
		end_date.tm_year = a2->year-1900;
		end_date.tm_mon = a2->month;
		end_date.tm_mday = a2->day;
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
