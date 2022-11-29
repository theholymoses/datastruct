#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#include "queue.h"

#define SIZE  10
#define FROM  33
#define TO   126

int
rand_range (int from, int to) {
	assert (from < to && from >= 0);

	return (from + rand () / (RAND_MAX / (to - from + 1) + 1));
}

int main (void) {
	srand (time (NULL));

	struct queue_t *queue;
	queue = init_queue ();

	printf ("******************** Adding elements to queue ********************\n");
	int randnum;
	int ind = 0;
	while (ind++ <= SIZE) {
		randnum = rand_range (FROM, TO);
		enqueue (queue, randnum);
		printf ("Added element %c(%d) to queue.\n", randnum, randnum);
	}

	printf ("******************** Removing elements from queue ********************\n");
	int removed;
	while ( !is_empty (queue)) {
		removed = dequeue (queue);

	printf ("Removed element %c(%d) from queue.\n", removed, removed);
	}

	return (0);
}
