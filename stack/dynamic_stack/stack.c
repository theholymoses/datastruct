#include <stdlib.h>
#include <assert.h>

#include "stack.h"

/*==================== init ====================*/
struct stack_t*
init_stack (size_t size) {
	assert (size > 0);
	struct stack_t *st;
	
	st       = (struct stack_t *)malloc (sizeof (struct stack_t));
	st->base = (char *)malloc (size * sizeof (char));
	st->size = size;
	st->top  = st->base;

	return (st);
}

/*==================== deinit ====================*/
void
deinit_stack (struct stack_t *st) {
	free (st->base);
	free (st);
}

/*==================== push ====================*/
int
push (struct stack_t *st, char item) {
	if (st->top < (st->base + st->size)) {
		*(st->top)++ = item;
		return (0);	
	} else {
		return (-1);
	}	
}

/*==================== pop ====================*/
char
pop (struct stack_t *st) {
	--st->top;
	return (*(st->top));
}

/*==================== is empty ====================*/
int
is_empty ( struct stack_t *st) {
	return (st->base == st->top);
}

/*==================== is full ====================*/
int
is_full (struct stack_t *st) {
	return ((st->top - st->base) == st->size);
}
