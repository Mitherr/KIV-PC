#include <stdio.h>
#include <stdlib.h>
#include "graphnode.h"
#include "arraylist.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
/*	
	while(1){
	graph_node *g1 = create_graph_node(1);
	graph_node *g2 = create_graph_node(2);
	graph_node *g3 = create_graph_node(3);
	graph_node *g4 = create_graph_node(4);
	
	arraylist *list = create_arraylist();
	append_node(list,g1);
	append_node(list,g2);
	append_node(list,g3);
	append_node(list,g4);
	
	print_list(list);
	
	dispose_arraylist(&list);
	}	
*/
	
	graph_node *g1 = create_graph_node(1);
	arraylist *list = create_arraylist();
	array_node *an = append_node(list,g1);

	set_date(an,"1996-02-05");
		
	dispose_arraylist(&list);
		
	
	return 0;
}
