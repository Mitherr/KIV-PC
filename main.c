#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "date.h"
#include "predecessor.h"
#include "dataloader.h"

int main(int argc, char *argv[]) {
	
	graph_list *graph = load_graph_from_file(argv[1]);
	
	if(graph == NULL){
		printf("There was an error during loading your graph either your input file does not have the correct format or you ran out of memory.");
		return -1;
	}

	search_paths_dfs(graph,1,2,4);

	dispose_graph_list(&graph);	
	
	return 0;
}
