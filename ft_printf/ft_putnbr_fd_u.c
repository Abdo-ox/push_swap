/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:15:15 by ajari             #+#    #+#             */
/*   Updated: 2023/02/07 08:17:59 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd_u(unsigned int n, int fd)
{
	size_t	m;
	int		i;

	i = 0;
	if (n >= 0 && n <= 9)
	{
		i++;
		m = n + 48;
		write(fd, &m, 1);
	}
	else
	{
		i += ft_putnbr_fd_u(n / 10, fd);
		i += ft_putnbr_fd_u(n % 10, fd);
	}
	return (i);
}
