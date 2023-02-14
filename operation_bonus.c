/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:33:21 by ajari             #+#    #+#             */
/*   Updated: 2023/02/09 08:51:03 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **lst_src, t_list **lst_dest, char c)
{
	t_list	*t;
	int		i;
	int		co;

	(void)c;
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
}

void	swap(t_list **lst, char c)
{
	t_list	*t;
	t_list	*t1;

	(void)c;
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
}

void	ss(t_list **a, t_list **b)
{
	swap(a, 'a');
	swap(b, 'b');
}

char	**read_stor(int fd)
{
	char	*s;
	char	**t;
	char	*m;

	m = get_next_line(fd);
	s = 0;
	while (m)
	{
		s = ft_strjoin(s, m);
		m = get_next_line(fd);
	}
	t = ft_split(s, '\n');
	free(s);
	return (t);
}

void	execute_instruction(t_list **a, t_list **b, char *s)
{
	if (!ft_strncmp(s, "sa", 2))
		swap(a, 'a');
	else if (!ft_strncmp(s, "sb", 2))
		swap(b, 'b');
	else if (!ft_strncmp(s, "ss", 2))
		ss(a, b);
	else if (!ft_strncmp(s, "pa", 2))
		push(b, a, 'a');
	else if (!ft_strncmp(s, "pb", 2))
		push(a, b, 'b');
	else if (!ft_strncmp(s, "rra", 3))
		onti_retate(a, 'a');
	else if (!ft_strncmp(s, "rrb", 3))
		onti_retate(b, 'b');
	else if (!ft_strncmp(s, "rrr", 3))
		rrr(a, b);
	else if (!ft_strncmp(s, "ra", 2))
		retate(a, 'a');
	else if (!ft_strncmp(s, "rb", 2))
		retate(b, 'b');
	else if (!ft_strncmp(s, "rr", 2))
		rr(a, b);
	else
		error();
}
