
#include "libft.h"
#include "libgc.h"

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

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	free(lst);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lstnew(t_garb *gc, void *data)
{
	t_list	*lst;

	lst = (t_list *)allocate(sizeof(t_list),gc);
	if (!lst)
		return (NULL);

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
