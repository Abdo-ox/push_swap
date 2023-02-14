/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:48:38 by ajari             #+#    #+#             */
/*   Updated: 2023/02/13 18:48:01 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five_handred(t_list **a, t_list **b, int j)
{
	int	size;
	int	start;
	int	end;
	int	i;

	i = j;
	size = ft_lstsize(*a) / 2;
	while (*a)
	{
		start = size - i;
		end = size + i;
		move_quarter(a, b, start, end);
		i += j;
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
	while (!chek_sort(*a) || *b)
	{
		if ((*a) == min((*a), 0))
		{
			push(a, b, 'b');
			if (ft_lstsize(*a) == 3)
			{
				sort_three(a, 'a');
				while (*b)
					push(b, a, 'a');
				break ;
			}
		}
		else if (r_or_rr(*a, min(*a, 0)))
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
		if (!chek_sort(a) && ft_lstsize(a) <= 3)
			sort_three(&a, 'a');
		else if (!chek_sort(a) && ft_lstsize(a) <= 5)
			sort_five(&a, &b);
		else if (!chek_sort(a) && ft_lstsize(a) > 100)
			sort_five_handred(&a, &b, 40);
		else if (!chek_sort(a) && ft_lstsize(a) <= 100)
			sort_five_handred(&a, &b, 16);
	}
}
