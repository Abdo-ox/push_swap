/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:29:27 by ajari             #+#    #+#             */
/*   Updated: 2023/02/07 16:36:07 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	lens;
	char	*sub;

	i = 0;
	sub = NULL;
	if (!s)
		return (NULL);
	lens = ft_strlen(s);
	if (start > lens || len == 0)
		return ((char *)ft_calloc(1, 1));
	if (lens - start < len)
		len = lens - start;
	sub = malloc(len + 1);
	if (sub && s)
	{
		while (i < len && s[start + i])
		{
			sub[i] = s[start + i];
			i++;
		}
		sub[i] = '\0';
	}
	return (sub);
}
