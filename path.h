#ifndef _PATH_H
#define _PATH_H

#include "date.h"
#include "predecessor.h"

/* ____________________________________________________________________________

    Structures and Datatypes
   ____________________________________________________________________________
*/

typedef struct PATHNODE{
	int id_path_node;
	date *path_date;
	struct PATHNODE *next;
}path_node;

typedef struct PATH{
	int length;
	struct PATHNODE *first;
	struct DATE *newest;
	struct DATE *oldest;
	int difference_in_days;
	struct PATH *next;
}path;

typedef struct PATHLIST{
	struct PATH *head;
}path_list;

/* ____________________________________________________________________________

    Function Prototypes
   ____________________________________________________________________________
*/

path_node *create_path_node(int id_path,date *d);
path_node *copy_path_node(path_node *node);
path *create_path();
path_list *create_path_list();
void append_path_node_to_path(path *p,path_node *node);
void append_path_to_path_list(path_list *paths,path *p);
path *copy_path(path *p);
void calculate_difference(path *p);
path_list *create_path_list_from_predecessors(predecessors_list *pred_l,int id_node_end);
void print_path(path *p);
void print_paths_list(path_list *paths);
void dispose_path_node(path_node **node);
void dispose_path(path **p);
void dispose_path_list(path_list **paths);


#endif
