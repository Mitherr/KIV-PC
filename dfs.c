#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "predecessor.h"
#include "neighbours.h"
#include "stack.h"


void dfs_rec(stack *open,predecessors_list *closed,int max_level){
		
	while(open->first != NULL){
	stack_node *temp = NULL;
	predecessors *temp2 = NULL;
	predecessor_node *temp3 = NULL;
	edge_node *temp4 = NULL;
	edges *temp5 = NULL;
	
	print_stack(open);
	print_predecessors_list(closed);
	print_predecessors_predecessor(closed);
	
	temp = pop_stack(open);
	printf("%i-pop\n",temp->node->id_node);
	
	temp2 = find_predecessors_in_list(closed,temp->node->id_node);
	
	if(temp2 != NULL){
		printf("adding predecesor %i to %i \n",temp->previous->id_node,temp->node->id_node);
		temp3 = create_predecessor(temp->d,temp->previous);
		append_predecessor_predecessors(temp2,temp3);
	}
	else{
		temp2 = create_predecessors(temp->node->id_node,temp->d,temp->previous);
		append_predecessors_predecessors_list(closed,temp2);
	
		if(temp->node->neighbours != NULL && temp->level < max_level){
			if(temp->node->neighbours->head != NULL){
				temp4 = temp->node->neighbours->head;
				while(temp4 != NULL){
					printf("%i-new neighbour(level%i)\n",temp4->graph_node->id_node,temp->level +1);
					temp = create_stack_node(temp4->graph_node,temp4->date,temp2,temp->level + 1);
					append_stack_node_to_stack(open,temp);
					temp4 = temp4->next;
				}
			}
		}
	}
	
	}
}

void *search_paths_dfs(list *graph,int id_node_start,int id_node_end,int max_level){
	stack *open = NULL;
	stack_node *new_node = NULL;
	predecessors_list *closed = NULL;
	predecessors *first = NULL;
	predecessor_node *lol = NULL;
	graph_node *temp = NULL;
	edges *temp2 = NULL;
	edge_node *edge = NULL;
	
	
	if(graph == NULL) return;
	
	temp = find_graph_node(graph,id_node_end);
	
	if(temp == NULL) return;
	
	temp = find_graph_node(graph,id_node_start);
	
	if(temp == NULL) return;
	
	open = create_stack();
	closed = create_predecessors_list();
	
	if(temp->neighbours == NULL){
		return;
	}
	
	first = create_predecessors(id_node_start,NULL,NULL);
	append_predecessors_predecessors_list(closed,first);
	
	edge = temp->neighbours->head;
	
	while(edge != NULL){
		new_node = create_stack_node(edge->graph_node,edge->date,first,0);
		append_stack_node_to_stack(open,new_node);
		edge = edge->next;	
	}
	
	dfs_rec(open,closed,max_level);
	
	print_predecessors_list(closed);
	print_predecessors_predecessor(closed);
	
	first = find_predecessors_in_list(closed,id_node_end);
	
	lol = first->predecessor;
	
	while(lol != NULL){
		printf("%i-%i-%i",lol->d->month,lol->d->year,lol->d->month,lol->d->day);
		lol = lol->previous_path;
	}
	
	
	dispose_predecessors_list(&closed);
	dispose_stack(&open);
}
