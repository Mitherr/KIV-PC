/*
    DFS

    Module graph.h
    For detailed description see graph.c

*/

#ifndef _GRAPH_H
#define _GRAPH_H

/* ____________________________________________________________________________

    Structures and Datatypes
   ____________________________________________________________________________
*/

typedef struct GRAPHNODE{
	int id_node;
	struct EDGES *neighbours;
	struct GRAPHNODE *next;
}graph_node;

typedef struct list{
	struct GRAPHNODE *head;
}graph_list;

/* ____________________________________________________________________________

    Function Prototypes
   ____________________________________________________________________________
*/

graph_node *create_graph_node(int id_node);
graph_list *create_graph_list();
void append_node_list_end(graph_list *graph,graph_node *node);
graph_node *find_graph_node(graph_list *graph,int id_node);
void print_graph(graph_list *list);
void dispose_graph_node(graph_node **node);
void dispose_graph_list(graph_list **graph);

#endif
