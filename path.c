#include <stdio.h>
#include <stdlib.h>
#include "path.h"

path_node *create_path_node(int id_path,date *d){
	path_node *temp = NULL;
	
	temp = (path_node *) malloc(sizeof(path_node));
	
	temp->id_path_node = id_path;
	temp->path_date = d;
	temp->next = NULL;
	
	return temp;
}

path_node *copy_path_node(path_node *node){
	path_node *new_node = NULL;
	
	new_node = create_path_node(node->id_path_node,node->path_date);
	
	return new_node;
}

path *create_path(){
	path *temp = NULL;
	
	temp = (path *) malloc(sizeof(temp));
	
	temp->difference_in_days = 0;
	temp->first = NULL;
	temp->length = 0;
	temp->newest = NULL;
	temp->oldest = NULL;
	temp->next = NULL;
	
	return temp;
}

path_list *create_path_list(){
	path_list *temp = NULL;
	
	temp = (path_list *) malloc(sizeof(path_list));
	
	temp->head = NULL;
	
	return temp;
}

void append_path_node_to_path(path *p,path_node *node){
	if(p == NULL || node == NULL) return;
	
	if(p->first == NULL){
		p->first = node;
		p->newest = node->path_date;
		p->oldest = node->path_date;
		return;
	}
	
	if(compare(p->oldest,node->path_date) == 1){
		p->oldest = node->path_date;
	}
	else if(compare(p->newest,node->path_date) == -1){
		p->newest = node->path_date;
	}
	
	node->next = p->first;
	p->first = node;		
}

void append_path_to_path_list(path_list *paths,path *p){
	path *temp = NULL;
	
	if(paths->head == NULL){
		paths->head = p;
	}
	
	temp = paths->head;
	
	if((temp->length > p->length) || ((temp->length == p->length) && (temp->difference_in_days > p->difference_in_days))){
		p->next = temp;
		paths->head = p;
		return;
	}
	
	while(temp->next != NULL){
		if((temp->length > p->length) || ((temp->length == p->length) && (temp->difference_in_days > p->difference_in_days))){
			p->next = temp->next;
			temp->next = p;
		}
		temp = temp->next;
	}
}

path *copy_path(path *p){
	path *new_path = NULL;
	path_node *temp = NULL;
	path_node *temp2 = NULL;
	
	if(p == NULL) return;
	
	new_path = create_path();
	
	new_path->length = p->length;
	new_path->newest = p->newest;
	new_path->oldest = p->oldest;
	
	temp = p->first;
	
	if(p != NULL){
		new_path->first = copy_path_node(temp);
	}
	
	temp2 = new_path->first;
	
	while(temp->next != NULL){
		temp2->next = copy_path_node(temp->next);
		temp2 = temp2->next;
		temp = temp->next;
	}
	
	return new_path;
}

void calculate_difference(path *p){
	p->difference_in_days = difference_days(p->oldest,p->newest);
}

void print_path(path *p){
	path_node *temp = NULL;
	
	if(p == NULL) return;
	
	if(p->length == 1){
	}
	
}

void print_paths_list(path_list *paths){
	path *temp = NULL;
	
	if(paths->head == NULL) return; 
	
	temp = paths->head;
	
	while(temp != NULL){
		print_path(temp);
	}
}

void dispose_path_node(path_node **node){
	if(*node == NULL) return;
	
	if(&(*node)->next != NULL) dispose_path_node(&(*node)->next);
	
	free(*node);
	*node = NULL;
}

void dispose_path(path **p){
	if(*p == NULL) return;
	
	if(&(*p)->first != NULL) dispose_path_node(&(*p)->first);
	if(&(*p)->next != NULL) dispose_path(&(*p)->next);
	
	free(*p);
	*p = NULL;
}

void dispose_path_list(path_list **paths){
	if(*paths == NULL) return;
	
	if(&(*paths)->head != NULL) dispose_path(&(*paths)->head);
	
	free(*paths);
	*paths = NULL;
}
