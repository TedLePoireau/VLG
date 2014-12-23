#include "renumbering.h"

void PrinttoFile(graph *g)
{
    FILE *fp = fopen("graph.out", "ab+");
    fprintf(fp, "%d\n", g->n);
    for (int i = 0; i < g->n; i++)
    {
        fprintf(fp, "%d %d\n", i, g->degrees[i]);
    }
    for (int i = 0; i< g->n; i++)
    {
        for (int j = 0; j < g->degrees[i]; i++)
        {
            fprintf(fp, "%d %d\n", i, g->links[i][j]);
        }
    }
}

void renumbering_from_BFS(graph *g, int x)
{
    int *tmpc, *tmpp, **tmppp;
    if( (tmpp=(int *)malloc(g->n*sizeof(int))) == NULL )
        report_error("renumbering: malloc() error");
    if( (tmppp=(int **)malloc(g->n*sizeof(int *))) == NULL )
        report_error("renumbering: malloc() error");
    if( (tmpc=(int *)malloc(g->n*sizeof(int))) == NULL )
        report_error("renumbering: malloc() error");

    int max = max_in_array(g->degrees, g->n);



    if (x > g->n)
		report_error("renumbering: index error");

    int* marked = (int*) malloc(g->n * sizeof(int));
    marked[x] = 1;
    for(int i=0; i<g->n;i++)
        marked[i] = 0;

    printf("%d\n\n\n", max);


    int neword = 0;
    int *neworder = &neword;
    int* newcoord = malloc(g->n * sizeof(int));
    BFS(g, tmppp, tmpp, tmpc, neworder, marked, x, max);
    //BFS_second(g, neworder, marked, x, max, newcoord);

    for (int i=0; i<g->n;i++)
    {
        if (marked[i] != 1)
            BFS(g, tmppp, tmpp, tmpc, neworder, marked, i, max);
//        if (marked[i] != 1)
//            BFS_second(g, neworder, marked, i, max, newcoord);
    }

    //renumbering(g, newcoord);
    //free(newcoord);

    PrinttoFile(g);
}


void BFS(graph *g, int **tmppp, int* tmpp, int* tmpc, int *neworder, int *marked, int targetvert, int MAX)
{
    int x = targetvert;
    queue *q;
    q = empty_queue(MAX);
    marked[x] = 1;

    tmpp[*neworder] = g->degrees[x];
    tmpc[*neworder] = g->capacities[x];
    tmppp[*neworder] = malloc (g->degrees[x] * sizeof(int));

    queue_add(q, x);
    int daddy = *neworder;

    while (!is_empty_queue(q))
    {
        x = queue_get(q);
        for (int i=0; i<g->degrees[x];i++)
        {
            if (marked[g->links[x][i]] != 1)
            {
                (*neworder)++;
                tmppp[*neworder] = malloc (g->degrees[g->links[x][i]] * sizeof(int));
                tmppp[daddy][i] = (*neworder);

                tmpp[*neworder] = g->degrees[g->links[x][i]];
                tmpc[*neworder] = g->capacities[g->links[x][i]];


                queue_add(q, g->links[x][i]);
                marked[g->links[x][i]] = 1;
            }
            else
                tmppp[g->links[x][i]][g->degrees[x] -1];
        }
        daddy++;
    }
    free_queue(q);

}

void BFS_second(graph *g, int *neworder, int *marked, int targetvert, int MAX, int* newcoord)
{
    int x = targetvert;
    queue *q;
    q = empty_queue(MAX);
    marked[x] = 1;
    newcoord[x] = *neworder;
    queue_add(q, x);

    while (!is_empty_queue(q))
    {
        x = queue_get(q);
        for (int i=0; i<g->degrees[x];i++)
        {
            if (marked[g->links[x][i]] != 1)
            {
                (*neworder)++;
                newcoord[x] = *neworder;
                queue_add(q, g->links[x][i]);
                marked[g->links[x][i]] = 1;
            }
        }
    }
    free_queue(q);

}

