#include "include/stack.h"
#include <stdlib.h>
#include <stdio.h>

void start_stack(stack *s, void *data) {
    s->data =  data;
    s->next = NULL;
    #if SHOW_LIFETIME
        s->lifetime = 0;
    #endif
}

void push_stack(stack **s, void *data) {
    #if SHOW_LIFETIME
        static int l = -1;
    #endif
    stack *t = calloc(1,sizeof(stack));
    if(t == NULL) exit(-1);
    t->data = data;
    t->next = *s;
    #if SHOW_LIFETIME
        t->lifetime = l--;
    #endif
    *s = t;
}

void print_stack(stack *s) {
    if(s == NULL) {
        printf("[Item: 0x0, next: 0x0]\n");
        return;
    }
    while (s->next != NULL)
    {
        #if SHOW_LIFETIME
            printf("[Item : %p, next: %p, lifetime: %d ] -> ", s, s->next, s->lifetime);
        #else
            printf("[Item : %p, next: %p] -> ", s, s->next);
        #endif
        s = s->next;
    }
    #if SHOW_LIFETIME
        printf("[Item : %p, next: %p, lifetime: %d ]\n", s, s->next, s->lifetime);
    #else
        printf("[Item : %p, next: %p]\n", s, s->next);
    #endif
}


void pop_stack(stack **s) {
    stack *t = *s;
    *s = t->next;
    // puts("1");
    if(*s != NULL) {
        free(t);
    }
    
}

int is_empty(stack *s) {
    return s == NULL ? 1 : 0;
}