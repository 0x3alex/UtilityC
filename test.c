#include "linked_list/include/linked_list.h"
#include <stdio.h>

int main(void) {

    void *a = 'a';
    void *b = 'b';
    void *c = 'c';

    list_node n;
    start_ll(&n,double_ll,a);
    push_ll(&n,b);
    push_ll(&n,c);
    print_ll(&n);
    printf("last value: %c\n",(char*)get_last_node_ll(&n)->data);
    pop_ll(&n);
    print_ll(&n);
    printf("last value: %c\n",(char*)get_last_node_ll(&n)->data);
    shift_ll(&n);
    print_ll(&n);
    printf("last value: %c\n",(char*)get_last_node_ll(&n)->data);
    set_data_ll(&n,a);
    printf("last value: %c\n",(char*)get_last_node_ll(&n)->data);
    return 0;
}