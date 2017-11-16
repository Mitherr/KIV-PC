#include <stdio.h>
#include <stdlib.h>
#include "path.h"
#include "date.h"

path_node *create_path_node(array_node *node){
	path_node *temp = NULL;
	
	temp = (path_node *) malloc(sizeof(path_node));
	
	temp->date = node->date;
	temp->id = node->node_g->id_node;
	temp->next = NULL;
	
	return temp;	
}

path *create_path(){
	path *temp = NULL;
	
	temp = (path *) malloc(sizeof(path));
	
	temp->newest = NULL;
	temp->oldest = NULL;
	temp->difference = -1;
	temp->length = 0;
	temp->head = NULL;
	
	return temp;
}

void *append_path_node(path *path,path_node *node){
	int comp = -5;
	
	if(path == NULL){
		return;	
	}
	
	if(node == NULL){
		return;
	}
	
	if(path->head == NULL){
		path->head = node;
	}
	else{
		node->next = path->head;
		path->head = node;
	}
	
	if(path->oldest == NULL || path->newest == NULL){
		path->newest = node->date;
		path->oldest = node->date;
	}
	
	if(node->date == NULL){
		return;
	}
	
	comp = compare(path->oldest,node->date);
	
	if(comp == 1 ){
		path->oldest = node->date;
	}
	
	comp = compare(path->newest,node->date);
	
	if(comp == -1){
		path->newest = node->date;
	}
}

void dispose_pathnode(path_node **node){
	
	if(*node == NULL){
		return;
	}
	
	if((*node)->next != NULL) dispose_pathnode(&(*node)->next);
	
	free(*node);
	*node = NULL;
}

void dispose_path(path **p){
	
	if(*p == NULL){
		return;
	}
	
	if((*p)->head != NULL) dispose_pathnode(&(*p)->head);
	
	free(*p);
	*p = NULL;
}

void print_path(path *p){
 	path_node *temp = NULL;
 	int difference = -1;
 	
 	if(p == NULL){
 		return;
	 }
	 
	 if(p->head = NULL){
	 	return;
	 }
	 
	 printf("%i",p->head->id);
	 temp = p->head->next;
	 
	 while(temp != NULL){
		printf("-%i",temp->id);
	 	temp = temp->next;
	 }
	 
	 difference = difference_days(p->oldest,p->newest);
	 
	 printf(";%i-%i-%i,%i-%i-%i;%i\n",p->oldest->year,p->oldest->month,p->oldest->day,p->newest->year,p->newest->month,p->newest->day,difference);
 	
}
