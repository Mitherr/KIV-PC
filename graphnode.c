#include <stdlib.h>
#include <stdio.h>
#include "graphnode.h"
#include "arraylist.h"

/* ____________________________________________________________________________

   	graph_node *create_graph_node(int id_node)
    
    Creates node that represents one node of a graph wich contains it's id and
    list of it's neighbours. Id is passe by argument 'id_node' and neigbours list
    is NULL when node is created.
   ____________________________________________________________________________
*/

graph_node *create_graph_node(int id_node){
	graph_node *temp = NULL;
	
	temp = (graph_node *) malloc(sizeof(graph_node));
	
	temp->id_node = id_node;
	temp->neighbours = NULL;
	
	return temp;	
}

/* ____________________________________________________________________________

   	void dispose_node(graph_node **node)
    
    Frees the memory occupied by a node(id,arraylist neighbours) given by the passed 'node' argument.
   ____________________________________________________________________________
*/

void dispose_graph_node(graph_node **node){
	if(*node == NULL) return;
	
	if((*node)->neighbours != NULL) dispose_neighbourlist(&(*node)->neighbours);
	
	free(*node);
	*node = NULL;
}
