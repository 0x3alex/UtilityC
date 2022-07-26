#include "array/include/array.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

int create(struct array *s, int size, enum types type) {
    switch (type)
    {
        case INT:
            int *i = (int*)calloc(size,INT);
            if(i == NULL) return -1;
            s->array = i;
            break;
        case DOUBLE:
            double *d = (double*)calloc(size,DOUBLE);
            if(d == NULL) return -1;
            s->array = d;
            break;
    }
    s->t = type;
    s->size = size;
    s->used_size = 0;
}

void *get(struct array *s, int index) {
    if(index > s->used_size) return 0x0;
    static void *vp;
    
    if(s->t == INT) {
        vp = &((int*)s->array)[index];
    }else{
        vp = &((double*)s->array)[index];
    }
    return vp;
}

int resize(struct array *s, int new_size) {
    /*
    *   Default realloc was not able to relocate the array
    *   -> values went missing when having to resize 2 or 3 times
    *   -> Not the most efficient method to realloc but it works for now
    */
    if(s->t == INT) {
        #if logging
            puts("[log] - resize(): creating new array");
        #endif

        int *newIntArray = (int*)calloc(new_size,INT);

        if(newIntArray == NULL) return -1;
        
        for(int i = 0; i < s->used_size; i++) {
            newIntArray[i] = ((int*)s->array)[i];
        
        }
        free(s->array);
        s->array = newIntArray;
        
    }else{
        #if logging
            puts("[log] - resize(): creating new array");
        #endif

        double *newDoubleArray = (double*)calloc(new_size,DOUBLE);

        if(newDoubleArray == NULL) return -1;

        for(int i = 0; i < s->used_size; i++) {
            newDoubleArray[i] = ((int*)s->array)[i];
        }
        free(s->array);
        s->array = newDoubleArray;
    }
    s->size = new_size;
    return 0;
}

/*
*   Push values, without setting
*   -> Helper function
*/

int push_values(struct array *s,int start_index, int number_of_indices_to_push_back) {
    /*
    *   Extra function to push back values needed for push, insert...
    */
    if(s->used_size+number_of_indices_to_push_back > s->size) {

        #if logging 
            puts("[log] - push_values(): resize needed");
        #endif
        
        if(resize(s,s->used_size+number_of_indices_to_push_back) != 0) return -1;
        
        #if logging 
            puts("[log] - push_values(): resized array");
        #endif
    }

    for(int i = s->used_size; i >= start_index; i--) {
        if(s->t == INT) {
            ((int*)s->array)[i+number_of_indices_to_push_back] =  ((int*)s->array)[i];
            ((int*)s->array)[i] = 0;       
            continue; 
        }
        ((double*)s->array)[i+number_of_indices_to_push_back] =  ((double*)s->array)[i];
        ((double*)s->array)[i] = 0.0;       
    }

    s->used_size += number_of_indices_to_push_back;
    return 0;
}

/*
*   Push value from the front
*/
int push(struct array *s, int number_of_values,...) {
    if(s->used_size+number_of_values > s->size) {

        #if logging 
            puts("[log] - push(): resize needed");
        #endif

        if(resize(s,s->used_size+number_of_values) != 0) return -1;

        #if logging 
            puts("[log] - push(): resized array");
        #endif
    }

    
    if(push_values(s,0,number_of_values) != 0) return -1;

    va_list values;
    va_start(values,number_of_values);
    for(int i = 0; i < number_of_values; i++) {
        if(s->t == INT) {
            ((int*)s->array)[i] = va_arg(values,int);
            continue;
        }
        ((double*)s->array)[i] = va_arg(values,double);
        
    }
    va_end(values);
}

/*
*   Append values at end of array
*/
int append(struct array *s, int number_of_values,...) {
    va_list values;
    va_start(values,number_of_values);

    if(s->used_size+number_of_values > s->size) {
        /*
        *   Realloc
        */
       #if logging 
            puts("[log] - append(): resize needed");
       #endif

       if(resize(s,s->used_size+number_of_values) != 0) return -1;

       #if logging 
            puts("[log] - append(): resized array");
       #endif
    }

    int startIndex = s->used_size;

    #if logging
        printf("[log] - append(): startIndex is %d\n",startIndex);
    #endif

    for(int i = 0; i < number_of_values; i++) {
        if(s->t == INT) {
            ((int*)s->array)[startIndex+i] = va_arg(values,int);
            continue;
        }
        ((double*)s->array)[startIndex+i] = va_arg(values,double);

    }
    va_end(values);
    s->used_size += number_of_values;
    return 0;
}

int insert(struct array *s,int startIndex, int number_of_values,...) {
    va_list values;
    va_start(values,number_of_values);

    if((s->used_size+number_of_values) > s->size) {
        #if logging 
            puts("[log] - insert(): resize needed");
        #endif
        if(resize(s,(s->used_size+number_of_values)) != 0) return -1;
        #if logging 
            puts("[log] - insert(): resized array");
        #endif
    
    }
    push_values(s,startIndex,number_of_values);

    for(int i = startIndex; i < startIndex+number_of_values; i++) {
        if(s->t == INT) {
            ((int*)s->array)[i] = va_arg(values,int);
            continue;
        }
        ((double*)s->array)[i] = va_arg(values,double);
    }
    va_end(values);
}

/*
*   Remove Value at Index
*/
int remove_at_index(struct array *s, int index) {
    if(index > s->used_size) return -1; //prevent direct overshooting
    for(int i = index; i < s->used_size;i++) {
        if(i+1 > s->size) return -1; //prevent overshooting while shifting
        if(s->t == INT) {
            ((int*)s->array)[i] =  ((int*)s->array)[i+1];
            continue;
        }
        ((double*)s->array)[i] =  ((double*)s->array)[i+1];

    }
    s->used_size--;
} 


/*
*   Remove last Index of array
*/
int pop(struct array *s) {
    if(s->t == INT) {
        ((int*)s->array)[s->used_size] = 0;
    }else{
         ((double*)s->array)[s->used_size] = 0;
    }
    s->used_size--;
    return 1;
}

int concat(struct array *s, struct array *s2) {
    if(s->t != s2->t) return -1;

    if(((s->used_size-1) + (s2->used_size-1)) > s->size) {
        /*
        *   Resize
        */
       #if logging 
            puts("[log] - concat(): resize needed");
       #endif

       if(resize(s,(s->used_size-1) + (s2->used_size-1)) == -1) return -1;

       #if logging 
            puts("[log] - concat(): resized array");
       #endif
    } 
    /*
    *   Append using append-method of array
    */
    for(int i = 0; i < s2->used_size; i++) {
        if(s->t == INT && s2->t == INT) {
            append(s,1,((int*)s2->array)[i]);
            continue;
        }
        append(s,1,((double*)s2->array)[i]);
    }
    return 0;
}


int reverse(struct array *s) {
    /*
    *   Only half length, because then it is finished whith reversing 
    */
    for(int i = 0; i < (s->used_size / 2); i++) {
        if(s->t == INT) {
            int v1 = *(int*)get(s,i);

            #if logging
                printf("[log] - reverse(): Front-Value: %d\n",v1);
            #endif

            #if logging
                printf("[log] - reverse(): Back-Value: %d\n",((int*)s->array)[(s->used_size-1)-i]);
            #endif

            *(int*)get(s,i) = *(int*)get(s,(s->used_size-1)-i);
            *(int*)get(s,(s->used_size-1)-i) = v1;
            continue;
        }
        double v1 = *(double*)get(s,i);

        #if logging
            printf("[log] - reverse(): Front-Value: %f\n",v1);
        #endif
        #if logging
            printf("[log] - reverse(): Back-Value: %f\n",((double*)s->array)[(s->used_size-1)-i]);
        #endif

        *(double*)get(s,i) = *(double*)get(s,(s->used_size-1)-i);
        *(double*)get(s,(s->used_size-1)-i) = v1;
        continue;
    }
    return 0;
}

char *array_to_string(struct array *s) {
    // if(s->t != INT) return (char)'a';
    char *str = (char*)calloc(s->used_size,sizeof(int));
    //ToDo: look-up-table
    // for(int i = 0; i < s->used_size; i++) {
    //     str[i] = (char)*(int*)get(s,i);
    //     printf("%d\n",*(int*)get(s,i));
    //     printf("%c\n",(char)(*(int*)get(s,i)));
    // }
    return str;
}