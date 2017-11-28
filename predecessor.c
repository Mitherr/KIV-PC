/*
    DFS

    Module predecessor.c
    This module creates list of predecessors wich represents predecessors in graph during search.
    And also contains all functions to work with the list and dispose it.

*/

#include <stdio.h>
#include <stdlib.h>
#include "predecessor.h"

/* ____________________________________________________________________________

   	predecessor_node *create_predecessor(int id_predecessor,date *d,predecessor_node *predecessors)
    
    Creates node that represents one predecessor. This node containes pointer on It's predecessor, his id and
    weight on the edge between them.
    
    returns:
    predecessor_node if succeed
    NULL if fails
   ____________________________________________________________________________
*/

predecessor_node *create_predecessor(int id_predecessor,date *d,predecessor_node *predecessors){
	predecessor_node *temp = NULL;
	
	if(d == NULL || predecessors == NULL) return;
	
	temp = (predecessor_node *) malloc(sizeof(predecessor_node));
	if(temp == NULL){
		printf("Out of memory (predecessor_node)\n");
		return NULL;
	}
	
	temp->id_node = id_predecessor;
	temp->previous_path = predecessors;
	temp->d = d;	
	temp->next = NULL;
	
	return temp;
}

/* ____________________________________________________________________________

   	predecessor_node *create_first_predecessor(int id_predecessor,date *d,predecessor_node *predecessors)
    
    Creates node that represents first predecessor. First predecessor has only id of a node we start our search from.
    
    returns:
    predecessor_node if succeed
    NULL if fails
   ____________________________________________________________________________
*/

predecessor_node *create_first_predecessor(int id_predecessor){
	predecessor_node *temp = NULL;
	
	temp = (predecessor_node *) malloc(sizeof(predecessor_node));
	if(temp == NULL){
		printf("Out of memory (predecessor_node)\n");
		return NULL;
	}
	
	temp->id_node = id_predecessor;
	temp->previous_path = NULL;
	temp->d = NULL;	
	temp->next = NULL;
	
	return temp;
}

/* ____________________________________________________________________________

   	predecessors *create_predecessors(int id_node)
    
    Creates predecessors that represents all predecessors of one node in a graph and It only contains id of that node in graph.
    
    returns:
    predecessors if succeed
    NULL if fails
   ____________________________________________________________________________
*/

predecessors *create_predecessors(int id_node){
	predecessors *temp = NULL;
	predecessor_node *new_node = NULL;
	
	temp = (predecessors *) malloc(sizeof(predecessors));
	if(temp == NULL){
		printf("Out of memory (predecessors)\n");
		return NULL;
	}
	
	temp->id_node = id_node;
	temp->predecessor = NULL;
	temp->next = NULL;
	
	return temp;
}

/* ____________________________________________________________________________

    predecessors_list *create_predecessors_list()
    
    Creates predecessors_list that represents list of all predecessors (list of predecessor_node of all nodes we found) in a graph.
    
    returns:
    predecessors_list if succeed
    NULL if fails
   ____________________________________________________________________________
*/

predecessors_list *create_predecessors_list(){
	predecessors_list *temp = NULL;
	
	temp = (predecessors_list *) malloc(sizeof(predecessors_list));
	if(temp == NULL){
		printf("Out of memory (predecessors_list)");
		return NULL;
	}
	
	temp->head = NULL;
	
	return temp;
}

/* ____________________________________________________________________________

    void append_predecessor_predecessors(predecessors *predecessors,predecessor_node *node)
    
   	Append predecessor_node passed by an argument node to a predecessors(list of predecessor_node of one node in a graph) passed by and argument predecessors).
   ____________________________________________________________________________
*/

void append_predecessor_predecessors(predecessors *predecessors,predecessor_node *node){
	predecessor_node *temp = NULL;
	
	if(predecessors == NULL || node == NULL) return;
	
	if(predecessors->predecessor == NULL){
		predecessors->predecessor = node;
		return;
	}

	node->next = predecessors->predecessor;
	predecessors->predecessor = node;
}

/* ____________________________________________________________________________

    void append_predecessor_predecessors(predecessors *predecessors,predecessor_node *node)
    
   	Append predecessors passed by an argument predecessors_l to a predecessors_list passed by and argument list_pr.
   ____________________________________________________________________________
*/

void append_predecessors_predecessors_list(predecessors_list *list_pr,predecessors *predecessors_l){
	predecessors *temp = NULL;
	
	if(list_pr == NULL || predecessors_l == NULL) return;
	
	if(list_pr->head == NULL){
		list_pr->head = predecessors_l;
		return;
	}
	
	temp = list_pr->head;
	
	while(temp->next != NULL){
		temp = temp->next;
	}
	
	temp->next = predecessors_l;
}

/* ____________________________________________________________________________

    predecessors *find_predecessors_in_list(predecessors_list *list_pr,int id_node)
    
   	Searches if predecessors_list passed by an argument list_pr for predecessors that has id passed by an argument id_node
   	
   	returns:
   	predecessors if succeed
   	NULL if fails
   ____________________________________________________________________________
*/

predecessors *find_predecessors_in_list(predecessors_list *list_pr,int id_node){
	predecessors *temp = NULL;	

	if(list_pr == NULL) return NULL;
	
	temp = list_pr->head;
	
	while(temp != NULL){
	if(temp->id_node == id_node){
		return temp;	
	}
	temp = temp->next;
	}
	
	return NULL;
}

/* ____________________________________________________________________________

    int predeccesor_contains_id(predecessor_node *node,int id_node)
    
   	Searches if predecessor_node predecessors(pointer previous_path) contains predecessor_node with it passed by and argument id_node. 
   	
   	returns:
   	1 if succeed
   	0 if fails
   ____________________________________________________________________________
*/

int predeccesor_contains_id(predecessor_node *node,int id_node){
	predecessor_node *temp = NULL;
	
	if(node == NULL) return;
	
	temp = node->previous_path;
	
	while(temp != NULL){
		if(temp->id_node == id_node){
			return 1;
		}
		temp = temp->previous_path;
	}
	
	return 0;
}

/* ____________________________________________________________________________

  	void print_predecessors_list(predecessors_list *list_pr)
    
    Prints id of all predecessors contained in a list passed by an argument list_pr. (debug reasons only)
   ____________________________________________________________________________
*/

void print_predecessors_list(predecessors_list *list_pr){
	predecessors *temp = NULL;
	predecessor_node *temp2 = NULL;
	
	if(list_pr == NULL) return;
	if(list_pr->head == NULL) return;
	
	temp = list_pr->head;
	while(temp != NULL){
		printf("%i",temp->id_node);
		temp = temp->next;
	}
	printf("-closed\n");
}

/* ____________________________________________________________________________

  	void print_previous_path(predecessor_node *node)
    
    Prints id of all predecessor_nodes contained in a list (previous_path) passed by an argument node. (debug reasons only)
	Basicly prints out a path from node to start node of a search.
   ____________________________________________________________________________
*/

void print_previous_path(predecessor_node *node){
	predecessor_node *temp = NULL;
	
	if(node == NULL) return;
	
	printf("%i",node->id_node);
	
	temp = node->previous_path;
	
	while(temp != NULL){
		printf("-%i",temp->id_node);
		temp = temp->previous_path;
	}
	
	printf(" -path\n");
}

/* ____________________________________________________________________________

  	void print_predecessors_predecessor(predecessors_list *list_pr)
    
    Prints id of all predecessors in a list with id of all predecessor_node they have. (debug reasons only)
   ____________________________________________________________________________
*/

void print_predecessors_predecessor(predecessors_list *list_pr){
	predecessors *temp = NULL;
	predecessor_node *temp2 = NULL;
	
	if(list_pr == NULL) return;
	if(list_pr->head == NULL) return;
	
	temp = list_pr->head;
	while(temp != NULL){
		temp2 = temp->predecessor;
		printf("%i(",temp->id_node);
		while(temp2 != NULL){
			if(temp2->previous_path != NULL){
			printf("-%i",temp2->previous_path->id_node);
			}
			temp2 = temp2->next;
		}
		printf(")");
		temp = temp->next;
	}
	printf(" -predecessors\n");
}

/* ____________________________________________________________________________

  	void dispose_predecessor_node(predecessor_node **node)
    
    Dispose memory occupied by a predecessor_node her neighbours in list recursively.
   ____________________________________________________________________________
*/

void dispose_predecessor_node(predecessor_node **node){
	if(*node == NULL) return;

	if(&(*node)->next != NULL) dispose_predecessor_node(&(*node)->next);
	
	free(*node);
	*node = NULL;
}

/* ____________________________________________________________________________

  	void dispose_predecessors(predecessors **predecessors_l)
    
    Dispose memory occupied by a predecessors her neighbours in list recursively.
   ____________________________________________________________________________
*/

void dispose_predecessors(predecessors **predecessors_l){
	if(*predecessors_l == NULL) return;
	
	if(&(*predecessors_l)->predecessor != NULL) dispose_predecessor_node(&(*predecessors_l)->predecessor);
	if(&(*predecessors_l)->next != NULL) dispose_predecessors(&(*predecessors_l)->next);
	
	free(*predecessors_l);
	*predecessors_l = NULL;
}

/* ____________________________________________________________________________

  	void dispose_predecessors_list(predecessors_list **list_pr)
    
    Dispose memory occupied by a predecessor_list list.
   ____________________________________________________________________________
*/

void dispose_predecessors_list(predecessors_list **list_pr){
	if(*list_pr == NULL) return;

	if(&(*list_pr)->head != NULL) dispose_predecessors(&(*list_pr)->head);

	free(*list_pr);
	*list_pr = NULL;	
}
