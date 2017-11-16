#include <stdlib.h>
#include <stdio.h>
#include "arraylist.h"
#include "string.h"
#include "date.h"

/* ____________________________________________________________________________

	array_node *create_array_node(graph_node *node)
    
    Creates node that represents one node of a arraylist wich contains reference to it's neigbour and
    graph_node with data. Data is passe by argument 'node' and neigbour is
    is NULL when node is created.
   ____________________________________________________________________________
*/

array_node *create_array_node(graph_node *node){
	array_node *temp = NULL;
	
	temp = (array_node *) malloc(sizeof(array_node));
	
	temp->date = NULL;	
	temp->node_g = node;
	temp->next = NULL;
	temp->previous_path = NULL;
	temp->level = 0;
	
	return temp;
}

void set_date(array_node *node,char *date_s){
	date *d = NULL;
	int i;
	
	char *year = NULL , *month = NULL , *day = NULL ;
	
	if(date_s == NULL || node ==  NULL) return;
	
	if(strlen(date_s) != 10) return;
	
	year = (char *) malloc(sizeof(char)*5);
	
	for(i=0;i<4;i++){
		year[i] = date_s[i];
	}
	year[4] = '\0';
	
	
		
	month = (char *) malloc(sizeof(char)*3);
	
	for(i=0;i<2;i++){
		month[i] = date_s[i+5];
	}
	month[2] = '\0';
	
	day = (char *) malloc(sizeof(char)*3);
	
	for(i=0;i<2;i++){
		day[i] = date_s[i+8];
	}
	day[2] = '\0';
	
	d = create_date(atoi(year),atoi(month),atoi(day));
	
	node->date = d;
	
	
	free(year);
	free(month);
	free(day);
}

/* ____________________________________________________________________________

	arraylist *create_arraylist()
    
    Creates arraylist that is represented by array_nodes that are linked by *next pointer.
    When arraylist is created it's empty so arraylist->head = NULL.
   ____________________________________________________________________________
*/

arraylist *create_arraylist(){
	arraylist *temp = NULL;
	
	temp = (arraylist *) malloc(sizeof(arraylist));
	
	temp->head = NULL;
	
	return temp;
}

/* ____________________________________________________________________________

	void append_node(arraylist *list,graph_node *node)
    
    Appends graph_node passed by an argument 'node! to an existing list passed by an argument 'list'.
   ____________________________________________________________________________
*/

array_node *append_node(arraylist *list,graph_node *node){
	array_node *temp = NULL;
	array_node *new_temp = NULL;
	
	if(list == NULL) return;
	if(node == NULL) return;
	
	new_temp = create_array_node(node);
	
	if(list->head == NULL){
		list->head = new_temp;
		return list->head;
	}
	
	temp = list->head;
	
	while(temp->next != NULL){
		temp = temp->next;
	}
	
	temp->next = new_temp;
	
	return new_temp;
}

array_node *copy_node(arraylist *list,array_node *node){
	array_node *temp = NULL;
	array_node *new_temp = NULL;
	
	if(list == NULL) return;
	if(node == NULL) return;
	
	new_temp = create_array_node(node->node_g);
	
	new_temp->date = node->date;
	new_temp->node_g = node->node_g;
	new_temp->previous_path = node->previous_path;
	
	if(list->head == NULL){
		list->head = new_temp;
		return list->head;
	}
	
	temp = list->head;
	
	while(temp->next != NULL){
		temp = temp->next;
	}
	
	temp->next = new_temp;
	
	return new_temp;
}

array_node *add_neighbour(graph_node *node, graph_node *neighbour){
	array_node *temp = NULL;
	
	
	if(node->neighbours == NULL){
		node->neighbours=create_arraylist();
		temp = append_node(node->neighbours,neighbour);
	}
	else{
		temp = append_node(node->neighbours,neighbour);
	}
	
	return temp;
}

array_node *find_node(arraylist *list,int id_node){
	array_node *temp = NULL;
	
	if(list == NULL){
		return NULL;
	}
	
	if(list->head == NULL){
		return NULL;
	}
	
	temp = list->head;
	
	while(temp != NULL){
		
		if(temp->node_g->id_node == id_node){
			return temp;
		}
		
		temp = temp->next;
		
	}
	
	return NULL;
}

array_node *pop_node(arraylist *list){
	array_node *temp = NULL;
	
	if(list == NULL){
		return NULL;
	}
	
	if(list->head == NULL){
		return NULL;
	}
	
	temp = list->head;
	
	list->head = temp->next;
	
	return temp;
}

/* ____________________________________________________________________________

	void dispose_nodes(array_node **node)
    
    Frees the memory occupied by an array_nodes given by the passed 'node' argument.
   ____________________________________________________________________________
*/

void dispose_array_nodes(array_node **node){
	if(*node == NULL) return;
	
	if((*node)->next != NULL) dispose_array_nodes(&(*node)->next);
	
	free(*node);
	*node = NULL;
}

/* ____________________________________________________________________________

	void dispose_nodes(array_node **node)
    
    Frees the memory occupied by all nodes given by the passed 'node' argument.
   ____________________________________________________________________________
*/

void dispose_array_and_graph_nodes(array_node **node){
	if(*node == NULL) return;
	
	dispose_graph_node(&(*node)->node_g);
	if((*node)->next != NULL) dispose_array_and_graph_nodes(&(*node)->next);
		
	free(*node);
	*node = NULL;
}


/* ____________________________________________________________________________

	void dispose_neighbourlist(arraylist **list)
    
    Frees the memory occupied by an neighbourlist and it's nodes given by the passed 'list' argument.
   ____________________________________________________________________________
*/

void dispose_neighbourlist(arraylist **list){
	if(*list == NULL) return;
	
	if((*list)->head != NULL) dispose_array_nodes(&(*list)->head);
	
	free(*list);
	*list = NULL;
}

/* ____________________________________________________________________________

	void dispose_arraylist(arraylist **list)
    
    Frees the memory occupied by an arraylist and it's nodes given by the passed 'list' argument.
   ____________________________________________________________________________
*/

void dispose_arraylist(arraylist **list){
	if(*list == NULL) return;
	
	if((*list)->head != NULL) dispose_array_and_graph_nodes(&(*list)->head);
	
	free(*list);
	*list = NULL;
}

void print_list(arraylist *list){
	array_node *temp = NULL;
	
	if(list == NULL) return;
	if(list->head == NULL) return;
	
	temp = list->head;
	
	while(temp != NULL){
		printf("%i",temp->node_g->id_node);
		temp = temp->next;
	}
	printf("\n");
}
