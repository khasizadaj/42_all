#include "./test.h"

void test_push_a_when_emptb(void)
{

}

void test_push_b_stack_becomes_empty()
{
    t_number *node_A = malloc(sizeof(t_number));
	t_number *node_B = malloc(sizeof(t_number));
    t_number *node_B_2 = malloc(sizeof(t_number));
    
    node_A->number = 1;
    node_A->next = NULL;

    node_B->number = 2;
    node_B->next = node_B_2;
    
    node_B_2->number = 3;
    node_B_2->next = NULL;
    

    printf("\nBefore push_b:\n\n");
    print_lists(node_A, node_B);

    push_b(&node_A, &node_B);

    printf("\nAfter push_b:\n\n");
    print_lists(node_A, node_B);

    if (node_B->number == 1 && !node_A && node_B->next->number == 2)
    {
        printf("\nPASS: push_b test passed!\n\n");
    }
    else
    {
        printf("\nFAIL: push_b test failed!\n\n");
    }
}

void test_push_b()
{
    t_number *node_A = malloc(sizeof(t_number));
	t_number *node_B = malloc(sizeof(t_number));
    t_number *node_A_2 = malloc(sizeof(t_number));
    t_number *node_B_2 = malloc(sizeof(t_number));
    
    node_A->number = 1;
    node_A->next = NULL;

    node_A->next = node_A_2;
    
    node_A_2->number = 4;
    node_A_2->next = NULL;

    node_B->number = 2;
    node_B->next = node_B_2;
    
    node_B_2->number = 3;
    node_B_2->next = NULL;
    

    printf("\nBefore push_b:\n\n");
    print_lists(node_A, node_B);

    push_b(&node_A, &node_B);

    printf("\nAfter push_b:\n\n");
    print_lists(node_A, node_B);

    if (node_A->number == 4 && !node_A->next && node_B->number == 1 && node_B->next->number == 2)
    {
        printf("\nPASS: push_b test passed!\n\n");
    }
    else
    {
        printf("\nFAIL: push_b test failed!\n\n");
    }
}

void test_push_a()
{
    t_number *node_A = malloc(sizeof(t_number));
	t_number *node_B = malloc(sizeof(t_number));
    t_number *node_A_2 = malloc(sizeof(t_number));
    t_number *node_B_2 = malloc(sizeof(t_number));
    
    node_A->number = 1;
    node_A->next = NULL;

    node_A->next = node_A_2;
    
    node_A_2->number = 4;
    node_A_2->next = NULL;

    node_B->number = 2;
    node_B->next = node_B_2;
    
    node_B_2->number = 3;
    node_B_2->next = NULL;
    

    printf("\nBefore push_b:\n\n");
    print_lists(node_A, node_B);

    push_a(&node_A, &node_B);

    printf("\nAfter push_b:\n\n");
    print_lists(node_A, node_B);

    if (node_A->number == 2 && node_A->next->number == 1 && node_B->number == 3 && !node_B->next)
    {
        printf("\nPASS: push_b test passed!\n\n");
    }
    else
    {
        printf("\nFAIL: push_b test failed!\n\n");
    }
}

void test_push_a_stack_becomes_empty()
{
	t_number *node_A = malloc(sizeof(t_number));
    t_number *node_A_2 = malloc(sizeof(t_number));
    t_number *node_B = malloc(sizeof(t_number));
    
    node_A->number = 2;
    node_A->next = node_A_2;
    
    node_A_2->number = 3;
    node_A_2->next = NULL;
    
	node_B->number = 1;
    node_B->next = NULL;

    printf("\nBefore push_a:\n\n");
    print_lists(node_A, node_B);

    push_a(&node_A, &node_B);

    printf("\nAfter push_a:\n\n");
    print_lists(node_A, node_B);

    if (node_A->number == 1 && node_A->next->number == 2 && !node_B)
    {
        printf("\nPASS: push_a test passed!\n\n");
    }
    else
    {
        printf("\nFAIL: push_a test failed!\n\n");
    }
}

void	test_push(void)
{
	test_push_b();
	test_push_b_stack_becomes_empty();
	test_push_a();
	test_push_a_stack_becomes_empty();
}