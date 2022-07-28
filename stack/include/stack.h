#ifndef STACK
#define STACK
#define SHOW_LIFETIME 1

typedef struct s_stack {
    void *data;
    struct s_stack *next;
    #if SHOW_LIFETIME
    /*
    *   The oldest entry has the lifetime 0.
    *   The younger the entry the more negative the number gets (-1,-2,-3,...)
    */
    int lifetime;
    #endif
} stack;


/*
*   size = -1 => unlimited
*/
void start_stack(stack *s, void *data);

void push_stack(stack **s, void *data);

void pop_stack(stack **s);

void print_stack(stack *s);

int is_empty(stack *s);

#endif