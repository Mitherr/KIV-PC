#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "predecessor.h"
#include "neighbours.h"


void dfs_rec(list *open,predecessors_list *closed,graph_node *previous_n,predecessors *previous_p){
	graph_node *temp = NULL;
	predecessors *temp2 = NULL;
	edge_node *temp3 = NULL;
	
	if(open->head == NULL){
		return;
	}
	
	temp = pop_node_list(open);
	temp2 = find_predecessors_in_list(closed,temp->id_node);
	
	if(temp2 != NULL){
		//TODO
	}
	else{
		temp3 = pop_edge_edges(previous_n->neighbours);
		create_predecessors(previous_n->id_node,temp3->date,previous_p);
	}
	
}

void *search_paths_dfs(list *graph,int id_node_start,int id_node_end){
	list *open = NULL;
	predecessors_list *closed = NULL;
	predecessors *first = NULL;
	graph_node *temp = NULL;
	edges *temp2 = NULL;
	edge_node *edge = NULL;
	
	
	if(graph == NULL) return;
	
	temp = find_graph_node(graph,id_node_end);
	
	if(temp = NULL) return;
	
	temp = find_graph_node(graph,id_node_start);
	
	if(temp = NULL) return;
	
	open = create_list();
	closed = create_predecessors_list();
	
	if(temp->neighbours == NULL){
		return;
	}
	
	edge = temp->neighbours->head;
	
	while(edge != NULL){
		append_node_list_start(open,edge->graph_node);
		edge = edge->next;	
	}
	
	first = create_predecessors(id_node_start,NULL,NULL);
	
	dfs_rec(open,closed,temp,first);
	
	dispose_predecessors_list(&closed);
	dispose_list(&open);
}
