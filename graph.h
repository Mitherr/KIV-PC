#ifndef _GRAPH_H
#define _GRAPH_H

/* ____________________________________________________________________________

    Structures and Datatypes
   ____________________________________________________________________________
*/

typedef struct GRAPHNODE{
	int id_node;
	struct EDGES *neighbours;
}graph_node;

typedef struct LISTNODE{
	struct GRAPHNODE *graph_node;
	struct LISTNODE *next;
}list_graph_node;

typedef struct list{
	struct LISTNODE *head;
}graph_list;

/* ____________________________________________________________________________

    Function Prototypes
   ____________________________________________________________________________
*/

graph_node *create_graph_node(int id_node);
list_graph_node *create_list_graph_node(graph_node *node);
graph_list *create_graph_list();
list_graph_node *append_node_list_end(graph_list *graph,graph_node *node);
graph_node *pop_node_graph_list(graph_list *graph);
graph_node *find_graph_node(graph_list *list_n,int id_node);
void print_graph(graph_list *list);
void dispose_graph_node(graph_node **node);
void dispose_list_graph_nodes(list_graph_node **node);
void dispose_graph_list(graph_list **graph);

#endif
