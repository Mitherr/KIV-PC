#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "predecessor.h"
#include "neighbours.h"


void dfs_rec(list *open,predecessors_list *closed,graph_node *previous_n,predecessors *previous_p){
	graph_node *temp = NULL;
	predecessors *temp2 = NULL;
	predecessor_node *temp3 = NULL;
	edge_node *temp4 = NULL;
	edges *temp5 = NULL;
	
	print_list(open);
	print_predecessors_list(closed);
	
	if(open->head == NULL){
		return;
	}
	
	temp = pop_node_list(open);
	printf("%i-pop\n",temp->id_node);
	
	temp2 = find_predecessors_in_list(closed,temp->id_node);
	
	if(temp2 != NULL){
		temp4 = pop_edge_edges(previous_n->neighbours);
		temp3 = create_predecessor(temp4->date,previous_p);
		append_predecessor_predecessors(temp2,temp3);
	}
	else{
		temp4 = pop_edge_edges(previous_n->neighbours);
		temp2 = create_predecessors(temp->id_node,temp4->date,previous_p);
		append_predecessors_predecessors_list(closed,temp2);
	
	if(temp->neighbours != NULL){
		if(temp->neighbours->head != NULL){
			temp4 = temp->neighbours->head;
			while(temp4 != NULL){
				printf("%i-new neighbour\n",temp4->graph_node->id_node);
				append_node_list_start(open,temp4->graph_node);
				temp4 = temp4->next;
			}	
		}
	}
	
	}
	
	dfs_rec(open,closed,temp,temp2);
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
	
	if(temp == NULL) return;
	
	temp = find_graph_node(graph,id_node_start);
	
	if(temp == NULL) return;
	
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
	append_predecessors_predecessors_list(closed,first);
	
	dfs_rec(open,closed,temp,first);
	
	dispose_predecessors_list(&closed);
	dispose_list(&open);
}
