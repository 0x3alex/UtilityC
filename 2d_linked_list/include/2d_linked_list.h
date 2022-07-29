#ifndef D_LINKED_LIST
#define D_LINKED_LIST

/*  (v)
*   a   b   c   d (h)
*   e   f   g   h
*   (v) -> vertical - column
*   (h) -> horizontal - row
*/

typedef struct s_2d_linked_list {
    void *data;
    /*
    *   ==========
    *   Horizontal
    */
    _2d_ll *next;
    _2d_ll *prev;
    /*
    *   ==========
    */

   /*
   *    ==========
   *    Vertical
   */
   _2d_ll *above;
   _2d_ll *below;
   /*
   *    ==========
   */
} _2d_ll;

void create_2d_ll(_2d_ll *l, void *data);

/*
*   Push / Pop vertical values -> Add / Delete last value
*/
void push_column(_2d_ll *l, void *data);

void pop_column(_2d_ll *l, void *data);

/*
*   Push / Pop horizontal values -> Add / Delete last value
*/
void push_row(_2d_ll *l, void *data);

void pop_row(_2d_ll *l, void *data);

/*
*   Unshift / shift vertical values -> -> Add / Delete first value
*/

void unshift_column(_2d_ll *l, void *data);

void shift_column(_2d_ll *l, void *data);

/*
*   Unshift / shift horizontal values -> -> Add / Delete first value
*/

void unshift_row(_2d_ll *l, void *data);

void shift_row(_2d_ll *l, void *data);


void insert_column(_2d_ll *l, void *data);

void insert_row(_2d_ll *l, void *data);

_2d_ll *get_below(_2d_ll *l);

_2d_ll *get_above(_2d_ll *l);

_2d_ll *get_next(_2d_ll *l);

_2d_ll *get_prev(_2d_ll *l);

#endif