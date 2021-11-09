#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
	int 			vol;
	struct s_list	*next;
	int 			stage;
}							t_list;

typedef struct s_all
{
	t_list 			*a_stack;
	t_list 			*b_stack;
	int 			start_len;
	int				current_len;
	int 			min_vol;
	int 			average;
	int 			chang_len;
	int				**mass;
}							t_all;

int init_list(t_all *all, int ac, char **av);
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **list, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);

#endif