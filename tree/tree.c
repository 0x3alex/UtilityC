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

/*
*   N needs to be the root node
*/
node *find_node(node *n, void *data) {
    if(n->data == data) {
        return n;
    }
    /*
    *   Found in right sub-tree
    */ 
    if(has_right(n)) {
        node *f = find_node(n->right,data);
        if(f != NULL) {
            return f;
        }
    }
    /*
    *   Found in left sub-tree
    */
    if(has_left(n)) {
        node *f = find_node(n->left,data);
        if(f != NULL) {
            return f;
        }
    }
    // static int i = 1;
    // static node *f;
    // if(n->data == data) {
    //     printf("found at: %p %d\n",n,i);
    //     f = n;
    //     return f;
    // }else {
    //     ++i;
    //     if(has_right(n)) {
            
    //         printf("has right! %d\n",i);
    //         find_node(n->right,data);
    //     }
    //     if(has_left(n)) {
    //         printf("has left! %d\n",i);
    //         find_node(n->left,data);
    //     }
    // }
    
}
