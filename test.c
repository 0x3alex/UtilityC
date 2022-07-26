// #include "linked_list/include/linked_list.h"
// #include "stack/include/stack.h"
#include "tree/include/tree.h"
// #include "binary_tree/include/binary_tree.h"
#include <stdio.h>

int main(void) {

    // binary_node n;
    // set_root(&n,INT,20);
    // printf("root value %d\n",n.data.INT);
    // add_node(&n,16);
    // add_node(&n,25);
    // add_node(n.left, 14);
    // add_node(n.left, 17);

    // add_node(n.left->left, 13);
    // add_node(n.left->left, 15);

    // printf("n.left %d\n",n.left->data.INT);
    // printf("n.right %d\n",n.right->data.INT);

    // printf("n.left.left %d\n",n.left->left->data);
    // printf("n.left.right %d\n",n.left->right->data);

    // printf("n.left.left.left %d\n",n.left->left->left->data);
    // printf("n.left.left.right %d\n",n.left->left->right->data);

    // printf("searched : %d\n",search(&n,17)->data); 
    // puts("-------");
    // print_in_order(&n);
    // printf("\n");
    // print_pre_order(&n);
    // printf("\n");
    // print_post_oder(&n);
    
    // search(&n,115);

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
    set_root(&n,a,2,CHAR);
    set_node(&n,b,0,5,CHAR);
    set_node(&n,c,1,3,CHAR);
    printf("before size change %p\n",get_child_node(&n,0));
    set_node(get_child_node(&n,0),d,0,5,CHAR);
    set_node(get_child_node(&n,1),e,0,3,CHAR);
    print_tree(&n,CHAR);

    change_size(&n,3);
    printf("after size change %p\n",get_child_node(&n,0));
    insert_node(&n,f,0,3,CHAR);
    printf("after insert n0 %p\n",get_child_node(&n,0));
    printf("after insert n0.0 %p\n",get_child_node(get_child_node(&n,0),0));
    print_tree(&n,CHAR);
    // set_root(&n,a);
    // set_node(&n,b,LEFT);
    // set_node(&n,c,RIGHT);
    // set_node(get_left(&n),d,LEFT);
    // set_node(get_left(&n),e,RIGHT);

    // set_node(get_right(&n),f,LEFT);
    // set_node(get_right(&n),g,RIGHT);

    // set_node(get_right(get_right(&n)),h,LEFT);
    // set_node(get_left(get_right(get_right(&n))),i,LEFT);
    // printf("found %p, %c\n",find_node(&n,g,INT),(char*)find_node(&n,g,INT)->data);
    // print_tree(&n,9,0);
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