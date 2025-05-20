/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:19:50 by akolupae          #+#    #+#             */
/*   Updated: 2025/05/20 21:10:18 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static bool	format_is_valid(const char *format);
static int	print_content(const char *format, va_list args);
static void	fill_flags(t_flags *flags, const char *format);
static void	check_flags(t_flags *flags);
static char	*check_type(t_flags flags, va_list args);

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
		{
			result = -1;
			if (format_is_valid(&format[i + 1]))
				result = print_content(&format[i + 1], args);
		}
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

static bool	format_is_valid(const char *format)
{
	int	i;
	const char	*flags = "#0- +.";
	const char	*type = "csidxXp";

	i = 0;
	if (format[i] == '%')
		return (true);
	while (format[i] != '\0' && ft_strchr(flags, format[i]) != NULL)
		i++;
	while (format[i] != '\0' && ft_isdigit(format[i]) != 0)
		i++;
	if (format[i] != '\0' && ft_strchr(type, format[i]) != NULL)
		return (true);
	return (false);
}

static void	fill_flags(t_flags *flags, const char *format)
{
	int	i;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '#' && !flags->number)
			flags->number = true;
		else if (format[i] == '0' && !flags->zero)
			flags->zero = true;
		else if (format[i] == '-' && !flags->minus)
			flags->minus = true;
		else if (format[i] == ' ' && !flags->space)
			flags->space = true;
		else if (format[i] == '+' && !flags->plus)
			flags->plus = true;
		else if (format[i] == '.' && !flags->dot)
			flags->dot = true;
		else
			break ;
		i++;
	}
	if (ft_isdigit(format[i]))
		flags->width = ft_atoi(&format[i]);
	while (ft_isdigit(format[i]))
		i++;
	flags->type = format[i];
}

static void	check_flags(t_flags *flags)
{
	flags->is_valid = true;
	if (flags->zero && flags->minus)
		flags->is_valid = false;
	if (flags->space && flags->plus)
		flags->is_valid = false;
	if (flags->number && (flags->type != 'x' || flags->type != 'X'))
		flags->is_valid = false;
	if (flags->plus && (flags->type != 'd' || flags->type != 'i'))
		flags->is_valid = false;
	if (flags->space && (flags->type != 'd' || flags->type != 'i'))
		flags->is_valid = false;
}

static int	print_content(const char *format, va_list args)
{
	int		print_count;
	t_flags	flags;
	char	*str_to_print;

	fill_flags(&flags, format);
	check_flags(&flags);
	str_to_print = check_type(flags, args);
	print_count = ft_strlen(str_to_print);
	ft_putstr_fd(str_to_print, 1);
	return (print_count);
}

static char	*check_type(t_flags flags, va_list args)
{
	if (flags.type == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		return("character");
	}
	else if (flags.type == 's')
	{
		ft_putstr_fd(va_arg(args, char *), 1);
		return ("string");
	}
	else
		return (0);
}
