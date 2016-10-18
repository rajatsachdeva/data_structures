/***********************************************
*
*       linked_list.h
*
***********************************************/
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* data structure type */
typedef void* list_data_t;

typedef struct list_node_t {
    struct list_node_t* next;
    list_data_t data;
}list_node;

/* Function Pointer type */
typedef void (*iterate_func_t)(list_data_t data); //iterate_func_t;

/* List Fucntion prototypes */
list_node*
add_at_start( list_node* head,
              void  *data);

list_node*
add_at_end(list_node* head,
           list_data_t data);

/*
int add_in_between(
                  list_node* head,
                int position, int data) ;
*/

list_data_t
delete_from_start(list_node **head);

list_data_t
delete_from_end(list_node *head);

/*list_node*
delete_data(list_node *head,
            list_data_t data);
*/

void iterate_list(list_node* head, 
                  iterate_func_t func, 
                  list_data_t data);

void print_list(list_node* head);

#endif /* LINKED_LIST_H */

