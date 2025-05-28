/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:44:51 by akolupae          #+#    #+#             */
/*   Updated: 2025/05/28 19:02:49 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c, t_flags flags)
{
	int	print_count;
	int	i;

	i = 0;
	if (!flags.minus)
	{
		while (i < flags.width)
		{
			write(1, " ", 1);
			i++;
		}
	}
	print_count = write(1, &c, 1);
	if (flags.minus)
	{
		while (i < flags.width)
		{
			write(1, " ", 1);
			i++;
		}
	}
	if (print_count != -1)
		print_count += i;
	return (print_count);
}

char	*print_ptr(unsigned long ptr)
{
	char	*str;

	if (ptr == 0)
		return (print_null('p'));
	str = ft_itoa_base(ptr, BASE_HEX);
	str = format_number(str, 'p');
	return (str);
}

char	*print_null(char type)
{
	char		*str;
	const char	*null_str = "(null)";
	const char	*nil_str = "(nil)";

	if (type == 'p')
	{
		str = ft_calloc(6, sizeof(char));
		if (str == NULL)
			return (NULL);
		ft_strlcpy(str, nil_str, 6);
	}
	else
	{
		str = ft_calloc(7, sizeof(char));
		if (str == NULL)
			return (NULL);
		ft_strlcpy(str, null_str, 7);
	}
	return (str);
}
