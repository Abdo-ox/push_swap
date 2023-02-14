/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_bonus1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:34:52 by ajari             #+#    #+#             */
/*   Updated: 2023/02/13 14:07:11 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	retate(t_list **lst, char c)
{
	t_list	*t;

	(void)c;
	if (ft_lstsize(*lst) < 2)
		return ;
	else
	{
		t = *lst;
		*lst = (*lst)->next;
		t->next = 0;
		ft_lstadd_back(lst, t);
	}
}

void	onti_retate(t_list **lst, char c)
{
	t_list	*t;
	t_list	*m;

	(void)c;
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
}

void	rr(t_list **a, t_list **b)
{
	retate(a, 'a');
	retate(b, 'b');
}

void	rrr(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) < 2 || ft_lstsize(*b) < 2)
		return ;
	else
	{
		onti_retate(b, 'b');
		onti_retate(a, 'a');
	}
}

void	ft_free_bonus(char **m)
{
	int	i;

	i = 0;
	if (!m)
		return ;
	while (m[i])
	{
		free(m[i]);
		i++;
	}
	free(m);
	m = 0;
}
