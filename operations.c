/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:39:03 by ajari             #+#    #+#             */
/*   Updated: 2023/02/13 14:06:17 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **lst_src, t_list **lst_dest, char c)
{
	t_list	*t;
	int		i;
	int		co;

	t = *lst_src;
	if (t)
	{
		t = *lst_src;
		i = t->idx;
		co = t->content;
		ft_lstadd_front(lst_dest, ft_lstnew(co, i));
		*lst_src = (*lst_src)->next;
		free(t);
	}
	else
		return ;
	ft_printf("p%c\n", c);
}

void	swap(t_list **lst, char c)
{
	t_list	*t;
	t_list	*t1;

	if (ft_lstsize(*lst) < 2)
		return ;
	else
	{
		t = (*lst)->next->next;
		t1 = (*lst)->next;
		(*lst)->next = t;
		t1->next = (*lst);
		*lst = t1;
	}
	if (c == 'a' || c == 'b')
		ft_printf("s%c\n", c);
}

int	r_or_rr(t_list *list, t_list *ma_min)
{
	int	p;
	int	size;

	size = ft_lstsize(list);
	p = 0;
	while (list)
	{
		if (list == ma_min)
			break ;
		p++;
		list = list->next;
	}
	if (p < size / 2)
		return (1);
	return (0);
}

void	ft_free(char **m)
{
	int	i;

	i = 0;
	if (!m)
		return ;
	while (m[i])
		free(m[i++]);
	free(m);
	m = 0;
}
