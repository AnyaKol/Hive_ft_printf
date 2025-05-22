/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:14:35 by akolupae          #+#    #+#             */
/*   Updated: 2025/05/22 16:14:38 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*format_minus(char *str, size_t	spaces_end, size_t len)
{
	size_t	i;

	ft_memmove(str, &str[spaces_end], len);
	i = len;
	while (str[i] != '\0')
	{
		str[i] = ' ';
		i++;
	}
	return (str);
}

char	*format_zero(char *str)
{
	size_t	i;

	i = 0;
	if (ft_strchr(str, '-') != NULL)
	{
		str[0] = '-';
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '-')
			str[i] = '0';
		i++;
	}
	return (str);
}
