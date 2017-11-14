#include <stdlib.h>
#include <stdio.h>
#include "arraylist.h"
#include "search.h"

void find_paths_rec(arraylist *open,arraylist *closed){
	array_node *temp = NULL;
	array_node *temp2 = NULL;
	
	if(open->head != NULL){
		temp = pop_node(open);
		append_node(closed,temp->node_g);
		
		do{
		temp2 = pop_node(temp->node_g->neighbours);
		append_node(open,temp2->node_g);
		}while(temp2->next != NULL);
		
		print_list(open);
		print_list(closed);
}

void find_paths(arraylist *graph,int id_node_start,int id_node_end){
	arraylist *open = NULL;
	arraylist *closed = NULL;
	array_node *start = NULL;
	array_node *end = NULL;
	
	start = find_node(graph,id_node_start);
	
	if(start == NULL){
		return;
	}
	
	end = find_node(graph,id_node_end);
	
	open = create_arraylist();
	closed = create_arraylist();
	
	append_node(open,start->node_g);
	
	find_paths_rec(open,closed);
	
	dispose_neighbourlist(&open);
	dispose_neighbourslist(&closed);
}

}
