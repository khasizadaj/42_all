#include "./test.h"

void test_rotate_a_with_multiple_numbers()
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


    printf("Before roate_a:\n");
    print_list(node_A);

    rotate_a(&node_A);

    printf("After roate_a:\n");
    print_list(node_A);

    if ((lli) node_A->content == 2 && (lli) node_A->next->content == 3 && (lli) node_A->next->next->next->content == 1)
    {
        printf("PASS: roate_a test passed!\n\n");
    }
    else
    {
        printf("FAIL: roate_a test failed!\n\n");
    }

	ft_lstclear_no_content(&node_A);
}

void test_rotate_a_with_3_numbers()
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


    printf("Before roate_a:\n");
    print_list(node_A);

    rotate_a(&node_A);

    printf("After roate_a:\n");
    print_list(node_A);

    if ((lli) node_A->content == 2 && (lli) node_A->next->content == 3 && (lli) node_A->next->next->content == 1)
    {
        printf("PASS: roate_a test passed!\n\n");
    }
    else
    {
        printf("FAIL: roate_a test failed!\n\n");
    }

	ft_lstclear_no_content(&node_A);
}

void test_rotate_both()
{
    t_list *node_A = malloc(sizeof(t_list));
    t_list *node2 = malloc(sizeof(t_list));
    t_list *node3 = malloc(sizeof(t_list));
    t_list *node_B = malloc(sizeof(t_list));
    t_list *node5 = malloc(sizeof(t_list));
    t_list *node6 = malloc(sizeof(t_list));
    
    node_A->content = (void *) 1;
    node_A->next = node2;
    
    node2->content = (void *) 2;
    node2->next = node3;
    
    node3->content = (void *) 3;
    node3->next = NULL;

    node_B->content = (void *) 4;
    node_B->next = node5;

    node5->content = (void *) 5;
    node5->next = node6;

    node6->content = (void *) 6;
    node6->next = NULL;

    printf("\nBefore rotate_both:\n\n");
    print_lists(node_A, node_B);

    rotate_both(&node_A, &node_B);

	printf("After rotate_both:\n\n");
    print_lists(node_A, node_B);

    if ((lli) node_A->content == 2 && (lli) node_A->next->next->content == 1 
		&& (lli) node_B->content == 5 && (lli) node_B->next->next->content == 4)
    {
        printf("PASS: rotate_both test passed!\n\n");
    }
    else
    {
        printf("FAIL: rotate_both test failed!\n\n");
    }

	ft_lstclear_no_content(&node_A);
	ft_lstclear_no_content(&node_B);
}

void test_rotate(void)
{
	test_rotate_a_with_3_numbers();
	test_rotate_a_with_multiple_numbers();
	test_rotate_both();
}