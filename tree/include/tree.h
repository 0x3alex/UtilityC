#ifndef TREE
#define TREE
#define LOGGING 1

enum data_type {INT,DOUBLE,CHAR,FLOAT};

typedef struct s_node{
    void *data;
    int size;
    struct s_node **nodes; //gets malloced / calloced when creating node 
    enum data_type type;
    // struct s_node *left;
    // struct s_node *right;
} node;




/*
*   Set root node
*/
void set_root(node *n, void *data, int number_of_child_nodes, enum data_type type);

/*
*   ==================================
*   If node has a right or left node
*   the node is going to be dropped
*   -> every following node of the
*   dropped node is also going to be
*   dropped
*/
void set_node(node *n, void *data, int pos,int number_of_child_nodes, enum data_type type);
/*
*   ==================================
*/

node *get_child_node(node *n, int pos);

void insert_node(node *n, void *data, int pos,int number_of_child_nodes, enum data_type type);

int is_leaf(node *n);

void drop_node(node *n, int pos);

/*
*   N needs to be the root node
*/
node *find_node(node *n, void *data, enum data_type d);

void change_data(node *n, void *new_data);

void change_size(node *n, int new_size);

void print_tree(node *n, enum data_type data_type_of_root);

#endif