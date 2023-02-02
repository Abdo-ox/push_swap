/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:29:14 by ajari             #+#    #+#             */
/*   Updated: 2023/02/02 19:34:38 by ajari            ###   ########.fr       */
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
	put_index(*lst);
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

t_list	*min(t_list *lst, int sort)
{
	t_list	*min;

	min = max(lst);
	while (lst)
	{
		if (lst->content < min->content && (lst->index == -1 || !sort))
			min = lst;
		lst = lst->next;
	}
	return (min);
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

void	put_index(t_list *lst)
{
	int	i;

	i = 0;
	while (i < ft_lstsize(lst))
	{
		min(lst, 1)->index = i;
		i++;
	}
}

void	repush_to_a(t_list **a, t_list **b, char c, char d)
{
	t_list	*t;

	while (*b)
	{
		t = max((*b));
		if (c == 'a')
			t = min(*b, 0);
		if (*b == t)
			push(b, a, d);
		else
		{
			if (r_or_rr(*b, t))
				retate(b, c);
			else
				onti_retate(b, c);
		}
	}
}

void	sort_more_then_three(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	move_quarter(a, b, size, 1);
	move_quarter(a, b, size, 2);
	move_quarter(a, b, size, 3);
	move_quarter(a, b, size, 4);
	move_quarter(a, b, size, 5);
	move_quarter(a, b, size, 6);
	while (*a)
		push(a, b, 'b');
	repush_to_a(a, b, 'b', 'a');
}

void	sort_five_handred(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	move_quarter_five_handred(a, b, size, 1);
	move_quarter_five_handred(a, b, size, 2);
	move_quarter_five_handred(a, b, size, 3);
	move_quarter_five_handred(a, b, size, 4);
	move_quarter_five_handred(a, b, size, 5);
	move_quarter_five_handred(a, b, size, 6);
	move_quarter_five_handred(a, b, size, 7);
	move_quarter_five_handred(a, b, size, 9);
	move_quarter_five_handred(a, b, size, 10);
	move_quarter_five_handred(a, b, size, 11);
	move_quarter_five_handred(a, b, size, 12);
	move_quarter_five_handred(a, b, size, 13);
	move_quarter_five_handred(a, b, size, 14);
	move_quarter_five_handred(a, b, size, 15);
	move_quarter_five_handred(a, b, size, 16);
	move_quarter_five_handred(a, b, size, 17);
	move_quarter_five_handred(a, b, size, 18);
	move_quarter_five_handred(a, b, size, 19);
	move_quarter_five_handred(a, b, size, 20);
	while (*a)
		push(a, b, 'b');
	repush_to_a(a, b, 'b', 'a');
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
		// system("leaks push_swap");
	}
}
