#include "./test.h"

void test_reverse_rotate_a_with_multiple_numbers()
{
    t_number *node1 = malloc(sizeof(t_number));
    t_number *node2 = malloc(sizeof(t_number));
    t_number *node3 = malloc(sizeof(t_number));
    t_number *node4 = malloc(sizeof(t_number));
    
    node1->number = 1;
    node1->next = node2;
    
    node2->number = 2;
    node2->next = node3;
    
    node3->number = 3;
    node3->next = node4;

    node4->number = 4;
    node4->next = NULL;


    printf("Before reverse_rotate_a:\n");
    print_list(node1);

    reverse_rotate_a(&node1);

    printf("After reverse_rotate_a:\n");
    print_list(node1);

    if (node1->number == 4 && node1->next->number == 1 && node1->next->next->next->number == 3)
    {
        printf("PASS: reverse_rotate_a test passed!\n\n");
    }
    else
    {
        printf("FAIL: reverse_rotate_a test failed!\n\n");
    }
}

void test_reverse_rotate_a_with_3_numbers()
{
    t_number *node1 = malloc(sizeof(t_number));
    t_number *node2 = malloc(sizeof(t_number));
    t_number *node3 = malloc(sizeof(t_number));
    
    node1->number = 1;
    node1->next = node2;
    
    node2->number = 2;
    node2->next = node3;
    
    node3->number = 3;
    node3->next = NULL;


    printf("Before reverse_rotate_a:\n");
    print_list(node1);

    reverse_rotate_a(&node1);

    printf("After reverse_rotate_a:\n");
    print_list(node1);

    if (node1->number == 3 && node1->next->number == 1 && node1->next->next->number == 2)
    {
        printf("PASS: reverse_rotate_a test passed!\n\n");
    }
    else
    {
        printf("FAIL: reverse_rotate_a test failed!\n\n");
    }
}

void test_reverse_rotate_both()
{
    t_number *node1 = malloc(sizeof(t_number));
    t_number *node2 = malloc(sizeof(t_number));
    t_number *node3 = malloc(sizeof(t_number));
    t_number *node4 = malloc(sizeof(t_number));
    
    node1->number = 1;
    node1->next = node2;
    
    node2->number = 2;
    node2->next = NULL;
    
    node3->number = 3;
    node3->next = node4;

    node4->number = 4;
    node4->next = NULL;


    printf("\nBefore push_b:\n\n");
    print_lists(node1, node3);

    reverse_rotate_both(&node1, &node3);

	printf("After push_b:\n\n");
    print_lists(node1, node3);

    if (node1->number == 2 && node1->next->number == 1 
		&& node3->number == 4 && node3->next->number == 3)
    {
        printf("PASS: reverse_reverse_rotate test passed!\n\n");
    }
    else
    {
        printf("FAIL: reverse_reverse_rotate test failed!\n\n");
    }
}

void test_reverse_rotate(void)
{
	test_reverse_rotate_a_with_3_numbers();
	test_reverse_rotate_a_with_multiple_numbers();
	test_reverse_rotate_both();
}