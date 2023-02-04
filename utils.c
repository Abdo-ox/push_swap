/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 08:53:33 by ajari             #+#    #+#             */
/*   Updated: 2023/02/04 11:21:34 by ajari            ###   ########.fr       */
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
		ft_lstadd_front(lst_dest, ft_lstnew(co, i, t->p));
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
	printf("s%c\n", c);
}

void	swap_a_and_b(t_list **a, t_list **b)
{
	swap(a, 'a');
	swap(b, 'b');
}

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

void	retate_a_and_b(t_list **a, t_list **b)
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

int	max_int(t_list *lst)
{
	int	i;

	i = 0;
	while (lst->next && lst->idx + 1 == lst->next->idx)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_list	*lst_large(t_list *list)
{
	t_list	*max;
	int		m;

	max = list;
	m = 0;
	while (list)
	{
		if (m < max_int(list))
		{
			m = max_int(list);
			max = list;
		}
		list = list->next;
	}
	return (max);
}

void	print_stack(t_list *list)
{
	t_list	*t;

	t = list;
	ft_printf("\n===> \n");
	while (list)
	{
		//ft_printf("n = %d ", list->content);
		list = list->next;
	}
	ft_printf("\n");
	while (t)
	{
		ft_printf("i = %d \n", t->idx);
		t = t->next;
	}
}

int	probabelite(t_list *list, int size)
{
	int	i;
	int	p1;
	int	p2;

	i = 0;
	p1 = 0;
	p2 = 0;
	while (i < size / 2)
	{
		if (list->idx < size / 5)
			p1++;
		if (list->idx > size / 5)
			p2++;
		list = list->next;
		i++;
	}
	if (p1 > p2)
		return (1);
	return (0);
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
void	move_quarter(t_list **a, t_list **b, int siz, int d)
{
	int	count;
	int	index;

	count = 0;
	index = min(*a, 0)->idx;
	while (count < siz / 6)
	{
		if ((*a)->idx <= siz * (d - 1) / 6 + (siz / 6 / 2))
		{
			push(a, b, 'b');
			if ((*a)->idx > siz * d / 6)
				retate_a_and_b(a, b);
			else
				retate(b, 'b');
			count++;
		}
		else if ((*a)->idx < siz * d / 6 && (*a)->idx >= siz * (d - 1) / 6)
		{
			push(a, b, 'b');
			count++;
		}
		else
			retate(a, 'a');
	}
}

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

void	move_quarter_five_handred(t_list **a, t_list **b, int start, int end)
{
	while (there_is_more_to_push(*a, start, end))
	{
		if ((*a)->idx < start + (end - start) / 2 && (*a)->idx >= start)
		{
			push(a, b, 'b');
			if (ft_lstsize(*a) > 1 && ft_lstsize(*b) > 1 && (*a)->idx < start
				&& (*a)->idx > end)
				retate_a_and_b(a, b);
			else
				retate(b, 'b');
		}
		else if ((*a)->idx < end && (*a)->idx >= start)
			push(a, b, 'b');
		else
			retate(a, 'a');
	}
}

int	where_big_percentage(t_list *lst, int size, int d)
{
	int count;
	int count2;
	int i;
	t_list *t;

	count = 0;
	count2 = 0;
	t = lst;
	while (lst)
	{
		if (lst->idx < size * d / 11 && lst->idx >= size * (d - 1) / 11)
			count++;
		lst = lst->next;
	}
	i = ft_lstsize(t) / 2;
	while (i)
	{
		if (t->idx < size * d / 11 && t->idx >= size * (d - 1) / 11)
			count2++;
		t = t->next;
		i--;
	}
	if (count2 >= count / 2)
		return (0);
	return (1);
}