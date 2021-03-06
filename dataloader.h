/*
    DFS

    Module dataloader.h
    For detailed description see dataloader.c

*/

#ifndef _DATALOADER_H
#define _DATALOADER_H

#include "graph.h"
#include "neighbours.h"

/* ____________________________________________________________________________

    Preprocessor-defined Symbols
   ____________________________________________________________________________
*/

#define MAX_NUMBER_OF_CHARS_ON_LINE 36
#define DELIM ";"

/* ____________________________________________________________________________

    Function Prototypes
   ____________________________________________________________________________
*/

graph_list *load_graph_from_file(char *file_name);
static edge_node *load_edge_node(graph_node *from,graph_node *to,char *token);
static graph_node *load_graph_node(graph_list *graph,char *token);

#endif
