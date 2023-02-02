/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 08:53:33 by ajari             #+#    #+#             */
/*   Updated: 2023/02/02 19:35:25 by ajari            ###   ########.fr       */
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
		i = t->index;
		co = t->content;
		ft_lstadd_front(lst_dest, ft_lstnew(co, i, t->p));
		*lst_src = (*lst_src)->next;
		free(t);
	}
	else
	{
		ft_printf("lst .com\n");
		return ;
	}
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
		ft_printf("lslslslslsllslslslslslslslsls");
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

t_list	*lst_large(t_list *list)
{
	t_list	*t;
	t_list	*max1;
	int		m;
	int		i;

	max1 = max(list);
	i = 0;
	while (list)
	{
		m = i;
		i = 0;
		t = list;
		while (t->next && t->index == t->next->index + 1)
		{
			ft_printf("i ==> %d ", i);
			i++;
			t = t->next;
		}
		if (i > m)
			max1 = list;
		list = list->next;
	}
	return (max1);
}

void	print_stack(t_list *list)
{
	t_list	*t;

	t = list;
	ft_printf("\n===> \n");
	while (list)
	{
		ft_printf("n = %d ", list->content);
		list = list->next;
	}
	ft_printf("\n");
	while (t)
	{
		ft_printf("i = %d ", t->index);
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
		if (list->index < size / 5)
			p1++;
		if (list->index > size / 5)
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

int	retate_or_onti(t_list *lst, int first, int last)
{
	int	p1;
	int	p2;
	int	size;

	size = ft_lstsize(lst);
	while (lst->next)
	{
		if (lst->index == last + 1)
			p1 = lst->p;
		if (lst->index == first - 1)
			p2 = lst->p;
		lst = lst->next;
	}
	if ((p1 < size / 2 && p2 < size / 2) || p1 > p2 - size)
		return (1);
	return (0);
}

void	move_quarter(t_list **a, t_list **b, int siz, int d)
{
	int	count;

	count = 0;
	while (count < siz / 6)
	{
		if ((*a) && (*a == min(*a, 0) || (*a)->index <= min(*a, 0)->index + 6))
		{
			push(a, b, 'b');
			retate(b, 'b');
			count++;
		}
		else if ((*a)->index < siz * d / 6 && (*a)->index >= siz * (d - 1) / 6)
		{
			push(a, b, 'b');
			count++;
		}
		else
			retate(a, 'a');
	}
}

void	move_quarter_five_handred(t_list **a, t_list **b, int siz, int d)
{
	int	count;

	count = 0;
	while (count < siz / 20)
	{
		if ((*a) && (*a == min(*a, 0) || (*a)->index <= min(*a, 0)->index + 9))
		{
			push(a, b, 'b');
			retate(b, 'b');
			count++;
		}
		else if ((*a)->index < siz * d / 20 && (*a)->index >= siz * (d - 1)
				/ 20)
		{
			push(a, b, 'b');
			count++;
		}
		else
			retate(a, 'a');
	}
}

int	where_big_percentage(t_list *lst, t_list *lst3, int size, int d)
{
	int count;
	int count2;
	int i;
	t_list *t;

	count = 0;
	count2 = 0;
	(void)lst3;
	t = lst;
	while (lst->next)
	{
		if (lst->index <= size * d / 5 && lst->index >= size * (d - 1) / 5)
			count++;
		lst = lst->next;
	}
	i = ft_lstsize(t) / 2;
	while (i >= 0)
	{
		if (t->index <= size * d / 5 && t->index >= size * (d - 1) / 5)
			count2++;
		t = t->next;
		i--;
	}
	if (count2 >= count / 2)
		return (1);
	return (0);
}