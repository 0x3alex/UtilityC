#ifndef QUEUE
#define QUEUE

typedef struct s_queue {
    void *data;
    struct s_queue *prev;
} queue;

void start_queue(queue *s, void *data);

/*
*   Add queue entry
*/
void enqueue(queue *s,void *data);

/*
*   Remove last entry of queue
*/
void dequeue(queue *s);

queue *get_next();

int is_empty(s_queue *s);

void print_queue(queue *s);

#endif