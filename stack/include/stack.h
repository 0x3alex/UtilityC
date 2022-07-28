#ifndef STACK
#define STACK

typedef struct s_stack {
    void *data;
    struct s_stack *next;
    int size;
} stack;


/*
*   Leave size as "NULL" when unlimited size
*/
void start_stack(stack *s, void *data, int size);

int push_stack(stack *s, void *data);

void pop_stack(stack *s, void *data);

void print_stack(stack *s);

#endif