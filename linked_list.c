# include <libft.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *	ptr;

	if (lst && *lst)
	{
		ptr = *lst;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
	else if (lst)
		*lst = new;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

t_list *	ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list *	ft_lstnew(alloc_ctx_t ctx, void *data)
{
	t_list	*lst;

	lst = alloc(sizeof(t_list), ctx._allocptr, ctx._type);
	if (!lst)
		return (ft_fprintf(2, "ft_lstnew:\n%s\n", arena_geterrlog(g_arena_err)), NULL);
	lst->data = data;
	lst->next = NULL;
	return (lst);
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
