#include <stdio.h>
#include <stdlib.h>
#include "predecessor.h"

predecessor_node *create_predecessor(int id_predecessor,date *d,predecessor_node *predecessors){
	predecessor_node *temp = NULL;
	
	if(d == NULL || predecessors == NULL) return;
	
	temp = (predecessor_node *) malloc(sizeof(predecessor_node));
	if(temp == NULL){
		printf("Out of memory (predecessor_node)\n");
		return NULL;
	}
	
	temp->id_node = id_predecessor;
	temp->previous_path = predecessors;
	temp->d = d;	
	temp->next = NULL;
	
	return temp;
}

predecessor_node *create_first_predecessor(int id_predecessor){
	predecessor_node *temp = NULL;
	
	temp = (predecessor_node *) malloc(sizeof(predecessor_node));
	if(temp == NULL){
		printf("Out of memory (predecessor_node)\n");
		return NULL;
	}
	
	temp->id_node = id_predecessor;
	temp->previous_path = NULL;
	temp->d = NULL;	
	temp->next = NULL;
	
	return temp;
}

predecessors *create_predecessors(int id_node){
	predecessors *temp = NULL;
	predecessor_node *new_node = NULL;
	
	temp = (predecessors *) malloc(sizeof(predecessors));
	if(temp == NULL){
		printf("Out of memory (predecessors)\n");
		return NULL;
	}
	
	temp->id_node = id_node;
	temp->predecessor = NULL;
	temp->next = NULL;
	
	return temp;
}

predecessors_list *create_predecessors_list(){
	predecessors_list *temp = NULL;
	
	temp = (predecessors_list *) malloc(sizeof(predecessors_list));
	if(temp == NULL){
		printf("Out of memory (predecessors_list)");
		return NULL;
	}
	
	temp->head = NULL;
	
	return temp;
}

void append_predecessor_predecessors(predecessors *predecessors,predecessor_node *node){
	predecessor_node *temp = NULL;
	
	if(predecessors == NULL || node == NULL) return;
	
	if(predecessors->predecessor == NULL){
		predecessors->predecessor = node;
		return;
	}

	node->next = predecessors->predecessor;
	predecessors->predecessor = node;
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

int predeccesor_contains_id(predecessor_node *node,int id_node){
	predecessor_node *temp = NULL;
	
	if(node == NULL) return;
	
	temp = node->previous_path;
	
	while(temp != NULL){
		if(temp->id_node == id_node){
			return 1;
		}
		temp = temp->previous_path;
	}
	
	return 0;
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

void print_previous_path(predecessor_node *node){
	predecessor_node *temp = NULL;
	
	if(node == NULL) return;
	
	printf("%i",node->id_node);
	
	temp = node->previous_path;
	
	while(temp != NULL){
		printf("-%i",temp->id_node);
		temp = temp->previous_path;
	}
	
	printf(" -path\n");
}

void print_predecessors_predecessor(predecessors_list *list_pr){
	predecessors *temp = NULL;
	predecessor_node *temp2 = NULL;
	
	if(list_pr == NULL) return;
	if(list_pr->head == NULL) return;
	
	temp = list_pr->head;
	while(temp != NULL){
		temp2 = temp->predecessor;
		printf("%i(",temp->id_node);
		while(temp2 != NULL){
			if(temp2->previous_path != NULL){
			printf("-%i",temp2->previous_path->id_node);
			}
			temp2 = temp2->next;
		}
		printf(")");
		temp = temp->next;
	}
	printf(" -predecessors\n");
}

void dispose_predecessor_node(predecessor_node **node){
	if(*node == NULL) return;

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
