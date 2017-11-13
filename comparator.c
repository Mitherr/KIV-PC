#include <stdlib.h>
#include <stdio.h>
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
	else{
		return 0;
	}
	
	m1 = a1->month;
	m2 = a2->month;
	
	if(m1 > m2){
		return 1;
	}
	else if(m2 > m1){
		return -1;
	}
	else{
		return 0;
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
