#include "test.h"

void test_get_cheapest()
{
    t_list *node_A = malloc(sizeof(t_list));
	t_list *node_B = malloc(sizeof(t_list));
    t_list *node_A_2 = malloc(sizeof(t_list));
    t_list *node_A_3 = malloc(sizeof(t_list));
    t_list *node_A_4 = malloc(sizeof(t_list));
    t_list *node_A_5 = malloc(sizeof(t_list));
    t_list *node_B_2 = malloc(sizeof(t_list));
    t_list *node_B_3 = malloc(sizeof(t_list));
    t_list *node_B_4 = malloc(sizeof(t_list));
	int			*steps;
    
    node_A->content = (void *) 1;
    node_A->next = node_A_2;
    
    node_A_2->content = (void *) 9;
    node_A_2->next = node_A_3;

    node_A_3->content = (void *) 13;
    node_A_3->next = node_A_4;

    node_A_4->content = (void *) -10;
    node_A_4->next = node_A_5;

    node_A_5->content = (void *) 6;
    node_A_5->next = NULL;

    node_B->content = (void *) -5;
    node_B->next = node_B_2;
    
    node_B_2->content = (void *) 12;
    node_B_2->next = node_B_3;
    
	node_B_3->content = (void *) 7;
    node_B_3->next = node_B_4;

	node_B_4->content = (void *) 5;
    node_B_4->next = NULL;

    printf("\nLISTS for get_cheapest:\n\n");
    print_lists(node_A, node_B);

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

void	test_get_location_4_b()
{
    t_list *node_A = malloc(sizeof(t_list));
    t_list *node_A_2 = malloc(sizeof(t_list));
    t_list *node_A_3 = malloc(sizeof(t_list));
    t_list *node_A_4 = malloc(sizeof(t_list));

    node_A->content = (void *) 2;
    node_A->next = node_A_2;
    
    node_A_2->content = (void *) 9;
    node_A_2->next = node_A_3;

    node_A_3->content = (void *) 7;
    node_A_3->next = node_A_4;

    node_A_4->content = (void *) 6;
    node_A_4->next = NULL;

	print_list(node_A);

	lli val = 5;
	lli ret = get_location_to_move(val, node_A);
	lli exp = 0;
	if (ret == exp)
	{
        printf("\nPASS: get_location_to_move(%lld, node_A)=%lld [%lld] test passed!\n", val, ret, exp);
	}
    else
	{
        printf("\nFAIL: get_location_to_move(%lld, node)=%lld [%lld] test failed!\n", val, ret, exp);
	}

	val = 0;
	ret = get_location_to_move(val, node_A);
	exp = 1;
	if (ret == exp)
	{
        printf("\nPASS: get_location_to_move(%lld, node_A)=%lld [%lld] test passed!\n", val, ret, exp);
	}
    else
	{
        printf("\nFAIL: get_location_to_move(%lld, node)=%lld [%lld] test failed!\n", val, ret, exp);
	}

	val = -5;
	ret = get_location_to_move(val, node_A);
	exp = 1;
	if (ret == exp)
	{
        printf("\nPASS: get_location_to_move(%lld, node_A)=%lld [%lld] test passed!\n", val, ret, exp);
	}
    else
	{
        printf("\nFAIL: get_location_to_move(%lld, node)=%lld [%lld] test failed!\n", val, ret, exp);
	}

	val = 10;
	ret = get_location_to_move(val, node_A);
	exp = 1;
	if (ret == exp)
	{
        printf("\nPASS: get_location_to_move(%lld, node_A)=%lld [%lld] test passed!\n", val, ret, exp);
	}
    else
	{
        printf("\nFAIL: get_location_to_move(%lld, node)=%lld [%lld] test failed!\n", val, ret, exp);
	}

	val = 8;
	ret = get_location_to_move(val, node_A);
	exp = 2;
	if (ret == exp)
	{
        printf("\nPASS: get_location_to_move(%lld, node_A)=%lld [%lld] test passed!\n", val, ret, exp);
	}
    else
	{
        printf("\nFAIL: get_location_to_move(%lld, node)=%lld [%lld] test failed!\n", val, ret, exp);
	}
}

void	test_get_location_first_is_biggest()
{
    t_list *node_A = malloc(sizeof(t_list));
    t_list *node_A_2 = malloc(sizeof(t_list));
    t_list *node_A_3 = malloc(sizeof(t_list));
    t_list *node_A_4 = malloc(sizeof(t_list));

    node_A->content = (void *) 10;
    node_A->next = node_A_2;
    
    node_A_2->content = (void *) 9;
    node_A_2->next = node_A_3;

    node_A_3->content = (void *) 7;
    node_A_3->next = node_A_4;

    node_A_4->content = (void *) 6;
    node_A_4->next = NULL;

	print_list(node_A);

	lli val = 5;
	lli ret = get_location_to_move(val, node_A);
	lli exp = 0;
	if (ret == exp)
	{
        printf("\nPASS: get_location_to_move(%lld, node_A)=%lld [%lld] test passed!\n", val, ret, exp);
	}
    else
	{
        printf("\nFAIL: get_location_to_move(%lld, node)=%lld [%lld] test failed!\n", val, ret, exp);
	}

	val = 0;
	ret = get_location_to_move(val, node_A);
	exp = 0;
	if (ret == exp)
	{
        printf("\nPASS: get_location_to_move(%lld, node_A)=%lld [%lld] test passed!\n", val, ret, exp);
	}
    else
	{
        printf("\nFAIL: get_location_to_move(%lld, node)=%lld [%lld] test failed!\n", val, ret, exp);
	}

	val = -5;
	ret = get_location_to_move(val, node_A);
	exp = 0;
	if (ret == exp)
	{
        printf("\nPASS: get_location_to_move(%lld, node_A)=%lld [%lld] test passed!\n", val, ret, exp);
	}
    else
	{
        printf("\nFAIL: get_location_to_move(%lld, node)=%lld [%lld] test failed!\n", val, ret, exp);
	}

	val = 11;
	ret = get_location_to_move(val, node_A);
	exp = 0;
	if (ret == exp)
	{
        printf("\nPASS: get_location_to_move(%lld, node_A)=%lld [%lld] test passed!\n", val, ret, exp);
	}
    else
	{
        printf("\nFAIL: get_location_to_move(%lld, node)=%lld [%lld] test failed!\n", val, ret, exp);
	}

	val = 8;
	ret = get_location_to_move(val, node_A);
	exp = 2;
	if (ret == exp)
	{
        printf("\nPASS: get_location_to_move(%lld, node_A)=%lld [%lld] test passed!\n", val, ret, exp);
	}
    else
	{
        printf("\nFAIL: get_location_to_move(%lld, node)=%lld [%lld] test failed!\n", val, ret, exp);
	}
}

void	test_algorithm(void)
{
	test_get_cheapest();
	// test_get_location_first_is_biggest();
	// test_get_location_4_b();
}