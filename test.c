#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "diam.h"
#include "prelim.h"
#include "test.h"

#define NB_TRY 5

void print_header()
{
	printf("********************************************\n");
	printf("***           VLG Test Suite             ***\n");
	printf("*** By Nicolas DURAN & Rodolphe Guitteny ***\n");
	printf("********************************************\n\n\n");
}

void test_suite(graph* g)
{
	print_header();
	srand(time(NULL));
	
	printf("********************************************\n");
	printf("***  FRINGE Algorithm - Unordered Graph  ***\n");	
	printf("********************************************\n\n");
	
	int nb_try = NB_TRY;
	while (nb_try--)	
		test_fringe(g);
}


void test_fringe(graph* g)
{
	printf("Generating random start & end\n");
	int start = rand()%g->n;
	int end = rand()%g->n;
	printf("Search path from %d to %d\n", start, end);
	fringe(g, start, end);
	printf("------\n");
}
