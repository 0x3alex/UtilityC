#include "include/stack.h"
#include <stdlib.h>
#include <stdio.h>

void start_stack(stack *s, void *data, int size) {
    s->data =  data;
    s->size = -1;
    s->next = NULL;
}

int push_stack(stack *s, void *data) {
    if(s->size != -1) {
        if(s->size == 0) {
            return -1;
        }
    }
    stack *n = calloc(1,sizeof(stack));
    n->data = s->data;
    n->next = s->next;
    n->size = s->size;

    s->data = data;
    s->size = s->size == -1 ? -1 : s->size -1;
    s->next = n;
    return 0;

}

void print_stack(stack *s) {
    while (s->next != NULL)
    {
        printf("[Item : %p, next: %p] -> ", s, s->next);
        s = s->next;
    }
    printf("[Item : %p, next: %p]\n", s, s->next);
    
}


void pop_stack(stack *s, void *data) {

}