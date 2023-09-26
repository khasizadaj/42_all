#include "libft.h"

// A custom function to apply to list elements
void *custom_function(void *content)
{
    // Assuming the content is an integer pointer, double it
    int *num = (int *)content;
    int *result = malloc(sizeof(int));
    if (result)
        *result = (*num) * 2;
    return result;
}

// A custom function to delete the content of a list node
void custom_delete(void *content)
{
    free(content);
}

int main(void)
{
    // Create a linked list with some integer values
    t_list *lst = NULL;
    for (int i = 1; i <= 5; i++)
    {
        int *num = malloc(sizeof(int));
        if (num)
        {
            *num = i;
            ft_lstadd_back(&lst, ft_lstnew(num));
        }
    }

    // Print the original list
    printf("Original List: ");
    t_list *current = lst;
    while (current)
    {
        int *num = (int *)(current->content);
        printf("%d ", *num);
        current = current->next;
    }
    printf("\n");

    // Apply ft_lstmap with custom_function
    t_list *new_list = ft_lstmap(lst, custom_function, custom_delete);

    // Print the new list after applying the custom_function
    printf("New List (after custom_function): ");
    current = new_list;
    while (current)
    {
        int *num = (int *)(current->content);
        printf("%d ", *num);
        current = current->next;
    }
    printf("\n");

    // Clean up memory
    ft_lstclear(&lst, custom_delete);
    ft_lstclear(&new_list, custom_delete);
    // free(new_list);

    return 0;
}
