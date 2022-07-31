#ifndef BINARY_TREE
#define BINARY_TREE


enum data_type {INT,FLOAT,DOUBLE ,CHAR};

typedef struct s_binary_node {
    union {
        int INT;
        double DOUBLE;
    }data;
    struct s_binary_node *left;
    struct s_binary_node *right;
    enum data_type type;
} binary_node;

void set_root(binary_node *n, enum data_type d,...);

void add_node(binary_node *n,...);

binary_node *search(binary_node *n,...);

#endif