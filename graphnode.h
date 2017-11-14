#ifndef _GRAPHNODE_H
#define _GRAPHNODE_H
/* ____________________________________________________________________________

    Structures and Datatypes
   ____________________________________________________________________________
*/

typedef struct GRAPHNODE{
	int id_node;
	struct ARRAYLIST *neighbours;
}graph_node;

/* ____________________________________________________________________________

    Function Prototypes
   ____________________________________________________________________________
*/
graph_node *create_graph_node(int id_node);
void dispose_graph_node(graph_node **node);

#endif
