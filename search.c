/*
    DFS

    Module search.c
    This module composes all the parts of the search together.

*/

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "predecessors.h"
#include "neighbours.h"
#include "stack.h"
#include "paths.h"
#include "search.h"

/* ____________________________________________________________________________

  	int dfs_alg(stack *open,predecessors_list *closed,int max_level)
    
    Pops node from stack search all her neighbours. Appends to the stack the ones wich are not already contained in nodes predecessors or their level is lower than max_level.
    Id of node is added to the predecessors_list with predecessor of the node. All of this is running in cycle until our stack is empty.
   ____________________________________________________________________________
*/


int dfs_alg(stack *open,predecessors_list *closed,int max_level){
	stack_node *temp = NULL;
	stack_node *new_temp = NULL;
	predecessors *temp2 = NULL;
	predecessor_node *temp3 = NULL;
	edge_node *temp4 = NULL;
	edges *temp5 = NULL;
	int error = 0;
		
	while(open->first != NULL){
	
//	print_stack(open);
//	print_predecessors_list(closed);
//	print_predecessors_predecessor(closed);
	
	temp = pop_stack(open);
//	printf("%i-pop\n",temp->node->id_node);
	
	temp2 = find_predecessors_in_list(closed,temp->node->id_node);
	
	if(temp2 != NULL ){
		if(predeccesor_contains_id(temp->previous,temp->node->id_node) == 0){
//		printf("adding predecesor %i to %i \n",temp->previous->id_node,temp->node->id_node);
		temp3 = create_predecessor(temp->node->id_node,temp->d,temp->previous);
		if(temp3 == NULL){
			error = 1;
			break;
		}
		
		append_predecessor_predecessors(temp2,temp3);
		
		if(temp->node != NULL){
		
		if(temp->node->neighbours != NULL && temp->level < max_level){
			if(temp->node->neighbours->head != NULL){
				temp4 = temp->node->neighbours->head;
				while(temp4 != NULL){
//					printf("%i-new neighbour(level%i)\n",temp4->graph_node->id_node,temp->level +1);
					new_temp = create_stack_node(temp4->graph_node,temp4->date,temp3,temp->level + 1);
					if(new_temp == NULL){
						error = 1;
						break;
					}
					
					append_stack_node_to_stack(open,new_temp);
					temp4 = temp4->next;
				}
				if(error == 1){
					break;
				}
			}
		}
	}
			
		}
	}
	else{
		temp2 = create_predecessors(temp->node->id_node);
		if(temp2 == NULL){
			error = 1;
			break;
		}
		
		temp3 = create_predecessor(temp->node->id_node,temp->d,temp->previous);
		if(temp3 == NULL){
			dispose_predecessors(&temp2);
			error = 1;
			break;
		}
		 
		append_predecessor_predecessors(temp2,temp3);
		append_predecessors_predecessors_list(closed,temp2);
		
		if(temp->node != NULL){
	
		if(temp->node->neighbours != NULL && temp->level < max_level){
			if(temp->node->neighbours->head != NULL){
				temp4 = temp->node->neighbours->head;
				while(temp4 != NULL){
//					printf("%i-new neighbour(level%i)\n",temp4->graph_node->id_node,temp->level +1);
					new_temp = create_stack_node(temp4->graph_node,temp4->date,temp3,temp->level + 1);
					if(new_temp == NULL){
						error = 1;
						break;
					}
					
					append_stack_node_to_stack(open,new_temp);
					temp4 = temp4->next;
				}
				if(error == 1){
					dispose_stack_node(&temp);
					break;
				}
			}
		}
	}
	}
	dispose_stack_node(&temp);
	}
	
	if(error == 1){
		return -1;
	}
	else{
		return 1;
	}
}

/* ____________________________________________________________________________

  	void *search_paths_dfs(graph_list *graph,int id_node_start,int id_node_end,int max_level)
    
    This method prepares date for DFS search. Finds start_node and end_node if they exit. Then creates stack and list of predecessors needed for dfs(search).
    Gets start node from graph and appends to the stack all her neighbours. Also creates first predecessor.
    Than calls function dfs_alg with prepared stack and predecessors_list) 
   ____________________________________________________________________________
*/

void search_paths_dfs(graph_list *graph,int id_node_start,int id_node_end,int max_level){
	stack *open = NULL;
	stack_node *new_node = NULL;
	predecessors_list *closed = NULL;
	predecessors *first = NULL;
	predecessor_node *first_node = NULL;
	path_list *paths = NULL;
	graph_node *temp = NULL;
	edges *temp2 = NULL;
	edge_node *edge = NULL;
	int error = 0;
	
	
	if(graph == NULL) return;
	
	temp = find_graph_node(graph,id_node_end);
	
	if(temp == NULL) return;
	
	temp = find_graph_node(graph,id_node_start);
	
	if(temp == NULL) return;
	
	open = create_stack();
	if(open == NULL){
		return;
	}
	
	closed = create_predecessors_list();
	if(closed == NULL){
		dispose_stack(&open);
		return;
	}
	
	if(temp->neighbours == NULL){
		dispose_stack(&open);
		dispose_predecessors_list(&closed);
		return;
	}
	
	first = create_predecessors(id_node_start);
	if(first == NULL){
		dispose_stack(&open);
		dispose_predecessors_list(&closed);
		return;
	}
	
	first_node = create_first_predecessor(id_node_start);
	if(first_node == NULL){
		dispose_stack(&open);
		dispose_predecessors_list(&closed);
		return;
	}
	
	append_predecessor_predecessors(first,first_node);
	append_predecessors_predecessors_list(closed,first);
	
	if(temp->neighbours->head != NULL){
	edge = temp->neighbours->head;
	}
	
	while(edge != NULL){
		new_node = create_stack_node(edge->graph_node,edge->date,first_node,1);
		if(new_node == NULL){
			dispose_stack(&open);
			dispose_predecessors_list(&closed);
			return;
		}
		
		append_stack_node_to_stack(open,new_node);
		edge = edge->next;	
	}
	
	error = dfs_alg(open,closed,max_level);
	if(error == -1){
		printf("There was an error during path searching\n");
		dispose_predecessors_list(&closed);
		dispose_stack(&open);
		return;
	}
	
	first = find_predecessors_in_list(closed,id_node_end);
	
	paths = create_paths_from_predecessors(first);
	if(paths == NULL){
		printf("No paths found\n");
	}
	print_paths_list(paths);
	
	dispose_path_list(&paths);
	dispose_predecessors_list(&closed);
	dispose_stack(&open);
}
