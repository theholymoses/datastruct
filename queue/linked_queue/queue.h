
/*==================== Types ====================*/
struct queue_node_t {
	char item;
	struct queue_node_t *next;
};

struct queue_t {
	struct queue_node_t *remove;
	struct queue_node_t *insert;
};

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
