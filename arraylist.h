#ifndef _ARRAYLIST_H
#define _ARRAYLIST_H

#include "graphnode.h"

/* ____________________________________________________________________________

    Structures and Datatypes
   ____________________________________________________________________________
*/
typedef struct ARRAYNODE{
	struct ARRAYNODE *next;
	struct GRAPHNODE *node_g;
	char *year;
	char *month;
	char *day;
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
array_node *append_node(arraylist *list,graph_node *node);
void print_list(arraylist *list);
void dispose_array_nodes(array_node **node);
void dispose_array_and_graph_nodes(array_node **node);
void dispose_neighbourlist(arraylist **list);
void dispose_arraylist(arraylist **list);

#endif
