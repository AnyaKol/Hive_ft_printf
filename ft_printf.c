/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:19:50 by akolupae          #+#    #+#             */
/*   Updated: 2025/05/15 19:20:39 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	check_format(const char type, va_list args);

int	ft_printf(const char *format, ...)
{
	int		print_count;
	va_list	args;
	int		i;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	print_count = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			print_count += check_format(format[i], args);
			if (print_count == -1)
				break ;
		}
		i++;
	}
	va_end(args);
	return (print_count);
}

static int	check_format(const char type, va_list args)
{
	if (type == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1), 1);
	else
		return (0);
}
