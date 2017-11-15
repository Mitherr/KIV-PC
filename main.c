#include <stdio.h>
#include <stdlib.h>
#include "graphnode.h"
#include "arraylist.h"
#include "comparator.h"
#include "search.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	arraylist *list = create_arraylist();
	
	graph_node *g1 = create_graph_node(1);
	graph_node *g2 = create_graph_node(2);
	graph_node *g3 = create_graph_node(3);
	graph_node *g4 = create_graph_node(4);
	graph_node *g5 = create_graph_node(5);
	graph_node *g6 = create_graph_node(6);
	graph_node *g7 = create_graph_node(7);
	graph_node *g9 = create_graph_node(9);
	
	append_node(list,g1);
	append_node(list,g2);
	append_node(list,g3);
	append_node(list,g4);
	append_node(list,g5);
	append_node(list,g6);
	append_node(list,g7);
	append_node(list,g9);
	
	array_node *h1 = add_neighbour(g1,g2);
	set_date(h1,"2007-02-16");
	array_node *h2 = add_neighbour(g1,g2);
	set_date(h2,"2008-02-15");
	array_node *h3 = add_neighbour(g1,g3);
	set_date(h3,"2007-10-26");
	array_node *h4 = add_neighbour(g1,g4);
	set_date(h4,"2007-10-30");
	array_node *h5 = add_neighbour(g3,g2);
	set_date(h5,"2007-10-11");
	array_node *h6 = add_neighbour(g3,g6);
	set_date(h6,"2007-06-04");
	array_node *h7 = add_neighbour(g3,g7);
	set_date(h7,"2007-08-14");
	array_node *h8 = add_neighbour(g3,g9);
	set_date(h8,"2008-03-05");
	array_node *h9 = add_neighbour(g4,g2);
	set_date(h9,"2007-10-05");
	array_node *h10 = add_neighbour(g5,g1);
	set_date(h10,"2007-02-04");
	
	find_paths(list,1,2,3);
		
	dispose_arraylist(&list);
	
	return 0;
}
