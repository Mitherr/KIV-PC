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

   	edge_node *load_edge_node(graph_node *from,graph_node *to,char *token)
    
	Creates edge node from node "from" to node "to" with value of date in token.
	If malloc failes or date format is wrong return NULL.
    
    returns:
    edge_node if succeed
    NULL if fails
   ____________________________________________________________________________
*/

static edge_node *load_edge_node(graph_node *from,graph_node *to,char *token){
	edge_node *temp = NULL;
	
	temp = create_edge_node(to,token);
   	if(temp == NULL){
		printf("Load edge node failed\n");
		return NULL;
	}
		
	append_edge_edges(from->neighbours,temp);
	return temp;			
}

/* ____________________________________________________________________________

   	graph_node *load_graph_node(graph_list *graph,char *token)
    
    Check if token is an integer if that agrees. Search if Graf already contains node if not creates it and append to the graf.
    Else returns pointer on a graph_node found in a graph with id from token.
    
    returns:
    graph_node if succeed
    NULL if fails
   ____________________________________________________________________________
*/

static graph_node *load_graph_node(graph_list *graph,char *token){
	graph_node *temp = NULL;
	int temp_number = 0;

	temp_number = atoi(token);
		
	if(temp_number != 0){
			
		temp = find_graph_node(graph,temp_number) ;
			
		if(temp == NULL){
				
		temp = create_graph_node(temp_number);
				
		if(temp == NULL){
			printf("Load graph node failed.\n");
			return NULL;
		}
				
		append_node_list_end(graph,temp);
		return temp;
		}
	}
	return temp;
}

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
	edge_node *temp_e;
	
	
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
		
		token = strtok(str, DELIM);
   		if(token == NULL){
			error = 1;
			printf("failed on token(1) - (wrong data)\n");
			break;
		}
		
		if(!(token[0] == '\n' || token[0] == '\r')){
		
		temp1 = load_graph_node(graph,token);		
		if(temp1 == NULL){
			error = 1;
			break;	
		}
		
   		token = strtok(NULL, DELIM);
   		if(token == NULL){
			error = 1;
			printf("failed on token(2) - (wrong data)\n");
			break;
		}
		
   		temp2 = load_graph_node(graph,token);   		
   		if(temp2 == NULL){
			error = 1;
			break;	
		}
   		
   		token = strtok(NULL, DELIM);
   		if(token == NULL){
			error = 1;
			printf("failed on token(3) - (wrong data)\n");
			printf(token);
			break;
		}
		
		temp_e = load_edge_node(temp1,temp2,token);
   		if(temp_e == NULL){
			error = 1;
			break;
		}
			
		temp_e = load_edge_node(temp2,temp1,token);		
		if(temp_e == NULL){
			error = 1;
			break;
		}
		
		}	
   }

    fclose(fp);
	
	if(error == 1){
		dispose_graph_list(&graph);
		return NULL;	
	}
	
	return graph;
}
