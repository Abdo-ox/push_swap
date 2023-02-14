/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:04:48 by ajari             #+#    #+#             */
/*   Updated: 2023/02/13 13:53:49 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	check_dup(t_list *list, int content)
{
	while (list)
	{
		if (list->content == content)
		{
			ft_printf("error you put  duplicate numbers\n");
			exit(0);
		}
		list = list->next;
	}
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*t;

	if (!new || !lst)
		return ;
	t = *lst;
	check_dup(t, new->content);
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (t->next)
		t = t->next;
	t->next = new;
}
