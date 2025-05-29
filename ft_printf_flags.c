/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:31:47 by akolupae          #+#    #+#             */
/*   Updated: 2025/05/28 12:57:47 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	flags_are_valid(const char *format, int *format_i)
{
	int			i;
	const char	*flags = "#0- +";
	const char	*type = "csiduxXp%";

	i = 0;
	while (format[i] != '\0' && ft_strchr(flags, format[i]) != NULL)
		i++;
	while (format[i] != '\0' && ft_isdigit(format[i]) != 0)
		i++;
	if (format[i] == '.')
		i++;
	while (format[i] != '\0' && ft_isdigit(format[i]) != 0)
		i++;
	if (format[i] != '\0' && ft_strchr(type, format[i]) != NULL)
	{
		*format_i += i + 1;
		return (true);
	}
	return (false);
}

void	fill_flags(t_flags *flags, const char *format)
{
	int	i;

	i = 0;
	*flags = (t_flags){false, false, false, false, false, true, 'c', 0, -1};
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
		else
			break ;
		i++;
	}
	if (ft_isdigit(format[i]) != 0)
		flags->width = ft_atoi(&format[i]);
	while (ft_isdigit(format[i]))
		i++;
	if (format[i] == '.')
	{
		i++;
		flags->precision = ft_atoi(&format[i]);
	}
	while (ft_isdigit(format[i]))
		i++;
	flags->type = format[i];
}

void	check_flags(t_flags *flags)
{
	if (flags->zero && flags->minus)
		flags->is_valid = false;
	if (flags->space && flags->plus)
		flags->is_valid = false;
	if (flags->number && !(flags->type == 'x' || flags->type == 'X'))
		flags->is_valid = false;
	if (flags->plus && !(flags->type == 'd' || flags->type == 'i'))
		flags->is_valid = false;
	if (flags->space && !(flags->type == 'd' || flags->type == 'i'))
		flags->is_valid = false;
	if (flags->zero && (flags->type == 'c' || flags->type == 's' ||
		flags->type == 'p'))
		flags->is_valid = false;
}
