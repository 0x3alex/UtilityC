#include "include/binary_tree.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

void set_root(binary_node *n, enum data_type d,...) {
    va_list value;
    va_start(value,d);
    n->type = d;
    n->left = NULL;
    n->right = NULL;
    switch (d)
    {
        case INT: case CHAR:
            n->data.INT = va_arg(value,int);
            break;
        case DOUBLE: case FLOAT:
            n->data.DOUBLE = va_arg(value,double);
            break;
    }
    va_end(value);
}

binary_node *search(binary_node *n,...) {
    va_list value;
    va_start(value,n);
    if(n == NULL) return NULL;
    switch (n->type)
    {
        case INT: case CHAR:
            int va_int = va_arg(value,int);
            if(n->data.INT == va_int) {
                puts("found");
                return n;
            }else{
               if(n->data.INT > va_int) {
                    binary_node *l_int = search(n->left,va_int);
                    if(l_int != NULL) {
                        return l_int;
                    }
               }else{
                    binary_node *r_int = search(n->right,va_int);
                    if(r_int != NULL) {
                        return r_int;
                    }
               }
            }
            break;
        case DOUBLE: case FLOAT:
            double va_double = va_arg(value,double);
            if(n->data.DOUBLE == va_double) {
                return n;
            }else{
                if(n->data.DOUBLE > va_double) {
                    binary_node *l_double = search(n->left,va_double);
                    if(l_double != NULL) {
                        return l_double;
                    }
               }else{
                    binary_node *r_double = search(n->right,va_double);
                    if(r_double != NULL) {
                        return r_double;
                    }
               }
            }
            break;
    }
    va_end(value);
}

void add_node(binary_node *n,...) {
    va_list value;
    va_start(value,n);
    
    switch (n->type)
    {
        case INT: case CHAR:
            int va_int = va_arg(value,int);
            if(n->data.INT == va_int) {
                return;
            }
            if(n->data.INT > va_int) {
                n->left = calloc(1,sizeof(binary_node));
                if(n->left == NULL) exit(-1);
                n->left->type = n->type;
                n->left->data.INT = va_int;
                n->left->left = NULL;
                n->left->right = NULL;
            }else{
                n->right = calloc(1,sizeof(binary_node));
                if(n->right == NULL) exit(-1);
                n->right->type = n->type;
                n->right->data.INT = va_int;
                n->right->left = NULL;
                n->right->right = NULL;
            }
            break;
        case DOUBLE: case FLOAT:
            double va_double = va_arg(value,double);
            if(n->data.DOUBLE == va_double) {
                return;
            }
            if(n->data.DOUBLE > va_double) {
                n->left = calloc(1,sizeof(binary_node));
                if(n->left == NULL) exit(-1);
                n->left->type = n->type;
                n->left->data.DOUBLE = va_double;
                n->left->left = NULL;
                n->left->right = NULL;
            }else{
                n->right = calloc(1,sizeof(binary_node));
                if(n->right == NULL) exit(-1);
                n->right->type = n->type;
                n->right->data.DOUBLE = va_double;
                n->right->left = NULL;
                n->right->right = NULL;
            }
            break;
    }
    va_end(value);
}