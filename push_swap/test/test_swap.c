#include "./test.h"

void test_swap_a_with_1_number()
{
    t_number *node1 = malloc(sizeof(t_number));
    
    node1->number = 1;
    node1->next = NULL;
    

    printf("Before swap_a:\n");
    print_list(node1);

    swap_a(&node1);

    printf("After swap_a:\n");
    print_list(node1);
    if (node1->number == 1 && node1->next == NULL)
    {
        printf("PASS: swap_a test passed!\n\n");
    }
    else
    {
        printf("FAIL: swap_a test failed!\n\n");
    }
}

void test_swap_a_with_2_numbers()
{
    t_number *node1 = malloc(sizeof(t_number));
    t_number *node2 = malloc(sizeof(t_number));
    
    node1->number = 1;
    node1->next = node2;
    
    node2->number = 2;
    node2->next = NULL;

    printf("Before swap_a:\n");
    print_list(node1);

    swap_a(&node1);

    printf("After swap_a:\n");
    print_list(node1);

    if (node1->number == 2 && node1->next->number == 1)
    {
        printf("PASS: swap_a test passed!\n\n");
    }
    else
    {
        printf("FAIL: swap_a test failed!\n\n");
    }
}

void	test_swap(void)
{
	test_swap_a_with_2_numbers();
	test_swap_a_with_1_number();
}