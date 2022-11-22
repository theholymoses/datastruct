/* Simple dynamic stack with a structure similar to linked list
 * Also, an intermediate layer of memory allocation is provided, so that
 * "malloc" and "free" wouldn't be called every time a new node is needed
 */

/*==================== Types ====================*/
struct node_t {
	char item;
	struct node_t *next;
};

/*==================== Memory access ====================*/
struct node_t*
get_node (void);

void
return_node (struct node_t *nd);

/*==================== Stack manipulation ====================*/
struct node_t*
init_stack (void);

void
deinit_stack (struct node_t *nd);

int
is_empty (struct node_t *nd);

void
push (struct node_t *nd, char item);

char
pop (struct node_t *nd);

/*==================== End ====================*/
