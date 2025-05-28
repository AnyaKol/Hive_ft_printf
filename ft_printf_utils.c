/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:44:51 by akolupae          #+#    #+#             */
/*   Updated: 2025/05/28 17:49:17 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_char(int c)
{
	char	*str;

	str = ft_calloc(2, sizeof(char));
	if (str == NULL)
		return (NULL);
	str[0] = (unsigned char) c;
	return (str);
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
