#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "list.h"
#include "date.h"
#include "predecessor.h"

stack_node *create_stack_node(graph_node *node,date *d,predecessor_node *previous,int level){
	stack_node *temp = NULL;
	
	if(node == NULL) return;
	
	temp = (stack_node *) malloc(sizeof(stack_node));
	
	temp->d = d;
	temp->level = level;
	temp->previous = previous;
	temp->node = node;
	temp->next = NULL;
	
	return temp;
}

stack *create_stack(){
	stack *temp = NULL;
	
	temp = (stack *) malloc(sizeof(stack));
	
	temp->first = NULL;
	
	return temp;
}

void append_stack_node_to_stack(stack *stck,stack_node *node){
	if(stck == NULL || node == NULL) return;
	
	if(stck->first == NULL){
		stck->first = node;
		return;
	}	
	
	node->next = stck->first;
	stck->first = node;
}

stack_node *pop_stack(stack *stck){
	stack_node *temp = NULL;
	if(stck == NULL) return;
	
	if(stck->first == NULL){
		return NULL;
	}
	
	temp = stck->first;
	stck->first = stck->first->next;
	
	temp->next = NULL;
	
	return temp;
}

void dispose_stack_node(stack_node **node){
	if(*node == NULL) return;
	
	if(&(*node)->next != NULL) dispose_stack_node(&(*node)->next);
	*node = NULL;
}

void dispose_stack(stack **stck){
	if(*stck == NULL) return;
	
	if(&(*stck)->first != NULL) dispose_stack_node(&(*stck)->first);
	
	free(*stck);
	*stck = NULL;
}

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
