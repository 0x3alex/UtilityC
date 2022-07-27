#ifndef single_linked_list
#define single_linked_list

typedef struct node {
	int data;
	struct node next_node;
}node_t_int;

typedef node_t_int *single_linked_list;

int int_insert_front(single_linked_list *s, int *val);
int int_insert_end(single_linked_list *s, int *val);

#endif
