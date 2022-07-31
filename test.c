// #include "linked_list/include/linked_list.h"
// #include "stack/include/stack.h"
#include "tree/include/tree.h"
#include <stdio.h>

int main(void) {

    void *a = (void*)'a';
    void *b = 'b';
    void *c = 'c';
    void *d = 'd';
    void *e = 'e';
    void *f = 'f';
    void *g = 'g';
    void *h = 'h';
    void *i = 'i';
    void *j = 'j';
    void *k = 'k';
    void *m = 'm';

    node n;
    set_root(&n,a);
    set_node(&n,b,LEFT);
    set_node(&n,c,RIGHT);
    set_node(get_left(&n),d,LEFT);
    set_node(get_left(&n),e,RIGHT);

    set_node(get_right(&n),f,LEFT);
    set_node(get_right(&n),g,RIGHT);

    set_node(get_right(get_right(&n)),h,LEFT);
    set_node(get_left(get_right(get_right(&n))),i,LEFT);
    printf("found %p, %c\n",find_node(&n,g,INT),(char*)find_node(&n,g,INT)->data);
    print_tree(&n,9,0);
    // stack *s;
    // start_stack(s,a);
    // print_stack(s);

    // // printf("top of stack: %c\n",(char*)s.data);
    // push_stack(&s,b);
    // // printf("top of stack: %c\n",(char*)s.data);
    // print_stack(s);
    // push_stack(&s,c);
    // print_stack(s);
    // push_stack(&s,c);
    // print_stack(s);
    // pop_stack(&s);
    // print_stack(s);
    // pop_stack(&s);
    // print_stack(s);
    // pop_stack(&s);
    // print_stack(s);
    // printf("Is Stack Empty? %s\n",is_empty(s) == 1 ? "True" : "False");
    // pop_stack(&s);
    // print_stack(s);
    // printf("Is Stack Empty? %s\n",is_empty(s) == 1 ? "True" : "False");
    // push_stack(&s,c);
    // print_stack(&s);
    // push_stack(&s,c);
    // print_stack(&s);

    // printf("top of stack: %c\n",(char*)s.data);
    // pop_stack(s);
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