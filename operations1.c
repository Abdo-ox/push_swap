/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:42:02 by ajari             #+#    #+#             */
/*   Updated: 2023/02/04 15:00:33 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	retate(t_list **lst, char c)
{
	t_list	*t;

	if (ft_lstsize(*lst) < 2)
		return ;
	else
	{
		t = *lst;
		*lst = (*lst)->next;
		t->next = 0;
		ft_lstadd_back(lst, t);
	}
	ft_printf("r%c\n", c);
}

void	onti_retate(t_list **lst, char c)
{
	t_list	*t;
	t_list	*m;

	if (ft_lstsize(*lst) < 2)
		return ;
	else
	{
		t = *lst;
		while (t->next->next)
			t = t->next;
		m = t->next;
		t->next = 0;
		ft_lstadd_front(lst, m);
	}
	ft_printf("rr%c\n", c);
}

void	rr(t_list **a, t_list **b)
{
	t_list	*t;

	if (ft_lstsize(*a) < 2 || ft_lstsize(*b) < 2)
		return ;
	else
	{
		t = *a;
		*a = (*a)->next;
		t->next = 0;
		ft_lstadd_back(a, t);
		t = *b;
		*b = (*b)->next;
		t->next = 0;
		ft_lstadd_back(b, t);
	}
	ft_printf("rr\n");
}
int	r_or_rrr(t_list *list, t_list *ma_min)
{
	int	p;
	int	size;

	size = ft_lstsize(list);
	p = 0;
	while (list)
	{
		if (list->idx == ma_min->idx - 1)
			break ;
		p++;
		list = list->next;
	}
	if (p < size / 2)
		return (1);
	return (0);
}
