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

void rev_rotate_stack(t_list **list)
{
	t_list *temp;
	t_list *curr;

	if (*list)
	{
		temp = ft_lstlast(*list);
		curr = *list;
		while (curr->next && curr->next->next)
			curr = curr->next;
		curr->next = NULL;
		temp->next = *list;
		*list = temp;
	}
}

void bub_sort(int **arr)
{
	int i;
	int j;
	int n;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (*arr[j])
		{
			if (*arr[i] > *arr[j])
			{
				n = *arr[i];
				*arr[i] = *arr[j];
				*arr[j] = n;
			}
			j++;
		}
		i++;
	}
}

int init_args(t_all *all)
{
	all->chang_len = all->start_len;
	all->a_stack = NULL;
	all->b_stack = NULL;
}

int current_len(t_list *steak)
{
	int i;

	i = 0;
	while (steak)
	{
		steak = steak->next;
		i++;
	}
	return (i);
}

int ft_search_min_vol(t_list *steak)
{
	int min_vol;

	min_vol = steak->vol;
	while (steak)
	{
		if (steak->vol < min_vol)
		{
			min_vol = steak->vol;
			steak = steak->next;
		}
		else
			steak = steak->next;
		printf("%p\t%d\n", steak, min_vol);
//		steak = steak->next;
	}
	return (min_vol);
}

int ft_search_average(t_all *all, t_list *steak)
{
	int average;

	average = 0;
	while (steak)
	{
		average += steak->vol;
		steak = steak->next;

	}
	return ((int)(average / (all->start_len)));
}

int	push_chang(t_all *all, t_list *steak)
{
	printf("AVE => %d\tLEN => %d\t3безостаткана2 => %d\n", all->average, all->start_len, (3 / 2));

	while (all->chang_len)
	{
		if (all->a_stack->vol <= all->average)
		{
			push_stack(&all->b_stack, &all->a_stack);
			all->chang_len--;
		}
		else
			if ((ft_lstlast(all->a_stack))->vol <= all->average)
			{
				rev_rotate_stack(&all->a_stack);
				push_stack(&all->b_stack, &all->b_stack);
				all->chang_len--;
			}
			else
				rotate_stack(&all->a_stack);
	}
	return (0);
}

//int ft_average_index(t_all *all, t_list *steak)
//{
//	all->mass = malloc(sizeof(int) * all->start_len);
//	if (all->mass == NULL)
//		return (1);
//	while (steak)
//	{
//
//		steak = steak->next;
//	}
//}

int main(int ac, char **av)
{
	t_all all;
	t_list *curr;
	int flag;
	t_list *test;

	flag = 33;
	init_args(&all);
	if (init_list(&all, ac, av))
		return (1);

	printf("AC => %d\n", ac - 1);

//	all.current_len = current_len(all.a_stack);


	while (all.current_len > 2)
	{
		all.min_vol = (ft_search_min_vol(all.a_stack));
		printf("MIN_VOL => %d\n", all.min_vol);
		all.average = ft_search_average(&all, all.a_stack);
		printf("AVErAGE => %d\n", all.average);
		all.current_len = current_len(all.a_stack);
		printf("CURRENT => %d\n", all.chang_len);
		all.chang_len = all.chang_len / 2;
		push_chang(&all, all.a_stack);
	}

/*	while (flag)
	{
		while (test)
		{
			if (test->next && test->vol > test->next->vol)
				rotate_stack(&test);
			else
				push_stack(&all.b_stack, &test);
		}
		if (test == NULL)
			flag = 0;
	}
*/	curr = all.a_stack;
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