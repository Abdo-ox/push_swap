/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 08:53:33 by ajari             #+#    #+#             */
/*   Updated: 2023/02/13 18:46:39 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	is_there_more(t_list *list, int start, int end)
{
	while (list)
	{
		if (list->idx >= start && list->idx <= end)
			return (1);
		list = list->next;
	}
	return (0);
}

t_list	*min(t_list *lst, int sort)
{
	t_list	*min;

	min = max(lst);
	while (lst)
	{
		if (lst->content < min->content && (lst->idx == -1 || !sort))
			min = lst;
		lst = lst->next;
	}
	return (min);
}

t_list	*max(t_list *lst)
{
	t_list	*max;

	max = lst;
	while (lst)
	{
		if (lst->content > max->content)
			max = lst;
		lst = lst->next;
	}
	return (max);
}

void	move_quarter(t_list **a, t_list **b, int start, int end)
{
	while (is_there_more(*a, start, end))
	{
		if ((*a)->idx <= end && (*a)->idx >= start)
		{
			if (ft_lstsize(*b) && (*a)->idx <= start + (end - start) / 2)
			{
				push(a, b, 'b');
				if (*a && ((*a)->idx < start || (*a)->idx > end))
					rr(a, b);
				else
					retate(b, 'b');
			}
			else
				push(a, b, 'b');
		}
		else
			retate(a, 'a');
	}
}
