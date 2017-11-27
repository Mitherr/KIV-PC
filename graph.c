/*
    DFS

    Module graph.h
    For detailed description see date.c

*/

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "neighbours.h"

/* ____________________________________________________________________________

   	graph_node *create_graph_node(int id_node)
    
    Creates node that represents one node of a graph wich contains it's id and
    list of it's neighbours. Id is passe by argument 'id_node'.
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

   	list_graph_node *create_list_graph_node(graph_node *node)
    
    Creates node that represents one node of a graph wich contains it's id and
    list of it's neighbours. Id is passe by argument 'id_node'.
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

void *append_node_list_end(graph_list *graph,graph_node *node){
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
	
	temp->next = new_temp;
	
	return new_temp;
}

graph_node *pop_node_graph_list(graph_list *graph){
	graph_node *temp = NULL;
	list_graph_node *temp2 = NULL;
	
	if(graph == NULL) return NULL;
	
	if(graph->head == NULL) return NULL;
	
	temp = graph->head->graph_node;
	temp2 = graph->head;
	 
	 if(graph->head->next != NULL){
	 	graph->head = graph->head->next;
	 	free(temp2);
	 	return temp;
	 }
	 
	graph->head = NULL;
	free(temp2);
	return temp;	
}

graph_node *find_graph_node(graph_list *graph,int id_node){
	list_graph_node *temp = NULL;
	
	if(graph == NULL) return NULL;
	
	temp = graph->head;
	
	while(temp != NULL){
		if(temp->graph_node->id_node == id_node){
			return temp->graph_node;
		}
		temp = temp->next;	
	}
	
	return NULL;
}

void print_graph(graph_list *graph){
	list_graph_node *temp = NULL;
	
	if(graph == NULL) return;
	if(graph->head == NULL) return;
	
	temp = graph->head;
	
	while(temp != NULL){
		printf("%i",temp->graph_node->id_node);
		temp = temp->next;
	}
	printf("-open\n");
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

void dispose_graph_list(graph_list **graph){
	if(*graph == NULL) return;
	
	if((*graph)->head != NULL) dispose_list_graph_nodes(&(*graph)->head);
	
	free(*graph);
	*graph = NULL;
}
