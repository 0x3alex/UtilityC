#include "linked_list/include/linked_list.h"
#include <stdlib.h>
#include <stdio.h>


void start_ll(list_node *l, enum ll_types t, void *data){
    l->t = t;
    l->data = data;
    l->next = NULL;
    l->prev = NULL;
}

void push_ll(list_node *l, void *data) {
    list_node *head = get_last_node_ll(l);

    head->next = calloc(1,sizeof(list_node));
    if(head->next == NULL) exit(-1);
    head->next->data = data;
    head->next->next = NULL;

    if(l->t == double_ll) {
        head->next->prev = head;
    }
}

void pop_ll(list_node *l) {
    list_node *last = get_last_node_ll(l);
    last->prev->next = NULL;
    free(last->prev->next);
}

void unshift_ll(list_node *l, void *data) {
    list_node *head = l;
    list_node *new = calloc(1,sizeof(list_node));
    new->data = l->data;
    new->next = l->next;
    if(l->t == double_ll) {
        new->prev = l;
    }
    l->data = data;
    l->next = new;
}

void shift_ll(list_node *l) {
    l->data = l->next->data;
    l->next = l->next->next;
    l->prev = NULL;
    free(l->next);
}

list_node *get_last_node_ll(list_node *l) {
    if(l->next != NULL) {
        get_last_node_ll(l->next);
    }else{
        return l;
    }
    
}

list_node *get_at_index_ll(list_node *l, int index) {
    if(index == 0) {
        return l;
    }else{
        if(l->next != NULL) {
            get_at_index_ll(l->next,--index);
        }else{
            return NULL;
        }
    }
}

void print_ll(list_node *l) {
    int i = 0;
    while(l->next != NULL) {
        printf("[Item %d - Address: %p - Next-Item: %p] -> ",i,l,l->next);
        i++;
        l = l->next;
    }
    printf("[Item %d - Address: %p - Next-Item: %p]\n",i++,l,l->next);
}

int get_length_ll(list_node *l) {
    int count = 0;
    while(l->next != NULL) {
        count++;
        l = l->next;
    }
    return count;
}