/*
 * Include created out of prelim.c for readability
 * by Nicolas DURAN & Rodolphe GUITTENY
 * Credit for code & datastructure goes to
 * Clemence Magnien and Matthieu Latapy
 * Projet VLG
 * SCIA 2014 - EPITA
 */

#ifndef PRELIM_H
#define PRELIM_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

typedef struct graph{
  int n;
  int m;
  int **links;
  int *degrees;
  int *capacities;
} graph;

/* Utility */
void report_error(char *s);
int is_in_array(int *a, int e, int left, int right);
int max_in_array(int *a, int n);
int index_max_array(int *a, int n);
int rand_index_max_array(int *a, int n);
void quicksort(int *v, int t);
int *random_perm(int n);
int *inverse_perm(int *p, int n);

/* Graph management */
void free_graph(graph *g);
graph *graph_from_file(FILE *f);

/* Graph sorting */
void sort_graph(graph *g);
int *sort_nodes_by_degrees(graph *g);
void renumbering(graph *g, int *perm);
void random_renumbering(graph *g);

int max(int i, int j);

#endif
