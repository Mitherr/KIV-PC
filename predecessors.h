/*
    DFS

    Module predecessor.h
    For detailed description see neighbours.h

*/

#ifndef _PREVIOUS_H
#define _PREVIOUS_H

#include "date.h"

/* ____________________________________________________________________________

    Structures and Datatypes
   ____________________________________________________________________________
*/

typedef struct PREDECESSORNODE{
	int id_node;
	struct DATE *d;
	struct PREDECESSORNODE *previous_path;
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

predecessor_node *create_predecessor(int id_predecessor,date *d,predecessor_node *predecessors);
predecessor_node *create_first_predecessor(int id_predecessor);
predecessors *create_predecessors(int id_node);
predecessors_list *create_predecessors_list();
void append_predecessor_predecessors(predecessors *predecessors,predecessor_node *node);
void append_predecessors_predecessors_list(predecessors_list *list_pr,predecessors *predecessors_l);
predecessors *find_predecessors_in_list(predecessors_list *list_pr,int id_node);
int predeccesor_contains_id(predecessor_node *node,int id_node);
void print_predecessors_list(predecessors_list *list_pr);
void print_previous_path(predecessor_node *node);
void print_predecessors_predecessor(predecessors_list *list_pr);
void dispose_predecessor_node(predecessor_node **node);
void dispose_predecessors(predecessors **predecessors_l);
void dispose_predecessors_list(predecessors_list **list_pr);

#endif
