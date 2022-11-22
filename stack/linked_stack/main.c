#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#include "stack.h"

#define SIZE  20
#define FROM  33
#define TO   126

int
rand_range (int from, int to) {
	assert (from < to && from >= 0);

	return (from + rand () / (RAND_MAX / (to - from + 1) + 1));
}

int main (void) {
	srand (time (NULL));

	struct node_t *st;
	st = init_stack ();

	printf ("******************** Adding elements to stack ********************\n");
	int randnum;
	int elem = 0;
	while (elem < SIZE) {
		randnum = rand_range (FROM, TO);
		push (st, randnum);

		printf ("Added element %c(%d) to stack.\n", randnum, randnum);
		++elem;
	}

	printf ("******************** Removing elements from stack ********************\n");
	int removed;
	while ( !is_empty (st)) {
		removed = pop (st);

	printf ("Removed element %c(%d) from stack.\n", removed, removed);
	}

	return (0);
}
