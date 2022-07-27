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

    head->next = calloc(1,sizeof(node_t));
    if(head->next == NULL) exit(-1);
    head->next->data = data;
    head->next->next = NULL;

    if(l->t == double_ll) {
        head->next->prev = head;
    }
}

void unshift_ll(list_node *l, void *data) {
    list_node *head = l;
    list_node *new = calloc(1,sizeof(node_t));
    new->data = l->data;
    new->next = l->next;
    if(l->t == double_ll) {
        new->prev = l;
    }
    l->data = data;
    l->next = new;
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
    printf("[Item %d - Address: %p - Next-Item: %p]",i++,l,l->next);
}

int get_length_ll(list_node *l) {
    int count = 0;
    while(l->next != NULL) {
        count++;
        l = l->next;
    }
    return count;
}

int del_last_node_ll(list_node *l) {

}

int del_first_node_ll(list_node *l) {

}