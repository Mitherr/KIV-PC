/*
    DFS

    Module path.c
    This module creates list of pahts wich final paths found in graph.
    And also contains all functions to work with the list and dispose it.

*/

#include <stdio.h>
#include <stdlib.h>
#include "path.h"

/* ____________________________________________________________________________

   	path_node *create_path_node(int id_path,date *d)
    
    
    Creates a path_node. path_node contains id of a node and weight of and edge that added this node.
    
    returns:
    path_node if succeed
    NULL if fails
   ____________________________________________________________________________
*/

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

/* ____________________________________________________________________________

   	path_node *create_last_path_node(int id_path)
    
    Creates a path_node. path_node contains id of a node but has no date becouse it's node we started our search from.
    
    returns:
    
    path_node if succeed
    NULL if fails
   ____________________________________________________________________________
*/

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

/* ____________________________________________________________________________

    path *create_path()
    
    Creates a path. Path contains her length,two dates we used for counting her weight, weight, and pointer on a path_node list.
    When new path is created all pointer are set on NULL, weight is set on 0 and length on -1.
    
    returns:
    path if succeed
    NULL if fails
   ____________________________________________________________________________
*/

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

/* ____________________________________________________________________________

    path_list *create_path_list()
    
    Creates a sorted list of all paths. List is empty when created.
    
    returns:
    path_list if succeed
    NULL if fails
   ____________________________________________________________________________
*/

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

/* ____________________________________________________________________________

    void append_path_node_to_path(path *p,path_node *node)
    
    Appends path_node node to a certain path p. If path is empty sets her dates to date of a node.
    Else dates of node are compared to path's dates and are replaced if necessery.
    Appending node also  increments path's lenght.
   ____________________________________________________________________________
*/

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

/* ____________________________________________________________________________

    void calculate_difference(path *p)
    
    Sets path's weight that is calculated from her oldest and newest date.
    If path has length 1 weight stays on default value 0.
   ____________________________________________________________________________
*/

void calculate_difference(path *p){
	if(p == NULL) return;
	
	if(p->length == 1){
		return;
	}
	
	p->difference_in_days = difference_days(p->oldest,p->newest);
}

/* ____________________________________________________________________________

    void append_paths_to_path_list(path_list *paths,path *p)
    
    Appends path to a list of paths. Path is appended on a place by her length and weight.
    Before path is appended her weight is calculated from her final dates.
   ____________________________________________________________________________
*/

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

/* ____________________________________________________________________________

    path_list *create_paths_from_predecessors(predecessors *end_node)
    
	Creates all paths from predecessors(wich is basicly one node in a graph containg pointer to all her predecessors).
	All paths are appended to a path_list.
	
	returns:
	path_list if succeed
	NULL if fails
   ____________________________________________________________________________
*/

path_list *create_paths_from_predecessors(predecessors *end_node){
	predecessor_node *temp = NULL;
	predecessor_node *temp2 = NULL;
	predecessor_node *prev = NULL;
	path *new_p = NULL;
	path_list * paths = NULL;
	path_node *path_n = NULL;
	int i = 0;
	int error = 0;
	
	if(end_node == NULL) return NULL;
	
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

/* ____________________________________________________________________________

  	void print_graph(graph_list *graph)
    
    Prints path in format (i-i-....-i;dn,do;w)
    if path has length 1 prints only(i-i;d;0)
    
    i - id_node in graph
    dn - date newest
    do - date oldest
    w - weight
    
   ____________________________________________________________________________
*/

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

/* ____________________________________________________________________________

  	void print_graph(graph_list *graph)

	Print paths in sorted path_list using function print_path
   ____________________________________________________________________________
*/

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

/* ____________________________________________________________________________

  	void dispose_path_node(path_node **node)
    
    Dispose memory occupied by a node and her neighbours in list recursively.
   ____________________________________________________________________________
*/

void dispose_path_node(path_node **node){
	if(*node == NULL) return;
	
	if(&(*node)->next != NULL) dispose_path_node(&(*node)->next);
	
	free(*node);
	*node = NULL;
}

/* ____________________________________________________________________________

  	void dispose_path(path **p)
    
    Dispose memory occupied by a path and her neighbours in list recursively.
   ____________________________________________________________________________
*/

void dispose_path(path **p){
	if(*p == NULL) return;
	
	if(&(*p)->first != NULL) dispose_path_node(&(*p)->first);
	if(&(*p)->next != NULL) dispose_path(&(*p)->next);
	
	free(*p);
	*p = NULL;
}

/* ____________________________________________________________________________

  	void dispose_path(path **p)
    
    Dispose memory occupied by a path_list and all nodes in the list recursively.
   ____________________________________________________________________________
*/

void dispose_path_list(path_list **paths){
	if(*paths == NULL) return;
	
	if(&(*paths)->head != NULL) dispose_path(&(*paths)->head);
	
	free(*paths);
	*paths = NULL;
}
