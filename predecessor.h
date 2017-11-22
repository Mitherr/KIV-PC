#ifndef _PREVIOUS_H
#define _PREVIOUS_H

#include "date.h"

/* ____________________________________________________________________________

    Structures and Datatypes
   ____________________________________________________________________________
*/

typedef struct PREDECESSORNODE{
	struct DATE *d;
	struct PREDECESSORS *previous_path;
	struct PREDECESSORNODE *next;
}predecessor_node;

typedef struct PREDECESSORS{
	int id_node;
	struct PREDECESSORNODE *predecessor;
	struct PREDECESSORS *next;
}predecessors;

typedef struct PREDECESSORSLIST{
	struct PREDECESSORS *head;
}predecessors_list;

/* ____________________________________________________________________________

    Function Prototypes
   ____________________________________________________________________________
*/

predecessor_node *create_predecessor(date *d,predecessors *predecessor);
predecessors *create_predecessors(int id_node,date *d,predecessors *predecessors_n);
predecessors_list *create_predecessors_list();
void append_predecessor_predecessors(predecessors *predecessors,predecessor_node *node);
void append_predecessors_predecessors_list(predecessors_list *list_pr,predecessors *predecessors_l);
predecessors *find_predecessors_in_list(predecessors_list *list_pr,int id_node);
void dispose_predecessor_node(predecessor_node **node);
void dispose_predecessors(predecessors **predecessors_l);
void dispose_predecessors_list(predecessors_list **list_pr);

void print_predecessors_list(predecessors_list *list_pr);

#endif
