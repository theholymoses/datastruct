/* Simple dynamic stack with a structure similar to linked list
 * Also, an intermediate layer of memory allocation is provided, so that
 * "malloc" and "free" wouldn't be called every time a new node is needed
 */

#include <stdlib.h>
#include "stack.h"

#define BLOCKSIZE 256

struct node_t *current_block = NULL;
struct node_t *free_list     = NULL;
int size_left                = 0;

/*==================== Memory access ====================*/

/* N nodes are allocated immideately and then used when needed
 *   so "malloc" is called rarely, only when N nodes are in use and more are needed
 *   memory is never freed, assuming that this structure will be used until programm termination
 * When node is "returned" it is placed in "free_list" and it can be used later via "get_node" call
 */

struct node_t*
get_node (void) {
	struct node_t *temp;

	if (free_list != NULL) {  /* If some nodes were returned via "return_node" they are reused here later */
		temp = free_list;
		free_list = free_list -> next;
	} else {
		if (current_block == NULL || size_left == 0) {
			current_block = (struct node_t*)malloc (BLOCKSIZE * sizeof(struct node_t));
			size_left = BLOCKSIZE; 
		}
		temp = current_block++;
		--size_left;
	}
	return (temp);
}

void
return_node (struct node_t *nd) {
	nd -> next = free_list;
	free_list = nd;
}

/*==================== Stack manipulation ====================*/
struct node_t*
init_stack (void) {
	struct node_t *nd;
	nd = get_node ();

	nd -> next = NULL;
	return (nd);
}

void
deinit_stack (struct node_t *nd) {
	struct node_t *temp;
	do {
		temp = nd -> next;
		return_node (nd);
		nd = temp;
	} while (temp != NULL);
}

int
is_empty (struct node_t *nd) {
	return (nd -> next == NULL);
}

void
push (struct node_t *nd, char item) {
	struct node_t *temp;

	temp = get_node ();
	temp -> item = item;
	temp -> next = nd -> next;
	nd -> next = temp;
}

char
pop (struct node_t *nd) {
	struct node_t *temp;
	char temp_item;
	
	temp = nd -> next;
	nd -> next = temp -> next;
	temp_item = temp -> item;
	return_node (temp);
	return (temp_item);
}

/*==================== End ====================*/
