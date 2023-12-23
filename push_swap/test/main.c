#include "./test.h"

void print_list(t_list *stack)
{
    while (stack != NULL)
    {
        printf("%lld -> ", (lli) stack->content);
        stack = stack->next;
    }
    printf("NULL\n");
}

void print_lists(t_list *stack_a, t_list *stack_b)
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
	        printf("%lld\t|", (lli) stack_a->content);
			stack_a = stack_a->next;
		}
		else
	        printf("\t|");
		if (stack_b)
	    {
		    printf(" %lld\t|\n", (lli) stack_b->content);
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
	// test_swap();
	// test_rotate();
	// test_reverse_rotate();
	// test_push();
	test_algorithm();

    return (0);
}
