/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 21:22:52 by ajari             #+#    #+#             */
/*   Updated: 2023/02/07 11:00:15 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long	v;
	int				m;
	int				i;

	i = 0;
	m = 1;
	v = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		(str[i] == '-') && (m = -1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		v = v * 10 + (str[i++] - 48);
		if ((v > INT_MAX && m == 1) || (v > 2147483648 && m == -1))
		{
			ft_printf("error out of range number\n");
			exit(0);
		}
	}
	return ((v * m));
}
