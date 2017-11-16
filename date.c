#include <stdio.h>
#include <stdlib.h>
#include "date.h"

date *create_date(int year,int month,int day){
	date *temp = NULL;
	
	temp = (date *) malloc(sizeof(date));
	
	temp->year = year;
	temp->month = month;
	temp->day = day;
	
	return temp;
}

void dispose_date(date **d){
	free(*d);
}

