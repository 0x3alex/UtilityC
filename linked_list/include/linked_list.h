#ifndef LINKED_LIST
#define LINKED_LIST

enum ll_types {single_ll,double_ll};

typedef struct node {
    void *data;  
    struct node *next;
    struct node *prev;
    enum ll_types t;
}node_t;

typedef node_t list_node;

void start_ll(list_node *l, enum ll_types t, void *data);

/*
*   Add node at the end
*/
void push_ll(list_node *l, void *data);

/*
*   Remove node at the end
*/
void pop_ll(list_node *l);


/*
*   Add node at the beginning
*/
void unshift_ll(list_node *l, void *data);

/*
*   Remove node from the beginning
*/
void shift_ll(list_node *l);

list_node *get_last_node_ll(list_node *l);

list_node *get_at_index_ll(list_node *l, int index);

void print_ll(list_node *l);

int get_length_ll(list_node *l);

int del_last_node_ll(list_node *l);

int del_first_node_ll(list_node *l);

#endif