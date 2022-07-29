#ifndef D_LINKED_LIST
#define D_LINKED_LIST
#define LOGGING 1

/*  (v)
*   a   b   c   d (h)
*   e   f   g   h
*   (v) -> vertical - column
*   (h) -> horizontal - row
*/

enum dimension {_2D, _3D};

typedef struct s_md_linked_list {
    void *data;
    struct s_md_linked_list *x_next;
    struct s_md_linked_list *x_prev;
  
   struct s_md_linked_list *y_prev;
   struct s_md_linked_list *y_next;
   
   struct s_md_linked_list *z_next;
   struct s_md_linked_list *z_prev;

   enum dimension d;

} _md_ll;

void create_md_ll(_md_ll *l, enum dimension d, void *data);

/*
*   Push and Pop for all three axis
*/

void push_x(_md_ll *l, void *data);

void pop_x(_md_ll *l, void *data);

void push_y(_md_ll *l, void *data);

void pop_y(_md_ll *l, void *data);

void push_z(_md_ll *l, void *data);

void pop_z(_md_ll *l, void *data);

/*
*   Unshift and shift for all three axis
*/

void unshift_x(_md_ll *l, void *data);

void shift_x(_md_ll *l, void *data);

void unshift_y(_md_ll *l, void *data);

void shift_y(_md_ll *l, void *data);

void unshift_z(_md_ll *l, void *data);

void shift_z(_md_ll *l, void *data);

_md_ll *get_last_x(_md_ll *l);

_md_ll *get_last_y(_md_ll *l);

_md_ll *get_last_z(_md_ll *l);

#endif