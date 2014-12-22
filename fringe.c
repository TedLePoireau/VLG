/* 
 * Fringe Search 
 * by Nicolas DURAN & Rodolphe GUITTENY 
 * Project VLG
 * EPITA
 */

#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define QUEUE_SIZE 10000

/* Our heuristic is based on the degree of the node */
int heuristic(int node)
{

}

LLIST* fringe(graph* g, int start, int end)
{
	/* Error check */
	if (start < 0)
		report_error("Start node must be positive");	
        if (end < 0)	
		report_error("End node must be positive");	
	if (start > g->n)
		report_error("Start node bigger than number of node in Graph");	
	if (end > g->n)
		report_error("End node bigger than number of node in Graph");	

	//min known cost for a node
	int* costs = (int*) malloc(sizeof (int) * g->n);
	//precedence list
	int* pred = (int*) malloc(sizeof (int) * g->n);
	for (i = 0; i < g->n;  i++)
	{
		costs[i] = INT_MAX;
		pred[i] = -1;
	}

	LLIST* path;
	
	//Fringe queues
	queue* now = empty_queue(QUEUE_SIZE);
	queue* later = empty_queue(QUEUE_SIZE);
	
	int node, deg, score = 0, i;
	queue_add(now, start);
	costs[start] = 0;

	while (	!is_empty_queue(now)
		&& !is_empty_queue(later)
		&& !found)
	{
		if (is_empty_queue(now))
		{
			free_queue(now);
			now = later;
			later = empty_queue(QUEUE_SIZE);
		}

		node = queue_get(now);
		deg = g->degree[node];

		for (int i = 0; i < deg; i++)
		{
			int son = g->links[node][i];
			
			if (son == end)
			{
				pred[end] = node;
				found = 1;	
			}
			score = cost[node] + heuristic(son);
			if (score < cost[son])
			{
				cost[son] = score;
				pred[son] = node;
			}
			if (score > thresold)
				queue_add(later, node);
			else
				queue_add(now, node);
			
		}
		
	}
}
