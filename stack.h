#ifndef _STACK_H
#define _STACK_H

#include "date.h"
#include "predecessor.h"

/* ____________________________________________________________________________

    Structures and Datatypes
   ____________________________________________________________________________
*/

typedef struct STACKNODE{
	struct DATE *d;
	struct GRAPHNODE *node;
	struct PREDECESSORNODE *previous;
	int level;
	struct STACKNODE *next;
}stack_node;

typedef struct STACK{
	struct STACKNODE *first;
}stack;

/* ____________________________________________________________________________

    Function Prototypes
   ____________________________________________________________________________
*/

stack_node *create_stack_node(graph_node *node,date *d,predecessor_node *previous,int level);
stack *create_stack();
void append_stack_node_to_stack(stack *stck,stack_node *node);
stack_node *pop_stack(stack *stck);
void print_stack(stack *stck);
void dispose_stack_node(stack_node **node);
void dispose_stack(stack **stck);

#endif
