#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
	int 			vol;
	struct s_list	*next;
}							t_list;

typedef struct s_all
{
	t_list 			*a_stack;
	t_list 			*b_stack;
	int 			len;
}							t_all;
#endif