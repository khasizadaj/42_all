#include "libft.h"

int main()
{
    t_list *list;

    list = ft_lstnew("HEYY");
    printf("Content: %s", (char *) list->content);
}