#include <stdio.h>
#include <stdlib.h>
#include "path.h"

path_node *create_path_node(int id_path,date *d){
	path_node *temp = NULL;
	
	temp = (path_node *) malloc(sizeof(path_node));
	if(temp == NULL){
		printf("Out of memory (path_node)\n");
		return NULL;
	}
	
	temp->id_path_node = id_path;
	temp->path_date = d;
	temp->next = NULL;
	
	return temp;
}

path_node *create_last_path_node(int id_path){
	path_node *temp = NULL;
	
	temp = (path_node *) malloc(sizeof(path_node));
	if(temp == NULL){
		printf("Out of memory (path_node)\n");
		return NULL;
	}
	
	temp->id_path_node = id_path;
	temp->path_date = NULL;
	temp->next = NULL;
	
	return temp;
}

path *create_path(){
	path *temp = NULL;
	
	temp = (path *) malloc(sizeof(path));
	if(temp == NULL){
		printf("Out of memory (path_node)\n");
		return NULL;
	}
	
	temp->difference_in_days = 0;
	temp->first = NULL;
	temp->length = -1;
	temp->newest = NULL;
	temp->oldest = NULL;
	temp->next = NULL;
	
	return temp;
}

path_list *create_path_list(){
	path_list *temp = NULL;
	
	temp = (path_list *) malloc(sizeof(path_list));
	if(temp == NULL){
		printf("Out of memory (path_list)");
		return NULL;
	}
	
	temp->head = NULL;
	
	return temp;
}

void append_path_node_to_path(path *p,path_node *node){
	if(p == NULL || node == NULL) return;
	
	if(p->first == NULL){
		p->first = node;
		p->length += 1;
		p->oldest = node->path_date;
		p->newest = node->path_date;
		return;
	}
	
	if(node->path_date != NULL){
		if(compare(p->oldest,node->path_date) == 1){
			p->oldest = node->path_date;
		}
		else if(compare(p->newest,node->path_date) == -1){
			p->newest = node->path_date;
		}
	}
	
	node->next = p->first;
	p->first = node;
	p->length += 1;		
}

void append_paths_to_path_list(path_list *paths,path *p){
	path *temp = NULL;
	
	if(paths == NULL || p == NULL) return;
	
	calculate_difference(p);
	
	if(paths->head == NULL){
		paths->head = p;
		return;
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
	temp->next = p;
}

void calculate_difference(path *p){
	if(p == NULL) return;
	
	p->difference_in_days = difference_days(p->oldest,p->newest);
}


path_list *create_paths_from_predecessors(predecessors *end_node,int id_node_end){
	predecessor_node *temp = NULL;
	predecessor_node *temp2 = NULL;
	predecessor_node *prev = NULL;
	path *new_p = NULL;
	path_list * paths = NULL;
	path_node *path_n = NULL;
	int i = 0;
	int error = 0;
	
	if(end_node->predecessor == NULL) return NULL;
	
	temp = end_node->predecessor;
	paths = create_path_list();
	if(paths == NULL){
		return NULL;
	}
	
	while(temp != NULL){
	new_p = create_path();
	if(new_p == NULL){
		error = 1;
		break;
	}
	
	path_n = create_path_node(temp->id_node,temp->d);
	if(path_n == NULL){
		error = 1;
		dispose_path(&new_p);
		break;
	}
	
	append_path_node_to_path(new_p,path_n);
	temp2 = temp->previous_path;
		while(temp2 != NULL){
			if(temp->previous_path != NULL){
				path_n = create_path_node(temp2->id_node,temp2->d);
				if(path_n == NULL){
					error = 1;
					break;
				}
			}
			else{
				path_n = create_last_path_node(temp2->id_node);
				if(path_n == NULL){
					error = 1;
					break;
				}
			}
			append_path_node_to_path(new_p,path_n);
			temp2 = temp2->previous_path;
		}
	if(error == 1){
		dispose_path_list(&paths);
		dispose_path(&new_p);
		return NULL;
	}
	
	append_paths_to_path_list(paths,new_p);
	temp=temp->next;
	}
	
	return paths;
}

void print_path(path *p){
	path_node *temp = NULL;
	
	if(p == NULL) return;
	
	if(p->length == 1){
		printf("%i-%i;",p->first->id_path_node,p->first->next->id_path_node);
		print_date(p->oldest);
		printf(";%i\n",p->difference_in_days);
		return;
	}
	
	temp = p->first->next;
	
	printf("%i",p->first->id_path_node);
	
	while(temp != NULL){
		printf("-%i",temp->id_path_node);
		temp = temp->next;
	}
	
	printf(";");
	print_date(p->newest);
	printf(",");
	print_date(p->oldest);
	printf(";%i\n",p->difference_in_days);
	
}

void print_paths_list(path_list *paths){
	path *temp = NULL;
	
	if(paths == NULL) return;
	if(paths->head == NULL) return; 
	
	temp = paths->head;
	
	while(temp != NULL){
		print_path(temp);
		temp = temp->next;
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
