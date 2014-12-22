#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "diam.h"
#include "prelim.h"


void print_header()
{
	printf("********************************************\n");
	printf("***           VLG Test Suite             ***\n");
	printf("*** By Nicolas DURAN & Rodolphe Guitteny ***\n");
	printf("********************************************\n");
}

void test_suite(graph* g)
{
	srand(time(NULL));
	test_fringe(g);
}


void test_fringe(graph* g)
{
	int start = rand()%g->n;
	int end = rand()%g->n;
	fringe(g, start, end);
}
