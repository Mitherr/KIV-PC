/*
    DFS

    Module dataloader.c
    This module creates our graph by loading and parsing datas from file.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataloader.h"
#include "graph.h"
#include "neighbours.h"

/* ____________________________________________________________________________

   	graph_list *load_graph_from_file(char *file_name)
    
    Creates a graph by loading and parsing data from file. Name of file is passed by an argument file_name;
    MAX_NUMBER_OF_CHARS_ON_LINE is 36 (2x(integer)(22 chars),yyyy-mm-dd(10 chars),2x(;) (2chars), newline(2chars) format)
    
    returns:
    graph_list if succeed
    NULL if fails
   ____________________________________________________________________________
*/

graph_list *load_graph_from_file(char *file_name){
	FILE *fp;
	char str[MAX_NUMBER_OF_CHARS_ON_LINE];
	char *token;
	graph_list *graph;
	graph_node *temp1;
	graph_node *temp2;
	int temp_number1;
	int temp_number2;
	int error = 0;
	edge_node *temp_e1;
	edge_node *temp_e2;
	
	
	if(file_name == NULL) return NULL;
	
	fp = fopen(file_name,"r");
	
	if(fp == NULL){
		printf("File not found!\n");
		return NULL;
	}
	
	graph = create_graph_list();
	if(graph == NULL){
		return NULL;
	}
	
	while(fgets (str, MAX_NUMBER_OF_CHARS_ON_LINE, fp) != NULL){
		printf(str);
		
		token = strtok(str, DELIM);
		if(token == NULL){
			error = 1;
			break;
		}
		
		temp_number1 = atoi(token);
		
		if(temp_number1 != 0){
			
			temp1 = find_graph_node(graph,temp_number1) ;
			
			if(temp1 == NULL){
				
				temp1 = create_graph_node(temp_number1);
				
				if(temp1 == NULL){
					error = 1;
					break;
				}
				
				append_node_list_end(graph,temp1);
			}
		}
		else{
			error = 1;
			break;
		}
		
   		token = strtok(NULL, DELIM);
   		if(token == NULL){
			error = 1;
			break;
		}
		
   		temp_number2 = atoi(token);
   		
			if(temp_number2 != 0){
				
				temp2 = find_graph_node(graph,temp_number2);
					
			if(temp2 == NULL){
				
				temp2 = create_graph_node(temp_number2);
				if(temp2 == NULL){
					error = 1;
					break;
				}
								
				append_node_list_end(graph,temp2);
			}
		}
		else{
			error = 1;
			break;
		}
   		
   		token = strtok(NULL, DELIM);
   		if(token == NULL){
			error = 1;
			break;
		}
		
   		temp_e1 = create_edge_node(temp2,token);
   		if(temp_e1 == NULL){
			error = 1;
			break;
		}
		
		append_edge_edges(temp1->neighbours,temp_e1);		
		temp_e2 = create_edge_node(temp1,token);		
		if(temp_e2 == NULL){
			dispose_edge(&temp_e1);
			error = 1;
			break;
		}
		
		append_edge_edges(temp2->neighbours,temp_e2);
   }

    fclose(fp);
	
	if(error == 1){
		dispose_graph_list(&graph);
		return NULL;	
	}
	
	return graph;
}
