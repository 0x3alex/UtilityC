#ifndef ARRAY
#define ARRAY
#define logging 0

enum types {INT = sizeof(int),DOUBLE = sizeof(double)};

/*
*   array.used_size will always be one greater than the actual used size
*/

struct array {
    void *array;
    enum types t;
    int size;
    int used_size;
};

int create(struct array *s, int length, enum types type);

void *get(struct array *s, int index);

int resize(struct array *s, int new_size);

int append(struct array *s, int number_of_values,...);

int insert(struct array *s,int startIndexc, int number_of_values,...);

int push(struct array *s, int number_of_values,...); //push and insert

int push_values(struct array *s,int start_index, int number_of_indices_to_push_back); //just push to free space

int remove_at_index(struct array *s, int index);

int pop(struct array *s);

/*
*   The new concatinated array will be stored in the array-pointer of s
*/
int concat(struct array *s, struct array *s2);

int reverse(struct array *s);

char *array_to_string(struct array *s);

#endif