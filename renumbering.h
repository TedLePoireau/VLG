#ifndef RENUMBERING_H
#define RENUMBERING_H

#include "diam.h"
#include "prelim.h"
/* reordering from BFS */
void BFS(graph *g, int **tmppp, int* tmpp, int* tmpc, int* neworder, int *marked, int targetvert, int MAX);
void BFS_second(graph *g, int *neworder, int *marked, int targetvert, int MAX, int* newcoord);
void renumbering_from_BFS(graph *g, int x);

#endif
