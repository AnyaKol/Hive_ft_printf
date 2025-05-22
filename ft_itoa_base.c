/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:52:52 by akolupae          #+#    #+#             */
/*   Updated: 2025/05/22 19:34:34 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	count_digits(size_t n);
static void	fill_str(char *str_end, size_t n, char type);

char	*ft_itoa_base(size_t n, char type)
{
	int		digits;
	char	*str;

	if (n == 0)
		digits = 1;
	else
		digits = count_digits(n);
	str = ft_calloc(digits + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	fill_str(&str[digits - 1], n, type);
	return (str);
}

static size_t	count_digits(size_t n)
{
	size_t	digits;

	digits = 0;
	while (n >= 1)
	{
		digits++;
		n = n / 16;
	}
	return (digits);
}

static void	fill_str(char *str_end, size_t n, char type)
{
	const char	*base_hex = "0123456789abcdef";
	const char	*base_hex_cap = "0123456789ABCDEF";

	if (n > 15)
		fill_str(str_end - 1, n / 16, type);
	if (type == 'x' || type == 'p')
		*str_end = base_hex[n % 16];
	else
		*str_end = base_hex_cap[n % 16];
}
