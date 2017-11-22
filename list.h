#ifndef _LIST_H
#define _LIST_H

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
}list;

/* ____________________________________________________________________________

    Function Prototypes
   ____________________________________________________________________________
*/

graph_node *create_graph_node(int id_node);
list_graph_node *create_list_graph_node(graph_node *node);
list *create_list();
list_graph_node *append_node_list_start(list *list_n,graph_node *node);
list_graph_node *append_node_list_end(list *list_n,graph_node *node);
graph_node *pop_node_list(list *list_n);
graph_node *find_graph_node(list *list_n,int id_node);
void dispose_graph_node(graph_node **node);
void dispose_list_graph_nodes(list_graph_node **node);
void dispose_list(list **list_n);

void print_list(list *list);

#endif
