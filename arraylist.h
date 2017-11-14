#ifndef _ARRAYLIST_H
#define _ARRAYLIST_H

#include "graphnode.h"

/* ____________________________________________________________________________

    Structures and Datatypes
   ____________________________________________________________________________
*/
typedef struct ARRAYNODE{
	struct ARRAYNODE *next;
	struct ARRAYNODE *previous_path;
	struct GRAPHNODE *node_g;
	int year;
	int month;
	int day;
	int level;
}array_node;

typedef struct ARRAYLIST{
	struct ARRAYNODE *head;
}arraylist;

/* ____________________________________________________________________________

    Function Prototypes
   ____________________________________________________________________________
*/

array_node *create_array_node(graph_node *node);
void set_date(array_node *node,char *date);
arraylist *create_arraylist();
array_node *add_neighbour(graph_node *node,graph_node *neighbour);
array_node *append_node(arraylist *list,graph_node *node);
array_node *find_node(arraylist *list,int id_node);
array_node *pop_node(arraylist *list);
void print_list(arraylist *list);
void dispose_array_nodes(array_node **node);
void dispose_array_and_graph_nodes(array_node **node);
void dispose_neighbourlist(arraylist **list);
void dispose_arraylist(arraylist **list);

#endif
