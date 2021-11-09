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

int init_list(t_all *all, int ac, char **av)
{
	int i;
	long num;

	i = 1;
	all->start_len = ac - 1;
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