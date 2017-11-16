#ifndef _DATE_H
#define _DATE_H

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
void dispose_date(date **d);

#endif
