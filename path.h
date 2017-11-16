#ifndef _PATH_H
#define _PATH_H

#include "arraylist.h"

/* ____________________________________________________________________________

    Structures and Datatypes
   ____________________________________________________________________________
*/

typedef struct PATHNODE{
	struct PATHNODE *next;
	struct DATE *date;
	int id;
}path_node;

typedef struct PATH{
	struct PATHNODE *head;
	struct DATE *newest;
	struct DATE *oldest;
	int difference;
	int length;
}path;

/* ____________________________________________________________________________

    Function Prototypes
   ____________________________________________________________________________
*/

path_node *create_path_node(array_node *node);
path *create_path();
void *append_path_node(path *path,path_node *node);
void dispose_pathnode(path_node **node);
void dispose_path(path **p);

#endif
