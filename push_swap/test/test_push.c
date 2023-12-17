#include "./test.h"

void test_push_a_when_empty(void)
{

}

void test_push_a()
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
    

    printf("Before push_a:\n");
    print_lists(node_A, node_B);

    // push_a(&node_A, &node_B);

    printf("After push_a:\n");
    print_lists(node_A, node_B);

    if (node_A->number == 2 && !node_A->next&& node_A->next->number == 1)
    {
        printf("PASS: swap_a test passed!\n\n");
    }
    else
    {
        printf("FAIL: swap_a test failed!\n\n");
    }
}

void	test_push(void)
{
	test_push_a();
}