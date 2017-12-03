/*
    DFS

    Module stack.c
    For detailed description see stack.c

*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "date.h"
#include "predecessors.h"

/* ____________________________________________________________________________

   	stack_node *create_stack_node(graph_node *node,date *d,predecessor_node *previous,int level)
    
    
    Creates a stack_node. Stack node contains graph_node (pointer node in graph). Date of an edge that got us there.
    Predecessor that appended this node to a stack and level a of node in search.
    
    returns:
    stack_node if succeed
    NULL if fails
   ____________________________________________________________________________
*/

stack_node *create_stack_node(graph_node *node,date *d,predecessor_node *previous,int level){
	stack_node *temp = NULL;
	
	if(node == NULL || d == NULL || previous == NULL) return;
	
	temp = (stack_node *) malloc(sizeof(stack_node));
	if(temp == NULL){
		printf("Out of memory (stack_node)\n");
		return NULL;
	}
	
	temp->d = d;
	temp->level = level;
	temp->previous = previous;
	temp->node = node;
	temp->next = NULL;
	
	return temp;
}

/* ____________________________________________________________________________

   	stack *create_stack()
    
    Creates a stack structure.
    
    returns:
    stack if succeed
    NULL if fails
   ____________________________________________________________________________
*/

stack *create_stack(){
	stack *temp = NULL;
	
	temp = (stack *) malloc(sizeof(stack));
	if(temp == NULL){
		printf("Out of memory (stack)\n");
		return NULL;
	}
	
	temp->first = NULL;
	
	return temp;
}

/* ____________________________________________________________________________

   	void append_stack_node_to_stack(stack *stck,stack_node *node)
    
    Appends stack_node node to a stack stck. Node is appened to the begging of a stack.
   ____________________________________________________________________________
*/

void append_stack_node_to_stack(stack *stck,stack_node *node){
	if(stck == NULL || node == NULL) return;
	
	if(stck->first == NULL){
		stck->first = node;
		return;
	}	
	
	node->next = stck->first;
	stck->first = node;
}

/* ____________________________________________________________________________

   	stack_node *pop_stack(stack *stck)
    
    Removes first stack_node from a stack and returns pointer on it.
    
    returns:
    stack_node if suceed
    NULL if stack is empty or stck is NULL
   ____________________________________________________________________________
*/

stack_node *pop_stack(stack *stck){
	stack_node *temp = NULL;
	if(stck == NULL) return NULL;
	
	if(stck->first == NULL){
		return NULL;
	}
	
	temp = stck->first;
	stck->first = stck->first->next;
	
	temp->next = NULL;
	
	return temp;
}

/* ____________________________________________________________________________

  	void print_stack(stack *stck)
    
    Prints id of all graph_nodes contained in stack_node in a stack passed by an argument stkc. (debug reasons only)
   ____________________________________________________________________________
*/

void print_stack(stack *stck){
	stack_node *temp = NULL;
	
	if(stck == NULL)return;
	
	temp = stck->first;
	
	while(temp != NULL){
		printf("%i",temp->node->id_node);
		temp = temp->next;
	}
	printf(" -open\n");	
}

/* ____________________________________________________________________________

  	void dispose_stack_node(stack_node **node)
    
    Dispose memory occupied by a node and her neighbours in stack recursively.
   ____________________________________________________________________________
*/

void dispose_stack_node(stack_node **node){
	if(*node == NULL) return;
	
	if(&(*node)->next != NULL) dispose_stack_node(&(*node)->next);
	
	free(*node);
	*node = NULL;
}

/* ____________________________________________________________________________

  	void dispose_stack(stack **stck)
    
    Dispose memory occupied by a stack and all nodes in it.
   ____________________________________________________________________________
*/

void dispose_stack(stack **stck){
	if(*stck == NULL) return;
	
	if(&(*stck)->first != NULL) dispose_stack_node(&(*stck)->first);
	
	free(*stck);
	*stck = NULL;
}
