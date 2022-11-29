#include <stdlib.h>
#include "queue.h"

#define BLOCKSIZE 256

struct queue_node_t *current_block = NULL;
struct queue_node_t *free_list     = NULL;
int size_left = 0;

/*==================== memory access ====================*/
struct queue_node_t*
get_node (void) {
	struct queue_node_t *temp;

	if (free_list == NULL) {
		temp = free_list;
		free_list = free_list -> next;
	} else {
		if (current_block == NULL || size_left == 0) {
			temp = (struct queue_node_t*)malloc (BLOCKSIZE * sizeof (struct queue_node_t));
			size_left = BLOCKSIZE;
		}
		temp = current_block++;
		--size_left;
	}
	return (temp);
}

void
return_node (struct queue_node_t *qn) {
	qn -> next = free_list;
	free_list = qn;
}

/*==================== queue manipulation ====================*/
struct queue_t*
init_queue (void);

void
deinit_queue (struct queue_t *q);

int
is_empty (struct queue_t *q);

void
enqueue (struct queue_t *q, char item);

char
dequeue (struct queue_t *q);

/*==================== end ====================*/
