/***********************************************
*
* singly_linked_list.c
*
* defines the single linked list functions.
*
***********************************************/

#include "linked_list.h"

/*********************************************
**
** Addition/Insertion of Data in List at 
** the begining of the list.
**
********************************************/
list_node*
add_at_start( list_node* head,
               void  *data) {

    list_node  *temp_node = NULL;
    temp_node = (list_node *)malloc(sizeof(list_node));
    temp_node->next = head;
    temp_node->data = data;
    head = temp_node;

    return head;
}

/*********************************************
**
** Addition/Insertion of Data in List at
** the End of the list.
**
********************************************/
list_node*
add_at_end(
           list_node* head,
           list_data_t data) {

    list_node* temp_node = NULL;

    if(NULL == head) {

        temp_node = (list_node*)malloc(sizeof(list_node));
        temp_node->next = NULL;
        temp_node->data = data;
        head = temp_node;

    } else {

        temp_node = head;
        while (temp_node->next != NULL) {
            temp_node = temp_node->next;
        }
        temp_node->next = (list_node *)malloc(sizeof(list_node));
        temp_node->next->next = NULL;
        temp_node->next->data = data;
    }
    return head;
}

/*********************************************
**
** Addition/Insertion of Data in List at a
** specific position in the list.
**
********************************************/

/*
int add_in_between(
                  list_node* head,
                int position, int data) ;
*/


/*********************************************
**
** Removal/Deletion of Data from List from
** start.
**
********************************************/
list_data_t
delete_from_start(list_node **head) {

    list_data_t temp_data = NULL;
    list_node *temp_node = NULL;

    if(NULL == *head) {

     //   printf("Nothing to POP\n");
        return NULL;
    }
    else {
        temp_node = *head;
        *head = temp_node->next;
        temp_data = temp_node->data;
        free(temp_node);
        return temp_data;
    }
}

/*********************************************
**
** Removal/Deletion of Data from List at
** end.
**
********************************************/
list_data_t
delete_from_end(list_node *head) {

    list_data_t temp_data = NULL;
    list_node *temp_node = head;

    if(NULL == head) {
        return NULL;
    }
    else if(head->next  == NULL){
        temp_data = head->data;
        free(head);
        return temp_data;
    }
    else {

        while(NULL != temp_node->next->next){
            temp_node = temp_node->next;
        }
        temp_data = temp_node->next->data;
        free(temp_node->next);
        temp_node->next = NULL;
        return temp_data;
    }
}

/*********************************************
**
** iterate the list from start to end 
** and call the function defined by the user.
**
********************************************/
void iterate_list(list_node* head, 
                  iterate_func_t func, 
                  list_data_t data) {

    list_node *temp_node = head;
    while(NULL != temp_node){
        func(temp_node->data);
        temp_node = temp_node->next;
    }
}

/*********************************************
**
** Print the list from start to end
**
********************************************/
void print_list(list_node* head) {

    list_node* temp_node = NULL;
    if(NULL == head) {
        printf("List is empty \n");
    }
    else
    {
        temp_node = head;
        while(NULL != temp_node)
        {
            printf("%d ", *(int *)temp_node->data);
            temp_node = temp_node->next;
        }
    }
}

