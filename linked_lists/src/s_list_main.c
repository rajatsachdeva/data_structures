/***********************************************************
*
* SINGLE LINKED LIST PROGRAM
*
* Add at start/ begining
* Add at end/ append
* Delete from Start/ begining
* Delete at END
* print list in normal order 
* print list in reverse order
* revrese the list
* iterate function generic
************************************************************/

#include "linked_list.h"

void print_data(int *item)
{
     printf("%d ", *item);
}

int  main(int argc, char **argv){
    
    list_node *head = NULL;
    
    int *data = NULL;   
    
    int i = 0;
    int *ec = NULL;
    for(i = 0; i < 10 ; i++)
    {
        data = (int *)malloc(sizeof(int));
        *data  = i;   
        head = add_at_start(head, (list_data_t)data);
        data = NULL;
    }
    printf("\n list 1\n");
    print_list(head);

    printf("\nlist 1_again\n");
    iterate_list(head, (iterate_func_t)print_data, NULL);

    ec = (int *)delete_from_start(&head);
    printf("\n%d was deleted", *ec);
    free(ec);
    ec = NULL;

    printf("\nlist 1_again\n");
    iterate_list(head, (iterate_func_t)print_data, NULL);
    ec = (int *)delete_from_end(head);
    printf("\n%d was deleted", *ec);
    free(ec);
    ec = NULL;

    printf("\nlist 1_again\n");
    iterate_list(head, (iterate_func_t)print_data, NULL);
	
    while(NULL != head)
    {
	ec = (int *)delete_from_start(&head);
	printf("\n%d was deleted\n", *ec);
	free(ec);
	ec = NULL;
    }
    return EXIT_SUCCESS;
}
