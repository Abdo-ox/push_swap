/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:29:14 by ajari             #+#    #+#             */
/*   Updated: 2023/02/04 15:49:30 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(t_list **lst, int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		ft_lstadd_back(lst, ft_lstnew(ft_atoi(av[i]), -1, i - 1));
		i++;
	}
	put_idx(*lst);
}

void	sort_three(t_list **lst, char c)
{
	if (chek_sort(*lst))
		return ;
	if (max(*lst) == (*lst)->next)
		onti_retate(lst, c);
	else if (max(*lst) == (*lst))
		retate(lst, c);
	if ((*lst)->content > (*lst)->next->content)
		swap(lst, c);
}

void	put_idx(t_list *lst)
{
	int	i;

	i = 0;
	while (i < ft_lstsize(lst))
	{
		min(lst, 1)->idx = i;
		i++;
	}
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

void	repush_to_a(t_list **src, t_list **dst, char srcc, char dstc)
{
	push_max(src, dst, srcc, dstc);
	while (*src || (!chek_sort(*dst) && !*src))
	{
		if ((*dst)->idx == lstlast(*dst)->idx + 1)
			onti_retate(dst, dstc);
		else if (lstlast(*dst) == max(*dst) || lstlast(*dst)->idx < (*src)->idx)
		{
			push(src, dst, dstc);
			retate(dst, dstc);
		}
		else if ((*src)->idx == (*dst)->idx + 1)
			push(src, dst, dstc);
		else if (r_or_rrr(*src, *dst))
			retate(src, srcc);
		else if (!r_or_rrr(*src, *dst))
			onti_retate(src, srcc);
	}
}

void	sort_five_handred(t_list **a, t_list **b)
{
	int	size;
	int	start;
	int	end;
	int	i;

	i = 40;
	size = ft_lstsize(*a) / 2;
	while (*a)
	{
		start = size - i;
		end = size + i;
		move_quarter(a, b, start, end);
		i += 40;
	}
	repush_to_a(b, a, 'b', 'a');
}

int	chek_sort(t_list *lst)
{
	while (lst->next)
	{
		if (lst->content > lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	sort_five(t_list **a, t_list **b)
{
	int	i;

	i = 0;
	while (!chek_sort(*a))
	{
		if ((*a) == min((*a), 0))
		{
			i++;
			push(a, b, 'b');
			if (i == 2)
			{
				sort_three(a, 'a');
				push(b, a, 'a');
				push(b, a, 'a');
				break ;
			}
		}
		if (r_or_rr(*a, min(*a, 0)))
			retate(a, 'a');
		else
			onti_retate(a, 'a');
	}
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	(void)b;
	if (ac > 1)
	{
		fill_stack(&a, ac, av);
		if (ft_lstsize(a) >= 500)
			sort_five_handred(&a, &b);
		else
			sort_more_then_three(&a, &b);
		// print_stack(a);
		// system("leaks push_swap");
	}
}
