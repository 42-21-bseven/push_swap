#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list *newelement;

	newelement = (t_list *)malloc(sizeof(t_list));
	if (newelement)
	{
		newelement->vol = content;
		newelement->next = NULL;
	}
	else
		return (NULL);
	newelement->stage = 0;
	return (newelement);
}

void	ft_lstadd_front(t_list **list, t_list *new)
{
	if (list && new)
	{
		new->next = *list;
		*list = new;
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *n;

	if (lst)
	{
		if (*lst)
		{
			n = ft_lstlast(*lst);
			n->next = new;
		}
		else
			*lst = new;
	}
}