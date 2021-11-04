#include "push_swap.h"

long ft_atoi(const char *str)
{
	long res;
	int sign;

	res = 0;
	sign = 1;
	while (*str)
	{
		if (*str == '-')
		{
			sign *= -1;
			str++;
		}
		res = res * 10 + (*str++ - '0');
	}
	return (res * sign);
}

int	chk_int(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && (str[i] != '-'))
			return (1);
		else if (str[i] == '-' && i != 0)
			return (1);
		else
			i++;
	}
	return (0);
}

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

int init_list(t_all *all, int ac, char **av)
{

	int i;
	long num;

	i = 1;
	while (i < ac)
	{
		if (chk_int(av[i]))
			return (1);
		else
		{
			num = ft_atoi(av[i]);
			if (num > 2147483647 || num < -2147483648)
				return (1);
			ft_lstadd_back(&all->a_stack, ft_lstnew((int)num));
		}
		i++;
	}
	return (0);
}

int main(int ac, char **av)
{
	t_all all;
	t_list *curr;

	if (init_list(&all, ac, av))
		return (1);
	curr = all.a_stack;
	printf("stack A:\t");
	while (curr)
	{
		printf("%d\t", curr->vol);
		curr = curr->next;
	}
	curr = all.b_stack;
	printf("\nstack B:\t");
	while (curr)
	{
		printf("%d\t", curr->vol);
		curr = curr->next;
	}
	printf("\n");
	return (0);
}