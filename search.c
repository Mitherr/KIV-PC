#include <stdlib.h>
#include <stdio.h>
#include "arraylist.h"
#include "search.h"

void find_paths_rec(arraylist *open,arraylist *closed,int level,int previous,int max_level){
	array_node *temp = NULL;
	array_node *temp2 = NULL;
	array_node *temp3 = NULL;
	array_node *temp4 = NULL;
	
	if(open->head == NULL){
		return;
	}
	
	if(open->head != NULL){
		temp = pop_node(open);
		temp4 = append_node(closed,temp->node_g);
		do{
		temp2 = pop_node(temp->node_g->neighbours);
		if(temp2 == NULL){
			break;
		}
		temp3 = find_node(closed,temp2->node_g->id_node);
		if(temp3 == NULL){
		if(temp->node_g->id_node != previous){
			previous = temp->node_g->id_node;
			level++;
		}
		if(level <= max_level){
		temp4 = append_node(open,temp2->node_g);
		temp4->level = level;
		temp4->previous_path = temp;
		}
		}
		}while(temp2->next != NULL);
		
		print_list(open);
		print_list(closed);
	}
	
	find_paths_rec(open,closed,level,previous,max_level);
}

void find_paths(arraylist *graph,int id_node_start,int id_node_end,int max_level){
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
	
	find_paths_rec(open,closed,0,0,max_level);
	
	dispose_neighbourlist(&open);
	dispose_neighbourlist(&closed);
}


