/*
    DFS

    Module neighbours.c
    This module creates list of edge_nodes wich represents edges in graph we want to search in.
    And also contains all functions to work with the list and dispose it.
    
*/

#include <stdio.h>
#include <stdlib.h>
#include "neighbours.h"
#include "graph.h"
#include "date.h"

/* ____________________________________________________________________________

   	edge_node *create_edge_node(graph_node *node,char *date_s)
    
    Creates node that represents one edge of a graph wich contains.
    Pointer of a graph_node on the end of an edge and its weight (date).
    
    returns:
    graph_node if succeed
    NULL if fails
   ____________________________________________________________________________
*/

edge_node *create_edge_node(graph_node *node,char *date_s){
	edge_node *temp = NULL;
	date *temp_d = NULL;
	
	if(node == NULL || date_s == NULL) return NULL;
	
	temp = (edge_node*) malloc(sizeof(edge_node));
	if(temp == NULL){
		printf("Out of memory (edge_node)\n");
		return NULL;
	}
	
	temp_d = create_date_from_str(date_s);
	if(temp_d == NULL){
		free(temp);
		return NULL;
	}
	
	temp->date = temp_d;
	temp->graph_node = node;
	temp->next = NULL;
	
	return temp;
}

/* ____________________________________________________________________________

   	edges *create_edges()
    
    Creates list that represents edges of a node in graph;
    
    returns:
    edges if succeed
    NULL if fails
   ____________________________________________________________________________
*/

edges *create_edges(){
	edges *temp = NULL;
	
	temp = (edges *) malloc(sizeof(edges));
	if(temp == NULL){
		printf("Out of memory (edges)\n");
		return NULL;
	}
	
	temp->head = NULL;
	
	return temp;
}

/* ____________________________________________________________________________

   	void *append_edge_edges(edges *edges_l,edge_node *edg_n)
    
    Append edge_node to an existing edges_list
   ____________________________________________________________________________
*/

void append_edge_edges(edges *edges_l,edge_node *edg_n){
	edge_node *temp = NULL;
	
	if(edges_l == NULL || edg_n == NULL) return;
	
	if(edges_l->head == NULL){
		edges_l->head = edg_n;
		return;
	}
	
	temp = edges_l->head;
	
	while(temp->next != NULL){
		temp = temp->next;
	}
	
	temp->next = edg_n;
}

/* ____________________________________________________________________________

  	void dispose_edge(edge_node **edge_n)
    
    Dispose memory occupied by an edge in graph.
   ____________________________________________________________________________
*/

void dispose_edge(edge_node **edge_n){
	if(*edge_n == NULL) return;
	
	if((*edge_n)->date != NULL) dispose_date(&(*edge_n)->date);
	if((*edge_n)->next != NULL) dispose_edge(&(*edge_n)->next);
	
	free(*edge_n);
	*edge_n = NULL;
}

/* ____________________________________________________________________________

  	void dispose_edges(edges **edges_l)
    
    Dispose memory occupied by a list of edges passed by an argument edges_l.
   ____________________________________________________________________________
*/

void dispose_edges(edges **edges_l){
	if(*edges_l == NULL) return;
	
	if((*edges_l)->head != NULL) dispose_edge(&(*edges_l)->head);
	
	free(*edges_l);
	*edges_l = NULL;
}
