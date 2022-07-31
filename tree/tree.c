#include "include/tree.h"
#include <stdlib.h>
#include <stdio.h>

void set_root(node *n, void *data) {
    n->data = data;
    n->left = NULL;
    n->right = NULL;
}

void set_node(node *n, void *data, enum node_pos pos) {
    node *new = calloc(1,sizeof(node));
    #if LOGGING
        printf("New left node at address: %p\n",new);
    #endif
    if(new != NULL) {
        new->data = data;
        new->left = NULL;
        new->right = NULL;
        if(pos == LEFT) {
            n->left = new;
            #if LOGGING
                printf("Address of n->left: %p\n",n->left);
            #endif
        }else{
            n->right = new;
            #if LOGGING
                printf("Address of n->right: %p\n",n->right);
            #endif
        }
    }
}

node *get_left(node *n) {
    return n->left;
}

node *get_right(node *n) {
    return n->right;
}

int has_left(node *n) {
    return n->left == NULL ? 0 : 1;
}

int has_right(node *n) {
    return n->right == NULL ? 0 : 1;
}

int is_leaf(node *n) {
    return (n->right == NULL && n->left == NULL);
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
    puts("1");
    if(comp(n->data,data,d)) {
        return n;
    }else{
        /*
        *   Found in right sub-tree
        */ 
        if(has_right(n)) {
            node *f = find_node(n->right,data,d);
            if(f != NULL) {
                return f;
            }
        }
        /*
        *   Found in left sub-tree
        */
        if(has_left(n)) {
            node *f = find_node(n->left,data,d);
            if(f != NULL) {
                return f;
            }
        }
    }
    
}

/*
*   Maybe drop all child-nodes recursive too?
*/
void drop_node(node *n, enum node_pos pos) {
    if(pos == LEFT) {
        free(n->left);
        n->left = NULL;
    }else{
        free(n->right);
        n->right = NULL;
    }
}

void change_data(node *n, void *new_data) {
    n->data = new_data;
}

void insert_node(node *n, void *data, enum node_pos pos) {
    node *new = calloc(1,sizeof(node));
    if(new != NULL) {
        new->data = data;
        if(pos == LEFT) {
            if(n->left != NULL) {
                new->left = n->left;
            }else{
                new->left = NULL;
            }
            n->left = new;
        }else{
            if(n->right != NULL) {
                new->right = n->right;
            }else{
                new->right = NULL;
            }
            n->right = new;
        }
    } 
}

void print_tree(node *n, int number_of_nodes,int spaces) {
    spaces += number_of_nodes;

}

