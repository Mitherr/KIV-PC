/*
    DFS

    Module main.c
    This module composes all the parts of the search together and is also responsible for the user interaction.

*/

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "date.h"
#include "predecessor.h"
#include "dataloader.h"

/* ____________________________________________________________________________

    int *check_parameters(char *arg1,char *arg2,char *arg3)
    
    Checks arguments passed from command line.
    
    returns:
    int array of arguments when everythings all right
    NULL when arguments are invalid
   ____________________________________________________________________________
*/

int *check_parameters(char *arg1,char *arg2,char *arg3){
	int *arguments = (int *) malloc(3*sizeof(int));
	int error = 0;
	
	arguments[0] = atoi(arg1);
	if(arguments[0] == 0){
		error = 1;
		printf("Wrong Parameter!\nArgument 2 should be a number\n");
	}
	
	arguments[1] = atoi(arg2);
	if(arguments[1] == 0){
		error = 1;
		printf("Wrong Parameter!\nArgument 3 should be a number\n");
	}
	
	arguments[3] = atoi(arg3);
	if(arguments[3] == 0){
		error = 1;
		printf("Wrong Parameter!\nArgument 4 should be a number\n");
	}
	
	if(error == 1){
		free(arguments);
		return NULL;
	}
	
	return arguments;
}

/* ____________________________________________________________________________

    print_help()
    
    Prints informations about what parameters should be passed when programme is started.
   ____________________________________________________________________________
*/

void print_help(){
	printf("Incorrect number of arguments\nProgram expects 4 parameters:\nFirst parameter is name of file with a structure of a graph.\n");
	printf("Second parameter is number(id) of node from wich you want to search.\nThird parameter is number(id) of node you search your path to\n");
	printf("Fourth parameter is number that represents depth of a search\n");
	printf("For example: dfs.exe graph.csv 1 2 4");
}

int main(int argc, char *argv[]) {
	int *arguments;
	
	if(argc != 5){
		print_help();
	}
	else{
	arguments = check_parameters(argv[2],argv[3],argv[4]);
	if(arguments == NULL){
		return -1;
	}
	
	graph_list *graph = load_graph_from_file(argv[1]);
	
	if(graph == NULL){
		printf("There was an error during loading your graph.\n");
		return -1;
	}

	search_paths_dfs(graph,arguments[0],arguments[1],arguments[2]);
	
	free(arguments);
	dispose_graph_list(&graph);	
	}
	
	return 0;
}
