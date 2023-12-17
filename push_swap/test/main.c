#include "../include/push_swap.h"

void print_list(t_number *stack)
{
    while (stack != NULL)
    {
        printf("%d -> ", stack->number);
        stack = stack->next;
    }
    printf("NULL\n");
}

void test_reverse_a_with_multiple_numbers()
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


    printf("Before reverse_a:\n");
    print_list(node1);

    reverse_a(&node1);

    printf("After reverse_a:\n");
    print_list(node1);

    if (node1->number == 2 && node1->next->number == 3 && node1->next->next->next->number == 1)
    {
        printf("PASS: reverse_a test passed!\n\n");
    }
    else
    {
        printf("FAIL: reverse_a test failed!\n\n");
    }
}

void test_reverse_a_with_3_numbers()
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


    printf("Before reverse_a:\n");
    print_list(node1);

    reverse_a(&node1);

    printf("After reverse_a:\n");
    print_list(node1);

    if (node1->number == 2 && node1->next->number == 3 && node1->next->next->number == 1)
    {
        printf("PASS: reverse_a test passed!\n\n");
    }
    else
    {
        printf("FAIL: reverse_a test failed!\n\n");
    }
}

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

int main(void)
{
	test_swap_a_with_2_numbers();
	test_swap_a_with_1_number();
	test_reverse_a_with_3_numbers();
	test_reverse_a_with_multiple_numbers();

    return (0);
}
