#include "./test.h"

void test_reverse_rotate_a_with_multiple_numbers()
{
    t_list *node_A = malloc(sizeof(t_list));
    t_list *node2 = malloc(sizeof(t_list));
    t_list *node3 = malloc(sizeof(t_list));
    t_list *node4 = malloc(sizeof(t_list));
    
    node_A->content = (void *) 1;
    node_A->next = node2;
    
    node2->content = (void *) 2;
    node2->next = node3;
    
    node3->content = (void *) 3;
    node3->next = node4;

    node4->content = (void *) 4;
    node4->next = NULL;


    printf("Before reverse_rotate_a:\n");
    print_list(node_A);

    reverse_rotate_a(&node_A);

    printf("After reverse_rotate_a:\n");
    print_list(node_A);

    if ((lli) node_A->content == 4 && (lli) node_A->next->content == 1 && (lli) node_A->next->next->next->content == 3)
    {
        printf("PASS: reverse_rotate_a test passed!\n\n");
    }
    else
    {
        printf("FAIL: reverse_rotate_a test failed!\n\n");
    }

	ft_lstclear_no_content(&node_A);
}

void test_reverse_rotate_a_with_3_numbers()
{
    t_list *node_A = malloc(sizeof(t_list));
    t_list *node2 = malloc(sizeof(t_list));
    t_list *node3 = malloc(sizeof(t_list));
    
    node_A->content = (void *) 1;
    node_A->next = node2;
    
    node2->content = (void *) 2;
    node2->next = node3;
    
    node3->content = (void *) 3;
    node3->next = NULL;


    printf("Before reverse_rotate_a:\n");
    print_list(node_A);

    reverse_rotate_a(&node_A);

    printf("After reverse_rotate_a:\n");
    print_list(node_A);

    if ((lli) node_A->content == 3 && (lli) node_A->next->content == 1 && (lli) node_A->next->next->content == 2)
    {
        printf("PASS: reverse_rotate_a test passed!\n\n");
    }
    else
    {
        printf("FAIL: reverse_rotate_a test failed!\n\n");
    }

	ft_lstclear_no_content(&node_A);
}

void test_reverse_rotate_both()
{
    t_list *node_A = malloc(sizeof(t_list));
    t_list *node2 = malloc(sizeof(t_list));
    t_list *node_B = malloc(sizeof(t_list));
    t_list *node4 = malloc(sizeof(t_list));
    
    node_A->content = (void *) 1;
    node_A->next = node2;
    
    node2->content = (void *) 2;
    node2->next = NULL;
    
    node_B->content = (void *) 3;
    node_B->next = node4;

    node4->content = (void *) 4;
    node4->next = NULL;


    printf("\nBefore push_b:\n\n");
    print_lists(node_A, node_B);

    reverse_rotate_both(&node_A, &node_B);

	printf("After push_b:\n\n");
    print_lists(node_A, node_B);

    if ((lli) node_A->content == 2 && (lli) node_A->next->content == 1 
		&& (lli) node_B->content == 4 && (lli) node_B->next->content == 3)
    {
        printf("PASS: reverse_reverse_rotate test passed!\n\n");
    }
    else
    {
        printf("FAIL: reverse_reverse_rotate test failed!\n\n");
    }

	ft_lstclear_no_content(&node_A);
	ft_lstclear_no_content(&node_B);
}

void test_reverse_rotate(void)
{
	test_reverse_rotate_a_with_3_numbers();
	test_reverse_rotate_a_with_multiple_numbers();
	test_reverse_rotate_both();
}