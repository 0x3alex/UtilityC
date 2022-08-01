#include "include/tree.h"
#include <stdlib.h>
#include <stdio.h>

void set_root(node *n, void *data, int number_of_child_nodes, enum data_type type) {
    if(n == NULL) {
        n = calloc(1,sizeof(node));
        if(n == NULL) return;
    }
    n->data = data;
    n->size = number_of_child_nodes;
    n->nodes = calloc(number_of_child_nodes,sizeof(node));
    n->type = type;
    for(int i = 0; i < number_of_child_nodes; i++) {
        n->nodes[i] = NULL; //default to null
    }
}

void set_node(node *n, void *data, int pos,int number_of_child_nodes, enum data_type type) {
    if(pos > n->size) return;
    node *new = calloc(1,sizeof(node));
    #if LOGGING
        printf("New node at address: %p\n",new);
    #endif
    if(new != NULL) {
        new->data = data;
        new->type = type;
        new->size = number_of_child_nodes;
        new->nodes = calloc(number_of_child_nodes,sizeof(node));
        for(int i = 0; i < number_of_child_nodes; i++) {
            new->nodes[i] = NULL;
        }
        n->nodes[pos] = new;
    }
}

node *get_child_node(node *n, int pos) {
    if(pos > n->size) return NULL;
    if(n == NULL) return NULL;
    return n->nodes[pos];
}

void change_size(node *n, int new_size) {
    if(new_size < n->size) return;
    n->nodes = realloc(n->nodes,new_size);
}

int is_leaf(node *n) {
    for(int i = 0; i < n->size; i++) {
        if(n->nodes[i] != NULL) {
            return 1;
        }
    }
    return 0;
}

static int comp(void *v1 ,void *v2,enum data_type d) {
    switch (d)
    {
        case INT:
            return (int*)v1 == (int*)v2;
            break;
        case FLOAT:
            return (float*)v1 == (float*)v2;
            break;
        case DOUBLE:
            return (double*)v1 == (double*)v2;
            break;
        case CHAR:
            return (char*)v1 == (char*)v2;
            break;
    }
}

/*
*   N needs to be the root node
*/

node *find_node(node *n, void *data, enum data_type d) {
    if(comp(n->data,data,d)) {
        return n;
    }else{
        /*
        *   Found in right sub-tree
        */ 
        for(int i = 0; i < n->size; i++) {
            if(n->nodes[i] != NULL) {
                node *f = find_node(n->nodes[i],data,d);
                if(f != NULL) {
                    return f;
                }
            }
        }
    }
    
}

/*
*   Maybe drop all child-nodes recursive too?
*/
void drop_node(node *n, int pos) {
    if(pos > n->size) return;
    n->nodes[pos] = NULL;
}

void change_data(node *n, void *new_data) {
    n->data = new_data;
}

void insert_node(node *n, void *data, int pos, int number_of_child_nodes, enum data_type type) {
    if(pos > n->size) return;
    if(n == NULL) return;
    node *new = calloc(1,sizeof(node));
    if(new != NULL) {
        new->data = data;
        new->type =type;
        new->nodes = calloc(number_of_child_nodes,sizeof(node));
        new->size = number_of_child_nodes;
        for(int i = 0; i < number_of_child_nodes; i++) {
            new->nodes[i] = NULL;
        }
        if(n->nodes[pos] != NULL) {
            new->nodes[pos] = n->nodes[pos]; //keep node index 
            printf("np: %p\n",new->nodes[pos]);
        }
        n->nodes[pos] = new;
        printf("nn: %p\n",n->nodes[pos]);
    }    
}

void print_tree(node *n, enum data_type data_type_of_root) {
    if(n != NULL) {
        switch(data_type_of_root) {
            case INT: 
                printf("%d ", (int*)n->data);
                break;
            case FLOAT:
                printf("%lf ", (float*)n->data);
                break;
            case CHAR:
                printf("%c ", (char*)n->data);
                break;
            case DOUBLE:
                printf("%lf ", (double*)n->data);
                break;
        }
        for(int i = 0; i < n->size; i++) {
            if(n->nodes[i] != NULL) {
                print_tree(n->nodes[i],n->nodes[i]->type);
            }
        }
    }
}

