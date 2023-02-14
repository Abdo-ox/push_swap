/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:56:11 by ajari             #+#    #+#             */
/*   Updated: 2023/02/13 19:00:01 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_str(char *s, char **m)
{
	int	i;

	i = 0;
	if (s[0] == '-' || s[0] == '+')
		i++;
	if (!s[i])
	{
		ft_printf("error you enter an i8nvalid number\n");
		ft_free_bonus(m);
		exit(0);
	}
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
		{
			ft_printf("error you enter an invalid9 number\n");
			ft_free_bonus(m);
			exit(0);
		}
		i++;
	}
}

void	fill_stack(t_list **lst, int ac, char **av)
{
	char	**s;
	int		i;
	int		j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (!*av[i])
		{
			ft_printf("error you enter an invalid number\n");
			exit(0);
		}
		s = ft_split(av[i], ' ');
		while (s[j])
		{
			ft_lstadd_back(lst, ft_lstnew(ft_atoi(s[j]), -1));
			check_str(s[j++], s);
		}
		ft_free_bonus(s);
		i++;
	}
}

void	error(void)
{
	write(2, "error\ninstruction not found ", 28);
	exit(0);
}

int	chek_sort(t_list *lst)
{
	while (lst && lst->next)
	{
		if (lst->content > lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	char	**s;
	t_list	*a;
	t_list	*b;
	int		i;

	fill_stack(&a, ac, av);
	s = read_stor(0);
	i = 0;
	b = 0;
	if (s)
	{
		while (s[i])
		{
			execute_instruction(&a, &b, s[i]);
			free(s[i++]);
		}
		free(s);
	}
	if (!b && chek_sort(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
