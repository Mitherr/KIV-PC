#include <stdio.h>
#include <stdlib.h>
#include "predecessor.h"

predecessor_node *create_predecessor(date *d,predecessors *predecessors){
	predecessor_node *temp = NULL;
	
	temp = (predecessor_node *) malloc(sizeof(predecessor_node));
	
	temp->previous_path = predecessors;
	if(d != NULL){
	temp->d = create_date(d->year,d->month,d->day);
	}
	else{
	temp->d = NULL;	
	}
	temp->next = NULL;
	
	return temp;
}

predecessors *create_predecessors(int id_node,date *d,predecessors *predecessors_n){
	predecessors *temp = NULL;
	predecessor_node *new_node = NULL;
	
	temp = (predecessors *) malloc(sizeof(predecessors));
	
	new_node = create_predecessor(d,predecessors_n);
	
	temp->id_node = id_node;
	temp->predecessor = new_node;
	temp->next = NULL;
	
	return temp;
}

predecessors_list *create_predecessors_list(){
	predecessors_list *temp = NULL;
	
	temp = (predecessors_list *) malloc(sizeof(predecessors_list));
	
	temp->head = NULL;
	
	return temp;
}

void append_predecessor_predecessors(predecessors *predecessors,predecessor_node *node){
	predecessor_node *temp = NULL;
	
	if(predecessors == NULL){
		return;
	}
	
	if(predecessors->predecessor == NULL){
		return;
	}

	temp = predecessors->predecessor;
	
	while(temp->next != NULL){
		temp = temp->next;
	}
	
	temp->next = node;
		
}

void append_predecessors_predecessors_list(predecessors_list *list_pr,predecessors *predecessors_l){
	predecessors *temp = NULL;
	
	if(list_pr == NULL || predecessors_l == NULL) return;
	
	if(list_pr->head == NULL){
		list_pr->head = predecessors_l;
		return;
	}
	
	temp = list_pr->head;
	
	while(temp->next != NULL){
		temp = temp->next;
	}
	
	temp->next = predecessors_l;
}

predecessors *find_predecessors_in_list(predecessors_list *list_pr,int id_node){
	predecessors *temp = NULL;	

	if(list_pr == NULL) return NULL;
	
	temp = list_pr->head;
	
	while(temp != NULL){
	if(temp->id_node == id_node){
		return temp;	
	}
	temp = temp->next;
	}
	
	return NULL;
}

void dispose_predecessor_node(predecessor_node **node){
	if(*node == NULL) return;

	if(&(*node)->d != NULL) dispose_date(&(*node)->d);
	if(&(*node)->next != NULL) dispose_predecessor_node(&(*node)->next);
	
	free(*node);
	*node = NULL;
}

void dispose_predecessors(predecessors **predecessors_l){
	if(*predecessors_l == NULL) return;
	
	if(&(*predecessors_l)->predecessor != NULL) dispose_predecessor_node(&(*predecessors_l)->predecessor);
	if(&(*predecessors_l)->next != NULL) dispose_predecessors(&(*predecessors_l)->next);
	
	free(*predecessors_l);
	*predecessors_l = NULL;
}

void dispose_predecessors_list(predecessors_list **list_pr){
	if(*list_pr == NULL) return;

	if(&(*list_pr)->head != NULL) dispose_predecessors(&(*list_pr)->head);

	free(*list_pr);
	*list_pr = NULL;	
}

void print_predecessors_list(predecessors_list *list_pr){
	predecessors *temp = NULL;
	predecessor_node *temp2 = NULL;
	
	if(list_pr == NULL) return;
	if(list_pr->head == NULL) return;
	
	temp = list_pr->head;
	while(temp != NULL){
		printf("%i",temp->id_node);
		temp = temp->next;
	}
	printf("-closed\n");
}
