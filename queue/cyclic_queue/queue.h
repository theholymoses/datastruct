/* Simple cyclic buffer implementation */

/*==================== Types ====================*/
struct queue_t {
	char *base;
	int front;
	int rear;
	int size;
};

/*==================== Queue manipulation ====================*/
struct queue_t*
init_queue (int size);

void
deinit_queue (struct queue_t *queue);

int
enqueue (struct queue_t *queue, char item);

char
dequeue (struct queue_t *queue);

int
is_empty (struct queue_t *queue);

/*==================== End ====================*/
