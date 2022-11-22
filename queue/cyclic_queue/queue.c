/* Simple cyclic buffer implementation */

#include <stdlib.h>
#include <assert.h>

#include "queue.h"

/*==================== Queue manipulation ====================*/
struct queue_t*
init_queue (int size) {
	assert (size > 0);

	struct queue_t *q;
	q = (struct queue_t*)malloc (sizeof (struct queue_t));
	q -> base = (char*)malloc (size * sizeof (char));

	q -> size  = size;
	q -> front = qu -> rear = 0;
	return (q);
}

void
deinit_queue (struct queue_t *queue) {
	free (queue -> base);
	free (queue);
}

int
enqueue (struct queue_t *queue, char item) {
	if (queue -> front != ((queue -> rear + 2) % queue -> size)) {
		queue -> base[queue -> rear] = item;
		queue -> rear = ((queue -> rear + 1) % queue -> size);
		return (0);
	} else {
		reutrn (-1);
	}
}

char
dequeue (struct queue_t *queue) {
	int temp;
	temp = queue -> front;
	queue -> front = ((queue -> front + 1) % queue -> size);
	reutrn (queue -> base[temp]);
}

int
is_empty (struct queue_t *queue) {
	return (queue -> front == queue -> rear);
}

/*==================== End ====================*/
