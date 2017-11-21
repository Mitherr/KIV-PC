#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "date.h"
#include "predecessor.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {

	while(1){
	list *graph = create_list();
	
	graph_node *gn1 = create_graph_node(1);
	graph_node *gn2 = create_graph_node(2);
	graph_node *gn3 = create_graph_node(3);
	graph_node *gn4 = create_graph_node(4);
	graph_node *gn5 = create_graph_node(5);
	graph_node *gn6 = create_graph_node(6);
	graph_node *gn7 = create_graph_node(7);
	graph_node *gn9 = create_graph_node(9);
	
	
	append_node_list_end(graph,gn1);
	append_node_list_end(graph,gn2);
	append_node_list_end(graph,gn3);
	append_node_list_end(graph,gn4);
	append_node_list_end(graph,gn5);
	append_node_list_end(graph,gn6);
	append_node_list_end(graph,gn7);
	append_node_list_end(graph,gn9);
	
	edge_node *e1 = create_edge_node(gn2,"2007-02-16");
	append_neighbour(gn1,e1);
	edge_node *e1o = create_edge_node(gn1,"2007-02-16");
	append_neighbour(gn2,e1o);
	set_opposite_edge(e1,e1o);
	
	edge_node *e2 = create_edge_node(gn2,"2008-02-15");
	append_neighbour(gn1,e2);
	edge_node *e2o = create_edge_node(gn1,"2008-02-15");
	append_neighbour(gn2,e2o);
	set_opposite_edge(e2,e2o);
	
	edge_node *e3 = create_edge_node(gn3,"2007-10-26");
	append_neighbour(gn1,e3);
	edge_node *e3o = create_edge_node(gn1,"2007-10-26");
	append_neighbour(gn3,e3o);
	set_opposite_edge(e3,e3o);
	
	edge_node *e4 = create_edge_node(gn4,"2007-10-30");
	append_neighbour(gn1,e4);
	edge_node *e4o = create_edge_node(gn1,"2007-10-30");
	append_neighbour(gn4,e4o);
	set_opposite_edge(e4,e4o);
	
	edge_node *e5 = create_edge_node(gn2,"2007-10-11");
	append_neighbour(gn3,e5);
	edge_node *e5o = create_edge_node(gn3,"2007-10-11");
	append_neighbour(gn2,e5o);
	set_opposite_edge(e5,e5o);
		
	edge_node *e6 = create_edge_node(gn6,"2007-06-04");
	append_neighbour(gn3,e6);
	edge_node *e6o = create_edge_node(gn3,"2007-06-04");
	append_neighbour(gn6,e6o);
	set_opposite_edge(e6,e6o);
	
	edge_node *e7 = create_edge_node(gn7,"2007-08-14");
	append_neighbour(gn3,e7);
	edge_node *e7o = create_edge_node(gn3,"2007-08-14");
	append_neighbour(gn7,e7o);
	set_opposite_edge(e7,e7o);
	
	edge_node *e8 = create_edge_node(gn9,"2008-03-05");
	append_neighbour(gn3,e8);
	edge_node *e8o = create_edge_node(gn3,"2008-03-05");
	append_neighbour(gn9,e8o);
	set_opposite_edge(e8,e8o);
	
	edge_node *e9 = create_edge_node(gn2,"2007-10-05");
	append_neighbour(gn4,e9);
	edge_node *e9o = create_edge_node(gn4,"2007-10-05");
	append_neighbour(gn2,e9o);
	set_opposite_edge(e9,e9o);
		
	edge_node *e10 = create_edge_node(gn1,"2007-02-04");
	append_neighbour(gn5,e10);
	edge_node *e10o = create_edge_node(gn5,"2007-02-04");
	append_neighbour(gn1,e10o);
	set_opposite_edge(e10,e10o);

	remove_edge_edges(gn5->neighbours,e10o);


//	search_paths_dfs(graph,1,3);

	dispose_list(&graph);	
}
	
	return 0;
}
