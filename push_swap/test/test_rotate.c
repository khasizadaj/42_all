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

void test_rotate(void)
{
	test_rotate_a_with_3_numbers();
	test_rotate_a_with_multiple_numbers();
}