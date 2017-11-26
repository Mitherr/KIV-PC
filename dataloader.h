#ifndef _DATALOADER_H
#define _DATALOADER_H

#include "graph.h"

/* ____________________________________________________________________________

    Preprocessor-defined Symbols
   ____________________________________________________________________________
*/

#define MAX_NUMBER_OF_CHARS_ON_LINE 34

/* ____________________________________________________________________________

    Function Prototypes
   ____________________________________________________________________________
*/

graph_list *load_graph_from_file(char *file_name);

#endif
