/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:19:50 by akolupae          #+#    #+#             */
/*   Updated: 2025/05/22 17:51:41 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

static int	print_content(const char *format, va_list args, int *format_i);
static char	*get_str(t_flags flags, va_list args);
static char	*format_str(char *str, t_flags flags);

int	ft_printf(const char *format, ...)
{
	int		print_count;
	int		result;
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
			result = print_content(&format[i + 1], args, &i);
		else
			result = ft_putchar_fd(format[i], 1);
		if (result == -1)
			return (-1);
		print_count += result;
		i++;
	}
	va_end(args);
	return (print_count);
}

static int	print_content(const char *format, va_list args, int *format_i)
{
	int		print_count;
	t_flags	flags;
	char	*str_to_print;

	if (!flags_are_valid(format, format_i))
		return (-1);
	fill_flags(&flags, format);
	check_flags(&flags);
	str_to_print = get_str(flags, args);
	str_to_print = format_str(str_to_print, flags);
	print_count = ft_strlen(str_to_print);
	ft_putstr_fd(str_to_print, 1);
	free(str_to_print);
	return (print_count);
}

static char	*get_str(t_flags flags, va_list args)
{
	if (flags.type == 'c')
		return(print_char(va_arg(args, int)));
	else if (flags.type == 's')
		return (ft_strdup(va_arg(args, const char *)));
	else if (flags.type == 'i' || flags.type == 'd')
		return (ft_itoa(va_arg(args, int)));
	else if (flags.type == 'x' || flags.type == 'X')
		return(ft_itoa_base(va_arg(args, size_t), flags.type));
	else
		return (NULL);
}

static char	*format_str(char *str, t_flags flags)
{
	size_t	len;
	char	*new_str;
	size_t	i;

	len = ft_strlen(str);
	if (flags.dot && flags.type == 's')
		return (format_dot_str(str, flags.width, len));
	if (flags.width > len)
	{
		new_str = ft_calloc(flags.width + 1, sizeof(char));
		i = 0;
		while (i < flags.width - len)
		{
			new_str[i] = ' ';
			i++;
		}
		ft_strlcpy(&new_str[i], (const char *) str, len + 1);
		free(str);
		str = NULL;
		if (flags.minus)
			new_str = format_minus(new_str, i, len);
		if (flags.zero && flags.is_valid)
			new_str = format_zero(new_str);
		return (new_str);
	}
	return (str);
}
