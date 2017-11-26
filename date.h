#ifndef _DATE_H
#define _DATE_H

#include "neighbours.h"

/* ____________________________________________________________________________

    Structures and Datatypes
   ____________________________________________________________________________
*/

typedef struct DATE{
	int year;
	int month;
	int day;
}date;

/* ____________________________________________________________________________

    Function Prototypes
   ____________________________________________________________________________
*/

date *create_date(int year,int month,int day);
date *create_date_from_str(char *date_s);
int compare(date *d1,date *d2);
int difference_days(date *oldest,date *newest);
void dispose_date(date **d);

#endif
