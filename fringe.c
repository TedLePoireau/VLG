/*
 * Fringe Search
 * by Nicolas DURAN & Rodolphe GUITTENY
 * Project VLG
 * EPITA
 */

#include "utils.h"
#include "prelim.h"
#include "diam.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <time.h>

#define QUEUE_SIZE 2000000

/* Our heuristic is based on the degree of the node */
int heuristic(int node)
{
	return 4;
}

LLIST* fringe(graph* g, int start, int end)
{
	clock_t begin_t = clock();
	printf("FRINGE : START (TIME %lf)\n", (double)begin_t/CLOCKS_PER_SEC);
	/* Error check */
	if (start < 0)
		report_error("Start node must be positive");
        if (end < 0)
		report_error("End node must be positive");
	if (start > g->n)
		report_error("Start node bigger than number of node in Graph");
	if (end > g->n)
		report_error("End node bigger than number of node in Graph");

	int node, deg, score = 0, i;
	char found = 0;
	int thresold = 100;
	//min known cost for a node
	int* cost = (int*) malloc(sizeof (int) * g->n);
	//precedence list
	int* pred = (int*) malloc(sizeof (int) * g->n);
	for (i = 0; i < g->n;  i++)
	{
		cost[i] = INT_MAX;
		pred[i] = -1;
	}

	LLIST* path = NULL;

	//Fringe queues
	queue* now = empty_queue(QUEUE_SIZE);
	queue* later = empty_queue(QUEUE_SIZE);

	queue_add(now, start);
	cost[start] = 0;

	while (	(!is_empty_queue(now)
		|| !is_empty_queue(later))
		&& !found)
	{
		if (is_empty_queue(now))
		{
			free_queue(now);
			now = later;
			later = empty_queue(QUEUE_SIZE);
			thresold += 100;
		}

		node = queue_get(now);
		deg = g->degrees[node];

		for (i = 0; i < deg; i++)
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
				if (score > thresold)
					queue_add(later, son);
				else
					queue_add(now, son);
			}

		}

	}
	clock_t end_t = clock();
	printf("FRINGE : END (TIME %lf)\n", (double)end_t/CLOCKS_PER_SEC);
	printf("FRINGE : Algorithm lasted %lf second(s)\n", (double)(end_t - begin_t)/CLOCKS_PER_SEC);

	path = llist_add(path, end);
    	i = end;
    	while (i != start)
    	{
                path = llist_add(path, pred[i]);
                i = pred[i];
    	}
	printf("Path found : ");
	llist_print(path);

	return path;
}
