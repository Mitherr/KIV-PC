#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "date.h"
#include "predecessor.h"
#include "dataloader.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	graph_list *graph = load_graph_from_file("graph.csv");

	search_paths_dfs(graph,1,2,5);

	dispose_list(&graph);
	
	return 0;
}
