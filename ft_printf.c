/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:19:50 by akolupae          #+#    #+#             */
/*   Updated: 2025/05/18 21:41:15 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_format	format_is_valid(const char format, );
static int		check_format(const char type, va_list args);
int				print_str(char *s);

int	ft_printf(const char *format, ...)
{
	int		print_count;
	int		result;
	va_list	args;
	int		i;
	t_format	flags;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	print_count = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			result = format_is_valid(format[i + 1], &flags);
		else
			result = write(1, &format[i], 1);
		if (result == -1)
			return (-1);
		print_count += result;
		i++;
	}
	va_end(args);
	return (print_count);
}

static int	format_is_valid(const char format, t_format *flags)
{
	int			i;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '#')
			flags->number = true;
		else if (format[i] == '0')
			flags->zero = true;
		else if (format[i] == '-')
			flags->minus = true;
		else if (format[i] == ' ')
			flags->space = true;
		else if (format[i] == '+')
			flags->plus = true;
		else if (format[i] == '.')
			flags->dot = true;
		else
			break ;
	}
	return (0);
}

static int	check_format(const char type, va_list args)
{
	if (type == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		return (1);
	}
	else if (type == 's')
		return (print_str(va_arg(args, char *)));
	else
		return (0);
}

int	print_str(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (write(1, &s[i], 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}
