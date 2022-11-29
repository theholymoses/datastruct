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

	if (free_list != NULL) {
		temp = free_list;
		free_list = free_list -> next;
	} else {
		if (current_block == NULL || size_left == 0) {
			current_block = (struct queue_node_t*)malloc (BLOCKSIZE * sizeof (struct queue_node_t));
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
init_queue (void) {
	struct queue_t *q;
	
	q = (struct queue_t*)malloc (sizeof (struct queue_t));
	q -> remove = q -> insert = NULL;
	return (q);
}

void
deinit_queue (struct queue_t *q) {
	struct queue_node_t *temp;

	while (q -> remove != NULL) {
		temp = q -> remove;
		q -> remove = temp -> next;
		return_node (temp);
	}
	free (q);
}

int
is_empty (struct queue_t *q) {
	return (q -> insert == NULL);
}

void
enqueue (struct queue_t *q, char item) {
	struct queue_node_t *temp;

	temp = get_node ();
	temp -> item = item;
	temp -> next = NULL;

	if (q -> insert != NULL) {
		q -> insert -> next = temp;
		q -> insert = temp;
	} else {
		q -> remove = q -> insert = temp;
	}
}

char
dequeue (struct queue_t *q) {
	struct queue_node_t *temp;
	char temp_item;

	temp = q -> remove;
	temp_item = temp -> item;
	q -> remove = temp -> next;

	if (q -> remove == NULL) {
		q -> insert = NULL;
	}
	return_node (temp);
	return (temp_item);
}

/*==================== end ====================*/
