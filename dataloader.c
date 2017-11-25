#include <stdio.h>
#include <string.h>
#include "dataloader.h"
#include "graph.h"
#include "neighbours.h"

#define MAX_NUMBER_OF_CHARS_ON_LINE 34

graph_list *load_graph_from_file(char *file_name){
	FILE *fp;
	char str[MAX_NUMBER_OF_CHARS_ON_LINE];
	char delim[2] = ";";
	char *token;
	graph_list *graph;
	graph_node *temp1;
	graph_node *temp2;
	int temp_number1;
	int temp_number2;
	edge_node *temp;
	
	
	if(file_name == NULL) return NULL;
	
	fp = fopen(file_name,"r");
	
	if(fp == NULL) return NULL;
	
	graph = create_graph_list();
	
	while(fgets (str, MAX_NUMBER_OF_CHARS_ON_LINE, fp) != NULL){
		token = strtok(str, delim);
		temp_number1= atoi(token);
		if(temp_number1 != 0){
		temp1 = find_graph_node(graph,temp_number1) ;
		if(temp1 == NULL){
			temp1 = create_graph_node(temp_number1);
			append_node_list_end(graph,temp1);
		}
		}
		
   		token = strtok(NULL, delim);
   		temp_number2 = atoi(token);
		if(temp_number2 != 0){
		temp2 = find_graph_node(graph,temp_number2);	
		if(temp2 == NULL){
			temp2 = create_graph_node(temp_number2);
			append_node_list_end(graph,temp2);
		}
		}
   		
   		token = strtok(NULL, delim);
   		temp = create_edge_node(temp2,token);
		append_neighbour(temp1,temp);
		temp = create_edge_node(temp1,token);
		append_neighbour(temp2,temp);
   }

   
    fclose(fp);
	
	return graph;
}
