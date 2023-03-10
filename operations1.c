/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:42:02 by ajari             #+#    #+#             */
/*   Updated: 2023/02/09 09:07:17 by ajari            ###   ########.fr       */
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

	if (ft_lstsize(*a) > 1)
	{
		t = *a;
		*a = (*a)->next;
		t->next = 0;
		ft_lstadd_back(a, t);
	}
	if (ft_lstsize(*b) > 1)
	{
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
