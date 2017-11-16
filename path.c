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
	temp->next = NULL;
	
	return temp;
}

paths *create_paths(){
	paths *temp = NULL;
	
	temp = (paths *) malloc(sizeof(paths));
	
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
		path->length++;
	}
	else{
		node->next = path->head;
		path->head = node;
		path->length++;
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

void append_path_sorted(paths *paths,path *path_new){
	path *temp = NULL;
	
	path_new->difference = difference_days(path_new->oldest,path_new->newest);
	
	if(paths == NULL){
		return;
	}
	
	if(path_new == NULL){
		return;
	}
	
	if(paths->head == NULL){
		paths->head = path_new;
		return;
	}
	
	if((paths->head->length > path_new->length) || ((paths->head->length == path_new->length) && (paths->head->difference > path_new->difference))){
		path_new->next = paths->head;
		paths->head = path_new;
		return;
	}
	
	temp = paths->head;
	
	while(temp->next != NULL){
		if(temp->next->length > path_new->length || ((temp->next->length == path_new->length)&& (temp->next->difference > path_new->difference))){
			path_new->next = temp->next;
			temp->next = path_new;
			return;
		}
		temp = temp->next;
	}
	
	temp->next = path_new;
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

void dispose_paths(paths **p){
	
	if(*p == NULL){
		return;
	}
	
	if((*p)->head != NULL) dispose_path(&(*p)->head);
	
	free(*p);
	*p = NULL;
}

void print_path(path *p){
 	path_node *temp = NULL;
 	
 	if(p == NULL){
 		return;
	 }
	 
	 if(p->head == NULL){
	 	return;
	 }
	 
	 printf("%i",p->head->id);
	 temp = p->head->next;
	 
	 while(temp != NULL){
		printf("-%i",temp->id);
	 	temp = temp->next;
	 }
	 
	 printf(";%i-%i-%i,%i-%i-%i;%i\n",p->newest->year,p->newest->month,p->newest->day,p->oldest->year,p->oldest->month,p->oldest->day,p->difference,p->length);
 	
}

void print_paths(paths *p){
	path *temp = NULL;
	
	if(p == NULL){
		return;
	}
	
	if(p->head == NULL){
		return;
	}
	
	temp = p->head;
	
	while(temp != NULL){
		print_path(temp);
		temp = temp->next;		
	}
}
