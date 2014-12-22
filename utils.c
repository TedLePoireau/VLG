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

LLIST* llist_reverse(LLIST* list)
{
	LLIST* l1 = list;
	LLIST* l2 = list->next;
	LLIST* next;
	
	
	// Si ca marche je suis trop fort.
	while (l2 != NULL)
	{	
		next = l2->next;
		l2->next = l1;
		l1 = l2;
		l2 = next;
	}
return l1;
}

void llist_print(LLIST* list)
{
	printf("{ ");
	while (list != NULL)
	{
		printf("%d ", list->n);
		list = list->next;
	}
	printf("}\n");
}
