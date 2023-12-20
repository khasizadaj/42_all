#include "test.h"

void test_get_cheapest()
{
    t_list *node_A = malloc(sizeof(t_list));
	t_list *node_B = malloc(sizeof(t_list));
    t_list *node_A_2 = malloc(sizeof(t_list));
    t_list *node_A_3 = malloc(sizeof(t_list));
    t_list *node_A_4 = malloc(sizeof(t_list));
    t_list *node_B_2 = malloc(sizeof(t_list));
    t_list *node_B_3 = malloc(sizeof(t_list));
	int			*steps;
    
    node_A->content = (void *) 1;
    node_A->next = node_A_2;
    
    node_A_2->content = (void *) 9;
    node_A_2->next = node_A_3;

    node_A_3->content = (void *) 7;
    node_A_3->next = node_A_4;

    node_A_4->content = (void *) 8;
    node_A_4->next = NULL;

    node_B->content = (void *) 4;
    node_B->next = node_B_2;
    
    node_B_2->content = (void *) 3;
    node_B_2->next = node_B_3;
    
	node_B_3->content = (void *) 2;
    node_B_3->next = NULL;

    printf("\nLISTS for get_cheapest:\n\n");
    // print_lists(node_A, node_B);

    steps = get_cheapest(node_A, node_B);

    if (steps[7] == 'x')
    {
        printf("\nPASS: push_b test passed!\n\n");
    }
    else
    {
        printf("\nFAIL: push_b test failed!\n\n");
    }
}


void	test_algorithm(void)
{
	test_get_cheapest();
}