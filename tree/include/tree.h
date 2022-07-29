#ifndef TREE
#define TREE
#define LOGGING 1

typedef struct s_node{
    void *data;
    struct s_node *left;
    struct s_node *right;
} node;

enum node_pos {LEFT,RIGHT};


/*
*   Set root node
*/
void set_root(node *n, void *data);

/*
*   ==================================
*   If node has a right or left node
*   the node is going to be dropped
*   -> every following node of the
*   dropped node is also going to be
*   dropped
*/
void set_node(node *n, void *data, enum node_pos pos);
/*
*   ==================================
*/

node *get_left(node *n);

node *get_right(node *n);

/*
*   ==================================
*   If the already has a right or left
*   node, the node is going to be the 
*   child-node of the inserted node
*   while keeping the node position
*   left -> left, right -> right
*/

void insert_right(node *n, void *data);

void insert_left(node *n, void *data);

/*
*   ==================================
*/

int has_left(node *n);

int has_right(node *n);

int is_leaf(node *n);

void drop_left(node *n);

void drop_right(node *n);

/*
*   N needs to be the root node
*/
node *find_node(node *n, void *data);

void change_data(node *n, void *new_data);

#endif