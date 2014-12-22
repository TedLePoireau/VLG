#ifndef UTILS_H
#define UTILS_H

struct linked_list {
	int n;
	struct linked_list* next;

};

typedef struct linked_list LLIST;

LLIST* llist_add(LLIST* list, int n);
LLIST* llist_reverse(LLIST* list);
void llist_print(LLIST* list);

#endif



