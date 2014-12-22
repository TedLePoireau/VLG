#ifndef DIAM_H
#define DIAM_H

typedef struct queue{
  int size;
  int *elts;
  int begin;
  int end;
} queue;

queue *empty_queue(int size);
void free_queue(queue *q);
int is_empty_queue(queue *q);
int is_full_queue(queue *q);
void queue_add(queue *q, int e);
int queue_get(queue *q);

#endif
