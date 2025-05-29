/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:19:50 by akolupae          #+#    #+#             */
/*   Updated: 2025/05/28 19:50:51 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	char	*str;

	if (*format == '%')
		return((*format_i)++, write(1, "%", 1));
	if (!flags_are_valid(format, format_i))
		return (-1);
	fill_flags(&flags, format);
	check_flags(&flags);
	if (flags.type == 'c')
		return(print_char(va_arg(args, int), flags));
	str = get_str(flags, args);
	if (str == NULL)
		str = print_null(flags.type);
	str = format_str(str, flags);
	print_count = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	str = NULL;
	if (!flags.is_valid)
		return (-1);
	return (print_count);
}

static char	*get_str(t_flags flags, va_list args)
{
	if (flags.type == 's')
		return (ft_strdup(va_arg(args, const char *)));
	else if (flags.type == 'i' || flags.type == 'd')
		return (ft_itoa(va_arg(args, int)));
	else if (flags.type == 'u')
		return (ft_itoa_base(va_arg(args, unsigned int), BASE_DEC));
	else if (flags.type == 'x')
		return(ft_itoa_base(va_arg(args, unsigned int), BASE_HEX));
	else if (flags.type == 'X')
		return(ft_itoa_base(va_arg(args, unsigned int), BASE_HEX_UPCASE));
	else if (flags.type == 'p')
		return(print_ptr(va_arg(args, unsigned long)));
	return (NULL);
}

static char	*format_str(char *str, t_flags flags)
{
	char	*new_str;
	int		len;
	int		i;

	len = ft_strlen(str);
	if (flags.precision > -1 && flags.is_valid)
		str = format_precision(str, flags.precision, flags.type, &len);
	if (flags.number && flags.is_valid && str[0] != '0')
	{
		str = format_number(str, flags.type);
		len += 2;
	}
	if ((flags.space || flags.plus) && flags.is_valid)
		str = format_space_plus(str, &len, flags.plus);
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
		if (flags.zero && flags.is_valid && flags.precision == -1)
			new_str = format_zero(new_str, flags.space);
		return (new_str);
	}
	return (str);
}
