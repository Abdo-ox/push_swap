/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 08:53:33 by ajari             #+#    #+#             */
/*   Updated: 2023/02/04 15:29:13 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	there_is_more_to_push(t_list *lst, int start, int end)
{
	while (lst)
	{
		if (lst->idx < end && lst->idx >= start)
			return (1);
		lst = lst->next;
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
	while (there_is_more_to_push(*a, start, end))
	{
		if ((*a)->idx < start + (end - start) / 2 && (*a)->idx >= start)
		{
			push(a, b, 'b');
			if (ft_lstsize(*a) > 1 && ft_lstsize(*b) > 1 && (*a)->idx < start
				&& (*a)->idx >= end)
				rr(a, b);
			else
				retate(b, 'b');
		}
		else if ((*a)->idx < end && (*a)->idx >= start)
			push(a, b, 'b');
		else
			retate(a, 'a');
	}
}
