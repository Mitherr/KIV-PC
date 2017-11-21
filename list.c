#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* ____________________________________________________________________________

   	graph_node *create_graph_node(int id_node)
    
    Creates node that represents one node of a graph wich contains it's id and
    list of it's neighbours. Id is passe by argument 'id_node' and neigbours list
    is NULL when node is created.
   ____________________________________________________________________________
*/

graph_node *create_graph_node(int id_node){
	graph_node *temp = NULL;
	
	temp = (graph_node *) malloc(sizeof(graph_node));
	
	temp->id_node = id_node;
	temp->neighbours = NULL;
	
	return temp;	
}

list_graph_node *create_list_graph_node(graph_node *node){
	list_graph_node * temp = NULL;
	
	if(node == NULL){
		return temp;
	}

	temp = (list_graph_node *) malloc(sizeof(list_graph_node));
	
	temp->graph_node = node;
	temp->next = NULL;	
	
	return temp;
}

list *create_list(){
list * temp = NULL;

temp = (list *) malloc(sizeof(list));

temp->head = NULL;

return temp;
}

list_graph_node *append_node_list_end(list *list_n,graph_node *node){
	list_graph_node *temp = NULL;
	list_graph_node *new_temp = NULL;
	
	if(list_n == NULL || node == NULL) return;
	
	new_temp = create_list_graph_node(node);
	
	if(list_n->head == NULL){
		list_n->head = new_temp;
		return list_n->head;
	}
	
	temp = list_n->head;
	
	while(temp->next != NULL){
		temp = temp->next;
	}
	
	temp->next = new_temp;
	
	return new_temp;
}

list_graph_node *append_node_list_start(list *list_n,graph_node *node){
	list_graph_node *new_temp = NULL;
	
	if(list_n == NULL || node == NULL) return;
	
	new_temp = create_list_graph_node(node);
	
	if(list_n->head == NULL){
		list_n->head = new_temp;
		return new_temp;
	}
	
	new_temp->next = list_n->head;
	list_n->head = new_temp;
	
	return new_temp;
}

graph_node *pop_node_list(list *list_n){
	graph_node *temp = NULL;
	list_graph_node *temp2 = NULL;
	
	if(list_n->head == NULL){
		return NULL;
	}
	
	temp = list_n->head->graph_node;
	temp2 = list_n->head;
	 
	 if(list_n->head->next != NULL){
	 	list_n->head = list_n->head->next;
	 	free(temp2);
	 	return temp;
	 }
	 
	list_n->head = NULL;
	free(temp2);
	return temp;
	
}

graph_node *find_graph_node(list *g,int id_node){
	list_graph_node *temp = NULL;
	
	temp = g->head;
	
	while(temp != NULL){
		if(temp->graph_node->id_node == id_node){
			return temp->graph_node;
		}
		temp = temp->next;	
	}
	return NULL;
}

void dispose_graph_node(graph_node **node){
	if(*node == NULL) return;
	
	if((*node)->neighbours != NULL) dispose_edges(&(*node)->neighbours);
	
	free(*node);
	*node = NULL;
}

void dispose_list_graph_nodes(list_graph_node **node){
	if(*node == NULL) return;
	
	if((*node)->graph_node != NULL) dispose_graph_node(&(*node)->graph_node);
	if((*node)->next != NULL) dispose_list_graph_nodes(&(*node)->next);
	
	free(*node);
	*node = NULL;
}

void dispose_list(list **list_n){
	if(*list_n == NULL) return;
	
	if((*list_n)->head != NULL) dispose_list_graph_nodes(&(*list_n)->head);
	
	free(*list_n);
	*list_n = NULL;
}
