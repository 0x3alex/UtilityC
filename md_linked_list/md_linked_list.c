#include "include/md_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

void create_md_ll(_md_ll *l, enum dimension d, void *data) {
    l->data = data;
    l->d = d;
    /*
    *   Single & double linked list pointers to null
    */
    l->x_next = NULL;
    l->y_next = NULL;
    l->z_next = NULL;

    /*
    *   Double linked list pointers to null
    */
    l->x_prev = NULL;
    l->y_prev = NULL;
    l->z_prev = NULL;
}

/*
*   ===================
*       X-Axis
*/
void push_x(_md_ll *l, void *data) {
    _md_ll *last = get_last_x(l);

    last->x_next = calloc(1,sizeof(_md_ll));
    last->x_next->data = data;

    /*
    *   Set all default to null and change afterwards if needed
    */
    last->x_next->x_next = NULL;
    last->x_next->y_next = NULL;
    last->x_next->z_next = NULL;

    last->x_next->x_prev = NULL;
    last->x_next->y_prev = NULL;
    last->x_next->z_prev = NULL;

    last->x_next->x_prev = last;
    printf("%p\n",last->x_next);
    /*
    *   Get possible node above new node
    */
    if(last->y_prev != NULL) { //check if last node has one above
        if(last->y_prev->x_next != NULL) { //check if one above has next node
            puts("1");
            last->y_prev->x_next->y_next = last->x_next; 

            last->x_next->y_prev = last->y_prev->x_next;
        }
   }

    /*
    *    Get possible node below new node
    */
    if(last->y_next != NULL) { //check if last node has one below
        if(last->y_next->x_next != NULL) { //check if one below has next node
            last->y_next->x_next->y_prev = last->x_next;
            last->x_next->y_next = last->y_next->x_next;
        }
    }
    /*
    *   If its 3D do the same for z-axis
    */
    if(l->d == _3D) {
        if(last->z_prev != NULL) {
            if(last->z_prev->x_next != NULL) {
                last->z_prev->x_next->z_next = last->x_next;
                last->x_next->z_prev = last->z_prev->x_next;
            }
        }
        if(last->z_next != NULL) {
            if(last->z_next->x_next != NULL) {
                last->z_next->x_next->z_prev = l->x_next;
                l->x_next->z_next = last->z_next->x_next;
            }
        }
    }
}

void pop_x(_md_ll *l, void *data) {
    _md_ll *last = get_last_x(l);

    /*
    *  Remvove reference from all neighbouring nodes
    */
    last->x_prev->x_next = NULL;
    last->y_prev->y_next = NULL;
    last->y_next->y_prev = NULL;
    last->z_next->z_prev = NULL;
    last->z_prev->z_next = NULL;

    free(last);
}
/*  =================== */

/*
*   ===================
*       Y-Axis
*/

void push_y(_md_ll *l, void *data) {
    static int i;
    _md_ll *last = get_last_y(l);
    last->y_next = calloc(1,sizeof(_md_ll));
    last->y_next->data = data;

    #if LOGGING
        printf("%d Last->y_next: %p\n",i++,last->y_next);
    #endif

    /*
    *   Set all default to null and change afterwards if needed
    */
    last->y_next->x_next = NULL;
    last->y_next->y_next = NULL;
    last->y_next->z_next = NULL;

    last->y_next->x_prev = NULL;
    last->y_next->y_prev = NULL;
    last->y_next->z_prev = NULL;

    last->y_next->y_prev = last;

    if(last->x_prev != NULL) {
        if(last->x_prev->y_next != NULL) {
            last->x_prev->y_next->x_next = last->y_next;
            last->y_next->x_prev = last->x_prev->y_next;
            #if LOGGING
                printf("last->x_prev->y_next->x_next: %p\n", last->x_prev->y_next->x_next);
                printf("last->x_prev->y_next: %p\n",last->x_prev->y_next);
            #endif
        }
    }

    if(last->x_next != NULL) {
        if(last->x_next->y_next != NULL) {
            last->x_next->y_next->x_prev = last->y_next;
            last->y_next->x_next = last->x_next->y_next;
            #if LOGGING
                printf("last->x_next->y_next->x_prev: %p\n", last->x_next->y_next->x_prev);
                printf("last->y_next->x_next: %p\n",last->y_next->x_next);
            #endif
        }
    }

    if(l->d == _3D) {
        if(last->z_next != NULL) {
            if(last->z_next->y_next != NULL) {
                last->z_next->y_next->z_prev = last->y_next;
                last->y_next = last->z_next->y_next;
                #if LOGGING
                #endif
            }
        }
        if(last->z_prev != NULL) {
            if(last->z_prev->y_next != NULL) {
                last->z_prev->y_next->z_next = last->y_next;
                last->y_next = last->z_prev->y_next;
                #if LOGGING
                #endif
            }
        }
    }

}

void pop_y(_md_ll *l, void *data) {
    _md_ll *last = get_last_y(l);

    /*
    *  Remvove reference from all neighbouring nodes
    */
    last->x_prev->x_next = NULL;
    last->x_next->y_prev = NULL;
    last->y_prev->y_next = NULL;
    last->z_next->z_prev = NULL;
    last->z_prev->z_next = NULL;

    free(last);
}

/*  =================== */

/*
*   =========================
*       Helper Functions
*/
_md_ll *get_last_x(_md_ll *l) {
    if(l->x_next != NULL) {
        get_last_x(l->x_next);
    }else{
        return l;
    }
}

_md_ll *get_last_y(_md_ll *l) {
    if(l->y_next != NULL) {
        get_last_y(l->y_next);
    }else{
        return l;
    }
}

_md_ll *get_last_z(_md_ll *l) {
    if(l->z_next != NULL) {
        get_last_z(l->z_next);
    }else{
        return l;
    }
}
/*  =========================   */