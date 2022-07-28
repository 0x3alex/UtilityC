#include "linked_list/include/linked_list.h"
#include "stack/include/stack.h"
#include <stdio.h>

int main(void) {

    void *a = 'a';
    void *b = 'b';
    void *c = 'c';


    stack s;
    start_stack(&s,a,-1);
    printf("top of stack: %c\n",(char*)s.data);
    push_stack(&s,b);
    printf("top of stack: %c\n",(char*)s.data);
    print_stack(&s);
    push_stack(&s,c);
    printf("top of stack: %c\n",(char*)s.data);
    print_stack(&s);
    // list_node n;
    // start_ll(&n,double_ll,a);
    // push_ll(&n,b);
    // push_ll(&n,c);
    // print_ll(&n);
    // printf("last value: %c\n",(char*)get_last_node_ll(&n)->data);
    // pop_ll(&n);
    // print_ll(&n);
    // printf("last value: %c\n",(char*)get_last_node_ll(&n)->data);
    // shift_ll(&n);
    // print_ll(&n);
    // printf("last value: %c\n",(char*)get_last_node_ll(&n)->data);
    // set_data_ll(&n,a);
    // printf("last value: %c\n",(char*)get_last_node_ll(&n)->data);
    return 0;
}