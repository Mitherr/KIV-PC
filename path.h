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
	struct PATH *next;
	struct PATHNODE *head;
	struct DATE *newest;
	struct DATE *oldest;
	int difference;
	int length;
}path;

typedef struct PATHS{
	struct PATH *head;
}paths;

/* ____________________________________________________________________________

    Function Prototypes
   ____________________________________________________________________________
*/

path_node *create_path_node(array_node *node);
path *create_path();
paths *create_paths();
void *append_path_node(path *path,path_node *node);
void append_path_sorted(paths *paths,path *path);
void print_paths(paths *p);
void dispose_pathnode(path_node **node);
void dispose_path(path **p);
void dispose_paths(paths **p);

#endif
