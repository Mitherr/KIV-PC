/*
    DFS

    Module search.h
    For detailed description see search.c

*/

#ifndef _SEARCH_H
#define _SEARCH_H

#include "stack.h"

void search_paths_dfs(graph_list *graph,int id_node_start,int id_node_end,int max_level);
static int dfs_alg(stack *open,predecessors_list *closed,int max_level);
static int append_all_valid_neighbours(stack *open, stack_node *from,predecessor_node *predecessor,int max_level);

#endif

