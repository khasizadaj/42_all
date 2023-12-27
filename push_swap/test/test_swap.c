#include "./test.h"

void test_swap_a_with_1_number()
{
    t_list *node_A = malloc(sizeof(t_list));
    
    node_A->content = (void *) 1;
    node_A->next = NULL;
    

    printf("Before swap_a:\n");
    print_list(node_A);

    swap_a(&node_A);

    printf("After swap_a:\n");
    print_list(node_A);
    if ((lli) node_A->content == 1 && node_A->next == NULL)
    {
        printf("PASS: swap_a test passed!\n\n");
    }
    else
    {
        printf("FAIL: swap_a test failed!\n\n");
    }

	ft_lstclear_no_content(&node_A);
}

void test_swap_a_with_2_numbers()
{
    t_list *node_A = malloc(sizeof(t_list));
    t_list *node2 = malloc(sizeof(t_list));
    
    node_A->content = (void *) 1;
    node_A->next = node2;
    
    node2->content = (void *) 2;
    node2->next = NULL;

    printf("Before swap_a:\n");
    print_list(node_A);

    swap_a(&node_A);

    printf("After swap_a:\n");
    print_list(node_A);

    if ((lli) node_A->content == 2 && (lli) node_A->next->content == 1)
    {
        printf("PASS: swap_a test passed!\n\n");
    }
    else
    {
        printf("FAIL: swap_a test failed!\n\n");
    }

	ft_lstclear_no_content(&node_A);
}

void	test_swap(void)
{
	test_swap_a_with_2_numbers();
	test_swap_a_with_1_number();
}