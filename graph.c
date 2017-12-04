/*
    DFS

    Module graph.h
    This module creates list of graph_node wich represents nodes in graph we want to search in.
    And also contains all functions to work with the list and dispose it.

*/

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "neighbours.h"

/* ____________________________________________________________________________

   	graph_node *create_graph_node(int id_node)
    
    Creates node that represents one node of a graph wich contains it's id and
    list of it's neighbours. Id is passe by argument 'id_node'.
    
    returns:
    graph_node if succeed
    NULL if fails
   ____________________________________________________________________________
*/

graph_node *create_graph_node(int id_node){
	graph_node *temp = NULL;
	edges *temp_e = NULL;
	
	temp = (graph_node *) malloc(sizeof(graph_node));
	if(temp == NULL){
		printf("Out of memory (graph_node)\n");
		return NULL;
	}
	
	temp_e = create_edges();
	if(temp_e == NULL){
		free(temp);
		return NULL;
	}
	
	temp->id_node = id_node;
	temp->neighbours = temp_e;
	temp->next = NULL;
	
	return temp;	
}

/* ____________________________________________________________________________

   	graph_list *create_graph_list()
    
    Creates list that represents all nodes in graph with its neighbours (graph structure);
    
    returns:
    graph_list if succeed
    NULL if fails
   ____________________________________________________________________________
*/

graph_list *create_graph_list(){
	graph_list * temp = NULL;
	
	temp = (graph_list *) malloc(sizeof(graph_list));
	if(temp == NULL){
		printf("Out of memory (graph_list)\n");
		return NULL;
	}
	
	temp->head = NULL;
	
	return temp;
}

/* ____________________________________________________________________________

   	void *append_node_list_end(graph_list *graph,graph_node *node)
    
    appends graph_node passed by and argume node to the end of a list passed by an argument graph.
   ____________________________________________________________________________
*/

void append_node_list_end(graph_list *graph,graph_node *node){
	graph_node *temp = NULL;
	
	if(graph == NULL || node == NULL) return;
	
	if(graph->head == NULL){
		graph->head = node;
		return graph->head;
	}
	
	temp = graph->head;
	
	while(temp->next != NULL){
		temp = temp->next;
	}
	
	temp->next = node;

}

/* ____________________________________________________________________________

   	graph_node *find_graph_node(graph_list *graph,int id_node)
    
    search in a list passed by an argument graph and if it find node with id passed by an argument id_node returns its pointer.
    
    returns:
    graphnode if succeed
    NULL if fails
   ____________________________________________________________________________
*/

graph_node *find_graph_node(graph_list *graph,int id_node){
	graph_node *temp = NULL;
	
	if(graph == NULL) return NULL;
	
	temp = graph->head;
	
	while(temp != NULL){
		if(temp->id_node == id_node){
			return temp;
		}
		temp = temp->next;	
	}
	
	return NULL;
}

/* ____________________________________________________________________________

  	 void print_graph(graph_list *graph)
    
    Prints id of all nodes contained in a list passed by an argument graph. (debug reasons only)
   ____________________________________________________________________________
*/

void print_graph(graph_list *graph){
	graph_node *temp = NULL;
	
	if(graph == NULL) return;
	if(graph->head == NULL) return;
	
	temp = graph->head;
	
	while(temp != NULL){
		printf("%i",temp->id_node);
		temp = temp->next;
	}
	printf("-open\n");
}

/* ____________________________________________________________________________

  	void dispose_graph_node(graph_node **node)
    
    Dispose memory occupied by a node and her neighbours in graph and in list recursively.
   ____________________________________________________________________________
*/

void dispose_graph_node(graph_node **node){
	if(*node == NULL) return;
	
	if((*node)->neighbours != NULL) dispose_edges(&(*node)->neighbours);
	if((*node)->next != NULL) dispose_graph_node(&(*node)->next);
	
	free(*node);
	*node = NULL;
}

/* ____________________________________________________________________________

  	void dispose_graph_list(graph_list **graph)
    
    Dispose memory occupied by a list passed by an argument graph.
   ____________________________________________________________________________
*/

void dispose_graph_list(graph_list **graph){
	if(*graph == NULL) return;
	
	if((*graph)->head != NULL) dispose_graph_node(&(*graph)->head);
	
	free(*graph);
	*graph = NULL;
}
