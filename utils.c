#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

LLIST* llist_add(LLIST* list, int n)
{
	LLIST* add = (LLIST*) malloc (sizeof (LLIST));
	add->n = n;
	add->next = list;
	return add;
}

LLIST* llist_pop(LLIST* list, int* n)
{
	if (list == NULL)
	{
		*n = -1;
		return NULL;
	}
	*n = list->n;
	LLIST* ret = list->next;
	free(list);
	return ret;
}
