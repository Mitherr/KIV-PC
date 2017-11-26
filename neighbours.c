#include <stdio.h>
#include <stdlib.h>
#include "neighbours.h"
#include "graph.h"
#include "date.h"

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

void *append_edge_edges(edges *edges_l,edge_node *edg_n){
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

edge_node *pop_edge_edges(edges *edges_l){
	edge_node *temp = NULL;
	
	if(edges_l == NULL) return;
	
	temp = edges_l->head;
	
	if(edges_l->head != NULL){
		edges_l->head = temp->next;
		return temp;
	}
	
	return NULL;
}

void dispose_single_edge(edge_node **edge_n){
	if(*edge_n == NULL) return;
	
	if((*edge_n)->date != NULL) dispose_date(&(*edge_n)->date);
	
	free(*edge_n);
	*edge_n = NULL;
}

void dispose_edge(edge_node **edge_n){
	if(*edge_n == NULL) return;
	
	if((*edge_n)->date != NULL) dispose_date(&(*edge_n)->date);
	if((*edge_n)->next != NULL) dispose_edge(&(*edge_n)->next);
	
	free(*edge_n);
	*edge_n = NULL;
}

void dispose_edges(edges **edges_l){
	if(*edges_l == NULL) return;
	
	if((*edges_l)->head != NULL) dispose_edge(&(*edges_l)->head);
	
	free(*edges_l);
	*edges_l = NULL;
}
