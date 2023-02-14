/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:29:14 by ajari             #+#    #+#             */
/*   Updated: 2023/02/13 18:54:44 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_str(char *s, char **m)
{
	int	i;

	i = 0;
	if (s[0] == '-' || s[0] == '+')
		i++;
	if (!s[i])
	{
		ft_printf("error you enter an invalid number\n");
		ft_free(m);
		exit(0);
	}
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
		{
			ft_printf("error you enter an invalid number\n");
			ft_free(m);
			exit(0);
		}
		i++;
	}
}

void	fill_stack(t_list **lst, int ac, char **av)
{
	char	**s;
	int		i;
	int		j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (!*av[i])
		{
			ft_printf("error you enter an invalid number\n");
			exit(0);
		}
		s = ft_split(av[i], ' ');
		while (s[j])
		{
			check_str(s[j], s);
			ft_lstadd_back(lst, ft_lstnew(ft_atoi(s[j++]), -1));
		}
		ft_free(s);
		i++;
	}
	put_idx(*lst);
}

void	sort_more_then_three(t_list **a, t_list **b)
{
	int	size;
	int	start;
	int	end;
	int	i;

	size = ft_lstsize(*a) / 4;
	i = 0;
	while (*a)
	{
		start = size * i;
		end = size * (i + 1);
		move_quarter(a, b, start, end);
		i++;
	}
	while (*b)
		push_max(b, a, 'b', 'a');
}

void	push_max(t_list **src, t_list **dst, char srcc, char dstc)
{
	t_list	*t;

	while (*src)
	{
		t = max((*src));
		if (*src == t)
		{
			push(src, dst, dstc);
			return ;
		}
		else
		{
			if (r_or_rr(*src, t))
				retate(src, srcc);
			else
				onti_retate(src, srcc);
		}
	}
}

void	repush_to_a(t_list **s, t_list **d, char sc, char dc)
{
	push_max(s, d, sc, dc);
	while (*s || !chek_sort(*d))
	{
		if (*s && (*s)->idx == (*d)->idx - 1)
			push(s, d, dc);
		else if ((*d)->idx == lstlast(*d)->idx + 1)
			onti_retate(d, dc);
		else if (*s && (lstlast(*d) == max(*d) || lstlast(*d)->idx < (*s)->idx))
		{
			push(s, d, dc);
			if (r_or_rrr(*s, *d))
				rr(d, s);
			else
				retate(d, dc);
		}
		else if (ft_lstsize(*s) > 1)
		{
			if (r_or_rrr(*s, *d))
				retate(s, sc);
			else
				onti_retate(s, sc);
		}
	}
}
