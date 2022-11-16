/*==================== Simple dynamic stack implementation ====================*/
struct stack_t {
	char *base;
	char *top;
	size_t size;
};

/*==================== init ====================*/
struct stack_t*
init_stack (size_t size);

/*==================== deinit ====================*/
void
deinit_stack (struct stack_t *st);

/*==================== push ====================*/
int
push (struct stack_t *st, char item);

/*==================== pop ====================*/
char
pop (struct stack_t *st);

/*==================== is empty ====================*/
int
is_empty (struct stack_t *st);

/*==================== is full ====================*/
int
is_full (struct stack_t *st);
