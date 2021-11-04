#include "push_swap.h"

void swap_stack(t_list **list)
{
	int	temp;

	if (*list)
	{
		temp = (*list)->vol;
		if ((*list)->next)
		{
			(*list)->vol = (*list)->next->vol;
			(*list)->next->vol = temp;
		}
	}
}

void push_stack(t_list **dest, t_list **srcs)
{
	t_list *temp;

	if(*srcs)
	{
		temp = *srcs;
		if ((*srcs)->next)
			(*srcs) = (*srcs)->next;
		else
			(*srcs) = NULL;
		temp->next = NULL;
		ft_lstadd_front(dest, temp);
	}
}

void rotate_stack(t_list **list)
{
	t_list *temp;

	if (*list)
	{
		temp = (*list);
		if ((*list)->next)
			(*list) = (*list)->next;
		else
			(*list) = NULL;
		temp->next = NULL;
		ft_lstadd_back(list, temp);
	}
}

int main(int ac, char **av)
{
	t_all all;
	t_list *curr;

	if (init_list(&all, ac, av))
		return (1);
//	swap_stack(&all.a_stack);
//	push_stack(&all.b_stack, &all.a_stack);
//	push_stack(&all.b_stack, &all.a_stack);
//	push_stack(&all.b_stack, &all.a_stack);
//	push_stack(&all.b_stack, &all.a_stack);
//	push_stack(&all.b_stack, &all.a_stack);
//	push_stack(&all.b_stack, &all.a_stack);
//	push_stack(&all.b_stack, &all.a_stack);
//	push_stack(&all.b_stack, &all.a_stack);
//	push_stack(&all.a_stack, &all.b_stack);
//	push_stack(&all.b_stack, &all.a_stack);
//	push_stack(&all.b_stack, &all.a_stack);
//	push_stack(&all.b_stack, &all.a_stack);
//	push_stack(&all.b_stack, &all.a_stack);
//	push_stack(&all.a_stack, &all.b_stack);
//	push_stack(&all.a_stack, &all.b_stack);
//	push_stack(&all.a_stack, &all.b_stack);
	rotate_stack(&all.a_stack);
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