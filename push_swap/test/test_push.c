#include "./test.h"

void test_push_a_when_emptb(void)
{

}

void test_push_b_stack_becomes_empty()
{
    t_list *node_A = malloc(sizeof(t_list));
	t_list *node_B = malloc(sizeof(t_list));
    t_list *node_B_2 = malloc(sizeof(t_list));
    
    node_A->content = (void *) 1;
    node_A->next = NULL;

    node_B->content = (void *) 2;
    node_B->next = node_B_2;
    
    node_B_2->content = (void *) 3;
    node_B_2->next = NULL;
    

    printf("\nBefore push_b:\n\n");
    print_lists(node_A, node_B);

    push_b(&node_A, &node_B);

    printf("\nAfter push_b:\n\n");
    print_lists(node_A, node_B);

    if ((lli) node_B->content == 1 && !node_A && (lli) node_B->next->content == 2)
    {
        printf("\nPASS: push_b test passed!\n\n");
    }
    else
    {
        printf("\nFAIL: push_b test failed!\n\n");
    }

	ft_lstclear_no_content(&node_A);
	ft_lstclear_no_content(&node_B);
}

void test_push_b()
{
    t_list *node_A = malloc(sizeof(t_list));
	t_list *node_B = malloc(sizeof(t_list));
    t_list *node_A_2 = malloc(sizeof(t_list));
    t_list *node_B_2 = malloc(sizeof(t_list));
    
    node_A->content = (void *)(void *) 1;
    node_A->next = NULL;

    node_A->next = node_A_2;
    
    node_A_2->content = (void *)4;
    node_A_2->next = NULL;

    node_B->content = (void *)2;
    node_B->next = node_B_2;
    
    node_B_2->content = (void *)3;
    node_B_2->next = NULL;
    

    printf("\nBefore push_b:\n\n");
    print_lists(node_A, node_B);

    push_b(&node_A, &node_B);

    printf("\nAfter push_b:\n\n");
    print_lists(node_A, node_B);

    if ((lli) node_A->content == 4 && !node_A->next && (lli) node_B->content == 1 && (lli) node_B->next->content == 2)
    {
        printf("\nPASS: push_b test passed!\n\n");
    }
    else
    {
        printf("\nFAIL: push_b test failed!\n\n");
    }

	ft_lstclear_no_content(&node_A);
	ft_lstclear_no_content(&node_B);
}

void test_push_a()
{
    t_list *node_A = malloc(sizeof(t_list));
	t_list *node_B = malloc(sizeof(t_list));
    t_list *node_A_2 = malloc(sizeof(t_list));
    t_list *node_B_2 = malloc(sizeof(t_list));
    
    node_A->content = (void *)1;
    node_A->next = NULL;

    node_A->next = node_A_2;
    
    node_A_2->content = (void *)4;
    node_A_2->next = NULL;

    node_B->content = (void *)2;
    node_B->next = node_B_2;
    
    node_B_2->content = (void *)3;
    node_B_2->next = NULL;
    

    printf("\nBefore push_b:\n\n");
    print_lists(node_A, node_B);

    push_a(&node_A, &node_B);

    printf("\nAfter push_b:\n\n");
    print_lists(node_A, node_B);

    if ((lli) node_A->content == 2 && (lli) node_A->next->content == 1 && (lli) node_B->content == 3 && !node_B->next)
    {
        printf("\nPASS: push_b test passed!\n\n");
    }
    else
    {
        printf("\nFAIL: push_b test failed!\n\n");
    }

	ft_lstclear_no_content(&node_A);
	ft_lstclear_no_content(&node_B);
}

void test_push_a_stack_becomes_empty()
{
	t_list *node_A = malloc(sizeof(t_list));
    t_list *node_A_2 = malloc(sizeof(t_list));
    t_list *node_B = malloc(sizeof(t_list));
    
    node_A->content = (void *)2;
    node_A->next = node_A_2;
    
    node_A_2->content = (void *)3;
    node_A_2->next = NULL;
    
	node_B->content = (void *)1;
    node_B->next = NULL;

    printf("\nBefore push_a:\n\n");
    print_lists(node_A, node_B);

    push_a(&node_A, &node_B);

    printf("\nAfter push_a:\n\n");
    print_lists(node_A, node_B);

    if ((lli) node_A->content == 1 && (lli) node_A->next->content == 2 && !node_B)
    {
        printf("\nPASS: push_a test passed!\n\n");
    }
    else
    {
        printf("\nFAIL: push_a test failed!\n\n");
    }

	ft_lstclear_no_content(&node_A);
	ft_lstclear_no_content(&node_B);
}

void	test_push(void)
{
	test_push_b();
	test_push_b_stack_becomes_empty();
	test_push_a();
	test_push_a_stack_becomes_empty();
}