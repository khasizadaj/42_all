#include "./test.h"

void test_rotate_a_with_multiple_numbers()
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


    printf("Before roate_a:\n");
    print_list(node1);

    rotate_a(&node1);

    printf("After roate_a:\n");
    print_list(node1);

    if (node1->number == 2 && node1->next->number == 3 && node1->next->next->next->number == 1)
    {
        printf("PASS: roate_a test passed!\n\n");
    }
    else
    {
        printf("FAIL: roate_a test failed!\n\n");
    }
}

void test_rotate_a_with_3_numbers()
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


    printf("Before roate_a:\n");
    print_list(node1);

    rotate_a(&node1);

    printf("After roate_a:\n");
    print_list(node1);

    if (node1->number == 2 && node1->next->number == 3 && node1->next->next->number == 1)
    {
        printf("PASS: roate_a test passed!\n\n");
    }
    else
    {
        printf("FAIL: roate_a test failed!\n\n");
    }
}

void test_rotate_both()
{
    t_number *STACK_A = malloc(sizeof(t_number));
    t_number *node2 = malloc(sizeof(t_number));
    t_number *node3 = malloc(sizeof(t_number));
    t_number *STACK_B = malloc(sizeof(t_number));
    t_number *node5 = malloc(sizeof(t_number));
    t_number *node6 = malloc(sizeof(t_number));
    
    STACK_A->number = 1;
    STACK_A->next = node2;
    
    node2->number = 2;
    node2->next = node3;
    
    node3->number = 3;
    node3->next = NULL;

    STACK_B->number = 4;
    STACK_B->next = node5;

    node5->number = 5;
    node5->next = node6;

    node6->number = 6;
    node6->next = NULL;

    printf("\nBefore rotate_both:\n\n");
    print_lists(STACK_A, STACK_B);

    rotate_both(&STACK_A, &STACK_B);

	printf("After rotate_both:\n\n");
    print_lists(STACK_A, STACK_B);

    if (STACK_A->number == 2 && STACK_A->next->next->number == 1 
		&& STACK_B->number == 5 && STACK_B->next->next->number == 4)
    {
        printf("PASS: rotate_both test passed!\n\n");
    }
    else
    {
        printf("FAIL: rotate_both test failed!\n\n");
    }
}

void test_rotate(void)
{
	test_rotate_a_with_3_numbers();
	test_rotate_a_with_multiple_numbers();
	test_rotate_both();
}