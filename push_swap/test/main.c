#include "./test.h"

void print_list(t_number *stack)
{
    while (stack != NULL)
    {
        printf("%d -> ", stack->number);
        stack = stack->next;
    }
    printf("NULL\n");
}


void print_lists(t_number *stack_a, t_number *stack_b)
{
	int	i;

	ft_printf("--------:-------:--------\n", 0x2605);
	ft_printf(" #\t| A\t| B\t|\n");
	ft_printf("--------◘-------◘--------\n");
	i = 0;
	while (stack_a != NULL || stack_b != NULL)
    {
        printf(" %d\t|", i);
		if (stack_a)
		{
	        printf(" %d\t|", stack_a->number);
			stack_a = stack_a->next;
		}
		else
	        printf("\t|");
		if (stack_b)
	    {
		    printf(" %d\t|\n", stack_b->number);
			stack_b = stack_b->next;
		}
		else
	        printf("\t|\n");
		i++;
    }
	ft_printf("¯¯¯¯¯¯¯¯°¯¯¯¯¯¯¯°¯¯¯¯¯¯¯¯\n", 0x2605);
}

int main(void)
{
	test_swap();
	test_rotate();
	test_reverse_rotate();
	test_push();

    return (0);
}
