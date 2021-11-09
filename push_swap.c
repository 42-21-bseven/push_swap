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
			temp = (*list)->stage;
			(*list)->stage = (*list)->next->stage;
			(*list)->next->stage = temp;
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
		while ((*arr)[j])
		{
			if ((*arr)[i] > (*arr)[j])
			{
				n = (*arr)[i];
				(*arr)[i] = (*arr)[j];
				(*arr)[j] = n;
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

int search_stage(t_list *steak)
{
	int i;
	
	i = 0;
	if (steak)
		i = steak->stage;
	while (steak)
	{
		if (steak->stage < i)
			i = steak->stage;
		steak = steak->next;
	}
	return (i);
}

void ft_average_index(t_all *all, t_list *steak, int stage)
{
	int i;
	
	i = 0;
	all->mass = malloc(sizeof(int) * all->current_len);
	while (steak)
	{
		if (steak->stage == stage)
			all->mass[i++] = steak->vol;
		steak = steak->next;
	}
	bub_sort(&all->mass);
	all->average = all->mass[i / 2];
	if (all->mass)
		free(all->mass);
}

int ft_search_average(t_all *all, t_list *steak)
{
	int i;
	int current_group;
	t_list *current;
	
	i = 0;
	current = steak;
	current_group = search_stage(steak);
	while (current)
	{
		if (current_group == current->stage)
			i++;
		current = current->next;
	}
	all->current_len = i;
	ft_average_index(all, steak, current_group);
}

int ft_search_stage_elements(t_list *steak, int average)
{
	while (steak)
	{
		if (steak->vol < average)
			return (1);
		steak = steak->next;
	}
	return (0);
}

int	push_chang(t_all *all, int stage)
{
	printf("AVE => %d\tLEN => %d\t3безостаткана2 => %d\n", all->average, all->start_len, (3 / 2));

	while (ft_search_stage_elements(all->a_stack, all->average))
	{
		if (all->a_stack->vol < all->average)
		{
			all->a_stack->stage = stage;
			push_stack(&all->b_stack, &all->a_stack);
		}
		else
			if ((ft_lstlast(all->a_stack))->vol < all->average)
			{
				rev_rotate_stack(&all->a_stack);
				all->a_stack->stage = stage;
				push_stack(&all->b_stack, &all->a_stack);
			}
			else
				rotate_stack(&all->a_stack);
	}
	return (0);
}



void sort(t_all *all)
{
	int stage;
	int flag = 0;
	
	stage = 0;	
	while (flag != 6)
	{
		while (current_len(all->a_stack) > 2)
		{
			ft_search_average(all, all->a_stack);
			push_chang(all, stage++);
			if (current_len(all->a_stack) < 3)
			{
				if(all->a_stack && all->a_stack->next && all->a_stack->vol > all->a_stack->next->vol)
					swap_stack(&all->a_stack);
			}
		}
//		while (current_len(all->b_stack))
//		{
//			push_stack(&all->a_stack, &all->b_stack);
//		}
		flag = 6;
	}
}

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

	sort(&all);



//	all.current_len = current_len(all.a_stack);

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