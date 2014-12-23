#include "renum.h"
#include "prelim.h"
#include "diam.h"

graph* rand_renumber(graph* g)
{

}

graph* renumber(graph* g, int n)
{
	if (n > g->n)
		report_error("Renumber : The node doesn't exist");

	graph* new_g = malloc(sizeof(graph));
	new_g->n = g->n;
	new_g->m = g->m;	

	new_g->degrees = (int*)calloc(g->n, sizeof(int));
	new_g->capacities = (int*)malloc(g->n*sizeof(int));	
	new_g->links = (int**)malloc(g->n*sizeof(int*));
	new_g->links[0] = (int*)malloc(2*g->m*sizeof(int));

	int node_nb = 0;

	char* marked = (char*)calloc(g->n, sizeof(char));
	queue* fifo = empty_queue(g->n);
	queue_add(fifo, n);
	while (is_empty_queue(fifo))
	{
		int node = queue_get(fifo);
		if (marked[node])
			continue;
		marked[node] = 1;

		new_g->degrees[node_nb] = g->degrees[node];
		new_g->capacities[node_nb] = g->capacities[node];
		g->links[node_nb+1] = g->links[node_nb] + g->capacities[node_nb];

		int i = 0;
		int deg = g->degrees[node];
		for (i = 0; i < deg; i++)
		{
			int son = g->links[node][i];
			g->links[node_nb][i] = son;
			queue_add(fifo, son);
		}

		node_nb++;
	}
	return new_g;			
}
