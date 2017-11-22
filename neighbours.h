#ifndef _NEIGHBOURS_H
#define _NEIGHBOURS_H

#include "list.h"

/* ____________________________________________________________________________

    Structures and Datatypes
   ____________________________________________________________________________
*/

typedef struct EDGENODE{
	struct GRAPHNODE *graph_node;
	struct DATE *date;
	struct EDGENODE *next;
}edge_node;

typedef struct EDGES{
	struct EDGENODE *head;
}edges;

/* ____________________________________________________________________________

    Function Prototypes
   ____________________________________________________________________________
*/

edge_node *create_edge_node(graph_node *node,char *date_s);
edges *create_edges();
void *append_edge_edges(edges *edges_l,edge_node *edg_n);
edge_node *pop_edge_edges(edges *edges_l);
void append_neighbour(graph_node *node,edge_node *edg_n);
void dispose_single_edge(edge_node **edge_n);
void dispose_edge(edge_node **edge_l);
void dispose_edges(edges **edges_l);


#endif
