#include "include/tree.h"
#include <stdlib.h>
#include <stdio.h>

void set_root(node *n, void *data, int number_of_child_nodes) {
    n->data = data;
    n->size = number_of_child_nodes;
    n->nodes = calloc(number_of_child_nodes,sizeof(node));
    for(int i = 0; i < number_of_child_nodes; i++) {
        n->nodes[i] = NULL; //default to null
    }
    // n->left = NULL;
    // n->right = NULL;
}

void set_node(node *n, void *data, int pos,int number_of_child_nodes) {
    puts("4");
    if(pos > n->size) return;
    puts("5");
    node *new = calloc(1,sizeof(node));
    puts("1");
    #if LOGGING
        printf("New node at address: %p\n",new);
    #endif
    if(new != NULL) {
        new->data = data;
        new->size = number_of_child_nodes;
        new->nodes = calloc(number_of_child_nodes,sizeof(node));
        for(int i = 0; i < number_of_child_nodes; i++) {
            new->nodes[i] = NULL;
        }
        printf("0 %p\n",new);
        n->nodes[pos] = new;
        printf("0 %p\n",n->nodes[pos]);

        // new->left = NULL;
        // new->right = NULL;
        // if(pos == LEFT) {
        //     // n->left = new;
        //     #if LOGGING
        //         // printf("Address of n->left: %p\n",n->left);
        //     #endif
        // }else{
        //     // n->right = new;
        //     #if LOGGING
        //         // printf("Address of n->right: %p\n",n->right);
        //     #endif
        // }
    }
}

node *get_child_node(node *n, int pos) {
    puts("2");
    if(pos > n->size) return NULL;
    for(int i = 0; i < n->size; i++) {
        printf("1 %p\n",n->nodes[i]);
    }
    puts("3");
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
        // if(has_right(n)) {
        //     // node *f = find_node(n->right,data,d);
        //     // if(f != NULL) {
        //         // return f;
        //     // }
        // }
        // /*
        // *   Found in left sub-tree
        // */
        // if(has_left(n)) {
        //     // node *f = find_node(n->left,data,d);
        //     // if(f != NULL) {
        //         // return f;
        //     // }
        // }
    }
    
}

/*
*   Maybe drop all child-nodes recursive too?
*/
void drop_node(node *n, int pos) {
    if(pos > n->size) return;
    n->nodes[pos] = NULL;
    // if(pos == LEFT) {
    //     // free(n->left);
    //     // n->left = NULL;
    // }else{
    //     // free(n->right);
    //     // n->right = NULL;
    // }
}

void change_data(node *n, void *new_data) {
    n->data = new_data;
}

void insert_node(node *n, void *data, int pos, int number_of_child_nodes) {
    if(pos > n->size) return;
    node *new = calloc(1,sizeof(node));
    if(new != NULL) {
        n->data = data;
        n->nodes = calloc(number_of_child_nodes,sizeof(node));
        n->size = number_of_child_nodes;
        for(int i = 0; i < number_of_child_nodes; i++) {
            n->nodes[i] = NULL;
        }
        if(n->nodes[pos] != NULL) {
            new->nodes[pos] = n->nodes[pos]; //keep node index 
        }
        n->nodes[pos] = new;
    }    
    // if(new != NULL) {
    //     new->data = data;
    //     if(pos == LEFT) {
    //         if(n->left != NULL) {
    //             new->left = n->left;
    //         }else{
    //             new->left = NULL;
    //         }
    //         n->left = new;
    //     }else{
    //         if(n->right != NULL) {
    //             new->right = n->right;
    //         }else{
    //             new->right = NULL;
    //         }
    //         n->right = new;
    //     }
    // } 
}

void print_tree(node *n, int number_of_nodes,int spaces) {
    spaces += number_of_nodes;

}

